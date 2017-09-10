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
// Nome:        Levenshtein.h
// Propósito:   Função de cálculo da distância de Levenshtein
// Author:      Adaptado de artigo originalmente publicado na revista c't em 1990, de autoria de dr. Michael König
// Modified by: Kenneth Camargo
// Criado:      2009-02-12
// Copyright:   (c) ? 
// Licença:     ?
/////////////////////////////////////////////////////////////////////////////

#ifndef LevenshteinH
#define LevenshteinH
typedef char *pstr;

#ifdef __cplusplus
extern "C"
{
  
#endif	/*  */
  int wld(const pstr word, const pstr sample, const int limit);
   
#ifdef __cplusplus
} 
#endif	/*  */
#endif	/*  */
