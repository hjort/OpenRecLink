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

 static int
MIN(const int x, const int y, const int z) 
{
  return (int) min(x, min(y, z));
}  int

wld(const pstr word, const pstr sample, const int limit) 
{
  char c;
  register int i, j;
  int lw, lm;
  int pp, p, q, r;
  int d1, d2, spmin;
  int d[255];
  const int maxlen = 255;
   
    // Weights
  int p0 = 1;	/****  Replace  ****/
  int q0 = 1;	/****  Insert   ****/
  int r0 = 1;	/****  Delete   ****/
    lw = strlen(word);
  lm = strlen(sample);
  spmin = 0;
   if (limit == 0)
    
  {
    
  /****  Compare initial letters  ****/ 
      if (lm >= 1 && lw >= 1 && sample[0] != word[0])
      spmin = maxlen;
  }
   if (limit == 1)
    
  /****  compare the first two letters  ****/ 
      if (lm >= 2 && lw >= 2 
	  &&sample[0] != word[0] && sample[0] != word[1] 
	  &&sample[1] != word[0] && sample[1] != word[1])
      spmin = maxlen;
   if (spmin <= limit)
    
  {
    j = 0;
     i = lm - j - lw;
    if (i * q0 > limit || (j == 0 && i * r0 < -limit))
      spmin = maxlen;
  }
   if (spmin <= limit)
    
  {
    
  /****  Calculate initial values  ****/ 
      if (lm == 0)
      for (i = 0; i <= lw; i++)
	d[i] = i * r0;
    
    else
      
    {
      p = MIN(p0, p0, r0 + q0);
      d[0] = d[1] = d[2] = q0;
       for (i = 1; i <= lw; i++)
	
      {
	if (word[i - 1] == sample[0])
	  p = 0;
	d[i] = (i - 1) * r0 + p;
      }
      spmin = MIN(d[0], d[1], d[2]);
    }
  }
   
 /****  Calculate distance matrix  ****/ 
    j = 1;
  while (j < lm && spmin <= limit)
    
  {
    c = sample[j];
    j = j + 1;
    p = p0;
    q = q0;
    r = r0;
    d2 = d[0];
    d[0] = d[0] + q;
    spmin = d[0];
     for (i = 1; i <= lw; i++)
      
    {
      
   /****  d[i] = Minimum of three numbers  ****/ 
	d1 = d2;
      d2 = d[i];
      pp = (word[i - 1] == c) ? 0 : p;
      d[i] = MIN(d1 + pp, d2 + q, d[i - 1] + r);
      if (d[i] < spmin)
	spmin = d[i];
    }
  }				/* while( j < lm && spmin <= limit ) */
   if (spmin <= limit && d[lw] <= limit)
    return d[lw];
  
  else
    return maxlen;
}

 
