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
// Nome:        dbutils.cpp
// Propósito:   Funções auxiliares para tabela
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef DBUTILS_H
#define DBUTILS_H

#include <wx/string.h>
#include <wx/datetime.h>
#include <wx/arrstr.h>

#include "dbtypes.h"

wxString packarray(wxArrayString dataarray, wxString sep);
wxArrayString unpackarray(wxString datastr, wxString sep);
wxString packstru(dbtable::fielddef * structarray);
wxArrayString stru2array(dbtable::fielddef * structarray);
dbtable::fielddef * unpackstru(wxString sructstring);
dbtable::fielddef * array2stru(wxArrayString sructarray);
wxString packfield(dbtable::fielddef field);
dbtable::fielddef unpackfield(wxString fieldstring);

#endif // DBUTILS_H
