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
// Nome:        runcalc.cpp
// Propósito:   Classe (janela) para executar cálculo de parâmetros de linkagem
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef RUNCALC_H
#define RUNCALC_H

//(*Headers(runcalc)
#include <wx/stopwatch.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class runcalc:public wxDialog
{
public:

  runcalc(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ runcalc();

  //(*Declarations(runcalc)
  wxTextCtrl *textout;
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    //*)
protected:

  //(*Identifiers(runcalc)
  static const long ID_STATICTEXT1;
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    //*)
private:

    wxArrayString m_estimates;
  wxArrayString u_estimates;
  void parest(void);
  void replace_values(void);

  //(*Handlers(runcalc)
  void OnopencfgClick(wxCommandEvent & event);
  void OnclosebtnClick(wxCommandEvent & event);
  void OngobtnClick(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif