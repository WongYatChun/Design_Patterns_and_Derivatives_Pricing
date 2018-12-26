#pragma warning (disable: 4786) // to prevent a warning message telling us that the debug info is too long under VC6

#include "Arrays.h"
#include "Parameters.h"
#include "TreeProducts.h"
#include <vector>

class SimpleBinomialTree{
    public:
        SimpleBinomialTree(double Spot_,
                            const Parameters& r_,
                            const Parameters& d_,
                            double Volatility_,
                            unsigned long Steps_,
                            double Time_);
        double GetThePrice(const TreeProduct& TheProduct);
    protected:
        void BuildTree();
    private:
        double Spot;
        Parameters r;
        Parameters d;
        double Volatility;
        unsigned long Steps;
        double Time;
        bool TreeBuilt;
        std::vector<std::vector<std::pair<double, double>>> TheTree;
        MJArray Discounts;
};
