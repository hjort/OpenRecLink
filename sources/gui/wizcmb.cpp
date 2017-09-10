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
// Nome:        wizcmb.cpp
// Propósito:   Classe (janela) para configurar combinação
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "wizcmb.h"

//(*InternalHeaders(wizcmb)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/tglbtn.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(wizcmb)
const long
  wizcmb::ID_STATICTEXT1 = wxNewId();
const long
  wizcmb::ID_PANEL3 = wxNewId();
const long
  wizcmb::ID_PANEL2 = wxNewId();
const long
  wizcmb::ID_LISTBOOK1 = wxNewId();
const long
  wizcmb::ID_BUTTON1 = wxNewId();
const long
  wizcmb::ID_BUTTON2 = wxNewId();
const long
  wizcmb::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wizcmb, wxDialog)
  //(*EventTable(wizcmb)
  //*)
  END_EVENT_TABLE()wizcmb::wizcmb(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				  const wxSize & size)
{
  //(*Initialize(wizcmb)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, id, _("Assistente"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE,
	 _T("id"));
  SetClientSize(wxSize(523, 349));
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  Panel3 =
    new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxSize(523, 23), wxTAB_TRAVERSAL,
		_T("ID_PANEL3"));
  StaticText1 =
    new wxStaticText(Panel3, ID_STATICTEXT1, _("Combina"), wxPoint(16, 8), wxDefaultSize, 0,
		     _T("ID_STATICTEXT1"));
  wxFont
    StaticText1Font(14, wxSWISS, wxFONTSTYLE_NORMAL, wxBOLD, false, _T("Sans"),
		    wxFONTENCODING_DEFAULT);
  StaticText1->SetFont(StaticText1Font);
  FlexGridSizer1->Add(Panel3, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  Listbook1 =
    new wxNotebook(this, ID_LISTBOOK1, wxDefaultPosition, wxSize(523, 276), 0, _T("ID_LISTBOOK1"));
  Panel2 =
    new wxPanel(Listbook1, ID_PANEL2, wxPoint(56, 8), wxSize(523, 260), wxTAB_TRAVERSAL,
		_T("ID_PANEL2"));
  Listbook1->AddPage(Panel2, _("Passo 1"), false);
  FlexGridSizer1->Add(Listbook1, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(523, 47), wxTAB_TRAVERSAL,
		_T("ID_PANEL1"));
  backbtn =
    new wxCustomButton(Panel1, ID_BUTTON1, _("Volta"),
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),
						wxART_MAKE_CLIENT_ID_FROM_STR(wxString
									      (wxEmptyString))),
		       wxPoint(368, 8), wxDefaultSize,
		       wxCUSTBUT_BUTTON | wxCUSTBUT_RIGHT | wxCUSTBUT_FLAT, wxDefaultValidator,
		       _T("ID_BUTTON1"));
  backbtn->SetBitmapDisabled(backbtn->CreateBitmapDisabled(backbtn->GetBitmapLabel()));
  fwdbtn =
    new wxCustomButton(Panel1, ID_BUTTON2, _("Segue"),
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),
						wxART_MAKE_CLIENT_ID_FROM_STR(wxString
									      (wxEmptyString))),
		       wxPoint(448, 8), wxDefaultSize,
		       wxCUSTBUT_BUTTON | wxCUSTBUT_LEFT | wxCUSTBUT_FLAT, wxDefaultValidator,
		       _T("ID_BUTTON2"));
  fwdbtn->SetBitmapDisabled(fwdbtn->CreateBitmapDisabled(fwdbtn->GetBitmapLabel()));
  FlexGridSizer1->Add(Panel1, 1,
		      wxBOTTOM | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FlexGridSizer1->SetSizeHints(this);
  //*)
}

wizcmb::~wizcmb()
{
  //(*Destroy(wizcmb)
  //*)
}
