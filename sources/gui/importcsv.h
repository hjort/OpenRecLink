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
// Nome:        importcsv.h
// Propósito:   Classe (janela) para importar dados de arquivo texto
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2010-01-23
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef IMPORTCSV_H
#define IMPORTCSV_H

//(*Headers(importcsv)
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/radiobox.h>
//*)

#define MAX_BYTES 32*1024

class importcsv:public wxDialog
{
public:

  importcsv(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	    wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ importcsv();

  //(*Declarations(importcsv)
  wxTextCtrl *filenamectrl;
  wxButton *cancelbtn;
  wxButton *delbtn;
  wxGrid *Grid1;
  wxTextCtrl *recsep;
  wxStaticText *StaticText1;
  wxStaticText *reclabel;
  wxButton *adbtn;
  wxStaticText *StaticText3;
  wxButton *okbtn;
  wxButton *selfilenamebtnButton1;
  wxFileDialog *FileDialog1;
  wxStaticText *StaticText2;
  wxTextCtrl *fldsep;
  wxRadioBox *RadioBox1;
  //*)

protected:

  //(*Identifiers(importcsv)
  static const long ID_TEXTCTRL1;
  static const long ID_BUTTON1;
  static const long ID_STATICTEXT1;
  static const long ID_TEXTCTRL2;
  static const long ID_STATICTEXT2;
  static const long ID_TEXTCTRL3;
  static const long ID_RADIOBOX1;
  static const long ID_GRID1;
  static const long ID_STATICTEXT3;
  static const long ID_STATICTEXT4;
  static const long ID_BUTTON2;
  static const long ID_BUTTON3;
  static const long ID_BUTTON4;
  static const long ID_BUTTON5;
  //*)

private:

    wxGridCellChoiceEditor * edit;

  //(*Handlers(importcsv)
  void OnadbtnClick(wxCommandEvent & event);
   void OndelbtnClick(wxCommandEvent & event);
   void OncancelbtnClick(wxCommandEvent & event);
   void OnokbtnClick(wxCommandEvent & event);
   void OnRadioBox1Select(wxCommandEvent & event);
   void OnselfilenamebtnButton1Click(wxCommandEvent & event);
   
    //*)
  DECLARE_EVENT_TABLE()};

#endif
