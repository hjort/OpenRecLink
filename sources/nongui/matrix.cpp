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


// short integer matrix
  matrix_short * matrix_short_alloc(const size r, const size c) 
{
  
  
  
    
  {
    
    
    
  
  
  else
    
  



{
  
  
  
  
    
  {
    
      // set elements to 0
      for (i = 0; i < r * c; i++)
      
  
  



matrix_short_free(matrix_short * m) 
{
  
  


matrix_short_set(matrix_short * m, size i, size j, short x) 
{
  


matrix_short_get(matrix_short * m, size i, size j) 
{
  
  
  



// unsigned integer matrix
  matrix_uint * matrix_uint_alloc(const size r, const size c) 
{
  
  
  
    
  {
    
    
    
  
  
  else
    
  



{
  
  
  
  
    
  {
    
      // set elements to 0
      for (i = 0; i < r * c; i++)
      
  
  



matrix_uint_free(matrix_uint * m) 
{
  
  


matrix_uint_set(matrix_uint * m, size i, size j, uint x) 
{
  

{
  
  
  


