/* C++ For Quantitative Finance                                 */
/* European options based on the BSM equations                  */
/* Author: David Li                                             */

 #include <iostream>
 #include <cmath>
 using namespace std;

 typedef double dbl;

 class Option
 {
 private:
 double S;                    /* price of stock or underlying security  */
 double K;                    /* strike price                           */
 double r;                    /* interest rate                          */
 double q;                    /* dividend yield                         */
 double T;                    /* remaining life                         */
 double sig;                  /* volatility                             */
 double d1, d2;

 double NP(double x);
 double N(double x);
 void calcD12();

 public:
 Option();
 Option(dbl S1, dbl K1, dbl r1, dbl q1, dbl T1, dbl sig1);
 ~Option(){}
 double euroCallPrc();
 double euroPutPrc();

 };

Option::Option()
 {
 double temp;

/* Sampl Testing / Testing Result: Call price: 8.5657   Put price: 2.92402 */ 
 S = 50.;       /* price of stock or underlying security                   */
 K = 45.;       /* strike price                                            */
 r = 0.04;      /* interest rate                                           */
 q = 0.01;      /* dividend yield                                          */
 T = 0.50;      /* remaining life                                          */
 sig = 0.40;    /* volatility                                              */

 cout << "Provide option parameters. Enter 0 to keep default ";
 cout << "values" << endl;

 cout << "Stock price: ";
 cin >> temp;
 if(temp != 0.) S = temp;

 cout << "Strike price: ";
 cin >> temp;
 if(temp != 0.) K = temp;

 cout << "Risk free interest rate: ";
 cin >> temp;
 if(temp != 0.) r = temp;

 cout << "Dividend yield: ";
 cin >> temp;
 if(temp != 0.) q = temp;

 cout << "Remaining life: ";
 cin >> temp;
 if(temp != 0.) T = temp;

 cout << "Volatility: ";
 cin >> temp;
 if(temp != 0.) sig = temp;
 cout << endl;

 calcD12();

 return;
 }

 Option::Option(dbl S1, dbl K1, dbl r1, dbl q1, dbl T1, dbl sig1)
 {
    
 S = S1;                        /* price of stock or underlying security */
 K = K1;                        /* strike price                          */
 r = r1;                        /* interest rate                         */
 q = q1;                        /* dividend yield                        */
 T = T1;                        /* remaining life                        */
 sig = sig1;                    /* volatility                            */

 calcD12();
 }

 void Option::calcD12()
 {
 d1 = (log(S/K) + (r-q +(sig*sig)*0.5) * T) / (sig * sqrt(T));
 d2 = d1 - sig*sqrt(T);
 }

 double Option:: euroCallPrc()
 {
 return S*exp(-q*T)*N(d1) - K*exp(-r*T)*N(d2) ;
 }

 double Option:: euroPutPrc()
 {
 return K*exp(-r*T)*N(-d2) - S*exp(-q*T)*N(-d1) ;
 }

 double Option::NP(double x)
 {
 return (1.0/sqrt(2.0 * 3.1415)* exp(-x*x*0.5));
 }


 double Option::N(double x)
 {
 double a1 = 0.319381530;
 double a2 = -0.356563782;
 double a3 = 1.781477937;
 double a4 = -1.821255978;
 double a5 = 1.330274429;
 double k;

 k = 1/(1+0.2316419*x);

 if (x >= 0.0)

{
 return (1 - NP(x)*((a1*k) + (a2*k*k) + (a3*k*k*k) + (a4*k*k*k*k) + (a5*k*k*k*k*k)));
 }
 else
 {
 return (1-N(-x));
 }
 }

 int main()
 {

 Option ob1;
 cout << "Call price: " << ob1.euroCallPrc() << endl;
 cout << "Put price: " << ob1.euroPutPrc() << endl;

 Option ob2(50., 45., 0.04, 0.01, 0.5, 0.40);
 cout << "Call price: " << ob2.euroCallPrc() << endl;
 cout << "Put price: " << ob2.euroPutPrc() << endl;

 cout << endl;
 
 return 0;
 }
