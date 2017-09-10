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
// Nome:        dbcomb.h
// Propósito:   Classe para combinação de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef dbcomb_h
#define dbcomb_h

#include "ntable.h"
#include <wx/string.h>

typedef class _dbcomb
{
public:
  _dbcomb();
  ~_dbcomb();
  bool init(wxString ncfg, wxString ncomb, wxString new_ref = _T(""), wxString new_comp = _T(""));
  int nrecs(void);
  bool process(void);
  bool purge(void);
private:
    ntable score;
  ntable ref;
  ntable comp;
  ntable comb;
  ntable newref;
  ntable newcomp;
  wxString nrefix, ncompix;
  void copystructure(ntable * original, ntable * copy);
  void addstructures(ntable * _ref, ntable * _comp, ntable * newtable);
  void copyfields(ntable * org, ntable * dest, wxString prefix);
  bool purge_file(wxChar which);
} dbcomb;
#endif
