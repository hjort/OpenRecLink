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
// Nome:        execlnmatrix.h
// Propósito:   Classe (janela) para gerar as matrizes p/cálculo
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef execlnmatrix_H
#define execlnmatrix_H

//(*Headers(execlnmatrix)
#include <wx/gauge.h>
#include <wx/stopwatch.h>
#include <wx/bmpbuttn.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class execlnmatrix:public wxDialog
{
public:

  execlnmatrix(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	       wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ execlnmatrix();

  //(*Declarations(execlnmatrix)
  wxBitmapButton *BitmapButton2;
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    //*)
protected:

  //(*Identifiers(execlnmatrix)
  static const long ID_GAUGE1;
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    //*)
private:

    bool stop;
  wxString msg;

  //(*Handlers(execlnmatrix)
  void OnBitmapButton3Click(wxCommandEvent & event);
   
   
   
    //*)
  DECLARE_EVENT_TABLE()};

#endif