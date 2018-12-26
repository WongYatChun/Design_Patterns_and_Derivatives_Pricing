#ifndef VANILLA_3_H
#define VANILLA_3_H

#include "PayOffBridge.h"

class VanillaOption{
    public:
        // although the constructor expects an argument of type PayOffBridge
        // it happily accepts the argument of type PayOffCall
        // Because: there is a constructor for PayOffBridge which is an object of type PayOff&
        // The compiler automatically accepts the inherited class object (i.e. PayOffCall) as a substitute for the base class object
        // and then silently converts it for us into the PayOffBridge object which is then passed to the VanillaOption constructor
        VanillaOption(const PayOffBridge& ThePayOff_, double Expiry);
        double OptionPayOff(double Spot) const;
        double GetExpiry() const;
    private:
        double Expiry;
        PayOffBridge ThePayOff;
};

#endif