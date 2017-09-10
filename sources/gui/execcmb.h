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
// Nome:        execcmb.h
// Propósito:   Classe (janela) para executar combinação de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef execcmb_H
#define execcmb_H

//(*Headers(execcmb)
#include <wx/gauge.h>
#include <wx/stopwatch.h>
#include <wx/bmpbuttn.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "dbcomb.h"
class execcmb:public wxDialog
{
public:

  execcmb(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
  virtual ~ execcmb();

  //(*Declarations(execcmb)
  wxBitmapButton *BitmapButton2;
  wxBitmapButton *opennewcomp;
  wxTextCtrl *cfgfilenamectrl;
  wxBitmapButton *opennewref;
  wxPanel *Panel1;
  wxBitmapButton *BitmapButton3;
  wxTextCtrl *outfilenamectrl;
  wxStaticLine *StaticLine2;
  wxBitmapButton *opencfgfile;
  wxTextCtrl *newrefnamectrl;
  wxCheckBox *CheckBox1;
  wxStaticText *StaticText1;
  wxStaticText *StaticText3;
  wxStaticLine *StaticLine1;
  wxTextCtrl *newcompnamectrl;
  wxFileDialog *FileDialog4;
  wxFileDialog *FileDialog1;
  wxFileDialog *FileDialog2;
  wxFileDialog *FileDialog3;
  wxStaticText *StaticText4;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxStopWatch StopWatch1;
  wxStaticText *StaticText6;
  wxGauge *Gauge1;
  wxBitmapButton *BitmapButton1;
  //*)

protected:

  //(*Identifiers(execcmb)
  static const long ID_TEXTCTRL2;
  static const long ID_BITMAPBUTTON2;
  static const long ID_TEXTCTRL4;
  static const long ID_BITMAPBUTTON4;
  static const long ID_BITMAPBUTTON5;
  static const long ID_BITMAPBUTTON1;
  static const long ID_STATICTEXT1;
  static const long ID_STATICTEXT4;
  static const long ID_STATICTEXT6;
  static const long ID_STATICTEXT3;
  static const long ID_GAUGE1;
  static const long ID_STATICTEXT2;
  static const long ID_STATICTEXT5;
  static const long ID_BITMAPBUTTON3;
  static const long ID_STATICLINE1;
  static const long ID_STATICLINE2;
  static const long ID_TEXTCTRL3;
  static const long ID_TEXTCTRL1;
  static const long ID_CHECKBOX1;
  static const long ID_PANEL1;
  //*)

private:

  wxString msg;
  void exec(void);

  //(*Handlers(execcmb)
  void OnopenoutfileClick(wxCommandEvent & event);
  void OnopencfgfileClick(wxCommandEvent & event);
  void OnBitmapButton2Click(wxCommandEvent & event);
  void OnCheckBox1Click(wxCommandEvent & event);
  void OnopennewrefClick(wxCommandEvent & event);
  void OnopennewcompClick(wxCommandEvent & event);
  //*)

DECLARE_EVENT_TABLE()};

#endif
