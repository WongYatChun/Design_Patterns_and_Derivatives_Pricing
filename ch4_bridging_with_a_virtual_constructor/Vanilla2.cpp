#include "Vanilla2.h"


VanillaOption::VanillaOption(const PayOff& ThePayOff_, double Expiry_): Expiry(Expiry_){
    ThePayOffPtr = ThePayOff_.clone();
}

VanillaOption::VanillaOption(const VanillaOption& original){
    Expiry = original.Expiry;
    ThePayOffPtr = original.ThePayOffPtr->clone();
}

VanillaOption& VanillaOption::operator=(const VanillaOption& original){
    if(this != &original){ // check against self-assignment
        Expiry = original.Expiry;
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}

double VanillaOption::GetExpiry() const{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const{
    return (*ThePayOffPtr)(Spot);
}

VanillaOption::~VanillaOption(){
    delete ThePayOffPtr;
}