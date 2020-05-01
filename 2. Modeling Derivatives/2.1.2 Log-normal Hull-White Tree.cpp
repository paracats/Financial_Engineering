/* C++ For Quantitative Finance                                                  */
/* Constructing a lognormal Hull-White tree calibrated to the yield curve        */
/* Author: Shaofei Li                                                            */

void HullWhite::buildHW(vector<double> zero, double a, double volatility, int N,
  double T)
{
  int i, j, k;
  int jmax; // max upward branch
  int jmin; // min downward branch
  double pu[20] = {0.0}; // up probabilities
  double pm[20] = {0.0}; // middle probabilities
  double pd[20] = {0.0}; // down probabilities
  double sum = 0.0; // sum of shifted discount Arrow-Debreu securities
  double sum1 = 0.0; // sums of discount Arrow-Debreu securities
  double sum2[20] = {0.0}; // sum of weighted discount Arrow-Debreu securities
  double alpha[20] = {0.0}; // the value of r(i*dt) – r*(i*dt)
  double alpha1[20][20]; // alpha value at node i, j
  double B[20] = {0.0}; // discount bond price at time step i
  double dt = T/N; // time step size
  double dr = volatility*sqrt(3*dt); // state step size

  jmax = (int) ceil(0.1835/(a*dt));
  jmin = -jmax;
  B[0] = 1; // par value of discount bond at time 0

  // calculate bond prices based on initial term structure
  for (i = 0; i <= N; i++)
  {
    for (j = i; j >= -i; j--)
    {
      // normal branching a
      if ((j != jmax) && (j != jmin))
      { 
	pu[j] = 0.167 + 0.5*(a*a*j*j*dt*dt – a*j*dt);
	pm[j] = 0.666 – a*a*j*j*dt*dt;
	pd[j] = 0.167 + 0.5*(a*a*j*j*dt*dt + a*j*dt);
      }
      else if (j == jmin)
      {
        // up branching if a == 0
	pu[j] = 0.167 + 0.5*(a*a*j*j*dt*dt + a*j*dt);
	pm[j] = -0.333 – a*a*j*j*dt*dt – 2*a*j*dt;
	pd[j] = 1.167 + 0.5*(a*a*j*j*dt*dt + 3*a*j*dt);
      } 
      else
      {
	pu[j] = 1.167 + 0.5*(a*a*j*j*dt*dt – 3*a*j*dt);
	pm[j] = -0.333 – a*a*j*j*dt*dt + 2*a*j*dt;
	pd[j] = 0.167 + 0.5*(a*a*j*j*dt*dt – a*j*dt);
      } 
   }  
}     

// generate short rate tree
for (i = 0; i <= N; i++)
{  
  for (j = i; j >= -i; j--)
  {
    r[i][j] = j*dr;
  }
}

// initialize values at node 0, 0
alpha[0] = zero[0];
r[0][0] = alpha[0];
Q[0][0] = 1.0;

// compute discount bond prices
for (i = 0; i <= N+1; i++)
{ 
  B[i+1] = exp(-zero[i]*(i+1)*dt);
}

for (jmax = 0; jmax <= N+1; jmax++)
{
  // reinitialize values for next iteration
  sum = 0;
  sum1 = 0;

  for (j = jmax+1; j >= -(jmax+1); j--)
  {
    sum2[j] = 0;
  }
  for (j=jmax; j >= -jmax; j--)
  {
    sum1 += (Q[jmax][j]*exp(-j*dr*dt));
  }
  alpha[jmax] = (1/dt)*(log(sum1/B[jmax+1]));

for (j = jmax; j >= -jmax; j--)
{
  sum += Q[jmax][j]*exp(-(alpha[jmax] + j*dr)*dt);
}
P[jmax] = sum; // assign bond price equal to sum of shifted Arrow-Debreu price

// determine Q[i][j] for i = m+1
if (jmax == 0)
{
  Q[1][1] = 0.167*exp(-(alpha[jmax] + dr));
  Q[1][0] = 0.666*exp(-alpha[jmax]);
  Q[1][-1] = 0.167*exp(-(alpha[jmax] – dr));
}
else // if (jmax > 1)
{
  for (k = jmax; k >= -jmax; k--)
  {
    for (j = k+1; j >= k-1; j--)
    { 
      if (j == jmax + 1)
      {
        Q[jmax+1][jmax+1] = Q[jmax][jmax]*pu[jmax]*(-(alpha[jmax] + jmax*dr)*dt);
      }
      if (j == -(jmax + 1))
      {
        Q[jmax+1][-jmax-1] = Q[jmax][-jmax]*pd[-jmax]*(-(alpha[jmax] + (- jmax)*dr)*dt);
      }
if ((pu[k] > 0) && (j – k == 1))
      {
        sum2[j] += Q[jmax][k]*pu[k]*exp(-(alpha[jmax] + k*dr)*dt);
      }
      if ((pm[k] > 0) && (j – k == 0))
      {
        sum2[j] += Q[jmax][k]*pm[k]*exp(-(alpha[jmax] + k*dr)*dt);
      }
      if ((pd[k] > 0) && (j – k == -1))
      {
        sum2[j] += Q[jmax][k]*pd[k]*exp(-(alpha[jmax] + k*dr)*dt);
      }
      Q[jmax+1][j] = sum2[j];
     }   
    } 
   }
 }

r[0][0] = 0;
P[0] = 1;
for (i = 0; i <= N; i++)
{
  for (j = i; j >= -i; j--)
  {
    alpha1[i][j] = alpha[i];
    rate[i][j] = alpha1[i][j] + r[i][j];
    d[i][j] = exp(-rate[i][j]*dt);
  }
 }
}
