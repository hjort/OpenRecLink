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
// Nome:        dbjin.h
// Propósito:   Classe para associação (join) de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef dbjin_h
#define dbjin_h

#include <wx/window.h>
#include <wx/string.h>

#include "ntable.h"


typedef class _dbjin
{
public:
  _dbjin(wxWindow * w = 0);
  ~_dbjin();
  bool init(wxString cfgname, wxString outname);
  bool exec(void);
  long norecs(void);
private:
    ntable master;
  ntable update;
  ntable joined;
  int mastersel;
  int updatesel;
  bool *mastercheck;
  bool *updatecheck;
  wxString masterkey;
  wxString updatekey;
  wxString mastername;
  void loadcfg(wxString cfgname);
  void addstructures(ntable * _master, ntable * _update, ntable * newtable);
  void copyfields(ntable * org, bool * permits, ntable * dest, wxString prefix);
  void clearfields(ntable * tbl);
  wxWindow *parent;
} dbjin;

#endif // dbjin_h
