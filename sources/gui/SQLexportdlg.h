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
// Nome:        SQLexportdlg.h
// Propósito:   Classe (janela) para exportar dados para SQL
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef SQLEXPORTDLG_H
#define SQLEXPORTDLG_H

//(*Headers(SQLexportdlg)
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

#include <iostream>
#include <fstream>

#include "ntable.h"

class SQLexportdlg:public wxDialog
{
public:

  SQLexportdlg(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	       wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ SQLexportdlg();

  //(*Declarations(SQLexportdlg)
  wxBitmapButton *BitmapButton2;
  wxPanel *Panel1;
  wxTextCtrl *outfilenamectrl;
  wxStaticText *StaticText1;
  wxBitmapButton *openoutfile;
  wxStaticText *StaticText3;
  wxStaticLine *StaticLine1;
  wxFileDialog *FileDialog1;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxStopWatch StopWatch1;
  wxGauge *Gauge1;
  wxBitmapButton *BitmapButton1;
  //*)

protected:

  //(*Identifiers(SQLexportdlg)
  static const long ID_TEXTCTRL4;
  static const long ID_BITMAPBUTTON1;
  static const long ID_STATICTEXT3;
  static const long ID_GAUGE1;
  static const long ID_STATICTEXT2;
  static const long ID_STATICTEXT5;
  static const long ID_BITMAPBUTTON3;
  static const long ID_STATICLINE1;
  static const long ID_STATICTEXT1;
  static const long ID_PANEL1;
  //*)

private:

  void selectcfgfile(void);
  bool loadcfgfile(void);
  void execute(void);
  bool exportdata(wxString fname);
  void exporthdr(wxString fname, bool isscore = false);
  void exportcommand(void);
  void write(wxString line);
  void write(const char *line);
  void click(void);
  int clicker;
  wxString compname;
  wxString refname;
  wxString matchname;
    std::ofstream output;

  //(*Handlers(SQLexportdlg)
  void OnopenoutfileClick(wxCommandEvent & event);
  void OnBitmapButton2Click(wxCommandEvent & event);
  void OnBitmapButton1Click(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};


#endif
