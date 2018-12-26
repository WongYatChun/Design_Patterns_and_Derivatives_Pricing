#include "Random2.h"
#include "Normals.h"
#include <cstdlib>


// the basic math functions should be in namespace std but aren't in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif


RandomBase::RandomBase(unsigned long Dimensionality_): Dimensionality(Dimensionality_){}
        
// trigger when dimensionality changes
// virtual method: if dimensionality changes, the random number generator will also need to know
void RandomBase::ResetDimensionality(unsigned long NewDimensionality){
    Dimensionality = NewDimensionality;
}
        
// call by ref: save time from coying arrays, minimize unnecessary operations
// transform Uniforms into Gaussian distributions via approximation to the inverse cummulative normal function
// virtual method: allow the possibility that for a particular generator there is another preferred conversion method
void RandomBase::GetGaussians(MJArray& variates){
    GetUniforms(variates);
    for (unsigned long i = 0; i < Dimensionality; i++){
        double x = variates[i];
        variates[i] = InverseCumulativeNormal(x);
    }
}
        