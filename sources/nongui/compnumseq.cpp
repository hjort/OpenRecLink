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
// Nome:        compnumsec.cpp
// Propósito:   Rotinas para comparação de seqüências de caracteres
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "Levenshtein.h"
#include "compnumseq.h"
#include "calc.h"

wxString
CleanString(wxString s)
{
  for (int i = s.Length(); i; i--)
    if ((s[i] < '0') || (s[i] > '9'))	// Não é dígito
      s.Remove(i, 1);
  return s;
}

double
numcomp(wxString s1, wxString s2)
{
  s1 = CleanString(s1);
  s2 = CleanString(s2);
  int ref = 0, len = s1.Length();
  double result = 0.0;
  if (len && s2.Length())
  {
    for (int i = 1; i <= len; i++)
      if (s1[i] != s2[i])
	ref++;
    result = (double) (len - ref) / (double) len;
  }
  return result;
}

int
numdif(wxString s1, wxString s2)
{
  s1 = CleanString(s1);
  s2 = CleanString(s2);
  int result = -1;
  if (s1.Length() && s2.Length())
  {
    long n1, n2;
    if (s1.ToLong(&n1) && s2.ToLong(&n2))
      result = abs(n1 - n2);
  }
  return result;
}

double
approx(wxString s1, wxString s2)
{
  char buff1[300], buff2[300];
  double apx;

  strcpy(buff1, s1.Upper().mb_str(wxConvUTF8));
  int len = strlen(buff1);
  if (len)
  {
    strcpy(buff2, s2.Upper().mb_str(wxConvUTF8));
    if (strlen(buff2))
    {
      if (strlen(buff2) > len)
	len = strlen(buff2);
      int result = wld(buff1, buff2, len);
      apx = (double) (len - result) / (double) len;
    }
    else
      apx = 0.0;
  }
  else
    apx = 0.0;
  return apx;
}

/*
  v1 e v2 são as strings a comparar
  comp é o identificador do algoritmo
  m, u e l são, respectivamente, os valores de m (correto),
  u (incorreto)e limiar
*/
double
docompare(wxString v1, wxString v2, reclink::compref comp, double m, double u, double l,
	  bool & match)
{
  double compare = 0.0, lim, tmp;

  if ((v1 == _T("*")) || (v2 == _T("*")))
  {
    if ((comp == reclink::APROX) || (comp == reclink::EXATO))
    {
      if (v1 == v2)
      {
	compare = ppos(m, u);
	match = true;
      }
      else
      {
	compare = npos(m, u);
	match = false;
      }
    }
    else
    {
      compare = npos(m, u);
      match = false;
    }
  }
  else if (!v1.IsEmpty() && !v2.IsEmpty())
  {
    switch (comp)
    {
    case reclink::EXATO:
      if (v1 == v2)
      {
	compare = ppos(m, u);
	match = false;
      }
      else
      {
	compare = npos(m, u);
	match = false;
      }
      break;
    case reclink::APROX:
      lim = l / 100.0;
      tmp = approx(v1, v2);
      if (tmp > lim)
      {
	compare = ppos(m, u) * tmp;
	match = true;
      }
      else
      {
	compare = npos(m, u);
	match = false;
      }
      break;
    case reclink::CARACTERE:
      lim = l / 100.0;
      tmp = numcomp(v1, v2);
      if (tmp > lim)
      {
	compare = ppos(m, u) * tmp;
	match = true;
      }
      else
      {
	compare = npos(m, u);
	match = false;
      }
      break;
    case reclink::DIFERENCA:
      tmp = numdif(v1, v2);
      if ((tmp > -1) && (tmp <= l))
      {
	if (tmp > 0.0)
	{
	  compare = ppos(m, u) * 0.85;
	  match = true;
	}
	else
	{
	  compare = ppos(m, u);
	  match = true;
	}
      }
      else
      {
	compare = npos(m, u);
	match = false;
      }
      break;
    case reclink::ERRADO:
      match = false;
      break;
    }
  }
  else
    match = false;

  return compare;
}
