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
// Nome:        wizjin.h
// Propósito:   Classe (janela) para configurar associação (join)
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef wizjin_H
#define wizjin_H

//(*Headers(wizjin)
#include <wx/bmpbuttn.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

class wizjin:public wxDialog
{
public:

  wizjin(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	 wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ wizjin();

  //(*Declarations(wizjin)
  wxTextCtrl *errrep;
  wxTextCtrl *cfgfilenamectrl;
  wxPanel *Panel1;
  wxPanel *Panel6;
  wxBitmapButton *openupdatefile;
  wxPanel *Panel7;
  wxBitmapButton *opencfgfile;
  wxPanel *Panel8;
  wxStaticText *StaticText1;
  wxCheckListBox *masterfields;
  wxPanel *Panel2;
  wxStaticText *StaticText3;
  wxBitmapButton *okbtn;
  wxPanel *Panel4;
  wxPanel *Panel5;
  wxStaticText *StaticText8;
  wxFileDialog *FileDialog1;
  wxFileDialog *FileDialog2;
  wxPanel *Panel3;
  wxStaticText *StaticText7;
  wxTextCtrl *updatefilenamectrl;
  wxStaticText *StaticText4;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxNotebook *Listbook1;
  wxStaticText *StaticText6;
  wxBitmapButton *cancelbtn;
  wxButton *backbtn;
  wxButton *fwdbtn;
  wxTextCtrl *masterfilenamectrl;
  wxCheckListBox *updatefields;
  wxBitmapButton *openmasterfile;
  wxStaticText *StaticText9;
  wxChoice *masterkey;
  wxChoice *updatekey;
  //*)

protected:

  //(*Identifiers(wizjin)
  static const long ID_STATICTEXT1;
  static const long ID_PANEL3;
  static const long ID_TEXTCTRL1;
  static const long ID_BITMAPBUTTON1;
  static const long ID_STATICTEXT6;
  static const long ID_PANEL2;
  static const long ID_TEXTCTRL2;
  static const long ID_BITMAPBUTTON2;
  static const long ID_TEXTCTRL3;
  static const long ID_BITMAPBUTTON3;
  static const long ID_STATICTEXT3;
  static const long ID_STATICTEXT4;
  static const long ID_PANEL4;
  static const long ID_CHOICE2;
  static const long ID_CHOICE1;
  static const long ID_STATICTEXT5;
  static const long ID_STATICTEXT7;
  static const long ID_PANEL5;
  static const long ID_CHECKLISTBOX1;
  static const long ID_STATICTEXT8;
  static const long ID_PANEL6;
  static const long ID_STATICTEXT9;
  static const long ID_CHECKLISTBOX2;
  static const long ID_PANEL7;
  static const long ID_TEXTCTRL4;
  static const long ID_STATICTEXT2;
  static const long ID_PANEL8;
  static const long ID_LISTBOOK1;
  static const long ID_BUTTON1;
  static const long ID_BUTTON2;
  static const long ID_PANEL1;
  //*)

private:

  void loadcfg(void);
  void savecfg(void);
  void analyze(void);
  bool comparenames(void);
  bool initlists(void);

  //(*Handlers(wizjin)
  void OnopencfgfileClick(wxCommandEvent & event);
  void OnopenmasterfileClick(wxCommandEvent & event);
  void OnopenupdatefileClick(wxCommandEvent & event);
  void OnokbtnClick(wxCommandEvent & event);
  void OnbackbtnClick(wxCommandEvent & event);
  void OnfwdbtnClick(wxCommandEvent & event);
  void OnListbook1PageChanged(wxNotebookEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
