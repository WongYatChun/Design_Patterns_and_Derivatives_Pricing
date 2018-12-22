#include "PayOff3.h"
#include <algorithm>
using namespace std;

PayOffCall::PayOffCall(double Strike_): Strike(Strike_){}

double PayOffCall::operator()(double Spot) const{
    return max(Spot - Strike, 0.0);
}

PayOff* PayOffCall::clone() const{
    /* 
     Virtual Copy Constructor
     Define a virtual method of the base class
     which causes the object to create a copy of itself and return a pointer to the copy
    */
    // this pointer always points to the object being called
    return new PayOffCall(*this);// create a copy of the object for which the clone method has been called
}

PayOffPut::PayOffPut(double Strike_): Strike(Strike_){}

double PayOffPut::operator()(double Spot) const{
    return max(Strike - Spot, 0.0);
}

PayOff* PayOffPut::clone() const{
    /* 
     Virtual Copy Constructor
     Define a virtual method of the base class
     which causes the object to create a copy of itself and return a pointer to the copy
    */
    // this pointer always points to the object being called
    return new PayOffPut(*this); // create a copy of the object for which the clone method has been called
}

