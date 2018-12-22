#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff{
    public:
        // distinguish between call and put
        enum OptionType {call, put};
        // constructor, take in the strike and the type of the option
        PayOff(double Strike_, OptionType TheOptionsType_);
        // main method, given a value of spot, return the value of the payoff
        // overload operator ()
        // const: the method does not modify the state of the object, computing the pay-off does not change the strike or the type of an option
        // adv of const: 1) safety enforcement mechanism; 2) make extra optimizations, run faster
        double operator()(double Spot) const; // make sure to add `const` every time before you declare it

    private:
        double Strike;
        OptionType TheOptionsType;
};

#endif