/* C++ For Quantitative Finance                                 */
/* Greeks (Delta, Theta, Gamma, Vega, and Rho)                  */
/* Author: David Li                                             */


#include <iostream>
#include <cmath>
using namespace std;

double EuroCall(double S, double K, double r, double q, double T,
double sig);
double EuroPut(double S, double K, double r, double q, double T,
double sig);
double EuroCallDelta(double S, double K, double r, double q,
double T, double sig);
double EuroPutDelta(double S, double K, double r, double q,
double T, double sig);
double EuroCallTheta(double S, double K, double r, double q,
double T, double sig);
double EuroPutTheta(double S, double K, double r, double q,
double T, double sig);
double EuroGamma(double S, double K, double r, double q,
double T, double sig);
double EuroVega(double S, double K, double r, double q,
double T, double sig);
double EuroCallRho(double S, double K, double r, double q,
double T, double sig);
double EuroPutRho(double S, double K, double r, double q,
double T, double sig);

double NP(double x);
double N(double x);


int main(int argc, char **argv)
{
if (argc != 7) 
{
cout << "S K r q T sig" << endl;
return 1;
}
double S = atof(argv[1]);   /* price of stock or underlying security */
double K = atof(argv[1]);   /* strike price                          */
double r = atof(argv[1]);   /* interest rate                         */
double q = atof(argv[1]);   /* dividend yield                        */
double T = atof(argv[1]);   /* remaining life                        */
double sig = atof(argv[1]); /* volatility                            */

double callPrice, putPrice;

callPrice = EuroCall(S, K, r, q, T, sig);
putPrice = EuroPut(S, K, r, q, T, sig);

cout << "Call price: " << callPrice << endl;
cout << "Put price: " << putPrice << endl;

cout << "Call delta: "<<EuroCallDelta(S, K, r, q, T, sig) <<endl;
cout << "Put delta: "<<EuroPutDelta(S, K, r, q, T, sig) <<endl;

cout << "Call theta: "<<EuroCallTheta(S, K, r, q, T, sig) <<endl;
cout << "Put theta: "<<EuroPutTheta(S, K, r, q, T, sig) <<endl;

cout << "Gamma: "<<EuroGamma(S, K, r, q, T, sig) <<endl;
cout << "Vega: "<<EuroVega(S, K, r, q, T, sig) <<endl;


cout << "Call rho: "<<EuroCallRho(S, K, r, q, T, sig) <<endl;
cout << "Put rho: "<<EuroPutRho(S, K, r, q, T, sig) <<endl;
return K*exp(-r*T)*N(-d2) - S*exp(-q*T)*N(-d1) ;

}



double EuroCallDelta(
double S, /* price of stock or underlying security */
double K, /* strike price   */
double r, /* interest rate  */
double q, /* dividend yield */
double T, /* remaining life */
double sig /* volatility    */
)

{
double d1, d2;

d1 = (log(S/K) + (r-q +(sig*sig)*0.5 ) * T ) / (sig * sqrt(T));
d2 = d1 - sig*sqrt(T);

return exp(-q*T)*N(d1);
}


double EuroPutDelta(
double S,      /* price of stock or underlying security */
double K,      /* strike price */
double r,      /* interest rate */
double q,      /* dividend yield */
double T,      /* remaining life */
double sig     /* volatility */
)

{
double d1, d2;

d1 = (log(S/K) + (r-q +(sig*sig)*0.5 ) * T ) / (sig * sqrt(T));
d2 = d1 - sig*sqrt(T);

return exp(-q*T)*(N(d1)-1);
}
