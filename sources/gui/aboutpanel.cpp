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
// Nome:        aboutpanel.cpp
// Propósito:   Classe (janela) para mostrar versão do programa
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "aboutpanel.h"

#include "version.h"

//(*InternalHeaders(aboutpanel)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//(*IdInit(aboutpanel)
const long
  aboutpanel::ID_STATICTEXT1 = wxNewId();
const long
  aboutpanel::ID_STATICLINE1 = wxNewId();
const long
  aboutpanel::ID_STATICTEXT2 = wxNewId();
const long
  aboutpanel::ID_STATICTEXT3 = wxNewId();
const long
  aboutpanel::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(aboutpanel, wxPanel)
  //(*EventTable(aboutpanel)
  //*)
  END_EVENT_TABLE()aboutpanel::aboutpanel(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					  const wxSize & size)
{
  int
    x = pos.x;
  int
    y = pos.y;
  //(*Initialize(aboutpanel)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, id, wxPoint(-1, -1), wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
  SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOTEXT));
  SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
  FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
  program =
    new wxStaticText(this, ID_STATICTEXT1, _T("Label"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT1"));
  wxFont
    programFont(18, wxSWISS, wxFONTSTYLE_NORMAL, wxBOLD, false, _T("Sans"), wxFONTENCODING_DEFAULT);
  program->SetFont(programFont);
  FlexGridSizer1->Add(program, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  StaticLine1 =
    new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(260, 3), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE1"));
  FlexGridSizer1->Add(StaticLine1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  version =
    new wxStaticText(this, ID_STATICTEXT2, _T("Label"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT2"));
  FlexGridSizer1->Add(version, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  wxversion =
    new wxStaticText(this, ID_STATICTEXT3, _T("Label"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT3"));
  FlexGridSizer1->Add(wxversion, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  Timer1.SetOwner(this, ID_TIMER1);
  Timer1.Start(5000, true);
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(ID_TIMER1, wxEVT_TIMER, (wxObjectEventFunction) & aboutpanel::OnTimer1Trigger);
  //*)

  wxString wxbuild(wxVERSION_STRING);
#if defined(__WXMSW__)
  wxbuild << _T("-Windows");
#elif defined(__UNIX__)
  wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
  wxbuild << _T("-Unicode");
#else
  wxbuild << _T("-ANSI");
#endif

  wxString year = wxString(AutoVersion::YEAR, wxConvUTF8);
  wxString month = wxString(AutoVersion::MONTH, wxConvUTF8);
  wxString day = wxString(AutoVersion::DATE, wxConvUTF8);
  wxString status = wxString(AutoVersion::STATUS, wxConvUTF8);
  wxString fullversion = wxString(AutoVersion::FULLVERSION_STRING, wxConvUTF8);

  wxString
    msg =
    _("Versão ") + fullversion + _T(" ") + status + _T(" (") + year + _T(".") + month + _T(".") +
    day + _T(")");
  program->SetLabel(_T("OpenRecLink"));
  version->SetLabel(msg);
  wxversion->SetLabel(wxbuild);
  wxRect trect = GetSize();
  x -= trect.width;
  y -= trect.height;
  wxPoint pt(x, y);
  SetPosition(pt);
}

aboutpanel::~aboutpanel()
{
  //(*Destroy(aboutpanel)
  //*)
}


void
aboutpanel::OnTimer1Trigger(wxTimerEvent & event)
{
  Destroy();
}
