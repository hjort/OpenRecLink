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
// Nome:        docopy.h
// Propósito:   Classe para cópia seletiva de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef DOCOPY_H
#define DOCOPY_H

#include "ntable.h"

namespace dbcopy
{

  typedef class _docopy
  {
  public:
    _docopy(wxString cfgfile, wxString nameout);
    virtual ~ _docopy();
    bool init(void);
    bool exec(void);		// executa 1 registro por vez
    bool isfinished(void);
    long numberofrecs(void);
  protected:
  private:
      bool createout(void);
    bool checksel(void);
    bool eval(int num);
    bool evals(int num);
    bool evali(int num);
    bool evalf(int num);
    bool evalb(int num);
    //int calcsize(wxString spec);
    wxString in;
    wxString out;
    wxString cfg;
    wxArrayString outfields;
    wxArrayString selflds;
    wxArrayInt selops;
    wxArrayString selvals;
    wxArrayInt sellnks;
    ntable tbin;		// area to review
    ntable tbout;		// area to review
    long nrecs;
  private:
  } docopy;

};
#endif // DOCOPY_H
