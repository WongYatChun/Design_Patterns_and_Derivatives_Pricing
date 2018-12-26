#ifndef TREE_PRODUCTS_H
#define TREE_PRODUCTS_H

class TreeProduct{
    public:
        TreeProduct(double FinalTime_);
        // vitual copying
        virtual TreeProduct* clone() const = 0;
        // ensure the absence of memory leaks after virtual copying
        virtual ~TreeProduct(){}
        
        virtual double FinalPayOff(double Spot) const = 0;
        virtual double PreFinalValue(double Spot,
                                     double Time,
                                     double DiscountedFutureValue) const = 0;
        double GetFinalTime() const;
    
    private:
        double FinalTime; // implicitly disallow perpetual options
};
#endif