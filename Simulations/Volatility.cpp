/* C++ For Quantitative Finance                    */
/* Volatility Calculation                          */
/* Author: David Li                                */


#include <iostream>
#include <cmath>
using namespace std;

double mean(double inData[], int sampSize);
double stdDev(double inData[], int sampSize, char statType = 'p');

int main(int argc, char** argv)
{
const int maxSize = 50;
int numPnts;     /* number of days of stock price history */
int i;

/* array of historical daily stock prices, going backward */
double stkPrc[maxSize];
for (i = 1; i < argc && i <= maxSize; i++) 
{
    stkPrc[i-1] = atof(argv[i]);
}

/* array for continuously compounded daily returns       */
double dlyRet[maxSize];

numPnts = argc-1;

/* calculate continuously compounded daily returns       */
for(i = 0; i < numPnts-1; i++)
{
dlyRet[i] = log(stkPrc[i]/stkPrc[i+1]);
}

cout << "Annualized volatility is: ";
cout << stdDev(dlyRet, numPnts -1, 'p') * sqrt(250.) << endl;

return 0;
}



double mean(double inData[], int sampSize)
{
double sum = 0.;
int i;

for(i = 0; i <sampSize; i++) sum += inData[i];
return sum/sampSize;
}



double stdDev(double inData[], int sampSize, char statType)
/* statType is s for sample and p for population std dev  */
{
double sumSqr = 0., sampMean;
int i;

sampMean = mean(inData, sampSize);

for(i = 0; i < sampSize; i++)
{
sumSqr += (inData[i] - sampMean) * (inData[i] - sampMean);
}

if(statType == 's') return sqrt(sumSqr/sampSize);
if(statType == 'p') return sqrt(sumSqr/(sampSize - 1));

}
