#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include "Random2.h"
#include "Wrapper.h"

class AntiThetic: public RandomBase{
    public:
        AntiThetic(const Wrapper<RandomBase>& innerGenerator);
        virtual RandomBase* clone() const;
        virtual void GetUniforms(MJArray& variates);
        virtual void Skip(unsigned long numberOfPaths);
        virtual void SetSeed(unsigned long Seed);
        virtual void ResetDimensionality(unsigned long NewDimensionality);
        virtual void Reset();
    private:
        Wrapper<RandomBase> InnerGenerator; // a copy of the generator we are using is stored using the Wrapper template class and cloning
        bool OddEven; // indicate whether the next draw should be drawn from the inner generator or be the anti-thetic of the last draw
        MJArray NextVariates;
};

#endif