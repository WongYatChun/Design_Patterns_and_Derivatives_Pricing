#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff{
    public:
        PayOff(){};
        virtual double operator()(double Spot) const = 0;
        virtual ~PayOff(){} //destructor, virtual
    private:

};

class PayOffCall: public PayOff{ //declaring the inherited class
    public:
        PayOffCall(double Strike_);
        virtual double operator()(double Spot) const;
        virtual ~PayOffCall(){} //destructor, virtual
    private:
        double Strike;
};

class PayOffPut: public PayOff{ //declaring the inherited class
    public:
        PayOffPut(double Strike_);
        virtual double operator()(double Spot) const;
        virtual ~PayOffPut(){} //destructor, virtual
    private:
        double  Strike;
};
#endif