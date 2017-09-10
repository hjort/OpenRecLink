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
// Nome:        execjin.h
// Propósito:   Classe (janela) para executar associação (join) de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef execjin_H
#define execjin_H

//(*Headers(execjin)
#include <wx/gauge.h>
#include <wx/stopwatch.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class execjin:public wxDialog
{
public:

  execjin(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ execjin();

  //(*Declarations(execjin)
  wxBitmapButton *BitmapButton2;
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    //*)
protected:

  //(*Identifiers(execjin)
  static const long ID_TEXTCTRL2;
   
   
   
   
   
   
   
   
   
   
   
   
   
    //*)
private:

  void exec(void);
  wxString msg;

  //(*Handlers(execjin)
  void OnopenoutfileClick(wxCommandEvent & event);
  void OnopencfgfileClick(wxCommandEvent & event);
  void OnBitmapButton2Click(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif