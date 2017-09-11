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
// Nome:        langdlg.h
// Propósito:   Classe (janela) para configurar língua default
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef LANGDLG_H
#define LANGDLG_H

//(*Headers(langdlg)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
//*)

class langdlg:public wxDialog
{
public:

  langdlg(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ langdlg();

  //(*Declarations(langdlg)
  wxRadioBox *RadioBox1;
  //*)

protected:

  //(*Identifiers(langdlg)
  static const long ID_RADIOBOX1;
  //*)

private:

  //(*Handlers(langdlg)
  //*)

  DECLARE_EVENT_TABLE()};

#endif
