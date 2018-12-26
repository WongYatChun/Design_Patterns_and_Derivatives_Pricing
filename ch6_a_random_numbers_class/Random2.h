#ifndef RANDOM2_H
#define RANDOM2_H

#include "Arrays.h"

/* Remember: we are now bound to this array class
    Sol1: pass in a pointer; Sol2: templatize so that array class is a template argument; Sol3: use iterator */
class RandomBase{
    public:
        RandomBase(unsigned long Dimensionality_);
        // return the dimensionality of the generator
        inline unsigned long GetDimensionality() const;
        // trigger when dimensionality changes
        // virtual method: if dimensionality changes, the random number generator will also need to know
        virtual void ResetDimensionality(unsigned long NewDimensionality);
        
        virtual RandomBase* clone() const = 0;

        virtual void Skip(unsigned long numberOfPaths) = 0;
        virtual void SetSeed(unsigned long Seed) = 0;
        virtual void Reset() = 0;

        // call by ref: save time from coying arrays, minimize unnecessary operations
        virtual void GetUniforms(MJArray& variates) = 0;
        // transform Uniforms into Gaussian distributions via approximation to the inverse cummulative normal function
        // virtual method: allow the possibility that for a particular generator there is another preferred conversion method
        virtual void GetGaussians(MJArray& variates);
            
    private:
        unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const{
    return Dimensionality;
}

#endif