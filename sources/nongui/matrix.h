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
// Nome:        matrix.h
// Propósito:   Rotinas de matrizes
// Author:      Washington Junger
// Modified by:
// Criado:      08/05/2007
// Copyright:   (c) Washington Junger
// Licença:     ?
/////////////////////////////////////////////////////////////////////////////

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
  
#include <stdlib.h>
#include <string>
  
/* defining some matrix structure to overcome GSL license issue */ 
typedef unsigned int size;
typedef unsigned int uint;

// short is ok
  struct matrix_short
{
  short *dat;
   size r, c;
 };
 struct matrix_uint
{
  uint * dat;
  size r, c;
};
 
#ifdef __cplusplus
extern "C"
{
  
#endif	/*  */
  
#ifdef BUILD_DLL
#define __declspec(dllexport)
#else	/*  */
#define DLL_EXPORT
#endif	/*  */
  
// function to be imported/exported
  
// short integer matrix
  matrix_short * matrix_short_alloc(const size r, const size c);
   matrix_short * matrix_short_calloc(const size r, const size c);
   void matrix_short_free(matrix_short * m);
   void matrix_short_set(matrix_short * m, size i, size j, short x);
   short matrix_short_get(matrix_short * m, size i, size j);
   
// unsigned integer matrix
    matrix_uint * matrix_uint_alloc(const size r, const size c);
   matrix_uint * matrix_uint_calloc(const size r, const size c);
   void matrix_uint_free(matrix_uint * m);
   void matrix_uint_set(matrix_uint * m, size i, size j, uint x);
   uint matrix_uint_get(matrix_uint * m, size i, size j);
   
#ifdef __cplusplus
} 
#endif	/*  */
 
#endif				// MATRIX_H_INCLUDED
