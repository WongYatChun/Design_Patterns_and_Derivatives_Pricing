#include "Arrays.h"
#include <algorithm>
#include <numeric>

MJArray::MJArray(unsigned long size): Size(size), Capacity(size){// constructor
    if(Size > 0){
        ValuesPtr = new double[size];
        EndPtr = ValuesPtr;
        EndPtr += size;
    }else{
        ValuesPtr = EndPtr = 0;
    }
} 
MJArray::MJArray(const MJArray& original): Size(original.Size), Capacity(original.Size){// copy constructor
    if(Size > 0){
        ValuesPtr = new double[Size];
        EndPtr = ValuesPtr;
        EndPtr += Size;
        std::copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
    }else{
        ValuesPtr = EndPtr = 0;
    }
} 

MJArray::~MJArray(){// destructor
    if(ValuesPtr >0) delete [] ValuesPtr;
}

//assignment operator
MJArray& MJArray::operator = (const MJArray& original){
    if(&original == this) return *this;
    if(original.Size > Capacity){
        if(Capacity > 0) delete [] ValuesPtr;
        ValuesPtr = new double[original.Size];
        Capacity = original.Size;
    }
    Size = original.Size;

    EndPtr = ValuesPtr;
    EndPtr += Size;

    std:: copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
    return *this;
}
MJArray& MJArray::operator = (const double& val){
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] = val;
    return *this;
}

// numerical operations, by arrays which are apllied pointwise
MJArray& MJArray::operator += (const MJArray& operand){
    #ifdef RANGE_CHECKING
        if (Size != operand.size()) throw("to apply += two arrays must be of same size");
    #endif
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] += operand[i];
    return *this;
}

MJArray& MJArray::operator -= (const MJArray& operand){
    #ifdef RANGE_CHECKING
        if (Size != operand.size()) throw("to apply -= two arrays must be of same size");
    #endif
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] -= operand[i];
    return *this;
}

MJArray& MJArray::operator /= (const MJArray& operand){
    #ifdef RANGE_CHECKING
        if (Size != operand.size()) throw("to apply /= two arrays must be of same size");
    #endif
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] /= operand[i];
    return *this;
}
MJArray& MJArray::operator *= (const MJArray& operand){
    #ifdef RANGE_CHECKING
        if (Size != operand.size()) throw("to apply *= two arrays must be of same size");
    #endif
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] *= operand[i];
    return *this;
}
// numerical operations, by doubles
MJArray& MJArray::operator += (const double& operand){
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] += operand;
    return *this;
}

MJArray& MJArray::operator -= (const double& operand){
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] -= operand;
    return *this;
}

MJArray& MJArray::operator /= (const double& operand){
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] /= operand;
    return *this;
}

MJArray& MJArray::operator *= (const double& operand){
    for (unsigned long i = 0; i < Size; i++) ValuesPtr[i] *= operand;
    return *this;
}

// take in a function object f and apply it to each element of the array
// outputs a new array consisting of the results
MJArray MJArray::apply(double f(double)) const{
    MJArray result(size());
    std::transform(ValuesPtr, EndPtr, result.ValuesPtr, f);
    return result;
}

// resize the array
void MJArray::resize(unsigned long newSize){
    if(newSize > Capacity){
         if(Capacity > 0) delete [] ValuesPtr;
         ValuesPtr = new double[newSize];
         Capacity = newSize;
    }
    Size = newSize;
    EndPtr = ValuesPtr + Size;
}
// sum operators
double MJArray::sum() const{
    return std::accumulate(ValuesPtr, EndPtr, 0.0);
}
 
double MJArray::min() const{
    #ifdef RANGE_CHECKING
        if (Size == 0) throw("cannot take min of empty array");
    #endif RANGE_CHECKING
        double* tmp = ValuesPtr;
        double* endTmp = EndPtr;
    return *std::min_element(tmp, endTmp);
}

double MJArray::max() const{
    #ifdef RANGE_CHECKING
        if (Size == 0) throw("cannot take min of empty array");
    #endif RANGE_CHECKING
        double* tmp = ValuesPtr;
        double* endTmp = EndPtr;
    return *std::max_element(tmp, endTmp);
}

