/* C++ For Quantitative Finance                                       */
/* Option Pricing                                                     */  
/* Author: David Li                                                   */


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

double EuroCall(double S, double K, double r, double q, double T,
	double sig);
double EuroPut(double S, double K, double r, double q, double T,
	double sig);

double NP(double x);
double N(double x);


void help() 
{
 cout << "S K r q T sig" << endl;
}

int main(int argc, char **argv)
{
if (argc != 7) 
{
  help();
  return 1;
}

double S = atof(argv[1]); /* price of stock or underlying security */
double K = atof(argv[2]); /* strike price                          */
double r = atof(argv[3]); /* interest rate                         */
double q = atof(argv[4]); /* dividend yield                        */
double T = atof(argv[5]); /* remaining life                        */
double sig = atof(argv[6]); /* volatility                          */

double callPrice, putPrice;

callPrice = EuroCall(S, K, r, q, T, sig);
putPrice = EuroPut(S, K, r, q, T, sig);

cout << "Call price: " << callPrice << endl;
cout << "Put price: " << putPrice << endl;

cout << "Put price from Put-Call Parity: " << callPrice + K * exp(-r * T) - S * exp(-q * T) << endl;

cout << endl;
return 0;
}

double EuroCall(
double S, /* price of stock or underlying security*/
double K, /* strike price                         */
double r, /* interest rate                        */
double q, /* dividend yield                       */
double T, /* remaining life                       */
double sig /* volatility                          */
)

{
double d1, d2;

d1 = (log(S / K) + (r - q + (sig*sig)*0.5) * T) / (sig * sqrt(T));
d2 = d1 - sig * sqrt(T);

return S * exp(-q * T)*N(d1) - K * exp(-r * T)*N(d2);
}

double EuroPut(
double S, /* price of stock or underlying security*/
double K, /* strike price                         */
double r, /* interest rate                        */
double q, /* dividend yield                       */
double T, /* remaining life                       */
double sig /* volatility                          */
)

{
double d1, d2;

d1 = (log(S / K) + (r - q + (sig*sig)*0.5) * T) / (sig * sqrt(T));
d2 = d1 - sig * sqrt(T);

return K * exp(-r * T)*N(-d2) - S * exp(-q * T)*N(-d1);
}

double NP(double x)
{
return (1.0 / sqrt(2.0 * 3.1415)* exp(-x * x*0.5));
}

double N(double x)
{
double a1 = 0.319381530;
double a2 = -0.356563782;
double a3 = 1.781477937;
double a4 = -1.821255978;
double a5 = 1.330274429;
double k;

k = 1 / (1 + 0.2316419*x);

if (x >= 0.0)
{
  return (1 - NP(x)*((a1*k) + (a2*k*k) + (a3*k*k*k) + (a4*k*k*k*k) + (a5*k*k*k*k*k)));
}
else
{
  return (1 - N(-x));
}
}
