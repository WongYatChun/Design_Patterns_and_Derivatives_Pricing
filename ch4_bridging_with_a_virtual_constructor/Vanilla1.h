/* 
Implement a Vanilla Option class using a reference to a pay-off object
 */

#ifndef VANILLA_1_H
#define VANILLA_1_H

#include "PayOff2.h"

class VanillaOption{
    public:
        VanillaOption(PayOff& ThePayOff_, double Expiry_);
        /* Give the expiry of the option */
        double GetExpiry() const;
        /* State the payoff at expiry given spot */
        double OptionPayOff(double Spot) const;
    private:
        double Expiry;
        PayOff& ThePayOff;
};
#endif