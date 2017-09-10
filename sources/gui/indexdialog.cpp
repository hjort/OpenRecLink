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
// Nome:        indexdialog.cpp
// Propósito:   Classe (janela) para criar/abrir índices
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "indexdialog.h"

//(*InternalHeaders(indexdialog)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

#include "ntable.h"

//(*IdInit(indexdialog)
const long
  indexdialog::ID_STATICTEXT1 = wxNewId();
const long
  indexdialog::ID_TEXTCTRL1 = wxNewId();
const long
  indexdialog::ID_BITMAPBUTTON1 = wxNewId();
const long
  indexdialog::ID_STATICTEXT2 = wxNewId();
const long
  indexdialog::ID_TEXTCTRL2 = wxNewId();
const long
  indexdialog::ID_OK = wxNewId();
//*)

BEGIN_EVENT_TABLE(indexdialog, wxDialog)
  //(*EventTable(indexdialog)
  //*)
  END_EVENT_TABLE()indexdialog::indexdialog(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					    const wxSize & size)
{
  //(*Initialize(indexdialog)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, id, _("Cria/abre arquivo de índice"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(2, 3, 0, 0);
  StaticText1 =
    new wxStaticText(this, ID_STATICTEXT1, _("Nome do arquivo:"), wxDefaultPosition, wxDefaultSize,
		     0, _T("ID_STATICTEXT1"));
  FlexGridSizer1->Add(StaticText1, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  filecontrol =
    new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(393, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL1"));
  FlexGridSizer1->Add(filecontrol, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  openfile =
    new wxBitmapButton(this, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  openfile->SetToolTip(_("Seleciona arquivo"));
  FlexGridSizer1->Add(openfile, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  StaticText2 =
    new wxStaticText(this, ID_STATICTEXT2, _("Campos:"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT2"));
  FlexGridSizer1->Add(StaticText2, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  varcontrol =
    new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(219, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL2"));
  FlexGridSizer1->Add(varcontrol, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  okbtn =
    new wxBitmapButton(this, ID_OK,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_OK"));
  okbtn->SetToolTip(_("OK"));
  FlexGridSizer1->Add(okbtn, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr,
		     wxFD_DEFAULT_STYLE | wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition,
		     wxDefaultSize, _T("wxFileDialog"));
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & indexdialog::OnopenfileClick);
  Connect(ID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & indexdialog::OnokbtnClick);
  //*)
}

indexdialog::~indexdialog()
{
  //(*Destroy(indexdialog)
  //*)
}

void
indexdialog::OnopenfileClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defixext());
  FileDialog1->SetMessage(_("Selecione o arquivo de índice"));
  //FileDialog1->SetStyle(wxFD_SAVE);
  if (FileDialog1->ShowModal() == wxID_OK)
    filecontrol->SetValue(FileDialog1->GetPath());
}

void
indexdialog::OnokbtnClick(wxCommandEvent & event)
{
  EndModal(wxID_OK);
}
