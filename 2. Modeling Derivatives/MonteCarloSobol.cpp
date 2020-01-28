
/* C++ For Quantitative Finance                                   */
/* Monte Carlo Implementation using the Sobol sequence            */
/* Author: David Li                                               */

double MonteCarloMethod::MonteCarloSobol(double price, double strike, double vol,
  double rate, double div, double T, char type, long N, long M)
{
  int i, j;
  double sum1 = 0.0; // sum of payoffs
  double sum2 = 0.0; // sum of squared payoffs
  double value = 0.0; // stores value of option for each simulation
  double S1 = price; // stock price for +deviate
  double S2 = price; // stock price for -deviate
  double lnS1 = log(price); // log of the initial stock price for +deviate
  double lnS2 = log(price); // log of the initial stock price for -deviate
  double SD; // standard deviation
  double SE; // standard error
  long dim = N; // dimension of Sobol sequence
  double dt = T/N; // time step
  double mu = rate - div - 0.5*vol*vol; // drift
  double rands[5]; // stores random variables
  cout.precision(4); // output decimal format precision
  int cnt = 0; // counter
  struct sobolp sp; // Sobol sequence structure
  srand(time(0)); // initialize RNG
  long seed = (long) rand() % 100; // generate seed

  util.sobolp_init(&sp,dim,seed);
  for (i = 0; i < M; i++)
  {
    lnS1 = log(price);
    lnS2 = log(price);
    for (j = 0; j < N; j++)
    {
      util.sobolp_generateSamples(&sp,rands);
      lnS1 = lnS1 + mu*dt + vol*sqrt(dt)*rands[cnt];
      lnS2 = lnS2 = mu*dt + vol*sqrt(dt)*(-rands[cnt]);
      if ((cnt + 1) % N == 0)
        cnt = 0;
      else
        cnt++;
    }

    S1 = exp(lnS1);
    S2 = exp(lnS2);
    if (type == ‘C’)
      value = 0.5*(max(0, S1 - strike) + max(0, S2 - strike));
    else
      value = 0.5*(max(0, strike - S1) + max(0,strike - S2));
    sum1 = sum1 + value;
    sum2 = sum2 + value*value;
  }

SD = sqrt((exp(-2*rate*T)/(M-1))*(sum2 - (sum1*sum1)/M));
cout << “stddev ” << “ ” < SD < endl;

SE = SD/sqrt(M_);
cout << “stdderr ” << “ ” << SE << endl;

return exp(-rate*T)*sum1/M;
}
