#include "Random1.h"
#include <cmath>
#include "SimpleMC7.h"
// the basic math functions should be in namespace std but are not in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

// all the data to be returned is inside the object gatherer
void SimpleMonteCarlo5(const VanillaOption& TheOption,
                        double Spot,
                        const Parameters& Vol, // we don't have to crete the Parameters object explicitly, the conversion is done implicity by the compiler
                        const Parameters& r, // we don't have to crete the Parameters object explicitly, the conversion is done implicity by the compiler
                        unsigned long NumberOfPaths,
                        StatisticsMC& gatherer){// pass by ref and not const
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    double movedSpot = Spot * exp(r.Integral(0,Expiry) + itoCorrection);
    double thisSpot;
    double discounting = exp(-r.Integral(0, Expiry));

    for(unsigned long i = 0; i < NumberOfPaths; i++){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayOff * discounting);
    }

} 