/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/////////////////////////////////////////////////////////////////////////////
// Nome:        parameters.cpp
// Propósito:   Cálculo dos parâmetros de linkagem
// Author:      Washington Junger
// Modified by:
// Criado:      08/05/2007
// Copyright:   (c) Washington Junger
// Licença:     ?
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "parameters.h"

using namespace std;

/* parameter estimation */
void
estimatepars(double *m, double *u, double *p, unsigned int *size_file_a,
	     unsigned int *size_file_b, unsigned int *maxit, double *eps,
	     double *loglik, std::string ctrlfile, std::string datafile, int *errcode)
{
  int errorcode;		// local error code variable. it will be passed to the next functions
  unsigned int pairs, fields;	// now we refer to them using prl terms
  matrix_short *gamma;		//data matrix

  gamma = readdata(ctrlfile, datafile, &pairs, &fields, size_file_a, size_file_b, &errorcode);

  // m_i estimate
  emparest(pairs, fields, maxit, eps, gamma, m, u, p, loglik, &errorcode);

  /* cleaning memory */
  matrix_short_free(gamma);
}

/* u_i estimate */
void
estimateu(double *u, unsigned int *freq, unsigned int *card_u,
	  std::string ctrlfile, std::string datafile, int *errcode)
{
  unsigned int pairs, fields;
  double u_i;
  //double eps;
  unsigned int size_file_a;
  unsigned int size_file_b;
  //unsigned int maxit;
  unsigned int freq_field_i, i, j;
  matrix_short *gamma;		//data matrix
  int err;

  gamma = readdata(ctrlfile, datafile, &pairs, &fields, &size_file_a, &size_file_b, &err);

  *card_u = (size_file_a) * (size_file_b);	//-(*p)*min(*size_file_a,*size_file_b);

  for (i = 0; i < fields; i++)
  {
    freq_field_i = 0;
    for (j = 0; j < pairs; j++)
      freq_field_i += matrix_short_get(gamma, j, i);
    u_i = (double) (freq_field_i) / (*card_u);
    freq[i] = freq_field_i;
    u[i] = u_i;
  }

  matrix_short_free(gamma);
}

/* thresholds computation (using observed data insted of patterns. we can change this if it is too slow.)*/
void
computethresh(double *m, double *u, double *alpha, double *beta,
	      double *lowthresh, double *highthresh, double *score,
	      std::string ctrlfile, std::string datafile, int *errcode)
{
  int errorcode;		// local error code variable. it will be passed to the next functions
  unsigned int pairs, fields, npat;	// now we refer to them using prl terms
  double prob_m_temp, prob_u_temp;
  double sum_prob_m, sum_prob_u;
  double *prob_m;
  double *prob_u;
  double *cum_prob_m;
  double *cum_prob_u;
  unsigned int i, j;		// pairs/fields counters
  double s_temp;		// temporary for weights
  unsigned int size_file_a, size_file_b;
  unsigned int *scr_order;
  matrix_short *gamma;

  gamma = readdata(ctrlfile, datafile, &pairs, &fields, &size_file_a, &size_file_b, &errorcode);

  npat = (unsigned int) pow_int(2, fields);
  matrix_uint *pat;
  pat = getpattern(pairs, fields, gamma);

  // computing composite weights
  for (j = 0; j < npat; j++)
  {
    s_temp = 0;
    for (i = 0; i < fields; i++)
    {
      if (matrix_uint_get(pat, j, i + 1) == 1)
	s_temp += log2(m[i] / u[i]);
      else
	s_temp += log2((1 - m[i]) / (1 - u[i]));
    }
    score[j] = s_temp;
  }

  // sorting scores
  scr_order = new unsigned int[npat];
  tagsort(scr_order, score, npat);

  // creating room
  prob_m = new double[npat];
  prob_u = new double[npat];

  for (j = 0; j < npat; j++)
  {
    prob_m_temp = 1;
    prob_u_temp = 1;

    // multiplying over fields
    for (i = 0; i < fields; i++)
    {
      // under H0
      prob_m_temp *=
	pow_int(m[i],
		matrix_uint_get(pat, scr_order[j],
				i + 1)) * pow_int((1 - m[i]),
						  (1 - matrix_uint_get(pat, scr_order[j], i + 1)));
      // under H1
      prob_u_temp *=
	pow_int(u[i],
		matrix_uint_get(pat, scr_order[j],
				i + 1)) * pow_int((1 - u[i]),
						  (1 - matrix_uint_get(pat, scr_order[j], i + 1)));
    }

    // assigning probabilities to ordered arrays
    prob_m[j] = prob_m_temp;
    prob_u[j] = prob_u_temp;
  }

  // summing probabilities
  cum_prob_m = new double[npat];
  cum_prob_u = new double[npat];

  for (j = 0; j < npat; j++)
  {
    sum_prob_m = 0;
    sum_prob_u = 0;
    for (i = 0; i <= j; i++)
      sum_prob_m += prob_m[i];
    for (i = j; i < npat; i++)
      sum_prob_u += prob_u[i];

    cum_prob_m[j] = sum_prob_m;
    cum_prob_u[j] = sum_prob_u;
  }

  // scanning for probabilities
  for (j = 0; j < npat; j++)
  {
    //higher
    if (cum_prob_m[npat - j - 1] > *alpha)
      *highthresh = score[scr_order[npat - j - 1]];	//get ordered score. workaround needed

    //lower
    if (cum_prob_u[j] >= *beta)
      *lowthresh = score[scr_order[j]];	//get ordered score
  }

  /* cleaning memory */
  matrix_short_free(gamma);
  matrix_uint_free(pat);
  delete[]prob_m;
  delete[]prob_u;
  delete[]cum_prob_m;
  delete[]cum_prob_u;
}

