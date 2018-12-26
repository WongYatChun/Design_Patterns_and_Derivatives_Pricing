#include "ParkMiller.h"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_) : Seed(Seed_){
    // check whether the seed == 0 because a zero seed yields a chain of zeros
    if(Seed_ == 0) Seed = 1;
}

void ParkMiller::SetSeed(long Seed_){
    Seed = Seed_;
    // check whether the seed == 0 because a zero seed yields a chain of zeros
    if(Seed == 0) Seed = 1;
}

long ParkMiller::GetOneRandomInteger(){
    long k;
    k = Seed / q;
    Seed = a * (Seed - k * q) - r * k;
    if (Seed < 0) Seed += m;
    return Seed;
}
        
// indicate the Max and Min values that the generator
unsigned long ParkMiller::Max(){
    return m - 1;
}
unsigned long ParkMiller::Min(){
    return 1;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimensionality, unsigned long Seed)
:RandomBase(Dimensionality), InnerGenerator(Seed), InitialSeed(Seed){
    // plus 1: ensure obtain random numbers on the open interval (0,1) rather than the closed 1,
    //  avoid troubles in the inverse cum. normal function
    Reciprocal = 1 / (1.0 + InnerGenerator.Max()); 
}

RandomBase* RandomParkMiller::clone() const{
    return new RandomParkMiller(*this);
}

void RandomParkMiller::GetUniforms(MJArray& variates){
    for (unsigned long j = 0; j < GetDimensionality(); j++)
        variates[j] = InnerGenerator.GetOneRandomInteger() * Reciprocal;
}

void RandomParkMiller::Skip(unsigned long numberOfPaths){
    MJArray tmp(GetDimensionality());
    for (unsigned long j = 0; j < numberOfPaths; j++)
        GetUniforms(tmp);
}

void RandomParkMiller::SetSeed(unsigned long Seed){
    InitialSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset(){
    InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality){
    RandomBase::ResetDimensionality(NewDimensionality);
    InnerGenerator.SetSeed(InitialSeed);
}
