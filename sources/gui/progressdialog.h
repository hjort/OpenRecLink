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
// Nome:        progressdialog.h
// Propósito:   Classe (janela) para informar programa ocupado
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

//(*Headers(progressdialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class progressdialog:public wxDialog
{
public:

  progressdialog(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
		 wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ progressdialog();

  //(*Declarations(progressdialog)
  wxStaticText *msglabel;
   
    //*)
protected:

  //(*Identifiers(progressdialog)
  static const long ID_STATICTEXT1;
   
    //*)
private:

  //(*Handlers(progressdialog)
  void OnSetFocus(wxFocusEvent & event);
   void OnKillFocus(wxFocusEvent & event);
   
    //*)
  DECLARE_EVENT_TABLE()};

#endif
