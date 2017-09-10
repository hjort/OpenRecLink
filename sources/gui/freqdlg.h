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
// Nome:        freqdlg.h
// Propósito:   Classe (janela) para gerar frequencia de scores
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef FREQDLG_H
#define FREQDLG_H

//(*Headers(freqdlg)
#include <wx/gauge.h>
#include <wx/stopwatch.h>
#include <wx/bmpbuttn.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include <wx/msgdlg.h>
#include <wx/fileconf.h>

#include <iostream>
#include <fstream>

#include "ntable.h"

class freqdlg:public wxDialog
{
public:

  freqdlg(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ freqdlg();

  //(*Declarations(freqdlg)
  wxBitmapButton *BitmapButton2;
  wxPanel *Panel1;
  wxTextCtrl *outfilenamectrl;
  wxStaticLine *StaticLine2;
  wxStaticText *StaticText1;
  wxBitmapButton *openoutfile;
  wxStaticText *StaticText3;
  wxStaticLine *StaticLine1;
  wxCheckListBox *CheckListBox1;
  wxFileDialog *FileDialog1;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxStopWatch StopWatch1;
  wxGauge *Gauge1;
  wxBitmapButton *BitmapButton1;
  //*)

protected:

  //(*Identifiers(freqdlg)
  static const long ID_TEXTCTRL4;
  static const long ID_BITMAPBUTTON1;
  static const long ID_STATICTEXT3;
  static const long ID_GAUGE1;
  static const long ID_STATICTEXT2;
  static const long ID_STATICTEXT5;
  static const long ID_BITMAPBUTTON3;
  static const long ID_STATICLINE1;
  static const long ID_STATICLINE2;
  static const long ID_CHECKLISTBOX1;
  static const long ID_STATICTEXT1;
  static const long ID_PANEL1;
  //*)

private:
  //ntable tbl;
    std::ofstream msgfile;
    std::ifstream inputfile;
  bool processfile(wxString filename, wxArrayString fields);
  bool compute(void);
  void execute(void);
  wxString compname;
  wxString refname;
  wxArrayString reffields;
  wxArrayString compfields;

  //(*Handlers(freqdlg)
  void OnopenoutfileClick(wxCommandEvent & event);
  void OnBitmapButton1Click(wxCommandEvent & event);
  void Run(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};


#endif
