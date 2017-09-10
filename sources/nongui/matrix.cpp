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
// Nome:        matrix.cpp
// Propósito:   Rotinas de matrizes
// Author:      Washington Junger
// Modified by:
// Criado:      08/05/2007
// Copyright:   (c) Washington Junger
// Licença:     ?
/////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "matrix.h"
 using namespace std;
 
// short integer matrix
  matrix_short * matrix_short_alloc(const size r, const size c) 
{
  matrix_short * m;
  m = (matrix_short *) malloc((r * c) * sizeof(matrix_short));
  if (m != 0)
    
  {
    m->dat = (short *) malloc((r * c) * sizeof(short));
    m->r = r;
    m->c = c;
  }
  
  else
    free(m);
   return m;
}

 matrix_short * matrix_short_calloc(const size r, const size c) 
{
  size i;
   matrix_short * m;
  m = matrix_short_alloc(r, c);
   if (m != 0)
    
  {
    
      // set elements to 0
      for (i = 0; i < r * c; i++)
      m->dat[i] = 0;
  }
  return m;
}

 void
matrix_short_free(matrix_short * m) 
{
  free(m->dat);
  free(m);
}   void

matrix_short_set(matrix_short * m, size i, size j, short x) 
{
  m->dat[i * m->c + j] = x;
}   short

matrix_short_get(matrix_short * m, size i, size j) 
{
  short x;
  x = m->dat[i * m->c + j];
  return x;
}

 
// unsigned integer matrix
  matrix_uint * matrix_uint_alloc(const size r, const size c) 
{
  matrix_uint * m;
  m = (matrix_uint *) malloc((r * c) * sizeof(matrix_uint));
  if (m != 0)
    
  {
    m->dat = (uint *) malloc((r * c) * sizeof(uint));
    m->r = r;
    m->c = c;
  }
  
  else
    free(m);
   return m;
}

 matrix_uint * matrix_uint_calloc(const size r, const size c) 
{
  size i;
   matrix_uint * m;
  m = matrix_uint_alloc(r, c);
   if (m != 0)
    
  {
    
      // set elements to 0
      for (i = 0; i < r * c; i++)
      m->dat[i] = 0;
  }
  return m;
}

 void
matrix_uint_free(matrix_uint * m) 
{
  free(m->dat);
  free(m);
}   void

matrix_uint_set(matrix_uint * m, size i, size j, uint x) 
{
  m->dat[i * m->c + j] = x;
}   uint matrix_uint_get(matrix_uint * m, size i, size j) 
{
  uint x;
  x = m->dat[i * m->c + j];
  return x;
}

   
