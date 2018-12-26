#ifndef SIMPLEMC8_H
#define SIMPLEMC8_H

#include"Vanilla3.h"
#include"Parameters.h"
#include"Random2.h"
#include"MCStatistics.h"

void SimpleMonteCarlo6(const VanillaOption& TheOption,
                        double Spot,
                        const Parameters& Vol,
                        const Parameters& r,
                        unsigned long NumOfPaths,
                        StatisticsMC& gatherer,
                        RandomBase& generator);//non-const, use ref to the ase class to allow the caller to decide how to implement the generator
#endif