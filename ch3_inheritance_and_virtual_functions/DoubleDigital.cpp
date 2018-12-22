/* 
The crucial point is 
-   We must include the file DoubleDigital.h in our interface
-   We do not include it in the Monte Carlo file, SimpleMC2
-   We do not include it in the Payoff file, PayOff2
 */

#include "DoubleDigital.h"

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_, double Upperlever_)
: LowerLevel(LowerLevel_), UpperLevel(Upperlever_){}

double PayOffDoubleDigital::operator()(double Spot) const{
    if (Spot <= LowerLevel || Spot >= UpperLevel) return 0;
    return 1;
}

