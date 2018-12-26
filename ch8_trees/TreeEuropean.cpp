#include "TreeEuropean.h"
#include <algorithm>

TreeEuropean::TreeEuropean(double FinalTime, const PayOffBridge& ThePayOff_)
:TreeProduct(FinalTime), ThePayOff(ThePayOff_){}

TreeProduct* TreeEuropean::clone() const{
    return new TreeEuropean(*this);
}

double TreeEuropean::FinalPayOff(double Spot) const{
    return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const{
    /* Borland compiler does not like unused named variables */
    return DiscountedFutureValue;
}