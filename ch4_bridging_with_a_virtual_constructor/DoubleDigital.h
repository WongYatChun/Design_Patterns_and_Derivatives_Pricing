/* 
Double digital pay-off
-   The payoff pays 1 if spot is between two values and 0 otherwise
 */

#ifndef DOUBLEDIGITAL_H
#define DOUBLEDIGITAL_H
#include "PayOff2.h"

class PayOffDoubleDigital : public PayOff{
    public:
        PayOffDoubleDigital(double LowerLever_, double UpperLevel_);
        virtual double operator()(double Spot) const;
        virtual ~PayOffDoubleDigital(){}
    private:
        double LowerLevel;
        double UpperLevel;
};

#endif