#include <math.h>
#include <iostream>
using namespace std;

template <class T, double (T::*Value)(double) const, double (T::*Derivative)(double) const>

double NewtonRaphson(double Target, double Start, double Tolerance, const T& TheObject){
    double y = (TheObject.*Value)(Start);
    cout << "\nfirst y: " << y << endl;
    double x = Start;
    cout << "first x: " << x << endl;
    while(fabs(y - Target) > Tolerance){
        double d = (TheObject.*Derivative)(x);
        cout << "d: " << d << endl;
        x += (Target - y) / d;
        y = (TheObject.*Value)(x);
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }
    return x;
}
