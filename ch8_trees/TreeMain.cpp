/* 
Require source files:
    Arrays.cpp
    BinomialTree.cpp
    BlackScholesFormulas.cpp
    Normals.cpp
    Parameters.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffForward.cpp
    TreeAmerican.cpp
    TreeEuropean.cpp
    TreeProducts.cpp
 */


#include "BinomialTree.h"
#include "BlackScholesFormulas.h"
#include "PayOffForward.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long Steps;

    cout << "\nEnter expiry\n";
    cin >> Expiry;

    cout << "\nEnter Strike\n";
    cin >> Strike;

    cout << "\nEnter Spot\n";
    cin >> Spot;

    cout << "\nEnter vol\n";
    cin >> Vol;

    cout << "\nEnter r\n";
    cin >> r;

    cout << "\nEnter d\n";
    cin >> d;

    cout << "\nEnter Number Of Steps\n";
    cin >> Steps;

    PayOffCall thePayOff(Strike);

    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    
    TreeEuropean europeanOption(Expiry, thePayOff);
    TreeAmerican americanOption(Expiry, thePayOff);

    SimpleBinomialTree theTree(Spot, rParam, dParam, Vol, Steps, Expiry);

    double euroPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);

    cout << "euro price: " << euroPrice << " amer price: " << americanPrice << endl;

    double BSPrice = BlackScholesCall(Spot, Strike, r, d, Vol, Expiry);

    cout << "BS formula euro price: " << BSPrice << endl;

    PayOffForward forwardPayOff(Strike);
    TreeEuropean forward(Expiry, forwardPayOff);

    double forwardPrice = theTree.GetThePrice(forward);
    cout << "forward price by tree: " << forwardPrice << endl;

    double actualForwardPrice = exp(-r * Expiry) * (Spot * exp((r - d) * Expiry) - Strike);
    cout << "forward price: " << actualForwardPrice << endl;

    Steps++;
    SimpleBinomialTree theNewTree(Spot, rParam, dParam, Vol, Steps, Expiry);

    double euroNewPrice = theNewTree.GetThePrice(europeanOption);
    double americanNewPrice = theNewTree.GetThePrice(americanOption);

    cout << "euro new price: " << euroNewPrice << " amer new price: " << americanNewPrice << endl;

    double forwardNewPrice = theNewTree.GetThePrice(forward);
    cout << "forward price by new tree: " << forwardNewPrice << endl;

    double averageEuro = 0.5 * (euroPrice + euroNewPrice);
    double averageAmer = 0.5 * (americanPrice + americanNewPrice);
    double averageForward = 0.5 * (forwardPrice + forwardNewPrice);

    cout << "euro average price: " << averageEuro << endl;
    cout << "amer average price: " << averageAmer << endl;
    cout << "average forward price: " << averageForward << endl;

    return 0;
}