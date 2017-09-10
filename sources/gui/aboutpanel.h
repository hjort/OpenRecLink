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
// Nome:        aboutpanel.h
// Propósito:   Classe (janela) para mostrar versão do programa
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////


#ifndef ABOUTPANEL_H
#define ABOUTPANEL_H

//(*Headers(aboutpanel)
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)

class aboutpanel:public wxPanel
{
public:

  aboutpanel(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	     wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ aboutpanel();

  //(*Declarations(aboutpanel)
  wxStaticText *wxversion;
  wxStaticText *version;
  wxTimer Timer1;
  wxStaticLine *StaticLine1;
  wxStaticText *program;
  //*)

protected:

  //(*Identifiers(aboutpanel)
  static const long ID_STATICTEXT1;
  static const long ID_STATICLINE1;
  static const long ID_STATICTEXT2;
  static const long ID_STATICTEXT3;
  static const long ID_TIMER1;
  //*)

private:

  //(*Handlers(aboutpanel)
  void OnTimer1Trigger(wxTimerEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
