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
// Nome:        fldconvert.h
// Propósito:   Classe para conversão de campos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef fldconvert_h
#define fldconvert_h

#include <wx/tokenzr.h>

#include "reclinktypes.h"
#include "soundex.h"

namespace fldcvt
{

  typedef class _fldcv
  {
  private:
    wxString punctuation;
    wxArrayString excllist;
    wxString suffixes;
     wxString stdval;
     wxString stdfirst;
     wxString stdlast;
     wxString stdinit;
     wxString stdapp;
    wxString procname(wxString name, reclink::convref convtype);
     void parsename(wxString name);
    void initvars(void);
     wxString blockvar(wxString var);
    wxString xchange(wxString var, wxString rules);
  public:
      _fldcv();
     ~_fldcv();
    wxString convstring(wxString src, reclink::opconv convtype);
    void initparms(wxString excl, wxString punct, wxString suffs);
  } fldcv;

}

#endif
