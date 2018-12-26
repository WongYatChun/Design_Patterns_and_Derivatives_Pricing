/* 
A linear congruential generator (a random number generator)
Park & Miller generator: the minimal standard generator - provides a minimum guaranteed level of statistical accuracy

A small inner class that develops a random genertor that returns one integer(i.e. long) every time it is called
A larger class that turns the output into a vector of uniforms in the formated desired
 */

#ifndef PARK_MILLER_H
#define PARK_MILLER_H
#include "Random2.h"

class ParkMiller{
    /* develop a sequence of uncorrelated longs*/
    public:
        ParkMiller(long Seed_ = 1);
        void SetSeed(long Seed_);
        
        long GetOneRandomInteger();
        
        // indicate the Max and Min values that the generator
        static unsigned long Max();
        static unsigned long Min();

    private:
        long Seed;
};

class RandomParkMiller: public RandomBase{
    /* 
    inherited from RandomBase 
    Main data member: ParkMiller generator object
    Remember the initial seed and the reciprocal of the maximum value plus 1 to save time
        then turning the output of the inner generator into uniform

    Adapter Pattern: use an intermediary class which transforms one interface into another
    */
    public:
        RandomParkMiller(unsigned long Dimensionality,
                         unsigned long Seed = 1);
        virtual RandomBase* clone() const;
        virtual void GetUniforms(MJArray& variates);
        virtual void Skip(unsigned long numberOfPaths);
        virtual void SetSeed(unsigned long Seed);
        virtual void Reset();
        virtual void ResetDimensionality(unsigned long NewDimensionality);
    private:
        ParkMiller InnerGenerator;
        unsigned long InitialSeed;
        double Reciprocal;
};

#endif