/* estimation using EM algorithm */
void
emparest(unsigned int pairs, unsigned int fields, unsigned int *maxit,
	 double *eps, matrix_short * gamma, double *m, double *u, double *p,
	 double *loglik, int *errcode)
{
  /* EM parameters estimation using Jaro methodology */
  unsigned int j, i;		// pairs/fields counter
  double *g_m;
  double *g_u;
  double *prob_m;
  double *prob_u;
  unsigned int itcounter = 0;
  double converg = 1000000000000.0;
  double prod_m, prod_u, num_m = 0, den_m = 0, num_u = 0, den_u = 0;	// temporary variables
  double old_loglik;
  double phat;

  unsigned int npat = (unsigned int) pow_int(2, fields);
  matrix_uint *pat = getpattern(pairs, fields, gamma);

  prob_m = new double[pairs];
  prob_u = new double[pairs];
  g_m = new double[pairs];
  g_u = new double[pairs];
  phat = *p;
  *loglik = 0;

  while ((itcounter <= *maxit) & (converg >= *eps))
  {
    itcounter += 1;		// update iterations counter

    // E step
    // for (j=0;j<pairs;j++)
    for (j = 0; j < npat; j++)
    {
      prod_m = 1;
      prod_u = 1;

      // multiplying over fields
      for (i = 0; i < fields; i++)
      {
	// prod_m *= pow_int_(m[i],matrix_short_get(gamma,j,i))*pow_int((1-m[i]),(1-matrix_short_get(gamma,j,i)));
	// prod_u *= pow_int(u[i],matrix_short_get(gamma,j,i))*pow_int((1-u[i]),(1-matrix_short_get(gamma,j,i)));
	prod_m *=
	  pow_int(m[i], matrix_uint_get(pat, j, i + 1)) * pow_int((1 - m[i]),
								  (1 -
								   matrix_uint_get(pat, j, i + 1)));
	prod_u *=
	  pow_int(u[i], matrix_uint_get(pat, j, i + 1)) * pow_int((1 - u[i]),
								  (1 -
								   matrix_uint_get(pat, j, i + 1)));
      }

      // for pair j
      g_m[j] = (phat * prod_m) / (phat * prod_m + (1 - phat) * prod_u);
      g_u[j] = ((1 - phat) * prod_u) / (phat * prod_m + (1 - phat) * prod_u);

      // assigning probabilities to arrays
      prob_m[j] = prod_m;
      prob_u[j] = prod_u;
    }

    // M step
    for (i = 0; i < fields; i++)
    {
      num_m = 0;
      den_m = 0;
      num_u = 0;
      den_u = 0;
      /*
         // summing over pairs
         for (j=0;j<pairs;j++)
         {
         num_m += g_m[j]*matrix_short_get(gamma,j,i);
         den_m += g_m[j];
         num_u += g_u[j]*matrix_short_get(gamma,j,i);
         den_u += g_u[j];
         }
       */

      // summing over patterns
      for (j = 0; j < npat; j++)
      {
	num_m += g_m[j] * matrix_uint_get(pat, j, i + 1) * matrix_uint_get(pat, j, 0);
	den_m += g_m[j] * matrix_uint_get(pat, j, 0);
	num_u += g_u[j] * matrix_uint_get(pat, j, i + 1) * matrix_uint_get(pat, j, 0);
	den_u += g_u[j] * matrix_uint_get(pat, j, 0);
      }

      m[i] = num_m / den_m;	// updating m_i
      u[i] = num_u / den_u;	// updating u_i
    }

    phat = den_m / pairs;	// updating phat

    // evaluating log-likelihood
    old_loglik = *loglik;
    *loglik = 0;
    for (j = 0; j < npat; j++)
      *loglik += g_m[j] * (log(prob_m[j]) + log(phat)) + g_u[j] * (log(prob_u[j]) + log(1 - phat));
    // cout << *loglik << endl;
    converg = abs((*loglik - old_loglik) / old_loglik);
  }

  *maxit = itcounter;
  *eps = converg;
  *p = phat;
  errcode = 0;

  matrix_uint_free(pat);
  delete[]prob_m;
  delete[]prob_u;
  delete[]g_m;
  delete[]g_u;
}

