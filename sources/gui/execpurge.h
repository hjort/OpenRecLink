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
// Nome:        execpurge.h
// Propósito:   Classe (janela) para redução de arquivo de pares
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef EXECPURGE_H
#define EXECPURGE_H

#include "ntable.h"

//(*Headers(execpurge)
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

class execpurge:public wxDialog
{
public:

  execpurge(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	    wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ execpurge();

  //(*Declarations(execpurge)
  wxBitmapButton *BitmapButton2;
  wxTextCtrl *cfgfilenamectrl;
  wxPanel *Panel1;
  wxBitmapButton *BitmapButton3;
  wxStaticLine *StaticLine2;
  wxBitmapButton *opencfgfile;
  wxStaticText *StaticText1;
  wxStaticLine *StaticLine1;
  wxFileDialog *FileDialog1;
  wxTextCtrl *text_minval;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxStopWatch StopWatch1;
  wxRadioBox *RadioBox1;
  wxGauge *Gauge1;
  wxBitmapButton *BitmapButton1;
  //*)

protected:

  //(*Identifiers(execpurge)
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
  static const long ID_TEXTCTRL1;
  static const long ID_STATICTEXT2;
  static const long ID_PANEL1;
  //*)

private:

    bool stop;
  wxString msg;
  ntable t_in;
  ntable t_out;
  long totalrecs;
  long maxrecs;
  void copyrecs(void);

  //(*Handlers(execpurge)
  void OnopencfgfileClick(wxCommandEvent & event);
  void OnBitmapButton2Click(wxCommandEvent & event);
  void OnBitmapButton3Click(wxCommandEvent & event);
  void OnRadioBox1Select(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
