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
// Nome:        dbtypes.h
// Propósito:   Tipos para tabela
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////


#ifndef DBTYPES_H
#define DBTYPES_H

#define LOTSA_RECS 75000000

#include <wx/string.h>

namespace dbtable
{

  typedef struct _date
  {
    int day;
    int month;
    int year;
  } date;

  typedef enum _ftype
  {
    CHAR, INT, FLOAT, BOOLEAN, DATE, UNKNOWN
  } ftype;

  typedef struct _fielddef
  {
    wxString fdname;
    ftype fdtype;
    int len;
    int dec;
  } fielddef;

}
#endif				// DBTYPES_H
