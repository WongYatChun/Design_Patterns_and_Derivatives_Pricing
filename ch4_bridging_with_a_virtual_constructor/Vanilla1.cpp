#include "Vanilla1.h"
#include <iostream>
using namespace std;

VanillaOption::VanillaOption(PayOff& ThePayOff_, double Expiry_)
: ThePayOff(ThePayOff), Expiry(Expiry_){}

double VanillaOption::GetExpiry() const{
    /* Give the expiry of the option */
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const{
    /* State the payoff at expiry given spot */
    // cout << Spot << endl;
    // cout << ThePayOff(Spot) << endl;
    return ThePayOff(Spot);
    // return 0;
}