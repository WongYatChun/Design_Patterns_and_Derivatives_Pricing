/* 
Require Source files:
    BlackScholesFormulas.cpp
    BSCallClass.cpp
    Normals.cpp
 */
#include "Bisection.h"
#include "BlackScholesFormulas.h"
#include "BSCallClass.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(){
    double Expiry;
    double Strike;
    double Spot;
    double r;
    double d;
    double Price;
    double low, high;
    double tolerance;
    
    cout << "\nEnter expiry\n";
    cin >> Expiry;

    cout << "\nEnter Strike\n";
    cin >> Strike;

    cout << "\nEnter spot\n";
    cin >> Spot;

    cout << "\nEnter price\n";
    cin >> Price;

    cout << "\nEnter r \n";
    cin >> r;
    
    cout << "\nEnter d \n";
    cin >> d;

    cout << "\nlower guess\n";
    cin >> low;

    cout << "\nhigher guess\n";
    cin >> high;

    cout << "\nTolerance\n";
    cin >> tolerance;

    BSCall theCall(r, d, Expiry, Spot, Strike);
    double vol = Bisection(Price, low, high, tolerance, theCall);
    double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

    cout <<  "\nvol: " << vol << " pricetwo " << PriceTwo << endl;
}

