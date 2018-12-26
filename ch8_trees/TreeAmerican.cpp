#include "TreeAmerican.h"
#include <algorithm>

TreeAmerican::TreeAmerican(double FinalTime, const PayOffBridge& ThePayOff_)
:TreeProduct(FinalTime), ThePayOff(ThePayOff_){}

TreeProduct* TreeAmerican::clone() const{
    return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double Spot) const{
    return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const{
    /* Borland compiler does not like unused named variables */
    return std::max(ThePayOff(Spot), DiscountedFutureValue);
}