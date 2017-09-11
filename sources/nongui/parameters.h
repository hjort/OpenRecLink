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
// Nome:        parameters.h
// Propósito:   Cálculo dos parâmetros de linkagem
// Author:      Washington Junger
// Modified by:
// Criado:      08/05/2007
// Copyright:   (c) Washington Junger
// Licença:     ?
/////////////////////////////////////////////////////////////////////////////

#ifndef parametersH
#define parametersH

#include "matrix.h"
   
#ifdef __cplusplus
extern "C"
{
  
#endif	/*  */
  
#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else	/*  */
#define DLL_EXPORT
#endif	/*  */
  
// function to be imported/exported
  
/* parameter estimation */ 
  DLL_EXPORT void estimatepars(double *m, double *u, double *p, unsigned int *size_file_a,
			       unsigned int *size_file_b, unsigned int *maxit, double *eps,
			       double *loglik, std::string ctrlfile, std::string datafile,
			       int *errcode);
   
/* u_i estimate */ 
   
    DLL_EXPORT void estimateu(double *u, unsigned int *freq, unsigned int *card_u,
			      std::string ctrlfile, std::string datafile, int *errcode);
   
/* thresholds computation (using observed patterns)*/ 
   
    DLL_EXPORT void computethresh(double *m, double *u, double *alpha, double *beta,
				  double *lowthresh, double *highthresh, double *score,
				  std::string ctrlfile, std::string datafile, int *errcode);
   
/* resturn a vector with agreement pattern */ 
    DLL_EXPORT matrix_uint * getpattern(unsigned int rows, unsigned int cols, matrix_short * gamma);
   
/* read data file */ 
   
    DLL_EXPORT matrix_short * readdata(std::string & ctrl_file, std::string & data_file,
				       unsigned int *rows, unsigned int *cols, unsigned int *size_a,
				       unsigned int *size_b, int *errcode);
   
/* wrapper for pow */ 
    DLL_EXPORT double pow_int(double base, int exp);
   
#ifdef __cplusplus
} 
#endif	/*  */
 
#endif				//parametersH
 
/* estimation using EM algorithm */ 
void emparest(unsigned int pairs, unsigned int fields, unsigned int *maxit, double *eps,
	      matrix_short * gamma, double *m, double *u, double *p, double *loglik, int *errcode);
 
/* sort vector */ 
void tagsort(unsigned int *tag, double *data, unsigned int size);
 
/* swap function */ 
void swap(unsigned int &x, unsigned int &y);

