/* 
requires:
    DoubleDigital.cpp
    PayOff2.cpp
    Random1.cpp
    SimpleMC2.cpp
*/

# include "SimpleMC2.h"
# include "DoubleDigital.h"
# include <iostream>
using namespace std;

int main(){

	double Expiry;
	double Low, Up; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter the low barrier\n";
	cin >> Low;

    cout << "\nEnter the up barrier\n";
	cin >> Up;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low, Up);

	double resultCall = SimpleMonteCarlo2(thePayOff,
                                          Expiry,                                           
							              Spot, 
							              Vol, 
							              r, 
						                  NumberOfPaths);
	
	cout <<"the prices are " << resultCall << endl ;
    return 0;
}