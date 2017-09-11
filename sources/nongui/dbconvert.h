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
// Nome:        dbconvert.h
// Propósito:   Classe para padronização de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef dbconvert_h
#define dbconvert_h

#include "fldconvert.h"
#include "reclinktypes.h"
#include "ntable.h"

namespace dbconv
{

  typedef class _doconv
  {
  public:
    _doconv(wxString cfgfile, wxString nameout);
    ~_doconv(void);
    bool init(void);
    bool exec(void);		// executa 1 registro por vez
    bool isfinished(void);
    long numberofrecs(void);
  private:
      bool createout(void);
    int calcsize(wxString spec);
    wxString in;
    wxString out;
    wxString cfg;
    wxString excl;
    wxString punct;
    wxString suffix;
      reclink::execstd * procopts;
    ntable tbin;		// area to review
    ntable tbout;		// area to review
    int nopts;
    long nrecs;
      fldcvt::fldcv converter;
  } doconv;

/*
USAGE:
dbconv::doconv myconv(filenamecfg, filenameout);

if (myconv.init())
{
    while (!myconv.isfinished())
        if (!myconv.exec())
            break;
    long nrecs = myconv.numberofrecs();
}
*/

}
#endif
