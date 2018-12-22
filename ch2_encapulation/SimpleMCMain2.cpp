/* requires
    PayOff1.cpp
    Random1.cpp
    SimpleMC.cpp
*/

#include "SimpleMC.h"
#include <iostream>
using namespace std;

int main(){
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
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

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);

    double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Strike, Vol, r, NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Strike, Vol, r, NumberOfPaths);
    cout << "The prices are " << resultCall
                              << " for the call and "
                              << resultPut
                              << " for the put\n"
                              << endl;
    return 0;
}