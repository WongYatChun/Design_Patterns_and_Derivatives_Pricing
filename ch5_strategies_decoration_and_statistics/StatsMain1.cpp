/* 
Uses source files
    MCStatistics.cpp
    Parameters.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    Random1.cpp
    SimleMC7.cpp
    Vanilla3.cpp
 */

#include "SimpleMC7.h"
#include "Vanilla3.h"
#include "MCStatistics.h"
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

    cout << "\nEnter Strike\n";
    cin >> Strike;

    cout << "\nEnter Spot\n";
    cin >> Spot;

    cout << "\nEnter vol\n";
    cin >> Vol;

    cout << "\nEnter r\n";
    cin >> r;

    cout << "\nEnter Number Of Paths\n";
    cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;

    SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gatherer);

    vector<vector<double>> results = gatherer.GetResultsSoFar();

    cout << "\nFor the call price the results are \n";

    for(unsigned long i = 0; i < results.size(); i++){
        for (unsigned long j = 0; j < results[i].size(); j++)
            cout << results[i][j] << " ";
        cout << "\n";
    }
    return 0;
}