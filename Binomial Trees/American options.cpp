/* C++ For Quantitative Finance                                 */
/* American options                                             */
/* Author: David Li                                             */

 #include <iostream>
 #include <string>
 #include <cmath>
 using namespace std;

 double termVal(char iType, double strkPr, double termPr);
 void printTree(double tree[][10], int numSteps, double timeStep);

int main(int argc, char **argv)
{
if (argc != 6) 
{
cout << "S K r T sig" << endl;
return 1;
}
double S = atof(argv[1]);   /* price of stock or underlying security */
double K = atof(argv[1]);   /* strike price                          */
double r = atof(argv[1]);   /* interest rate                         */
double T = atof(argv[1]);   /* remaining life                        */
double sig = atof(argv[1]); /* volatility                            */

 const int maxSize = 10;
 double stk[maxSize][maxSize];
 double amer[maxSize][maxSize], euro[maxSize][maxSize];

 char optType;
 string optName;
 int i, j, n;
 double dt, u, d, p, emrdt, exVal;

 n = 5;                      /* number of steps; must be < maxSize*/
 optType = 'c';              /* c for call p for put              */
 optName = "call";
 if(optType == 'p') optName = "put";

 dt = T / n;                    /* step size in years      */
 u = exp(sig * sqrt(dt));       /* up movement multiplier  */
 d = 1/u;                       /* down movement multiplier*/
 emrdt = exp(-r * dt);          /* discount factor per step*/

 /* p is risk neutral probability of up movement*/
 p = (exp(r * dt) - d) / (u - d);

 stk[0][0] = S;                  /* initial stock price at time 0 */

/* generate stock price tree* /
 for(j = 1; j <= n; j++) /* counts steps*/
 {
 for(i = 0; i <= j; i++)
 {
 if (i == 0) {stk[i][j] = stk[i][j-1] * u;}
 else {stk[i][j] = stk[i-1][j-1] * d;}
 }
 }

 /* generate option value tree */
 for(j = n; j >= 0; j--)          /* counts steps backward         */
 {
 for(i = 0; i <= j; i++)
 {
 if (j == n)
 {
 amer[i][j] = termVal(optType, K, stk[i][j]);
 euro[i][j] = termVal(optType, K, stk[i][j]);
 }
 else
 {
 euro[i][j] = (p * euro[i][j+1] + (1 -p)
 * euro [i+1][j+1]) * emrdt;
 amer[i][j] = (p * amer[i][j+1] + (1 -p)
 * amer [i+1][j+1]) * emrdt;
 exVal = termVal(optType, K, stk[i][j]);
 if (exVal > amer[i][j]) amer[i][j] = exVal;
 }
 }
 }

 cout << "Value of the American " << optName << " option: ";
 cout << amer[0][0];
 cout << endl;

 cout << endl << " Stock price tree" << endl << endl;
 printTree(stk, n, dt);
 cout << endl;

 cout << endl << " American " << optName << " value tree";
 cout << endl << endl;
 printTree(amer, n, dt);
 cout << endl;

 cout << endl << " European " << optName << " value tree";
 cout << endl << endl;
 printTree(euro, n, dt);

 cout << endl;

 system("PAUSE");
 return 0;
 }

 double termVal(char iType, double strkPr, double termPr)
 {
 /*
 functions parameters:
 iType: position type, c, p, or u (underlying)
 strkPr: strike price of option or purchase price of u
 termPr: terminal price of u
 */

 double posVal = 0.;

 switch (iType)
 {
 case 'u':
 posVal = termPr - strkPr;
 break;

 case 'c':
 if(termPr > strkPr) posVal = termPr - strkPr;
 break;

 case 'p':
 if(termPr < strkPr) posVal = strkPr - termPr;
 break;
 }

 return posVal;
 }

void printTree(double tree[][10], int numSteps, double timeStep)
{
 int i, j, k;

 cout << " Step";
 cout.setf (ios::fixed);

 for(j = 0; j <= numSteps; j++)
 {
  cout.width(10);
 cout << j;
 }

 cout << endl;
 cout << " Time";
 cout.precision (2);
 cout.setf (ios::fixed);
 cout.setf(ios::showpoint);

 for(j = 0; j <= numSteps; j++)
{
 cout.width(10);
 cout << j * timeStep;
 }

 cout << endl;

 for(i = 0; i <= numSteps; i++)
 {
 cout << endl;
 for (k = 1; k <= i+1; k++) {cout << " ";}

 for(j = i; j <= numSteps; j++)
 {
 cout.width(10);
 cout << tree[i][j];
 }
 }

 return;
 }
