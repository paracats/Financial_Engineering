
/* C++ For Quantitative Finance                                   */
/* Computing four correlated deviates for Monte Carlo simulation  */
/* Author: David Li                                               */

class MatrixUtil
{
  public:
  double* genCorrelatedDeviates(const SymmetricMatrix& R, double dt, double z[])
  {
    int i, j;
    double sum[4] = {0.0};
    double deviate = 0.0; // standard normal deviate
    int m = R.Nrows(); // number of rows in correlation matrix

    std::vector<double> dz; // vector of correlated deviates
    std::vector<double> eigenValue; // vector of eigenvalues
    std::vector<double> eigenVector[4]; // array of vector of eigenvectors

    std::vector<double>::iterator eigenVecIter; // vector iterator
    double lambda[4] = {0.0}; // stores eigenvalues of correlation matrix R

    double dw[4] = {0.0}; // stores correlated deviates
    DiagonalMatrix D(m); // diagonal matrix
    Matrix V(m,m); // m x n matrix
    D = genEigenValues(R); // get eigenvalues
    V = genEigenVectors(R); // get eigenvectors store eigenvalues

    for (i = 0; i < m; i++)
    {
      eigenValue.push_back(D.element(i,i));
      lambda[i] = D.element(i,i);
    }

    for (i = 0; i < m; i++)
    {
      for (j = 0; j < m; j++)
      {
        eigenVector[i].push_back(V.element(i,j));
      }
    }
    srand(0); // initialize random number generator
    long seed = (long) rand() % 100; // generate seed
    long *idum = &seed;

    for (i = 0; i < m; i++)
    { 
      deviate = util.NormalDeviate(idum);
      dw[i] = deviate*sqrt(dt);
    }

    for (i = 0; i < m; i++)
    {
      eigenVecIter = eigenVector[i].begin();
      for (j = 0; j < m; j++)
      {
        sum[i] += (*eigenVecIter)*sqrt(lambda[j])*dw[j];
        eigenVecIter++;
      }
      z[i] = sum[i];
    }
    return z;
  }
};
