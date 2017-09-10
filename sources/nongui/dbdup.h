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
// Nome:        dbdup.h
// Propósito:   Classe para deduplicação de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef dbdup_h
#define dbdup_h

#include "ntable.h"
#include "reclinktypes.h"
#include "compnumseq.h"

#include <wx/window.h>
#include <wx/string.h>

//
#include <wx/wfstream.h>
//

typedef class _dbdup
{
public:
  _dbdup(wxWindow * w = 0);
  ~_dbdup();
  void init(wxString cfgfile);
  bool copyrec(void);
  bool checkrec(void);
  bool findblockbeg(void);
  int nrecs(void);
  bool checkfields(void);
  bool initindex(void);
protected:
private:
    ntable update;
  ntable tmp;
  bool hasthefield;
  wxString updatefilename;
  wxString oldstring;
  double minscore;
  int nopts;
  int nblocks;
  long recno;
  int numrecs;
  wxArrayString storedblock;
  wxArrayString storedvals;
    reclink::comparecfg * cpopts;
    reclink::blockcfg * blockopts;
  void loadcfg(wxString cfgname);
  void dupstru(void);
  bool checkmasterindex(void);
  void copyfields(void);
  wxString genuniq(void);
  bool checkblockvars();
  void setupdfile(void);
  bool checkfield(ntable * tbl);
  wxWindow *parent;
} dbdup;

#endif // dbdup_h
