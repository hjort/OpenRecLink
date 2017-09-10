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
// Nome:        execlnk.h
// Propósito:   Classe (janela) para executar relacionamento de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef EXECLNK_H
#define EXECLNK_H

//(*Headers(execlnk)
#include <wx/gauge.h>
#include <wx/stopwatch.h>
#include <wx/bmpbuttn.h>
#include <wx/spinctrl.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "dbtypes.h"

class execlnk:public wxDialog
{
public:

  execlnk(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ execlnk();

  //(*Declarations(execlnk)
  wxBitmapButton *BitmapButton2;
  wxSpinCtrl *initrec;
  wxTextCtrl *cfgfilenamectrl;
  wxSpinCtrl *endrec;
  wxPanel *Panel1;
  wxBitmapButton *BitmapButton3;
  wxStaticLine *StaticLine2;
  wxBitmapButton *opencfgfile;
  wxStaticText *StaticText1;
  wxStaticText *StaticText3;
  wxStaticLine *StaticLine1;
  wxFileDialog *FileDialog1;
  wxGauge *Gauge2;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxStopWatch StopWatch1;
  wxStaticText *StaticText6;
  wxGauge *Gauge1;
  wxBitmapButton *BitmapButton1;
  //*)

protected:

  //(*Identifiers(execlnk)
  static const long ID_GAUGE1;
  static const long ID_TEXTCTRL2;
  static const long ID_BITMAPBUTTON2;
  static const long ID_STATICTEXT1;
  static const long ID_STATICTEXT2;
  static const long ID_STATICTEXT5;
  static const long ID_BITMAPBUTTON3;
  static const long ID_STATICLINE1;
  static const long ID_STATICLINE2;
  static const long ID_SPINCTRL1;
  static const long ID_STATICTEXT7;
  static const long ID_STATICTEXT8;
  static const long ID_SPINCTRL2;
  static const long ID_GAUGE2;
  static const long ID_BITMAPBUTTON1;
  static const long ID_PANEL1;
  //*)

private:

    bool stop;
  wxString msg;
  long maxrecs;

  //(*Handlers(execlnk)
  void OnBitmapButton3Click(wxCommandEvent & event);
  void OnBitmapButton2Click(wxCommandEvent & event);
  void OnopencfgfileClick(wxCommandEvent & event);
  void OninitrecChange(wxSpinEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
