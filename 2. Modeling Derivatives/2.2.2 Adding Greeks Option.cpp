/* C++ For Quantitative Finance                                 */
/* Adding calculations of the Greeks to the Option class        */
/* Author: Shaofei Li                                           */

 #include <iostream>
 using namespace std;

 typedef double dbl;

 class Option
 {
 private:
 dbl S; /* price of stock or underlying security*/
 dbl K; /* strike price */
 dbl r; /* interest rate */
 dbl q; /* dividend yield */
 dbl T; /* remaining life */
 dbl sig; /* volatility */
 dbl d1, d2;

 double NP(double x);
 double N(double x);
 void calcD12();

 public:
 Option();
 Option(dbl S1, dbl K1, dbl r1, dbl q1, dbl T1, dbl sig1);
 ∼Option(){}

 double euroCallPrc();
 double euroPutPrc();
 double euroCallDelta();
 double euroPutDelta();
 double euroCallTheta();
 double euroPutTheta();
 double euroCallGamma();
 double euroPutGamma();
 double euroCallVega();
 double euroPutVega();
 double euroCallRho();
 double euroPutRho();

 };


 double Option:: euroCallPrc()
 {
 return S*exp(-q*T)*N(d1) - K*exp(-r*T)*N(d2) ;
 }


 double Option:: euroPutPrc()
 {
 return K*exp(-r*T)*N(-d2) - S*exp(-q*T)*N(-d1) ;
 }


 double Option:: euroCallDelta()
 {
 return exp(-q*T)*N(d1);
 }


 double Option:: euroPutDelta()
 {
 return exp(-q*T)*(N(d1)-1);
 }


 double Option::euroCallTheta()
 {
 return -(S*NP(d1)*sig*exp(-q*T))/(2*sqrt(T))
 + (q*S*N(d1)*exp(-q*T)) - (r*K*exp(-r*T)*N(d2));
 }


 double Option::euroPutTheta()
 {
 return -(S*NP(d1)*sig*exp(-q*T))/(2*sqrt(T))
 - (q*S*N(-d1)*exp(-q*T)) + (r*K*exp(-r*T)*N(-d2));
 }


 double Option::euroCallGamma()
 {
 return (NP(d1)*exp(-q*T))/(S*sig*sqrt(T));
 }


 double Option:: euroPutGamma()
 {
 return euroCallGamma();
 }


 double Option::euroCallVega()
 {
     return S*sqrt(T)*NP(d1)*exp(-q*T);
 }


 double Option::euroPutVega()
 {
 return euroCallVega();
 }


 double Option::euroCallRho()
 {
 return K*T*exp(-r*T)*N(d2);
 }


 double Option::euroPutRho()
 {
 return -K*T*exp(-r*T)*N(-d2);
 }

 Option::Option()
 {
 double temp;

 S = 50.; /* price of stock or underlying security*/
 K = 45.; /* strike price*/
 r = 0.04; /* interest rate*/
 q = 0.01; /* dividend yield*/
 T = 0.50; /* remaining life*/
 sig = 0.40; /* volatility*/

 cout << "Provide option parameters. Enter 0 to keep default ";
 cout << "values" << endl;

 cout << "Stock price, default is " << S << ": ";
 cin >> temp;
 if(temp != 0.) S = temp;

 cout << "Strike price, default is " << K << ": ";
 cin >> temp;
 if(temp != 0.) K = temp;

 cout << "Risk free interest rate, default is " << r << ": ";
 cin >> temp;
 if(temp != 0.) r = temp;

 cout << "Dividend yield, default is " << q << ": ";
 cin >> temp;
 if(temp != 0.) q = temp;

 cout << "Remaining life, default is " << T << ": ";
 cin >> temp;
 if(temp != 0.) T = temp;

 cout << "Volatility, default is " << sig << ": ";
 cin >> temp;
 if(temp != 0.) sig = temp;
 cout << endl;

 calcD12();

 return;
 }

 Option::Option(dbl S1, dbl K1, dbl r1, dbl q1, dbl T1, dbl sig1)
 {
 S = S1; /* price of stock or underlying security*/
 K = K1; /* strike price*/
 r = r1; /* interest rate*/
 q = q1; /* dividend yield*/
 T = T1; /* remaining life*/
 sig = sig1; /* volatility*/

 calcD12();
 }


 void Option::calcD12()
 {
 d1 = (log(S/K) + (r-q +(sig*sig)*0.5) * T)
 / (sig * sqrt(T));
 d2 = d1 - sig*sqrt(T);
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
 return (1 - NP(x)*((a1*k) + (a2*k*k) + (a3*k*k*k)
 + (a4*k*k*k*k) + (a5*k*k*k*k*k)));
 }
 else
 {
 return (1-N(-x));
 }
 }



 int main()
 {
 Option ob2(50., 50., 0.04, 0.01, 0.5, 0.40);
 cout << "Call price: " << ob2.euroCallPrc() << endl;
 cout << "Put price: " << ob2.euroPutPrc() << " \n\n";

 cout << "Call delta: " << ob2.euroCallDelta() << endl;
 cout << "Put delta: " << ob2.euroPutDelta() << endl << endl;

 cout << "Call theta: " << ob2.euroCallTheta() << endl;
 cout << "Put theta: " << ob2.euroPutTheta() << endl << endl;

 cout << "Call gamma: " << ob2.euroCallGamma() << endl << endl;
 cout << "Put gamma: " << ob2.euroPutGamma() << endl << endl;

 cout << "Call vega: " << ob2.euroCallVega() << endl;
 cout << " Put vega: " << ob2.euroPutVega() << endl << endl;

 cout << "Call rho: " << ob2.euroCallRho() << endl;
 cout << "Put rho: " << ob2.euroPutRho() << endl << endl;


 cout << endl;
 /* Wait for the user to read the output on the console*/
 system("PAUSE");
 return 0;
 }
