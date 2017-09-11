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
// Nome:        dblink.h
// Propósito:   Classe para relacionamento (join) de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef dblink_h
#define dblink_h

#include <wx/window.h>
#include <wx/string.h>

#include "reclinktypes.h"
#include "compnumseq.h"
#include "ntable.h"

namespace dblink
{

  typedef class _dolink
  {
  public:
    _dolink(wxString cfgfile, long firstrec, long lastrec);
     ~_dolink();
    bool init(wxWindow * w = 0);
    bool findblockbeg(void);
    bool isinblock(void);
    void docalc(void);		// executa 1 registro por vez
    long therecno(void);
  private:
      bool checkmasterndx(wxString fname, wxString ixname);
    bool createscoretbl(void);
    //bool setindex(void);
    bool checkblockvars(void);
    wxString cfg;
    long first;
    long last;
    bool ignmin;
    double minscore;
      reclink::blockcfg * blockopts;
      reclink::comparecfg * cpopts;
    ntable tbref;		// area to review (read blocks)
    ntable tbcomp;		// area to review (read all)
    ntable tbscore;		// area to review
    int noblks;
    int nocps;
    wxWindow *parent;
  } dolink;

}

#endif

/*
usage:

dolink mylink(cfgfile, firstrec, lastrec);

mylink.init();
while (mylink.findblockbeg())
	while (mylink.isinblock())
		while (docalc());

*/
