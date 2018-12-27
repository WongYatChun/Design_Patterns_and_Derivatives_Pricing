#if defined(_MSC_VER)
#pragma warning (disable:4786)
#endif

#include "PayOffFactory.h"
#include <iostream>
using namespace std;


PayOffFactory& PayOffFactory::Instance(){
    static PayOffFactory theFactory;
    return theFactory;
}

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction){
    TheCreatorFunctions.insert(pair<string, CreatePayOffFunction>(PayOffId, CreatorFunction));
}

// make the CreatePayOff method return a pointer to a PayOff
// allow the possibility of returning a null pointer if the identity string was not found
// otherwise we would have to throw an error or return a default sort of payoff
PayOff* PayOffFactory::CreatePayOff(string PayOffId, double Strike){
    map<string, CreatePayOffFunction>::const_iterator i = TheCreatorFunctions.find(PayOffId);
    if(i == TheCreatorFunctions.end()){
        cout << PayOffId << " is an unknown payoff" << endl;
        return NULL;
    }
    return (i->second)(Strike);
}
