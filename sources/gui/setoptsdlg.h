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
// Nome:        setoptsdlg.h
// Propósito:   Classe (janela) para selecionar algoritmo de padronização
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef SETOPTSDLG_H
#define SETOPTSDLG_H

//(*Headers(setoptsdlg)
#include <wx/grid.h>
#include <wx/spinctrl.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/radiobox.h>
//*)

class setoptsdlg:public wxDialog
{
public:

  setoptsdlg(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	     wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ setoptsdlg();
  void setparms(wxString exclu, wxString punctu, wxString suffs);
  void provideexamples(void);

  //(*Declarations(setoptsdlg)
  wxRadioBox *RadioBox2;
   
   
   
   
   
   
   
   
   
   
   
   
   
    //*)
protected:

  //(*Identifiers(setoptsdlg)
  static const long ID_RADIOBOX1;
   
   
   
   
   
   
   
   
   
   
   
   
   
    //*)
private:

    wxString excl;
  wxString punct;
  wxString suffixes;

  //(*Handlers(setoptsdlg)
  void OnRadioBox1Select(wxCommandEvent & event);
  void OnSpinCtrl1Change(wxSpinEvent & event);
  void OnSpinCtrl2Change(wxSpinEvent & event);
  void OnRadioBox2Select(wxCommandEvent & event);
  void OnButton1Click(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif