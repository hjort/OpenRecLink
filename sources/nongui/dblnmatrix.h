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
// Nome:        dblnmatrix.h
// Propósito:   Classe para geração de matrizes para cálculo de parâmetros de relacionamento
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////


#ifndef dblnmatrix_h
#define dblnmatrix_h

#include <wx/window.h>
#include <wx/string.h>

#include "reclinktypes.h"
#include "compnumseq.h"
#include "ntable.h"

namespace dblnmatrix
{

  typedef class _domatrix
  {
  public:
    _domatrix(wxString cfgfile);
    ~_domatrix();
    bool init(wxWindow * w = 0);
    bool findblockbeg(void);
    bool isinblock(void);
    void domatrix(wxArrayString * matches);	// executa 1 registro por vez
    void domatrix_nb(wxArrayString * matches, long refno, long compno);
    long getcomprecs(void);
    long getrefrecs(void);
    void reset(void);
    bool checkmatches(long linecount);
    bool reachedend(void);
    long therecno(void);
  private:
      bool checkmasterndx(wxString fname, wxString ixname);
    bool checkblockvars(void);
    wxString cfg;
      reclink::blockcfg * blockopts;
      reclink::comparecfg * cpopts;
    ntable tbcomp;		// area to review (read all)
    ntable tbref;
    int noblks;
    int nocps;
    long refrecs;
    long comprecs;
    double *freqmatch;
    bool fullrun;
    wxWindow *parent;
  } domatrix;

}

#endif

/*
usage:

domatrix mylink(cfgfile, firstrec, lastrec);

mylink.init();
while (mylink.findblockbeg())
	while (mylink.isinblock())
		while (domatrix());

*/
