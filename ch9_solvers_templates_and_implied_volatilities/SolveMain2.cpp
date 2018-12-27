/* 
Require Source files:
    BlackScholesFormulas.cpp
    BSCallTwo.cpp
    Normals.cpp
 */

#include "BlackScholesFormulas.h"
#include "BSCallTwo.h"
#include "NewtonRaphson.h"
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
    double Start;
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

    cout << "\nStart guess\n";
    cin >> Start; //   0.02 <=  Start <= 1.5


    cout << "\nTolerance\n";
    cin >> tolerance;

    BSCallTwo theCall(r, d, Expiry, Spot, Strike);
    double vol = NewtonRaphson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(Price, Start, tolerance, theCall);
    double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);
    cout <<  "\nvol: " << vol << "\npricetwo " << PriceTwo << endl;
}

