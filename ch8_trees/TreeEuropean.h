#ifndef TREE_EUROPEAN_H
#define TREE_EUROPEAN_H

#include "TreeProducts.h"
#include "PayOffBridge.h"

class TreeEuropean: public TreeProduct{
    public:
        TreeEuropean(double FinalTime, const PayOffBridge& ThePayOff_);
        virtual TreeProduct* clone() const;
        virtual ~TreeEuropean(){}
        virtual double FinalPayOff(double Spot) const;
        virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
    
    private:
        PayOffBridge ThePayOff;
};
#endif