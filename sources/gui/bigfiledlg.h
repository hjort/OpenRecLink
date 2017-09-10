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
// Nome:        bigfile.h
// Propósito:   Classe (janela) para informar sobre arquivos muito grandes
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////


#ifndef BIGFILEDLG_H
#define BIGFILEDLG_H

//(*Headers(bigfiledlg)
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class bigfiledlg:public wxDialog
{
public:

  bigfiledlg(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	     wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ bigfiledlg();

  //(*Declarations(bigfiledlg)
  wxStaticText *StaticText1;
  wxStaticText *StaticText3;
  wxTextCtrl *TextCtrl1;
  wxStaticText *StaticText2;
  wxBitmapButton *BitmapButton1;
  //*)

protected:

  //(*Identifiers(bigfiledlg)
  static const long ID_STATICTEXT1;
  static const long ID_STATICTEXT2;
  static const long ID_STATICTEXT3;
  static const long ID_TEXTCTRL1;
  static const long ID_BITMAPBUTTON1;
  //*)

private:

  //(*Handlers(bigfiledlg)
  void OnBitmapButton1Click(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
