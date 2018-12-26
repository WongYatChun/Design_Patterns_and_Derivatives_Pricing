/* 
our class called "MJArray to avoid the likelihood of name clashes" 

provide our own array class which is modelled on valarray<double> and provides a subset of of its operations

we can use a typedef to replace our class with valarray<double> when we are confident in our code
while retaining an easy-to-use class for debugging

Our class provides range-checking iff the macro RANGE_CHECKING is defined.
By changing one project setting, we can quickly shift between safe and fast modes
We also provide the facility to shift between valarray<double> and our class via defining the marcro USE_VAL_ARRAY

Once a class interface has been chosen, you are stuck with it.
*/

#ifndef MJARRAYS_H
#define MJARRAYS_H

#ifdef USE_VAL_ARRAY
#include <valarray>
typedef std::valarray<double> MJArray;
#else //ifdef USE_VAL_ARRAY

class MJArray{
    public:
        explicit MJArray(unsigned long size = 0); // constructor
        MJArray(const MJArray& original); // copy constructor

        ~MJArray(); // destructor

        //assignment operator
        MJArray& operator = (const MJArray& original);
        MJArray& operator = (const double& val);

        // numerical operations, by arrays which are apllied pointwise
        MJArray& operator += (const MJArray& operand);
        MJArray& operator -= (const MJArray& operand);
        MJArray& operator /= (const MJArray& operand);
        MJArray& operator *= (const MJArray& operand);
        // numerical operations, by doubles
        MJArray& operator += (const double& operand);
        MJArray& operator -= (const double& operand);
        MJArray& operator /= (const double& operand);
        MJArray& operator *= (const double& operand);

        // take in a function object f and apply it to each element of the array
        // outputs a new array consisting of the results
        MJArray apply(double f(double)) const;

        // overload operator[] both const and non-const version
        // inline: reproduce code inside the function instead of setting up a call to the function, prevent extra overhead
        inline double operator[] (unsigned long i) const; // read const array
        inline double & operator[] (unsigned long i); // modify elements of non-const arrays

        // take the size
        inline unsigned long size() const;
        // resize the array
        void resize(unsigned long newSize);
        // sum operators
        double sum() const;
        double min() const;
        double max() const;

    private:
        double* ValuesPtr; // ptr to the beginning of the array
        double* EndPtr; // ptr to the end of the array
        
        unsigned long Size; // number of elements currently in the array, Size = EndPtr - StartPtr
        unsigned long Capacity; // the amount of memory that has been allocated, Size <= Capacity
};

inline double MJArray::operator[] (unsigned long i) const{
    #ifdef RANGE_CHECKING
    if(i >= Size) throw("Index out of bounds");
    #endif
    return ValuesPtr[i];
}

inline double& MJArray::operator[](unsigned long i){
    #ifdef RANGE_CHECKING
    if(i >= Size) throw("Index out of bounds");
    #endif
    return ValuesPtr[i];
}

inline unsigned long MJArray::size() const{
    return Size;
}


#endif //ifdef USE_VAL_ARRAY
#endif //ifndef MJARRAYS_H