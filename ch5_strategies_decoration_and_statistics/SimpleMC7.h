#ifndef SIMPLEMC7_H
#define SIMPLEMC7_H

#include "Vanilla3.h"
#include "Parameters.h"
#include "MCStatistics.h"

// all the data to be returned is inside the object gatherer
void SimpleMonteCarlo5(const VanillaOption& TheOption,
                        double Spot,
                        const Parameters& Vol,
                        const Parameters& r,
                        unsigned long NumberOfPaths,
                        StatisticsMC& gatherer); // pass by ref and not const

#endif