/* 
an implementation of the of rational approximations for cummulative normal distribution function
for a standard normal random variable and its inverse
 */

#ifndef NORMALS_H
#define NORMALS_H

double NormalDensity(double x);

double CumulativeNormal(double x);

double InverseCumulativeNormal(double x);

#endif