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
// Nome:        progressdialog.h
// Propósito:   Classe (janela) para informar programa ocupado
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "progressdialog.h"

//(*InternalHeaders(progressdialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(progressdialog)
const long
  progressdialog::ID_STATICTEXT1 = wxNewId();

//*)
  BEGIN_EVENT_TABLE(progressdialog, wxDialog)
  //(*EventTable(progressdialog)
  //*)
  END_EVENT_TABLE()progressdialog::progressdialog(wxWindow * parent, wxWindowID id,
						  const wxPoint & pos, const wxSize & size)
{
  //(*Initialize(progressdialog)
  wxBoxSizer *
    BoxSizer1;
   Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxRAISED_BORDER, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  msglabel =
    new wxStaticText(this, ID_STATICTEXT1, _("Indexando, aguarde..."), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer1->Add(msglabel, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(BoxSizer1);
  BoxSizer1->Fit(this);
  BoxSizer1->SetSizeHints(this);
   Connect(wxEVT_SET_FOCUS, (wxObjectEventFunction) & progressdialog::OnSetFocus);
  Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction) & progressdialog::OnKillFocus);
  
    //*)
}

progressdialog::~progressdialog()
{
  //(*Destroy(progressdialog)
  //*)
}

void
progressdialog::OnSetFocus(wxFocusEvent & event)
{
  wxBeginBusyCursor();
  wxYieldIfNeeded();
}

void
progressdialog::OnKillFocus(wxFocusEvent & event)
{
  wxEndBusyCursor();
  wxYieldIfNeeded();
}
