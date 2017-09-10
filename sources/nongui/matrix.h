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



// short is ok
  
{
  
   
 

{
  
  


#ifdef __cplusplus
extern "C"
{
  
#endif	/* 
  
#ifdef BUILD_DLL
#define __declspec(dllexport)
#else	/* 
#define DLL_EXPORT
#endif	/* 
  
// function to be imported/exported
  
// short integer matrix
  matrix_short * matrix_short_alloc(const size r, const size c);
   
   
   
   
   
// unsigned integer matrix
    matrix_uint * matrix_uint_alloc(const size r, const size c);
   
   
   
   
   
#ifdef __cplusplus
} 
#endif	/* 
 
#endif				// MATRIX_H_INCLUDED