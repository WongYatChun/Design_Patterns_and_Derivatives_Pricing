/* 
requires:
    PayOff2.cpp
    Random1.cpp
    SimpleMC2.cpp
*/

# include "SimpleMC2.h"
# include <iostream>
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

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    unsigned long optionType;
    cout << "\nEnter 0 for call, otherwise put\n";
	cin >> optionType;

    PayOff* thePayOffPtr; // declare outside the 'if' to ensure that it persists after the 'if statement' is complete

    if (optionType == 0)
        // remember to free up the memory at the end
        thePayOffPtr = new PayOffCall(Strike); // ask the compiler to reserve some memory and return a pointer to the object
    else
        // remember to free up the memory at the end
        thePayOffPtr = new PayOffPut(Strike);

    /* 
    This won't work: because `thePayOff` will be created as a automatic variable, disappears when the scope is left
    if (optionType == 0)
        PayOffCall thePayOff(Strike);
    else
        PayOffPut thePayOff(Strike);
    
    as soon as we leave the if statement the object no longer exists and any attempts to reference thePayOff will result in compiler error
    */

	double result = SimpleMonteCarlo2(*thePayOffPtr, // dereference the pointer to pass in the object rather than the pointer
                                      Expiry,                                           
				                      Spot, 
						              Vol, 
						              r, 
						              NumberOfPaths);
    //if the destructor is NOT virtual, the it will call the base class destructor, which may be problematic if the object is an inherited class
    // we declare the destructor virtual, the compiler then uses the virtual function table to correctly decide which destructor to call
    delete thePayOffPtr;// free up the memory
    
    cout <<"the prices are " << result << endl;


    return 0;
}