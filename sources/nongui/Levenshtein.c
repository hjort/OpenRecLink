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
// Nome:        Levenshtein.c
// Propósito:   Função de cálculo da distância de Levenshtein
// Author:      Adaptado de artigo originalmente publicado na revista c't em 1990, de autoria de dr. Michael König
// Modified by: Kenneth Camargo
// Criado:      2009-02-12
// Copyright:   (c) ? 
// Licença:     ?
/////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <stdlib.h>
#include "Levenshtein.h"
  static int
min(const int a, const int b)
{
  return ((a) < (b) ? (a) : (b));
}


MIN(const int x, const int y, const int z) 
{
  


wld(const pstr word, const pstr sample, const int limit) 
{
  
  
  
  
  
  
  
  
    // Weights
  int p0 = 1;	/****  Replace  ****/
  
  
  
  
  
  
    
  {
    
  /****  Compare initial letters  ****/ 
      if (lm >= 1 && lw >= 1 && sample[0] != word[0])
      
  
  
    
  /****  compare the first two letters  ****/ 
      if (lm >= 2 && lw >= 2 
	  &&sample[0] != word[0] && sample[0] != word[1] 
	  &&sample[1] != word[0] && sample[1] != word[1])
      
  
    
  {
    
    
    
      
  
  
    
  {
    
  /****  Calculate initial values  ****/ 
      if (lm == 0)
      
	
    
    else
      
    {
      
      
      
	
      {
	
	  
	
      
      
    
  
  
 /****  Calculate distance matrix  ****/ 
    j = 1;
  
    
  {
    
    
    
    
    
    
    
    
    
      
    {
      
   /****  d[i] = Minimum of three numbers  ****/ 
	d1 = d2;
      
      
      
      
	
    
  
  
    
  
  else
    


