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
// Nome:        wizcmb.h
// Propósito:   Classe (janela) para configurar combinação
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef wizcmb_H
#define wizcmb_H

//(*Headers(wizcmb)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/things/toggle.h>
#include <wx/panel.h>
#include <wx/dialog.h>
//*)

class wizcmb:public wxDialog
{
public:

  wizcmb(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	 wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ wizcmb();

  //(*Declarations(wizcmb)
  wxPanel *Panel1;
  wxStaticText *StaticText1;
  wxPanel *Panel3;
  wxNotebook *Listbook1;
  wxCustomButton *backbtn;
  wxPanel *Panel2;
  wxCustomButton *fwdbtn;
  //*)

protected:

  //(*Identifiers(wizcmb)
  static const long ID_STATICTEXT1;
  static const long ID_PANEL3;
  static const long ID_PANEL2;
  static const long ID_LISTBOOK1;
  static const long ID_BUTTON1;
  static const long ID_BUTTON2;
  static const long ID_PANEL1;
  //*)

private:

  //(*Handlers(wizcmb)
  //*)

  DECLARE_EVENT_TABLE()};

#endif
