/* C++ For Quantitative Finance                                      */
/* Constructing a BDT(Black–Derman–Toy) tree calibrated to the yield */
/* Author: Shaofei Li                                                */

void BlackDermanToy::buildBDT(vector<double> yield_curve, double vol, int N, double
  T, double inityield)
{
  double U[20] = {0.0}; // median of the (lognormal) distribution for r at time t
  double dt = 0.0; // time step
  double P[20] = {0.0}; // bond prices
  double R[20] = {0.0}; // discount factors
  const double epsilon = 0.001; // error tolerance in numerical search
  double error = 0.0; // error between model and target values
  double sum1 = 0.0; // sum of first derivatives
  double sum2 = 0.0; // sum of second derivatives
  double alpha1 = 0.05; // parameter to calibrate U(i)
  double alpha2 = 0.0; // updates alpha1 in numerical search
  int i,j;

  // precompute constants – assume 1 year time steps
  dt = 1;

  // initialize yield curve
  for (i = 1; i <= N; i++)
  {
    R[i] = yield_curve[i-1];
    P[i] = 1/(pow((1 + R[i]*dt),i*dt));
  }

  // initialize first node
  Q[0][0] = 1;
  P[0] = 1;
  U[0] = yield_curve[0];
  r[0][0] = yield_curve[0];
  d[0][0] = 1/(1 + r[0][0]*dt)

  // evolve the tree for the short rate
  for (i = 1; i <= N; i++)
  {
  // update pure security prices at time i
    Q[i][-i] = 0.5*Q[i-1][-i+1]*d[i-1][-i+1];
    Q[i][i] = 0.5*Q[i-1][i-1]*d[i-1][i-1];
    for (j = -i+2; j <= i-2; j += 2)
      {
    Q[i][j] = 0.5*Q[i-1][j-1]*d[i-1][j-1] + 0.5*Q[i-1][j+1]*d[i-1][j+1];
    }
    // use numerical search to solve for U[i]
    // Newton-Raphson method
    alpha1 = inityield;
    do
    {
      sum1 = 0;
      sum2 = 0;
      for (j = -i; j <= i; j += 2)
      {
        sum1 += Q[i][j]*(1/(1 + alpha1*exp(vol*j*sqrt(dt))*dt));
        sum2 += Q[i][j]*(pow((1+ alpha1*exp(vol*j*sqrt(dt))*dt),-
          2)*exp(vol*j*sqrt(dt))*dt);
      }
      alpha2 = alpha1 – (sum1 – P[i+1])/(-sum2);
      error = alpha2 – alpha1;
      alpha1 = alpha2;
    }
    while (error > epsilon);
    U[i] = alpha1;
    // set r[.] and d[.]
    for (j = -i; j <= i; j+= 2)
    {
      r[i][j] = U[i]*exp(vol*j*sqrt(dt));
      d[i][j] = 1/(1 + r[i][j]*dt);
    }
  }
}
