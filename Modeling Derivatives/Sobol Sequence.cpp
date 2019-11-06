
/* C++ For Quantitative Finance                                   */
/* Computing a Sobol Sequence                                     */
/* Author: David Li                                               */

#include <time.h>

#define GRAY(n) (n ^ ( n >> 1 )) // for Sobol sequence
#define MAXDIM 5
#define VMAX 30

struct sobolp
{
  double sequence[MAXDIM];
  int x[MAXDIM];
  int v[MAXDIM][VMAX];
  double RECIPD;
  int _dim; // dimension of the sample space
  int _skip;
  unsigned long _nextn;
  unsigned long cur_seed;
};
class StatUtility
{
public:
  inline void sobolp_generateSamples(struct sobolp* config, double* samples)
  {
    int i;
    nextSobol(config, config->cur_seed);
    config->cur_seed++;
    for(i = 0; i < config->_dim; i++ )
      samples[i] = config->sequence[i];
  }

  inline static void nextSobolNoSeed(struct sobolp* config)
  {
    int c = 1;
    int i;
    int save = config->_nextn;
    while((save %2) == 1)
    {
      c += 1;
      save = save /2;
    }
    for(i=0;i<config->_dim;i++)
    {
      config->x[i] = config->x[i]^(config->v[i][c-1]<< (VMAX-c));
      config->sequence[i] = config->x[i]*config->RECIPD;
    }
    config->_nextn += 1;
  }

  inline void sobolp_init(struct sobolp* config, int dim, unsigned long seed)
  {
    int d[MAXDIM], POLY[MAXDIM];
    int save;
    int m,i,j,k;

    config->_dim = dim;
    config->_nextn = 0;
    config->RECIPD = 1.0 / pow( 2.0, VMAX );
    config->cur_seed = seed;

    POLY[0] = 3; d[0] = 1; // x + 1
    POLY[1] = 7; d[1] = 2; // x^2 + x + 1
    POLY[2] = 11; d[2] = 3; // x^3 + x + 1
    POLY[3] = 19; d[3] = 4; // x^4 + x + 1
    POLY[4] = 37; d[4] = 5; // x^5 + x^2 + 1

    for(i = 0; i < config->_dim; i++ )
      for(j = 0; j < d[i]; j++ )
        config->v[i][j] = 1;

    for( i = 0; i < config->_dim; i++ )
    {
      for( j = d[i]; j < VMAX; j++ )
      {
        config->v[i][j] = config->v[i][j-d[i]];
        save = POLY[i];
        m = pow( 2, d[i] );
        for( k = d[i]; k > 0; k-- )
        {
          config->v[i][j] = config->v[i][j] ^ m*(save%2)*config->v[i][j-k];
          save = save/2;
          m = m/2;
        }
      }
    }
    for( i = 0; i < config->_dim; i++ )
      config->x[i]=0;
    config->_skip = pow( 2, 6 );
    for( i = 1; i <= config->_skip; i++ )
      nextSobolNoSeed(config);
    }
};
