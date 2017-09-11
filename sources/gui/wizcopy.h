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
// Nome:        wizcopy.h
// Propósito:   Classe (janela) para configurar cópia seletiva de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef WIZCOPY_H
#define WIZCOPY_H

//(*Headers(wizcopy)
#include <wx/bmpbuttn.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

class wizcopy:public wxDialog
{
public:

  wizcopy(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ wizcopy();

  //(*Declarations(wizcopy)
  wxTextCtrl *errrep;
  wxTextCtrl *value2;
  wxTextCtrl *filenamectrl;
  wxPanel *Panel1;
  wxPanel *Panel6;
  wxStaticText *StaticText13;
  wxTextCtrl *value5;
  wxBitmapButton *openfile;
  wxButton *backbtn;
  wxChoice *link3;
  wxButton *Button4;
  wxButton *Button1;
  wxChoice *link1;
  wxTextCtrl *value1;
  wxStaticText *StaticText1;
  wxStaticText *StaticText10;
  wxCheckListBox *masterfields;
  wxPanel *Panel2;
  wxChoice *fld5;
  wxChoice *op2;
  wxBitmapButton *okbtn;
  wxPanel *Panel4;
  wxChoice *op4;
  wxChoice *fld1;
  wxPanel *Panel5;
  wxStaticText *StaticText8;
  wxStaticText *StaticText12;
  wxFileDialog *FileDialog1;
  wxPanel *Panel3;
  wxButton *fwdbtn;
  wxChoice *fld4;
  wxChoice *fld3;
  wxChoice *op5;
  wxStaticText *StaticText2;
  wxChoice *link4;
  wxChoice *fld2;
  wxChoice *op1;
  wxNotebook *Listbook1;
  wxBitmapButton *cancelbtn;
  wxChoice *link2;
  wxTextCtrl *value4;
  wxChoice *op3;
  wxTextCtrl *value3;
  wxStaticText *StaticText11;
  //*)

protected:

  //(*Identifiers(wizcopy)
  static const long ID_STATICTEXT1;
  static const long ID_PANEL3;
  static const long ID_TEXTCTRL1;
  static const long ID_BITMAPBUTTON1;
  static const long ID_PANEL2;
  static const long ID_STATICTEXT10;
  static const long ID_STATICTEXT11;
  static const long ID_STATICTEXT12;
  static const long ID_STATICTEXT13;
  static const long ID_CHOICE1;
  static const long ID_CHOICE2;
  static const long ID_TEXTCTRL6;
  static const long ID_CHOICE3;
  static const long ID_CHOICE4;
  static const long ID_CHOICE5;
  static const long ID_TEXTCTRL2;
  static const long ID_CHOICE6;
  static const long ID_CHOICE7;
  static const long ID_CHOICE8;
  static const long ID_TEXTCTRL3;
  static const long ID_CHOICE9;
  static const long ID_CHOICE10;
  static const long ID_CHOICE11;
  static const long ID_TEXTCTRL4;
  static const long ID_CHOICE12;
  static const long ID_CHOICE13;
  static const long ID_CHOICE14;
  static const long ID_TEXTCTRL5;
  static const long ID_PANEL4;
  static const long ID_CHECKLISTBOX1;
  static const long ID_STATICTEXT8;
  static const long ID_BUTTON3;
  static const long ID_BUTTON6;
  static const long ID_PANEL5;
  static const long ID_TEXTCTRL7;
  static const long ID_STATICTEXT2;
  static const long ID_PANEL6;
  static const long ID_LISTBOOK1;
  static const long ID_BUTTON1;
  static const long ID_BUTTON2;
  static const long ID_PANEL1;
  //*)

private:

  void init(void);
  void checkifload(void);
  void analyze(void);
  void loadcfg(wxString fname);
  void savecfg(wxString fname);

  //(*Handlers(wizcopy)
  void OnopenfileClick(wxCommandEvent & event);
  void OnAddAllFieldsClick(wxCommandEvent & event);
  void OnokbtnClick(wxCommandEvent & event);
  void OncancelbtnClick(wxCommandEvent & event);
  void OnListbook1PageChanged(wxNotebookEvent & event);
  void OnRemoveAllFieldsClick(wxCommandEvent & event);
  void OnbackbtnClick(wxCommandEvent & event);
  void OnfwdbtnClick(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
