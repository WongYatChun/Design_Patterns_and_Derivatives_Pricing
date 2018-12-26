/* 
uses source file:
    AntiThetic.cpp
    Arrays.cpp
    ConvergenceTable.cpp
    MCStatistics.cpp
    Normals.cpp
    Parameters.cpp
    ParkMiller.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    Random2.cpp
    SimpleMC8.cpp
    Vanilla3.cpp
 */

#include "SimpleMC8.h"
#include "ParkMiller.h"
#include <iostream>
#include "Vanilla3.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"

using namespace std;

int main(int argc, char const *argv[])
{
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
    
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(1);
    AntiThetic GenTwo(generator);

    SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererTwo, GenTwo);

    vector<vector<double>> results = gathererTwo.GetResultsSoFar();

    cout << "\nFor the call price the results are\n";

    for (unsigned long i = 0; i < results.size(); i++){
        for (unsigned long j = 0; j < results[i].size(); j++)
            cout << results[i][j] << " " ;
        cout << "\n";
    }    
    return 0;
}
