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
// Nome:        runcalc.cpp
// Propósito:   Classe (janela) para executar cálculo de parâmetros de linkagem
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef RUNCALC_H
#define RUNCALC_H

//(*Headers(runcalc)
#include <wx/stopwatch.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class runcalc:public wxDialog
{
public:

  runcalc(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ runcalc();

  //(*Declarations(runcalc)
  wxTextCtrl *textout;
   wxTextCtrl * falsopos;
   wxTextCtrl * p_ini;
   wxTextCtrl * falsoneg;
   wxBitmapButton * gobtn;
   wxStaticText * StaticText1;
   wxStaticText * StaticText3;
   wxTextCtrl * m_ini;
   wxTextCtrl * maxiterctrl;
   wxStaticText * StaticText8;
   wxFileDialog * FileDialog1;
   wxTextCtrl * epsilonctrl;
   wxStaticText * StaticText7;
   wxStaticText * StaticText4;
   wxStaticText * StaticText5;
   wxStaticText * StaticText2;
   wxStopWatch StopWatch1;
   wxStaticText * StaticText6;
   wxTextCtrl * u_ini;
   wxBitmapButton * opencfg;
   wxTextCtrl * cfgnamectrl;
   wxBitmapButton * closebtn;
   
    //*)
protected:

  //(*Identifiers(runcalc)
  static const long ID_STATICTEXT1;
   static const long ID_TEXTCTRL1;
   static const long ID_BITMAPBUTTON1;
   static const long ID_STATICTEXT2;
   static const long ID_TEXTCTRL3;
   static const long ID_STATICTEXT3;
   static const long ID_TEXTCTRL4;
   static const long ID_STATICTEXT4;
   static const long ID_TEXTCTRL5;
   static const long ID_STATICTEXT5;
   static const long ID_TEXTCTRL6;
   static const long ID_STATICTEXT6;
   static const long ID_TEXTCTRL7;
   static const long ID_STATICTEXT7;
   static const long ID_TEXTCTRL8;
   static const long ID_STATICTEXT8;
   static const long ID_TEXTCTRL9;
   static const long ID_TEXTCTRL2;
   static const long ID_BITMAPBUTTON2;
   static const long ID_BITMAPBUTTON3;
   
    //*)
private:

    wxArrayString m_estimates;
  wxArrayString u_estimates;
  void parest(void);
  void replace_values(void);

  //(*Handlers(runcalc)
  void OnopencfgClick(wxCommandEvent & event);
  void OnclosebtnClick(wxCommandEvent & event);
  void OngobtnClick(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
