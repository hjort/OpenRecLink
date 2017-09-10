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
// Nome:        execmark.h
// Propósito:   Classe (janela) para marcar/desmarcar arquivo de pares
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef EXECMARK_H
#define EXECMARK_H

#include "ntable.h"

//(*Headers(execmark)
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
#include <wx/radiobox.h>
//*)

class execmark:public wxDialog
{
public:

  execmark(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	   wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ execmark();

  //(*Declarations(execmark)
  wxBitmapButton *BitmapButton2;
  wxTextCtrl *cfgfilenamectrl;
  wxPanel *Panel1;
  wxBitmapButton *BitmapButton3;
  wxStaticLine *StaticLine2;
  wxBitmapButton *opencfgfile;
  wxTextCtrl *text_maxval;
  wxStaticText *StaticText1;
  wxStaticText *minlbl;
  wxStaticLine *StaticLine1;
  wxFileDialog *FileDialog1;
  wxTextCtrl *text_minval;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxStopWatch StopWatch1;
  wxRadioBox *RadioBox1;
  wxGauge *Gauge1;
  wxBitmapButton *BitmapButton1;
  wxStaticText *maxlbl;
  //*)

protected:

  //(*Identifiers(execmark)
  static const long ID_GAUGE1;
  static const long ID_TEXTCTRL2;
  static const long ID_BITMAPBUTTON2;
  static const long ID_STATICTEXT1;
  static const long ID_STATICTEXT5;
  static const long ID_BITMAPBUTTON3;
  static const long ID_STATICLINE1;
  static const long ID_STATICLINE2;
  static const long ID_BITMAPBUTTON1;
  static const long ID_RADIOBOX1;
  static const long ID_TEXTCTRL3;
  static const long ID_TEXTCTRL1;
  static const long ID_STATICTEXT2;
  static const long ID_STATICTEXT4;
  static const long ID_STATICTEXT3;
  static const long ID_PANEL1;
  //*)

private:

    bool stop;
  wxString msg;
  ntable tbl;
  long matchrecs;
  long doubtrecs;
  long notmrecs;
  long unmrecs;
  void markrecs(void);

  //(*Handlers(execmark)
  void OnRadioBox1Select(wxCommandEvent & event);
  void OnopencfgfileClick(wxCommandEvent & event);
  void OnBitmapButton2Click(wxCommandEvent & event);
  void OnBitmapButton3Click(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
