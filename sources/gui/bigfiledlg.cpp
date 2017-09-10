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
// Nome:        bigfile.cpp
// Propósito:   Classe (janela) para informar sobre arquivos muito grandes
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////


#include "bigfiledlg.h"

//(*InternalHeaders(bigfiledlg)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(bigfiledlg)
const long
  bigfiledlg::ID_STATICTEXT1 = wxNewId();
const long
  bigfiledlg::ID_STATICTEXT2 = wxNewId();
const long
  bigfiledlg::ID_STATICTEXT3 = wxNewId();
const long
  bigfiledlg::ID_TEXTCTRL1 = wxNewId();
const long
  bigfiledlg::ID_BITMAPBUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(bigfiledlg, wxDialog)
  //(*EventTable(bigfiledlg)
  //*)
  END_EVENT_TABLE()bigfiledlg::bigfiledlg(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					  const wxSize & size)
{
  //(*Initialize(bigfiledlg)
  wxFlexGridSizer *
    FlexGridSizer1;
  wxFlexGridSizer *
    FlexGridSizer2;

  Create(parent, id, _("ARQUIVO MUTO EXTENSO"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
  StaticText1 =
    new wxStaticText(this, ID_STATICTEXT1, _("Este arquivo tem NNNNNN registros."),
		     wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  FlexGridSizer1->Add(StaticText1, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  StaticText2 =
    new wxStaticText(this, ID_STATICTEXT2, _("Não é possível exibi-los todos."),
		     wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  FlexGridSizer1->Add(StaticText2, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
  StaticText3 =
    new wxStaticText(this, ID_STATICTEXT3, _("Selecione o registro inicial:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  FlexGridSizer2->Add(StaticText3, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  TextCtrl1 =
    new wxTextCtrl(this, ID_TEXTCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT,
		   wxDefaultValidator, _T("ID_TEXTCTRL1"));
  FlexGridSizer2->Add(TextCtrl1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  BitmapButton1 =
    new wxBitmapButton(this, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  BitmapButton1->SetDefault();
  FlexGridSizer2->Add(BitmapButton1, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer2, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & bigfiledlg::OnBitmapButton1Click);
  //*)
}

bigfiledlg::~bigfiledlg()
{
  //(*Destroy(bigfiledlg)
  //*)
}


void
bigfiledlg::OnBitmapButton1Click(wxCommandEvent & event)
{
  EndModal(wxOK);
}
