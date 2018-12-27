#ifndef PAYOFF_FACTORY_H
#define PAYOFF_FACTORY_H
#if defined(_MSC_VER)
#pragma warning (disable:4786)
#endif

#include "PayOff3.h"
#include <map>
#include <string>

class PayOffFactory{
    public:
    // CreatePayOffFunction: pointers to functions which take in a double and spit out as a PayOff*
        typedef PayOff* (*CreatePayOffFunction)(double );
        static PayOffFactory& Instance();
        void RegisterPayOff(std::string, CreatePayOffFunction);
        // make the CreatePayOff method return a pointer to a PayOff
        // allow the possibility of returning a null pointer if the identity string was not found
        // otherwise we would have to throw an error or return a default sort of payoff
        PayOff* CreatePayOff(std::string PayOffId, double Strike);
        ~PayOffFactory(){};
    private:
        std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
        PayOffFactory(){};
        PayOffFactory(const PayOffFactory&){}
        PayOffFactory& operator = (const PayOffFactory&){return *this;}
};



#endif