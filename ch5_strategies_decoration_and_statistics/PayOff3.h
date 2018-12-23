#ifndef PAYOFF3_H
#define PAYOFF3_H

class PayOff{
    public:
        PayOff(){};
        
        virtual double operator()(double Spot) const = 0;
        virtual ~PayOff(){}
        // Virtual Copy Constructor
        virtual PayOff* clone() const = 0;
    private:
};

class PayOffCall: public PayOff{
    public:
        PayOffCall(double Strike_);

        virtual double operator()(double Spot) const;
        virtual ~PayOffCall(){}
        // Virtual Copy Constructor
        virtual PayOff* clone() const;
    
    private:
        double Strike;
};

class PayOffPut: public PayOff{
    public:
        PayOffPut(double Strike_);

        virtual double operator()(double Spot) const;
        virtual ~PayOffPut(){}
        // Virtual Copy Constructor
        virtual PayOff* clone() const;
    
    private:
        double Strike;
};

#endif