/* 
requires PayOff3.cpp
         Random1.cpp
         SimpleMC4.cpp
         Vanilla2.cpp
 */

#include "SimpleMC4.h"
#include "Vanilla2.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter exiry\n";
    cin >> Expiry;

    cout << "\nEnter strike\n";
    cin >> Strike;

    cout << "\nEnter spot\n";
    cin >> Spot;

    cout << "\nEnter vol\n";
    cin >> Vol;

    cout << "\nEnter r\n";
    cin >> r;

    cout << "\nEnter Number of Paths\n";
    cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);

    double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);
    cout << "\nThe call price is " << result << "\n";

    VanillaOption secondOption(theOption);
    result = SimpleMonteCarlo3(secondOption, Spot, Vol, r, NumberOfPaths);
    cout << "\nThe call price is " << result << "\n";

    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff, Expiry);
    theOption = thirdOption;
    
    result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);
    cout << "\nThe put price is " << result << "\n";

    return 0;
}