/* resturn a vector with agreement pattern */
matrix_uint *
getpattern(unsigned int rows, unsigned int cols, matrix_short * gamma)
{
  unsigned int i, j;
  unsigned int npat = (unsigned int) pow_int(2, cols);
  unsigned int pat, pat_counter;
  matrix_uint *pattern = matrix_uint_calloc(npat, cols + 1);

  for (j = 0; j < rows; j++)
  {
    pat = 0;
    for (i = 0; i < cols; i++)
      pat += matrix_short_get(gamma, j, cols - i - 1) * (unsigned int) pow_int(2, i);
    pat_counter = matrix_uint_get(pattern, pat, 0);
    matrix_uint_set(pattern, pat, 0, pat_counter + 1);

    // fill up the pattern matrix if it is empty
    if (matrix_uint_get(pattern, pat, 0) == 1)
      for (i = 0; i < cols; i++)	// start in second column of pattern matrix
	matrix_uint_set(pattern, pat, i + 1, (unsigned) matrix_short_get(gamma, j, i));
  }
  return pattern;
}

/* read data file */
matrix_short *
readdata(std::string & ctrl_file, std::string & data_file, unsigned int *rows,
	 unsigned int *cols, unsigned int *size_a, unsigned int *size_b, int *errcode)
{
  ifstream ctrlfile, datafile;
  unsigned int j, i;		/* rows/cols counters */
  matrix_short *datamat;
  short int tempd;		/* temporary variable for data reading */

  /* set control file handle */
  ctrlfile.open(ctrl_file.c_str(), ios::in);
  if (!ctrlfile.is_open())
    *errcode = 101;

  /* set data file handle */
  datafile.open(data_file.c_str(), ios::in);
  if (!datafile.is_open())
    *errcode = 101;

  /* read matrix dimensions */
  ctrlfile >> *rows >> *cols;
  /* algorithm control */
  ctrlfile >> *size_a >> *size_b;	// >> *maxit >> *eps;

  datamat = matrix_short_alloc(*rows, *cols);
  if (datamat == 0)
    *errcode = 102;

  /* read data matrix */
  for (j = 0; j < *rows; j++)
    for (i = 0; i < *cols; i++)
    {
      datafile >> tempd;
      matrix_short_set(datamat, j, i, tempd);
    }

  ctrlfile.close();
  datafile.close();

  return datamat;
}

/* sort vector */
void
tagsort(unsigned int *tag, double *data, unsigned int size)
{
  unsigned int k, index, pass;

  for (k = 0; k < size; k++)
    tag[k] = k;

  for (pass = 0; pass < size - 1; pass++)
  {
    index = pass;
    for (k = pass + 1; k < size; k++)
      if (data[tag[k]] < data[tag[index]])
	index = k;
    if (index != pass)
      swap(tag[pass], tag[index]);
  }
}

/* swap function */
void
swap(unsigned int &x, unsigned int &y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}

/* wrapper for pow */
double
pow_int(double base, int exp)
{
  double p;
  p = pow((double) base, (double) exp);
  return p;
}
