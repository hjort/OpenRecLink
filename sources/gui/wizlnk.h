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
// Nome:        wizlnk.h
// Propósito:   Classe (janela) para configurar relacionamento
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef wizlnk_H
#define wizlnk_H

//(*Headers(wizlnk)
#include <wx/bmpbuttn.h>
#include <wx/grid.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class wizlnk:public wxDialog
{
public:

  wizlnk(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	 wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ wizlnk();

  //(*Declarations(wizlnk)
  wxButton *btnadd3;
  wxTextCtrl *errrep;
  wxTextCtrl *cfgfilenamectrl;
  wxButton *btnclear3;
  wxPanel *Panel1;
  wxPanel *Panel6;
  wxBitmapButton *BitmapButton3;
  wxPanel *Panel7;
  wxTextCtrl *compfilenamectrl;
  wxBitmapButton *opencfgfile;
  wxStaticText *maxscore;
  wxCheckBox *CheckBox1;
  wxTextCtrl *reffilenamectrl;
  wxPanel *Panel8;
  wxStaticText *StaticText1;
  wxStaticText *StaticText10;
  wxPanel *Panel2;
  wxStaticText *StaticText3;
  wxBitmapButton *okbtn;
  wxButton *btnclear2;
  wxPanel *Panel4;
  wxButton *btndel3;
  wxBitmapButton *opencompfile;
  wxPanel *Panel5;
  wxStaticText *StaticText8;
  wxBitmapButton *BitmapButton5;
  wxBitmapButton *BitmapButton4;
  wxFileDialog *FileDialog1;
  wxFileDialog *FileDialog2;
  wxPanel *Panel3;
  wxStaticText *StaticText7;
  wxButton *btnadd2;
  wxButton *btndel2;
  wxTextCtrl *TextCtrl1;
  wxStaticText *StaticText4;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxGrid *Grid2;
  wxNotebook *Listbook1;
  wxGrid *Grid3;
  wxStaticText *StaticText6;
  wxBitmapButton *cancelbtn;
  wxButton *backbtn;
  wxBitmapButton *openreffile;
  wxButton *fwdbtn;
  wxStaticText *minscore;
  wxStaticText *StaticText9;
  wxTextCtrl *TextCtrl2;
  wxBitmapButton *BitmapButton6;
  //*)

protected:

  //(*Identifiers(wizlnk)
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
  static const long ID_GRID2;
  static const long ID_BUTTON8;
  static const long ID_BUTTON9;
  static const long ID_BUTTON10;
  static const long ID_BITMAPBUTTON4;
  static const long ID_BITMAPBUTTON5;
  static const long ID_TEXTCTRL5;
  static const long ID_STATICTEXT5;
  static const long ID_PANEL5;
  static const long ID_GRID3;
  static const long ID_BUTTON12;
  static const long ID_BUTTON13;
  static const long ID_BUTTON14;
  static const long ID_BITMAPBUTTON7;
  static const long ID_BITMAPBUTTON6;
  static const long ID_PANEL6;
  static const long ID_CHECKBOX1;
  static const long ID_STATICTEXT7;
  static const long ID_STATICTEXT8;
  static const long ID_STATICTEXT9;
  static const long ID_STATICTEXT10;
  static const long ID_STATICTEXT11;
  static const long ID_STATICTEXT12;
  static const long ID_TEXTCTRL6;
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

    wxArrayString compflds;
  wxArrayString refflds;
  void loadcfg(void);
  void savecfg(void);
  void analyze(void);
  void calcparms(void);
  bool comparenames(void);
  wxString loadfields(wxArrayString * list, wxString fname);

  //(*Handlers(wizlnk)
  void OnGrid2CellLeftClick(wxGridEvent & event);
  void Onbtnadd3Click(wxCommandEvent & event);
  void Onbtndel3Click(wxCommandEvent & event);
  void Onbtnclear3Click(wxCommandEvent & event);
  void OnBitmapButton3Click(wxCommandEvent & event);
  void OnBitmapButton6Click(wxCommandEvent & event);
  void Onbtnadd2Click(wxCommandEvent & event);
  void Onbtndel2Click(wxCommandEvent & event);
  void Onbtnclear2Click(wxCommandEvent & event);
  void OnBitmapButton4Click(wxCommandEvent & event);
  void OnBitmapButton5Click(wxCommandEvent & event);
  void OnopencfgfileClick(wxCommandEvent & event);
  void OnopencompfileClick(wxCommandEvent & event);
  void OnopenreffileClick(wxCommandEvent & event);
  void OnokbtnClick(wxCommandEvent & event);
  void OnbackbtnClick(wxCommandEvent & event);
  void OnfwdbtnClick(wxCommandEvent & event);
  void OnListbook1PageChanged(wxNotebookEvent & event);
  void OnCheckBox1Click(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
