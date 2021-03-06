#include "ExoticEngine.h"
#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependent>&  TheProduct_, const Parameters& r_)
:TheProduct(TheProduct_), r(r_), Discounts(TheProduct_->PossibleCashFlowTimes()){
    for(unsigned long i = 0; i < Discounts.size(); i++){
        Discounts[i] = exp(-r.Integral(0.0, Discounts[i]));
    }
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

double ExoticEngine::DoOnePath(const MJArray& SpotValues) const{
    unsigned long NumberFlows = TheProduct->CashFlows(SpotValues, TheseCashFlows);
    double Value = 0.0;
    for (unsigned long i = 0; i < NumberFlows; i++){
        Value += TheseCashFlows[i].Amount * Discounts[TheseCashFlows[i].TimeIndex];
    }
    return Value;
}

void ExoticEngine::DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths){
    MJArray SpotValues(TheProduct->GetLookAtTimes().size());
    TheseCashFlows.resize(TheProduct->GetLookAtTimes().size());
    double thisValue;

    for(unsigned long i = 0; i < NumberOfPaths; ++i){
        GetOnePath(SpotValues);
        thisValue = DoOnePath(SpotValues);
        TheGatherer.DumpOneResult(thisValue);
    }
    return;
}


