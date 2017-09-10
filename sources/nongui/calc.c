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
// Nome:        calc.c
// Propósito:   Rotinas para facilitar cálculo de m e u
// Author:      Kenneth Camargo
// Modified by:
// Criado:     2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "calc.h"

#define calclog(n) ((double)(log((double)n)/log((double)2.0)))
  double
ppos(double m, double u) 
{
  double r = m / u;
  return calclog(r);
}

 double
npos(double m, double u) 
{
  double r = (1 - m) / (1 - u);
  return calclog(r);
}

 
