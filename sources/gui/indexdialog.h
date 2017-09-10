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
// Nome:        indexdialog.h
// Propósito:   Classe (janela) para criar/abrir índices
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef INDEXDIALOG_H
#define INDEXDIALOG_H

//(*Headers(indexdialog)
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class indexdialog:public wxDialog
{
public:

  indexdialog(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	      wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ indexdialog();

  //(*Declarations(indexdialog)
  wxBitmapButton *openfile;
  wxTextCtrl *filecontrol;
  wxStaticText *StaticText1;
  wxBitmapButton *okbtn;
  wxFileDialog *FileDialog1;
  wxTextCtrl *varcontrol;
  wxStaticText *StaticText2;
  //*)

protected:

  //(*Identifiers(indexdialog)
  static const long ID_STATICTEXT1;
  static const long ID_TEXTCTRL1;
  static const long ID_BITMAPBUTTON1;
  static const long ID_STATICTEXT2;
  static const long ID_TEXTCTRL2;
  static const long ID_OK;
  //*)

private:

  //(*Handlers(indexdialog)
  void OnopenfileClick(wxCommandEvent & event);
  void OnokbtnClick(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
