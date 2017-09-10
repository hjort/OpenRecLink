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
// Nome:        langdlg.cpp
// Propósito:   Classe (janela) para configurar língua default
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "langdlg.h"

//(*InternalHeaders(langdlg)
#include <wx/button.h>
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(langdlg)
const long
  langdlg::ID_RADIOBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(langdlg, wxDialog)
  //(*EventTable(langdlg)
  //*)
  END_EVENT_TABLE()langdlg::langdlg(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(langdlg)
  wxFlexGridSizer *
    FlexGridSizer1;
  wxStdDialogButtonSizer *
    StdDialogButtonSizer1;

  Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE,
	 _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
  wxString __wxRadioBoxChoices_1[2] =
  {
  _("English"), _("Portugues")};
  RadioBox1 =
    new wxRadioBox(this, ID_RADIOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2,
		   __wxRadioBoxChoices_1, 0, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
  FlexGridSizer1->Add(RadioBox1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
  StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, wxEmptyString));
  StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
  StdDialogButtonSizer1->Realize();
  FlexGridSizer1->Add(StdDialogButtonSizer1, 1,
		      wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);
  //*)
}

langdlg::~langdlg()
{
  //(*Destroy(langdlg)
  //*)
}
