/* 
Required source files:
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffFactory.cpp
    PayOffregistration.cpp
 */

#include "PayOff3.h"
#include "PayOffBridge.h"
#include "PayOffConstructible.h"
#include "PayOffFactory.h"

#include <iostream>
#include <string>

using namespace std;

int main(){
    double Strike;
    string name;

    cout << "\nEnter Strike\n";
    cin >> Strike;

    cout << "\npay-off name\n";
    cin >> name;

    PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(name, Strike);

    if(PayOffPtr != NULL){
        double Spot;
        cout << "\nspot\n";
        cin >> Spot;
        cout << "\n" << PayOffPtr->operator()(Spot) << "\n";
        delete PayOffPtr;
    }
    return 0;
}