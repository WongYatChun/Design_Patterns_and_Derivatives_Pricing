#ifndef PATH_DEPENDENT_ASIAN_H
#define PATH_DEPENDENT_ASIAN_H

#include "PathDependent.h"
#include "PayOffBridge.h"

class PathDependentAsian:public PathDependent{
    public:
        PathDependentAsian(const MJArray& LookAtTimes_,
                            double DeliveryTime_,
                            const PayOffBridge& ThePayOff_);
        virtual PathDependent* clone() const;
        virtual unsigned long MaxNumberOfCashFlows() const;
        virtual MJArray PossibleCashFlowTimes() const;
        virtual unsigned long CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedFlows) const;
        virtual ~PathDependentAsian(){}
    private:
        double DeliveryTime;
        PayOffBridge ThePayOff;
        unsigned long NumberOfTimes;
};

#endif