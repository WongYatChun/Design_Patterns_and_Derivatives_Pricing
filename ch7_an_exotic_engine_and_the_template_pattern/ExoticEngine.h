#ifndef EXOTIC_ENGINE_H
#define EXOTIC_ENGINE_H

#include "Wrapper.h"
#include "Parameters.h"
#include "PathDependent.h"
#include "MCStatistics.h"
#include <vector>

class ExoticEngine{
    
    public:
        ExoticEngine(const Wrapper<PathDependent>&  TheProduct_, const Parameters& r_);
        
        virtual ~ExoticEngine(){};
        
        void DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths);
    
        // pure virtual and therefore will be defined in an inherited class which will involve a choice of stochastic process and model
        // not constant: we will want a different set of spot values every time and so it will necessarily change something about the state of the object
        // By Ref: avoid any memory allocation; 
        // Implitict assumption: the array passed into GetOnePath is of the correct size
        virtual void GetOnePath(MJArray& SpotValues) = 0;
        // does everything necessary for one path given the spot values
        // const: turning spot values into prices is a purely functional action with no underlying changes
        double DoOnePath(const MJArray& SpotValues) const;
    
    private:
        // The product is stored using the Wrapper template as we do not know its type
        Wrapper<PathDependent> TheProduct;
        // The interest rates
        Parameters r;
        // Store the discount factors in order for the possible cash-flow times
        MJArray Discounts;
        // mutable: it can change value inside const member functions
        // the variable is not really a data member, but instead it is a workspace variable
        // Remember that creating and destroying containers can be time-consuming so we design the class so that the vector is created once and for all at the beginning
        mutable std::vector<CashFlow> TheseCashFlows;
};

#endif