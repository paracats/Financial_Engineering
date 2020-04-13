/* C++ For Quantitative Finance                                   */
/* Generating correlated deviates from a Cholesky decomposition   */
/* Author: Shaofei Li                                             */

#include “newmatap.h”
#include <vector>
#include <math.h>
#include “Constants.h”
#include “StatUtility.h”
class MatrixUtil
{
  public:
  double* genCorrelatedDeviatesCholesky(const SymmetricMatrix& R, double dt,
    double z[])
 {
    int m = R.Nrows(); // number of rows
    int n = R.Ncols(); // number of columns
    Matrix lb(m,n); // lower-banded (lb) matrix
    StatUtil util; // Statistical utility class
    double deviate = 0.0; // standard normal deviate
    double dw[4] = {0.0}; // stores deviate*sqrt(dt)
    double sum = 0.0;
    long seed = 0; // seed for RNG
    long* idum = 0; // stores address of seed
    int i, j;

    lb = Cholesky(R); // calls Cholesky routine in NEWMAT library

    srand(time(0)); // initialize RNG
    seed = (long) rand() % 100; // generate seed
    idum = &seed; // store address of seed

    for (i = 0; i < m; i++)
    {
      deviate = util.gasdev(idum); // generate normal (gaussian) deviate
      dw[i] = deviate*sqrt(dt);
    }

    for (i = 0; i < m; i++)
    {
      sum = 0;
      for (j = 0; j < m; j++)
      {
        sum += lb.element(i,j)*dw[j];
      }
      z[i] = sum; 
    }  
    return z;
 }
...
};
