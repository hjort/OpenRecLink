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
// Nome:        wizstd.h
// Propósito:   Classe (janela) para configurar padronização
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef wizstd_H
#define wizstd_H

//(*Headers(wizstd)
#include <wx/bmpbuttn.h>
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class wizstd:public wxDialog
{
public:

  wizstd(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	 wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ wizstd();

  //(*Declarations(wizstd)
  wxBitmapButton *BitmapButton2;
  wxTextCtrl *errrep;
  wxTextCtrl *filenamectrl;
  wxButton *btnadd;
  wxPanel *Panel1;
  wxPanel *Panel6;
  wxBitmapButton *openfile;
  wxTextCtrl *sufixctrl;
  wxButton *Button1;
  wxGrid *Grid1;
  wxTextCtrl *punctctrl;
  wxButton *btndel;
  wxStaticText *StaticText1;
  wxPanel *Panel2;
  wxStaticText *StaticText3;
  wxBitmapButton *okbtn;
  wxPanel *Panel4;
  wxPanel *Panel5;
  wxFileDialog *FileDialog1;
  wxPanel *Panel3;
  wxTextCtrl *exclctrl;
  wxStaticText *StaticText4;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxNotebook *Listbook1;
  wxBitmapButton *cancelbtn;
  wxButton *backbtn;
  wxButton *btnclear;
  wxButton *fwdbtn;
  wxBitmapButton *BitmapButton1;
  //*)

  // wxGridCellChoiceEditor *fldedit;

protected:

  //(*Identifiers(wizstd)
  static const long ID_STATICTEXT1;
  static const long ID_PANEL3;
  static const long ID_TEXTCTRL1;
  static const long ID_BITMAPBUTTON1;
  static const long ID_PANEL2;
  static const long ID_GRID1;
  static const long ID_BUTTON3;
  static const long ID_BUTTON4;
  static const long ID_BUTTON5;
  static const long ID_BUTTON6;
  static const long ID_BITMAPBUTTON2;
  static const long ID_BITMAPBUTTON3;
  static const long ID_PANEL4;
  static const long ID_STATICTEXT3;
  static const long ID_STATICTEXT4;
  static const long ID_TEXTCTRL3;
  static const long ID_TEXTCTRL4;
  static const long ID_STATICTEXT5;
  static const long ID_TEXTCTRL5;
  static const long ID_PANEL5;
  static const long ID_TEXTCTRL2;
  static const long ID_STATICTEXT2;
  static const long ID_PANEL6;
  static const long ID_LISTBOOK1;
  static const long ID_BUTTON1;
  static const long ID_BUTTON2;
  static const long ID_PANEL1;
  //*)

private:

    wxArrayString fieldnames;
  wxArrayString fieldtypes;

  void readcfg(wxString fname);
  void analyze(void);

  //(*Handlers(wizstd)
  void OnopenfileClick(wxCommandEvent & event);
  void OnbackbtnClick(wxCommandEvent & event);
  void OnfwdbtnClick(wxCommandEvent & event);
  void OnbtnaddClick(wxCommandEvent & event);
  void OnbtndelClick(wxCommandEvent & event);
  void OnButton1Click(wxCommandEvent & event);
  void OnbtnclearClick(wxCommandEvent & event);
  void OnGrid1EditorShown(wxGridEvent & event);
  void OnokbtnClick(wxCommandEvent & event);
  void OnListbook1PageChanged(wxNotebookEvent & event);
  void OnBitmapButton1Click(wxCommandEvent & event);
  void OnBitmapButton2Click(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
