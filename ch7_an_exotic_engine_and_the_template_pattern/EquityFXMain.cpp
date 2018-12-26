/* 
Require source files:
    AntiThetic.cpp
    Arrays.cpp
    ConvergenceTable.cpp
    ExoticBSEngine.cpp
    ExoticEngine.cpp
    MCStatistics.cpp
    Normals.cpp
    Parameters.cpp
    ParkMiller.cpp
    PathDependent.cpp
    PathDependentAsian.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    Random2.cpp
 */

#include "AntiThetic.h"
#include "ConvergenceTable.h"
#include "ExoticBSEngine.h"
#include "MCStatistics.h"
#include "ParkMiller.h"
#include "PathDependentAsian.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    double NumberOfDates;
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

    cout << "\nEnter d\n";
    cin >> d;

    cout << "\nEnter Number Of Dates\n";
    cin >> NumberOfDates;

    cout << "\nEnter Number Of Paths\n";
    cin >> NumberOfPaths;

    MJArray times(NumberOfDates);

    for(unsigned long i = 0; i < NumberOfDates; i++){
        times[i] = (i + 1.0) * Expiry / NumberOfDates;
    }

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    /* Option type */
    PayOffCall thePayOff(Strike);
    PathDependentAsian theOption(times, Expiry, thePayOff);
    /* Statistic gatherer */
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    /* Random number generator */
    RandomParkMiller generator(NumberOfDates);
    AntiThetic GenTwo(generator);

    ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);
    theEngine.DoSimulation(gathererTwo, NumberOfPaths);

    vector<vector<double>> results = gathererTwo.GetResultsSoFar();

    cout << "\nFor the Asian call price the results are\n";

    for (unsigned long i = 0; i < results.size(); i++){
        for (unsigned long j = 0; j < results[i].size(); j++)
            cout << results[i][j] << " " ;
        cout << "\n";
    }    
    return 0;
}