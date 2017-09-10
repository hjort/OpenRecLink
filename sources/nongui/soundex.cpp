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
// Nome:        soundex.cpp
// Propósito:   Algoritmo soundex para wxString (funciona com unicode)
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "soundex.h"
#include <ctype.h>

wxString
soundex(wxString value)
{
  wxChar key[] = _T("0000");
  int code = 0;
  int lastcode = 0;
  int len = value.Length();

  if (!value.IsEmpty())
  {
    int i = 0;

    while ((i < len) && value[i] && !isalpha(value[i]))
      i++;

    if (value[i])
    {
      key[0] = toupper(value[i++]);
      int j = 1;
      while ((i < len) && (j < 4))
      {
	switch ((char) value[i])
	{
	case _T('b'):
	case _T('p'):
	case _T('f'):
	case _T('v'):
	case _T('B'):
	case _T('P'):
	case _T('F'):
	case _T('V'):
	  code = 1;
	  break;

	case _T('c'):
	case _T('s'):
	case _T('k'):
	case _T('g'):
	case _T('j'):
	case _T('q'):
	case _T('x'):
	case _T('z'):
	case _T('C'):
	case _T('S'):
	case _T('K'):
	case _T('G'):
	case _T('J'):
	case _T('Q'):
	case _T('X'):
	case _T('Z'):
	  code = 2;
	  break;

	case _T('d'):
	case _T('t'):
	case _T('D'):
	case _T('T'):
	  code = 3;
	  break;

	case _T('l'):
	case _T('L'):
	  code = 4;
	  break;

	case _T('m'):
	case _T('n'):
	case _T('M'):
	case _T('N'):
	  code = 5;
	  break;

	case _T('r'):
	case _T('R'):
	  code = 6;
	  break;

	case _T('a'):
	case _T('e'):
	case _T('i'):
	case _T('o'):
	case _T('u'):
	case _T('y'):
	case _T('w'):
	case _T('h'):
	case _T('A'):
	case _T('E'):
	case _T('I'):
	case _T('O'):
	case _T('U'):
	case _T('Y'):
	case _T('W'):
	case _T('H'):
	  code = 0;
	  break;

	default:
	  break;
	}

	if (code && code != lastcode)
	{
	  key[j++] = _T('0') + code;
	  lastcode = code;
	}
	if (i < len)
	  i++;
	else
	  break;
      }
    }
  }

  return wxString(key);
}
