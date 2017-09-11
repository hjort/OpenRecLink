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
// Nome:        inspect.cpp
// Propósito:   Classe (janela) para inspecionar arquivo de pares
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "inspect.h"

#include "progressdialog.h"
#include "ops_log.h"
//#include "findex.cpp"

#include "checksep.h"

//RH #include <wx/notifmsg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>
#include <wx/tipwin.h>

//(*InternalHeaders(inspect)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)


//(*IdInit(inspect)
const long
  inspect::ID_STATICTEXT1 = wxNewId();
const long
  inspect::ID_TEXTCTRL1 = wxNewId();
const long
  inspect::ID_BITMAPBUTTON1 = wxNewId();
const long
  inspect::ID_BITMAPBUTTON2 = wxNewId();
const long
  inspect::ID_BITMAPBUTTON3 = wxNewId();
const long
  inspect::ID_STATICTEXT2 = wxNewId();
const long
  inspect::ID_GRID1 = wxNewId();
const long
  inspect::ID_STATICTEXT3 = wxNewId();
const long
  inspect::ID_GRID2 = wxNewId();
const long
  inspect::ID_BITMAPBUTTON4 = wxNewId();
const long
  inspect::ID_BITMAPBUTTON5 = wxNewId();
const long
  inspect::ID_STATICTEXT7 = wxNewId();
const long
  inspect::ID_STATICTEXT8 = wxNewId();
const long
  inspect::ID_RADIOBOX1 = wxNewId();
const long
  inspect::ID_STATICTEXT9 = wxNewId();
const long
  inspect::ID_TEXTCTRL2 = wxNewId();
const long
  inspect::ID_STATICTEXT10 = wxNewId();
const long
  inspect::ID_TEXTCTRL3 = wxNewId();
const long
  inspect::ID_BUTTON5 = wxNewId();
const long
  inspect::ID_BUTTON6 = wxNewId();
const long
  inspect::ID_GRID3 = wxNewId();
const long
  inspect::ID_GAUGE1 = wxNewId();
const long
  inspect::ID_BUTTON4 = wxNewId();
const long
  inspect::ID_BUTTON3 = wxNewId();
const long
  inspect::ID_BUTTON2 = wxNewId();
const long
  inspect::ID_BUTTON1 = wxNewId();
const long
  inspect::ID_STATICTEXT4 = wxNewId();
const long
  inspect::ID_SPINCTRL1 = wxNewId();
const long
  inspect::ID_OK = wxNewId();
const long
  inspect::ID_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(inspect, wxDialog)
  //(*EventTable(inspect)
  //*)
  END_EVENT_TABLE()inspect::inspect(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(inspect)
  wxFlexGridSizer *
    FlexGridSizer8;
  wxFlexGridSizer *
    FlexGridSizer1;
  wxFlexGridSizer *
    FlexGridSizer2;
  wxFlexGridSizer *
    FlexGridSizer15;
  wxFlexGridSizer *
    FlexGridSizer17;
  wxFlexGridSizer *
    FlexGridSizer11;
  wxFlexGridSizer *
    FlexGridSizer7;
  wxFlexGridSizer *
    FlexGridSizer4;
  wxFlexGridSizer *
    FlexGridSizer9;
  wxFlexGridSizer *
    FlexGridSizer14;
  wxFlexGridSizer *
    FlexGridSizer6;
  wxFlexGridSizer *
    FlexGridSizer3;
  wxFlexGridSizer *
    FlexGridSizer16;
  wxFlexGridSizer *
    FlexGridSizer10;
  wxFlexGridSizer *
    FlexGridSizer13;
  wxFlexGridSizer *
    FlexGridSizer12;
  wxFlexGridSizer *
    FlexGridSizer5;

  Create(parent, wxID_ANY, _("Inspeciona pares"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
  FlexGridSizer2 = new wxFlexGridSizer(1, 3, 0, 0);
  StaticText1 =
    new wxStaticText(this, ID_STATICTEXT1, _("Config. do relacionamento"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  FlexGridSizer2->Add(StaticText1, 1, wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  cfgfilectrl =
    new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(438, 36),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  FlexGridSizer2->Add(cfgfilectrl, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  opencfgfile =
    new wxBitmapButton(this, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  opencfgfile->SetDefault();
  opencfgfile->SetToolTip(_("Abre o arquivo"));
  FlexGridSizer2->Add(opencfgfile, 1, wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  FlexGridSizer1->Add(FlexGridSizer2, 1,
		      wxTOP | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3 = new wxFlexGridSizer(1, 4, 0, 0);
  FlexGridSizer4 = new wxFlexGridSizer(3, 1, 0, 0);
  FlexGridSizer4->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  refup =
    new wxBitmapButton(this, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  refup->SetToolTip(_("Sobe campo"));
  FlexGridSizer4->Add(refup, 1,
		      wxTOP | wxBOTTOM | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  refdown =
    new wxBitmapButton(this, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
  refdown->SetToolTip(_("Desce campo"));
  FlexGridSizer4->Add(refdown, 1, wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3->Add(FlexGridSizer4, 1, wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL, 5);
  FlexGridSizer5 = new wxFlexGridSizer(2, 1, 0, 0);
  StaticText2 =
    new wxStaticText(this, ID_STATICTEXT2, _("Referência (lido integralmente)"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  FlexGridSizer5->Add(StaticText2, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
  refgrid = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(293, 199), 0, _T("ID_GRID1"));
  refgrid->CreateGrid(10, 1);
  refgrid->EnableEditing(false);
  refgrid->EnableGridLines(true);
  refgrid->SetColLabelSize(20);
  refgrid->SetRowLabelSize(70);
  refgrid->SetDefaultColSize(200, true);
  refgrid->SetColLabelValue(0, _("Valor"));
  refgrid->SetRowLabelValue(0, _("..."));
  refgrid->SetRowLabelValue(1, _("..."));
  refgrid->SetRowLabelValue(2, _("..."));
  refgrid->SetRowLabelValue(3, _("..."));
  refgrid->SetRowLabelValue(4, _("..."));
  refgrid->SetRowLabelValue(5, _("..."));
  refgrid->SetRowLabelValue(6, _("..."));
  refgrid->SetRowLabelValue(7, _("..."));
  refgrid->SetRowLabelValue(8, _("..."));
  refgrid->SetRowLabelValue(9, _("..."));
  refgrid->SetDefaultCellFont(refgrid->GetFont());
  refgrid->SetDefaultCellTextColour(refgrid->GetForegroundColour());
  FlexGridSizer5->Add(refgrid, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3->Add(FlexGridSizer5, 1,
		      wxBOTTOM | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer6 = new wxFlexGridSizer(2, 1, 0, 0);
  StaticText3 =
    new wxStaticText(this, ID_STATICTEXT3, _("Comparação (lido em  blocos)"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  FlexGridSizer6->Add(StaticText3, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
  compgrid = new wxGrid(this, ID_GRID2, wxDefaultPosition, wxSize(293, 199), 0, _T("ID_GRID2"));
  compgrid->CreateGrid(10, 1);
  compgrid->EnableEditing(false);
  compgrid->EnableGridLines(true);
  compgrid->SetColLabelSize(20);
  compgrid->SetRowLabelSize(70);
  compgrid->SetDefaultColSize(200, true);
  compgrid->SetColLabelValue(0, _("Valor"));
  compgrid->SetRowLabelValue(0, _("..."));
  compgrid->SetRowLabelValue(1, _("..."));
  compgrid->SetRowLabelValue(2, _("..."));
  compgrid->SetRowLabelValue(3, _("..."));
  compgrid->SetRowLabelValue(4, _("..."));
  compgrid->SetRowLabelValue(5, _("..."));
  compgrid->SetRowLabelValue(6, _("..."));
  compgrid->SetRowLabelValue(7, _("..."));
  compgrid->SetRowLabelValue(8, _("..."));
  compgrid->SetRowLabelValue(9, _("..."));
  compgrid->SetDefaultCellFont(compgrid->GetFont());
  compgrid->SetDefaultCellTextColour(compgrid->GetForegroundColour());
  FlexGridSizer6->Add(compgrid, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3->Add(FlexGridSizer6, 1,
		      wxBOTTOM | wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer7 = new wxFlexGridSizer(3, 1, 0, 0);
  FlexGridSizer7->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  compup =
    new wxBitmapButton(this, ID_BITMAPBUTTON4,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
  compup->SetToolTip(_("Sobe campo"));
  FlexGridSizer7->Add(compup, 1,
		      wxTOP | wxBOTTOM | wxLEFT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  compdown =
    new wxBitmapButton(this, ID_BITMAPBUTTON5,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
  compdown->SetToolTip(_("Desce campo"));
  FlexGridSizer7->Add(compdown, 1, wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3->Add(FlexGridSizer7, 1, wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL, 5);
  FlexGridSizer1->Add(FlexGridSizer3, 0, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 0);
  FlexGridSizer8 = new wxFlexGridSizer(1, 6, 0, 0);
  StaticText5 =
    new wxStaticText(this, ID_STATICTEXT7, _("Score do par:"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT7"));
  FlexGridSizer8->Add(StaticText5, 1, wxLEFT | wxRIGHT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  scorelbl =
    new wxStaticText(this, ID_STATICTEXT8, _("0"), wxDefaultPosition, wxSize(123, 17),
		     wxALIGN_RIGHT, _T("ID_STATICTEXT8"));
  FlexGridSizer8->Add(scorelbl, 1, wxLEFT | wxRIGHT | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer8, 1,
		      wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer9 = new wxFlexGridSizer(1, 4, 0, 0);
  FlexGridSizer10 = new wxFlexGridSizer(3, 1, 0, 0);
  wxString __wxRadioBoxChoices_1[4] =
  {
  _("Par"), _("Dúvida"), _("Não par"), _("Ignorado")};
  pairstatus =
    new wxRadioBox(this, ID_RADIOBOX1, _("Status"), wxDefaultPosition, wxDefaultSize, 4,
		   __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxDefaultValidator,
		   _T("ID_RADIOBOX1"));
  pairstatus->SetSelection(3);
  FlexGridSizer10->Add(pairstatus, 1,
		       wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer9->Add(FlexGridSizer10, 1, wxRIGHT | wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL, 5);
  FlexGridSizer11 = new wxFlexGridSizer(6, 1, 0, 0);
  StaticText6 =
    new wxStaticText(this, ID_STATICTEXT9, _("Score + min:"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT9"));
  FlexGridSizer11->Add(StaticText6, 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  scoremmin =
    new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT,
		   wxDefaultValidator, _T("ID_TEXTCTRL2"));
  FlexGridSizer11->Add(scoremmin, 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  StaticText7 =
    new wxStaticText(this, ID_STATICTEXT10, _("Score - máx:"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT10"));
  FlexGridSizer11->Add(StaticText7, 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  scorenmax =
    new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT,
		   wxDefaultValidator, _T("ID_TEXTCTRL3"));
  FlexGridSizer11->Add(scorenmax, 1, wxBOTTOM | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer11->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer11->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer11->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer11->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  markall =
    new wxButton(this, ID_BUTTON5, _("Marca todos"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON5"));
  FlexGridSizer11->Add(markall, 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  clearall =
    new wxButton(this, ID_BUTTON6, _("Limpa todos"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON6"));
  FlexGridSizer11->Add(clearall, 1, wxTOP | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer11->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer9->Add(FlexGridSizer11, 1,
		      wxLEFT | wxRIGHT | wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL, 5);
  FlexGridSizer12 = new wxFlexGridSizer(0, 3, 0, 0);
  valuesgrid = new wxGrid(this, ID_GRID3, wxDefaultPosition, wxSize(244, 230), 0, _T("ID_GRID3"));
  valuesgrid->CreateGrid(1, 1);
  valuesgrid->EnableEditing(false);
  valuesgrid->EnableGridLines(true);
  valuesgrid->SetColLabelSize(20);
  valuesgrid->SetRowLabelSize(140);
  valuesgrid->SetDefaultRowSize(20, true);
  valuesgrid->SetDefaultColSize(80, true);
  valuesgrid->SetColLabelValue(0, _("Freq."));
  valuesgrid->SetRowLabelValue(0, _("..."));
  valuesgrid->SetDefaultCellFont(valuesgrid->GetFont());
  valuesgrid->SetDefaultCellTextColour(valuesgrid->GetForegroundColour());
  FlexGridSizer12->Add(valuesgrid, 1, wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL, 5);
  FlexGridSizer9->Add(FlexGridSizer12, 1,
		      wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer13 = new wxFlexGridSizer(3, 1, 0, 0);
  FlexGridSizer14 = new wxFlexGridSizer(1, 3, 0, 0);
  Gauge1 =
    new wxGauge(this, ID_GAUGE1, 100, wxDefaultPosition, wxSize(28, 203), wxGA_VERTICAL,
		wxDefaultValidator, _T("ID_GAUGE1"));
  FlexGridSizer14->Add(Gauge1, 1, wxTOP | wxRIGHT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer15 = new wxFlexGridSizer(5, 1, 0, 0);
  golast =
    new wxButton(this, ID_BUTTON4, _("Fim"), wxDefaultPosition, wxSize(60, 28), 0,
		 wxDefaultValidator, _T("ID_BUTTON4"));
  FlexGridSizer15->Add(golast, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer15->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer15->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  goforward =
    new wxButton(this, ID_BUTTON3, _("Avança\n"), wxDefaultPosition, wxSize(60, 28), 0,
		 wxDefaultValidator, _T("ID_BUTTON3"));
  FlexGridSizer15->Add(goforward, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  goback =
    new wxButton(this, ID_BUTTON2, _("Volta"), wxDefaultPosition, wxSize(60, 28), 0,
		 wxDefaultValidator, _T("ID_BUTTON2"));
  FlexGridSizer15->Add(goback, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer15->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer15->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  gofirst =
    new wxButton(this, ID_BUTTON1, _("Início"), wxDefaultPosition, wxSize(60, 28), 0,
		 wxDefaultValidator, _T("ID_BUTTON1"));
  FlexGridSizer15->Add(gofirst, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer14->Add(FlexGridSizer15, 1,
		       wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer17 = new wxFlexGridSizer(2, 1, 0, 0);
  StaticText4 =
    new wxStaticText(this, ID_STATICTEXT4, _("Passo:"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT4"));
  FlexGridSizer17->Add(StaticText4, 1, wxBOTTOM | wxRIGHT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL,
		       5);
  stepctrl =
    new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxSize(64, 27), 0, 1, 10, 0,
		   _T("ID_SPINCTRL1"));
  stepctrl->SetValue(_T("0"));
  FlexGridSizer17->Add(stepctrl, 1,
		       wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer14->Add(FlexGridSizer17, 1,
		       wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer13->Add(FlexGridSizer14, 1, wxTOP | wxLEFT | wxRIGHT | wxALIGN_LEFT | wxALIGN_TOP,
		       5);
  FlexGridSizer16 = new wxFlexGridSizer(1, 4, 0, 0);
  okbtn =
    new wxBitmapButton(this, ID_OK,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),
						wxART_BUTTON), wxDefaultPosition, wxSize(32, 32),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_OK"));
  okbtn->SetToolTip(_("OK"));
  FlexGridSizer16->Add(okbtn, 1, wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer16->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer16->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  cancelbtn =
    new wxBitmapButton(this, ID_CANCEL,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CROSS_MARK")),
						wxART_BUTTON), wxDefaultPosition, wxSize(32, 32),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_CANCEL"));
  cancelbtn->SetToolTip(_("Cancela"));
  FlexGridSizer16->Add(cancelbtn, 1, wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		       5);
  FlexGridSizer13->Add(FlexGridSizer16, 1, wxTOP | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer9->Add(FlexGridSizer13, 1,
		      wxBOTTOM | wxLEFT | wxRIGHT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer9, 1,
		      wxBOTTOM | wxRIGHT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Selecione o arquivo de configuração"), wxEmptyString, wxEmptyString,
		     _("*.lnkcfg"), wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST,
		     wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OnrefupClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OnrefdownClick);
  Connect(ID_GRID1, wxEVT_GRID_SELECT_CELL, (wxObjectEventFunction) & inspect::OnrefgridCellSelect);
  Connect(ID_GRID2, wxEVT_GRID_SELECT_CELL,
	  (wxObjectEventFunction) & inspect::OncompgridCellSelect);
  Connect(ID_BITMAPBUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OncompupClick);
  Connect(ID_BITMAPBUTTON5, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OncompdownClick);
  Connect(ID_RADIOBOX1, wxEVT_COMMAND_RADIOBOX_SELECTED,
	  (wxObjectEventFunction) & inspect::OnpairstatusSelect);
  Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OnmarkallClick);
  Connect(ID_BUTTON6, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OnclearallClick);
  Connect(ID_GRID3, wxEVT_GRID_CELL_LEFT_CLICK,
	  (wxObjectEventFunction) & inspect::OnvaluesgridCellSelect);
  Connect(ID_GRID3, wxEVT_GRID_LABEL_LEFT_CLICK,
	  (wxObjectEventFunction) & inspect::OnvaluesgridCellSelect);
  Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OngolastClick);
  Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OngoforwardClick);
  Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OngobackClick);
  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OngofirstClick);
  Connect(ID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & inspect::OnokbtnClick);
  Connect(ID_CANCEL, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & inspect::OncancelbtnClick);
  //*)
}

inspect::~inspect()
{
  //(*Destroy(inspect)
  //*)
}

/*
class scoredata
{
public:
    wxChar score;
    int    freq;
};

int compare_scores(class scoredata o1, class scoredata o2)
{
    double s1, s2;
    o1.score.ToDouble(&s1);
    o2.score.ToDouble(&s2);
    return (s1 < s2);
};

WX_DECLARE_OBJECT_ARRAY(scoredata, scoredatatbl);
WX_DEFINE_OBJECT_ARRAY(scoredatatbl);
*/

void
inspect::initialize(void)
{
  wxBeginBusyCursor();
  wxString cfgfilename;

  if (FileDialog1->ShowModal() == wxID_OK)
    cfgfilename = FileDialog1->GetPath();
  else
    cfgfilename = _T("");

  if (!wxIsEmpty(cfgfilename) && wxFileExists(cfgfilename))
  {
    read = true;
    cfgfilectrl->SetValue(cfgfilename);
    wxYield();

    if (comp.isopen())
      comp.close();
    if (ref.isopen())
      ref.close();
    if (score.isopen())
      score.close();

    wxFileConfig *cfgfile =
      new wxFileConfig(_T(""), _T(""), cfgfilename, _T(""), wxCONFIG_USE_LOCAL_FILE);
    wxString aux = _T("");
    cfgfile->Read(_T("FILES/COMPNAME"), &aux);
    if (wxFileExists(aux))
      read &= comp.open(aux);
    else
      read = false;

    aux = _T("");
    cfgfile->Read(_T("FILES/REFNAME"), &aux);
    if (wxFileExists(aux))
      read &= ref.open(aux);
    else
      read = false;

    delete cfgfile;

    relrec = -1L;

    if (read)
    {
      int nlines = comp.getnumfields();
      int glines = compgrid->GetNumberRows();
      if (glines > (int) nlines)
      {
	glines -= (int) nlines;
	compgrid->DeleteRows(0, glines);
      }
      else if (glines < (int) nlines)
      {
	glines = (int) nlines - glines;
	compgrid->AppendRows(glines);
      }
      for (int i = 0; i < nlines; i++)
	compgrid->SetRowLabelValue(i, comp.getfieldname(i));
      nlines = ref.getnumfields();
      glines = refgrid->GetNumberRows();
      if (glines > (int) nlines)
      {
	glines -= (int) nlines;
	refgrid->DeleteRows(0, glines);
      }
      else if (glines < (int) nlines)
      {
	glines = (int) nlines - glines;
	refgrid->AppendRows(glines);
      }
      for (int i = 0; i < nlines; i++)
	refgrid->SetRowLabelValue(i, ref.getfieldname(i));
    }

    wxFileName matchfile = wxFileName(cfgfilename);
    ntable t;
    matchfile.SetExt(t.defdbext().Right(3));
    wxString name = matchfile.GetName();
    name = name + _T("SCORE");
    matchfile.SetName(name);
    aux = matchfile.GetFullPath();

    if (wxFileExists(aux))
      read &= score.open(aux);

    wxString timestring = _("");
    bool forceredo = false;

    if (read)
    {
      matchfile.SetExt(t.defixext().Right(3));
      aux = matchfile.GetFullPath();
      bool this_file_exists = wxFileExists(aux);
      if (this_file_exists)
	this_file_exists =
	  (wxMessageBox
	   (_
	    ("Já existe um arquivo de índice\nassociado a esta configuração.\nDevo utilizá-lo?"),
	    _("ATENÇÃO"), wxYES_NO | wxICON_QUESTION) == wxYES);
      if (!this_file_exists)
      {
	forceredo = true;
	wxArrayString ixflds;
	ixflds.Clear();
	ixflds.Add(_T("SCORE"));
	progressdialog *dlg = new progressdialog(this);
	dlg->msglabel->SetLabel(_T("Indexando..."));
	dlg->Show();
	dlg->Update();
	wxYieldIfNeeded();
	//StopWatch1.Start();
	if (wxFileExists(aux))
	  wxRemoveFile(aux);
	read &= score.makeindex(aux, &ixflds);
	dlg->Close();
	delete dlg;
	//StopWatch1.Pause();
	/*
	   long time = StopWatch1.Time() / 1000L; // time in seconds
	   int secs = (int) (time % 60L);
	   time /= 60L; // time in minutes
	   int mins = (int) (time % 60L);
	   int hrs = (int) (time / 60L);
	   wxString runtime;
	   runtime.Printf(_("Tempo de indexação: %d:%02d:%02d"), hrs, mins, secs);
	   timestring = runtime;
	 */
      }
      else
	read = wxFileExists(aux);
    }

    //wxMessageBox("So far so good","HELLO");

    if (read)
    {
      wxFileName sessionfile = wxFileName(cfgfilename);
      sessionfile.SetExt(_T("inspect"));
      wxString sessionname = sessionfile.GetFullPath();

      bool this_file_exists = false;

      if (!forceredo)
      {
	this_file_exists = wxFileExists(sessionname);
	if (this_file_exists)
	  this_file_exists =
	    (wxMessageBox
	     (_
	      ("Já existe uma tabela de scores\nassociada a esta configuração.\nDevo utilizá-la?"),
	      _("ATENÇÃO"), wxYES_NO | wxICON_QUESTION) == wxYES);
      }

      if (this_file_exists)
	loadsession();
      else
      {
	//StopWatch1.Start();
	valuesgrid->Hide();

	progressdialog *dlg = new progressdialog(this);

	dlg->msglabel->SetLabel(_T("Lendo scores..."));
	dlg->Show();
	dlg->Update();
	wxYieldIfNeeded();

	matchfile.SetExt(t.defixext().Right(3));
	aux = matchfile.GetFullPath();
	ixfile index;
	index.open(aux);
	index.first();
	int line = 0;
	long ntimes = 0;
	Gauge1->SetRange(index.gettotalrecs());
	Gauge1->SetValue(0);
	wxString auxl, tmp, old;
	int ticker = 0;
	//if (finals.Count())
	//finals.Clear();
	if (initials.Count())
	  initials.Clear();
	wxString currscore = index.getkey();
	//valuesgrid->SetRowLabelValue(0, currscore);
	long refrec = 1;
	initials.Add(refrec);
	//finals.Add(refrec);
	while (!index.iseof())
	{
	  if (currscore != index.getkey())
	  {
	    if (line)
	      valuesgrid->AppendRows(1);
	    valuesgrid->SetRowLabelValue(line, currscore);
	    auxl.Printf(_T("%d"), ntimes);
	    valuesgrid->SetCellValue(line, 0, auxl);
	    ntimes = 1;
	    currscore = index.getkey();
	    line++;
	    initials.Add(refrec);
	  }
	  else
	    ntimes++;
	  Gauge1->SetValue(refrec++);
	  ticker++;
	  if (ticker > 99)
	  {
	    wxYieldIfNeeded();
	    ticker = 0;
	  }
	  index.next();
	}
	valuesgrid->AppendRows(1);
	valuesgrid->SetRowLabelValue(line, currscore);
	auxl.Printf(_T("%d"), ntimes);
	valuesgrid->SetCellValue(line, 0, auxl);
	index.close();

	int gridlines = valuesgrid->GetNumberRows();
	double n1, n2;
	wxString lbl;

	dlg->msglabel->SetLabel(_T("Ordenando scores..."));
	dlg->Update();
	wxYieldIfNeeded();

	bool swapped;
	do
	{
	  swapped = false;
	  for (int i = 0; i < (gridlines - 1); i++)
	  {
	    lbl = valuesgrid->GetRowLabelValue(i);
	    lbl.Trim(false);
	    lbl.Replace(CVTFROM, CVTTO);
	    lbl.ToDouble(&n1);

	    lbl = valuesgrid->GetRowLabelValue(i + 1);
	    lbl.Replace(CVTFROM, CVTTO);
	    lbl.Trim(false);
	    lbl.ToDouble(&n2);

	    if (n2 > n1)
	    {
	      swap(valuesgrid, i, i + 1, true);
	      swapped = true;
	    }
	  }
	}
	while (swapped);

	dlg->Close();
	delete dlg;

	valuesgrid->Show();
	savesession();
	valuesgrid->ForceRefresh();

	/*
	   StopWatch1.Pause();
	   long time = StopWatch1.Time() / 1000L; // time in seconds
	   int secs = (int) (time % 60L);
	   time /= 60L; // time in minutes
	   int mins = (int) (time % 60L);
	   int hrs = (int) (time / 60L);
	   wxString runtime;
	   runtime.Printf(_("Tempo de leitura de scores: %d:%02d:%02d"), hrs, mins, secs);
	   if (timestring.IsEmpty())
	   timestring = runtime;
	   else
	   timestring = timestring + _T("\n") + runtime;
	 */
      }
      /*
         if (!timestring.IsEmpty())
         {
         wxMessageBox(timestring, _("NOTA"));
         //wxNotificationMessage msg(_("NOTA"), timestring);
         //msg.Show(20);
         }
       */
      int max = valuesgrid->GetNumberRows();
      for (int line = 0; line < max; line++)
	valuesgrid->SetCellAlignment(wxALIGN_RIGHT, line, 0);
    }

    if (read)
    {
      matchfile.SetExt(t.defixext().Right(3));
      aux = matchfile.GetFullPath();
      if (!wxFileExists(aux))
	read = false;
      if (read)
      {
	//progressdialog *dlg = new progressdialog(this);
	//dlg->Show();
	//dlg->Update();
	//wxYieldIfNeeded();
	read &= score.setindex(aux);
	//dlg->Close();
	//delete dlg;
      }
    }

    if (read)
    {
      if (relrec == -1L)
      {
	currow = 0;
	relrec = 1L;
      }
      score.find(initials[currow]);
      if (relrec > 1L)
	score.moveby(relrec - 1L);

      wxString refcnt = valuesgrid->GetCellValue(currow, 0);
      long count;
      if (refcnt.ToLong(&count))
      {
	Gauge1->SetRange((int) count);
	Gauge1->SetValue(relrec);
      }

      valuesgrid->SetGridCursor(currow, 1);
      wxString currscore = valuesgrid->GetRowLabelValue(currow);
      loadvalues();
      valuesgrid->SelectRow(currow);
    }

    if (!read)
    {
      if (comp.isopen())
	comp.close();
      if (ref.isopen())
	ref.close();
      if (score.isopen())
	score.close();
    }
  }
  else
    read = false;
  wxEndBusyCursor();
}

void
inspect::OnopencfgfileClick(wxCommandEvent & event)
{
  initialize();
  /*
     //
     // OLD WORKING CODE
     //
     wxBeginBusyCursor();
     wxString cfgfilename;

     if (FileDialog1->ShowModal() == wxID_OK)
     cfgfilename = FileDialog1->GetPath();
     else
     cfgfilename = _T("");

     if (!wxIsEmpty(cfgfilename) && wxFileExists(cfgfilename))
     {
     read = true;
     cfgfilectrl->SetValue(cfgfilename);
     wxYield();

     if (comp.isopen())
     comp.close();
     if (ref.isopen())
     ref.close();
     if (score.isopen())
     score.close();

     wxFileConfig *cfgfile = new wxFileConfig(_T(""),_T(""),cfgfilename,_T(""),wxCONFIG_USE_LOCAL_FILE);
     wxString aux = _T("");
     cfgfile->Read(_T("FILES/COMPNAME"),&aux);
     if (wxFileExists(aux))
     read &= comp.open(aux);
     else
     read = false;

     aux = _T("");
     cfgfile->Read(_T("FILES/REFNAME"),&aux);
     if (wxFileExists(aux))
     read &= ref.open(aux);
     else
     read = false;

     delete cfgfile;

     wxFileName matchfile = wxFileName(cfgfilename);
     ntable t;
     matchfile.SetExt(t.defdbext().Right(3));
     wxString name = matchfile.GetName();
     name = name + _T("SCORE");
     matchfile.SetName(name);
     aux = matchfile.GetFullPath();

     if (wxFileExists(aux))
     read &= score.open(aux);

     if (read)
     {
     int nlines = comp.getnumfields();
     int glines = compgrid->GetNumberRows();
     if (glines > (int) nlines)
     {
     glines -= (int) nlines;
     compgrid->DeleteRows(0,glines);
     }
     else if (glines < (int) nlines)
     {
     glines = (int) nlines - glines;
     compgrid->AppendRows(glines);
     }
     for (int i = 0; i < nlines; i++)
     compgrid->SetRowLabelValue(i, comp.getfieldname(i));
     nlines = ref.getnumfields();
     glines = refgrid->GetNumberRows();
     if (glines > (int) nlines)
     {
     glines -= (int) nlines;
     refgrid->DeleteRows(0,glines);
     }
     else if (glines < (int) nlines)
     {
     glines = (int) nlines - glines;
     refgrid->AppendRows(glines);
     }
     for (int i = 0; i < nlines; i++)
     refgrid->SetRowLabelValue(i, ref.getfieldname(i));
     wxString currscore;

     wxFileName sessionfile = wxFileName(cfgfilename);
     sessionfile.SetExt(_T("inspect"));
     wxString sessionname = sessionfile.GetFullPath();

     wxString timestring = _T("");

     if (wxFileExists(sessionname) &&
     (wxMessageBox(_("Já existe uma tabela de scores\nassociada a esta configuração.\nDevo utilizá-la?"), _("ATENÇÃO"), wxYES_NO|wxICON_QUESTION) == wxYES))
     loadsession();
     else
     {
     StopWatch1.Start();
     valuesgrid->Hide();

     progressdialog *dlg = new progressdialog(this);

     dlg->msglabel->SetLabel(_T("Lendo scores..."));
     dlg->Show();
     dlg->Update();
     wxYieldIfNeeded();

     score.first();
     int line = 0;
     long ntimes;
     Gauge1->SetValue(0);
     wxString aux, tmp, old;
     int ticker = 0;
     currscore = score.getstring(_T("SCORE"));
     valuesgrid->SetRowLabelValue(0, currscore);
     valuesgrid->SetCellValue(0, 0, _T("0"));
     while (!score.eof() && !currscore.IsEmpty())
     {
     int i;
     int nrows = valuesgrid->GetNumberRows();

     bool found = false;
     for (i = 0; i < nrows; i++)
     if (currscore == valuesgrid->GetRowLabelValue(i))
     {
     found = true;
     break;
     }

     if (found)
     {
     aux = valuesgrid->GetCellValue(i, 0);
     aux.ToLong(&ntimes);
     aux.Printf(_T("%d"), ++ntimes);
     valuesgrid->SetCellValue(i, 0, aux);
     }
     else
     {
     valuesgrid->AppendRows(1);
     valuesgrid->SetRowLabelValue(i, currscore);
     aux.Printf(_T("%d"), 1);
     valuesgrid->SetCellValue(i, 0, aux);
     }
     score.next();
     currscore = score.getstring(_T("SCORE"));
     Gauge1->Pulse();
     ticker ++;
     if (ticker > 99)
     {
     wxYieldIfNeeded();
     ticker = 0;
     }
     }

     int gridlines = valuesgrid->GetNumberRows();
     double n1, n2;
     wxString lbl;

     dlg->msglabel->SetLabel(_T("Ordenando scores..."));
     dlg->Update();
     wxYieldIfNeeded();

     bool swapped;
     do {
     swapped = false;
     for (int i = 0; i < (gridlines - 1); i++)
     {
     lbl = valuesgrid->GetRowLabelValue(i);
     lbl.Trim(false);
     lbl.ToDouble(&n1);
     lbl = valuesgrid->GetRowLabelValue(i+1);
     lbl.Trim(false);
     lbl.ToDouble(&n2);
     if (n2 > n1)
     {
     swap(valuesgrid, i, i + 1);
     swapped = true;
     }
     }
     } while (swapped);

     int max = valuesgrid->GetNumberRows();
     for (int line = 0; line < max; line++)
     valuesgrid->SetCellAlignment(wxALIGN_RIGHT, line, 0);

     dlg->Close();
     delete dlg;

     valuesgrid->Show();

     StopWatch1.Pause();
     long time = StopWatch1.Time() / 1000L; // time in seconds
     int secs = (int) (time % 60L);
     time /= 60L; // time in minutes
     int mins = (int) (time % 60L);
     int hrs = (int) (time / 60L);
     timestring.Printf(_("Tempo de leitura de scores: %d:%02d:%02d"), hrs, mins, secs);
     }
     wxString refcnt = valuesgrid->GetCellValue(0, 0);
     long count;
     if (refcnt.ToLong(&count))
     {
     Gauge1->SetRange((int)count);
     Gauge1->SetValue(1);
     }

     ntable t;
     matchfile.SetExt(t.defixext().Right(3));
     aux = matchfile.GetFullPath();
     if (!wxFileExists(aux))
     {
     wxArrayString ixflds;
     ixflds.Clear();
     ixflds.Add(_T("SCORE"));
     progressdialog *dlg = new progressdialog(this);
     dlg->Show();
     dlg->Update();
     wxYieldIfNeeded();
     StopWatch1.Start();
     read &= score.makeindex(aux, &ixflds);
     if (read)
     read &= score.setindex(aux);
     dlg->Close();
     delete dlg;
     StopWatch1.Pause();
     long time = StopWatch1.Time() / 1000L; // time in seconds
     int secs = (int) (time % 60L);
     time /= 60L; // time in minutes
     int mins = (int) (time % 60L);
     int hrs = (int) (time / 60L);
     wxString runtime;
     runtime.Printf(_("Tempo de indexação: %d:%02d:%02d"), hrs, mins, secs);
     if (timestring.IsEmpty())
     timestring = runtime;
     else
     timestring = timestring + _T("\n") + runtime;
     }
     else
     {
     progressdialog *dlg = new progressdialog(this);
     dlg->Show();
     dlg->Update();
     wxYieldIfNeeded();
     read &= score.setindex(aux);
     dlg->Close();
     delete dlg;
     }
     if (!timestring.IsEmpty())
     wxMessageBox(timestring,_("NOTA"));
     if (read)
     {
     currscore = valuesgrid->GetRowLabelValue(0);
     score.first();
     score.find(currscore);
     loadvalues();
     valuesgrid->SelectRow(0);
     }
     }

     if (!read)
     {
     if (comp.isopen())
     comp.close();
     if (ref.isopen())
     ref.close();
     if (score.isopen())
     score.close();
     }
     }
     else
     read = false;
     wxEndBusyCursor();
   */
}

void
inspect::OnrefupClick(wxCommandEvent & event)
{
  int row = refgrid->GetGridCursorRow();
  int lastline = refgrid->GetNumberRows() - 1;
  if (row && lastline)
  {
    swap(refgrid, row, row - 1);
    refgrid->SetGridCursor(row - 1, 0);
  }
}

void
inspect::OnrefdownClick(wxCommandEvent & event)
{
  int row = refgrid->GetGridCursorRow();
  int lastline = refgrid->GetNumberRows() - 1;
  if (row < lastline)
  {
    swap(refgrid, row, row + 1);
    refgrid->SetGridCursor(row + 1, 0);
  }
}

void
inspect::OncompupClick(wxCommandEvent & event)
{
  int row = compgrid->GetGridCursorRow();
  int lastline = compgrid->GetNumberRows() - 1;
  if (row && lastline)
  {
    swap(compgrid, row, row - 1);
    compgrid->SetGridCursor(row - 1, 0);
  }
}

void
inspect::OncompdownClick(wxCommandEvent & event)
{
  int row = compgrid->GetGridCursorRow();
  int lastline = compgrid->GetNumberRows() - 1;
  if (row < lastline)
  {
    swap(compgrid, row, row + 1);
    compgrid->SetGridCursor(row + 1, 0);
  }
}

void
inspect::OngofirstClick(wxCommandEvent & event)
{
  if (read)
  {
    movetop();
    loadvalues();
  }
}

void
inspect::OngobackClick(wxCommandEvent & event)
{
  if (read)
  {
    moveup();
    loadvalues();
  }
}

void
inspect::OngoforwardClick(wxCommandEvent & event)
{
  if (read)
  {
    movedown();
    loadvalues();
  }
}

void
inspect::OngolastClick(wxCommandEvent & event)
{
  if (read)
  {
    movebottom();
    loadvalues();
  }
}

void
inspect::OnpairstatusSelect(wxCommandEvent & event)
{
  wxString val;
  switch (pairstatus->GetSelection())
  {
  case 0:
    val = _T("+");		// par
    break;
  case 1:
    val = _T("?");		// dúvida
    break;
  case 2:
    val = _T("-");		// não par
    break;
  case 3:
  default:
    val = _T("*");		// ignorado
    break;
  }
  if (read)
  {
    score.setfield(val, _T("MATCH"));
    score.replacerec();
  }
}

void
inspect::OnmarkallClick(wxCommandEvent & event)
{
  if (wxMessageBox(_("Confirma operação?"), _("ATENÇÃO"), wxYES_NO | wxICON_EXCLAMATION) ==
      wxYES)
  {
    if (read)
    {
      wxBeginBusyCursor();
      Gauge1->SetRange(score.gettotalrecs());
      wxString aux;
      double posmin = 0.0, negmax = 0.0, fscore;
      aux = scoremmin->GetValue();
      aux.Replace(CVTFROM, CVTTO);
      aux.ToDouble(&posmin);
      aux = scorenmax->GetValue();
      aux.Replace(CVTFROM, CVTTO);
      aux.ToDouble(&negmax);
      Gauge1->SetValue(0);
      int n = 0;
      int ticker = 0;
      /*
         ntable tmp;
         dbtable::fielddef stru[] = {
         {_T("COMPREC"), dbtable::CHAR, 12, 0},
         {_T("REFREC"), dbtable::CHAR, 12, 0},
         {_T("SCORE"), dbtable::CHAR, 15, 0},
         {_T("MATCH"), dbtable::CHAR, 1, 0}
         };
       */
      wxString ixname = score.getcurrentidx();
      long bookmark = score.getcurrentrec();
      score.setindex(_T(""));
      score.first();
      while (!score.eof())
      {
	aux = score.getstring(_T("SCORE"));
	aux.Replace(CVTFROM, CVTTO);
	if (aux.ToDouble(&fscore))
	{
	  if (fscore >= posmin)
	    aux = _T("+");
	  else if (fscore <= negmax)
	    aux = _T("-");
	  else
	    aux = _T("?");
	}
	else
	  aux = _T("*");
	score.setfield(aux, _T("MATCH"));
	score.replacerec();
	score.next();
	Gauge1->SetValue(++n);
	ticker++;
	if (ticker > 99)
	{
	  wxYieldIfNeeded();
	  ticker = 0;
	}
      }
      score.setindex(ixname);
      score.go(bookmark);
      read = true;
      wxString refcnt = valuesgrid->GetCellValue(0, 0);
      long count;
      if (refcnt.ToLong(&count))
      {
	Gauge1->SetRange((int) count);
	Gauge1->SetValue(1);
      }
      valuesgrid->SelectRow(0);
      loadvalues();
      wxEndBusyCursor();
    }
  }
}

void
inspect::OnclearallClick(wxCommandEvent & event)
{
  if (wxMessageBox(_("Confirma operação?"), _("ATENÇÃO"), wxYES_NO | wxICON_EXCLAMATION) ==
      wxYES)
  {
    if (read)
    {
      wxBeginBusyCursor();
      Gauge1->SetRange(score.gettotalrecs());
      Gauge1->SetValue(0);
      int n = 0;
      int ticker = 0;
      wxString ixname = score.getcurrentidx();
      long bookmark = score.getcurrentrec();
      score.setindex(_T(""));
      score.first();
      while (!score.eof())
      {
	score.setfield(_T("*"), _T("MATCH"));
	score.replacerec();
	score.next();
	Gauge1->SetValue(++n);
	ticker++;
	if (ticker > 99)
	{
	  wxYieldIfNeeded();
	  ticker = 0;
	}
      }
      score.setindex(ixname);
      score.go(bookmark);
      read = true;
      wxString refcnt = valuesgrid->GetCellValue(0, 0);
      long count;
      if (refcnt.ToLong(&count))
      {
	Gauge1->SetRange((int) count);
	Gauge1->SetValue(1);
      }
      valuesgrid->SelectRow(0);
      loadvalues();
      wxEndBusyCursor();
    }
  }
}

void
inspect::moveup(void)
{
  long pos = relrec;
  int step = stepctrl->GetValue() * -1;
  pos += step;
  if (pos < 1L)
    movetop();
  else
  {
    relrec = pos;
    score.moveby((long) step);
    Gauge1->SetValue(pos);
  }

  /*
     int loop = 0;
     while (!score.bof() && (loop < step))
     {
     pos--;
     loop++;
     if (pos < 1)
     {
     pos = 1;
     break;
     }
     score.prev();
     }
   */
}

void
inspect::movetop(void)
{
  if ((currow >= 0) && (currow < initials.Count()))
  {
    relrec = 1L;
    score.find(initials[currow]);
    Gauge1->SetValue(1);
  }
}

void
inspect::movedown(void)
{
  int pos = relrec;
  wxString lim_string = valuesgrid->GetCellValue(currow, 0);
  long lim;
  lim_string.ToLong(&lim);
  int step = stepctrl->GetValue();
  pos += step;
  if (pos > lim)
    movebottom();
  else
  {
    relrec = pos;
    score.moveby((long) step);
    Gauge1->SetValue(pos);
  }

  /*
     int loop = 0;
     while (!score.eof() && (loop < step))
     {
     pos++;
     loop++;
     if (pos > lim)
     {
     pos = lim;
     break;
     }
     score.next();
     }
   */
}

void
inspect::movebottom(void)
{
  wxString pos_string = valuesgrid->GetCellValue(currow, 0);
  long pos;
  pos_string.ToLong(&pos);
  if ((currow >= 0) && (currow < initials.Count()))
  {
    relrec = pos;
    long newpos = initials[currow] + pos - 1L;
    score.find(newpos);
    Gauge1->SetValue(relrec);
  }
}

void
inspect::swap(wxGrid * grid, int row1, int row2, bool arrays)
{
  wxString swapstr = grid->GetCellValue(row1, 0);
  grid->SetCellValue(row1, 0, grid->GetCellValue(row2, 0));
  grid->SetCellValue(row2, 0, swapstr);
  swapstr = grid->GetRowLabelValue(row1);
  grid->SetRowLabelValue(row1, grid->GetRowLabelValue(row2));
  grid->SetRowLabelValue(row2, swapstr);
  if (arrays)
  {
    long swaplong = initials[row1];
    initials[row1] = initials[row2];
    initials[row2] = swaplong;
  }
}

void
inspect::loadvalues(void)
{
  if (read)
  {
    wxString aux = score.getstring(_T("COMPREC"));
    long recno;
    aux.ToLong(&recno);		// this might be a PROBLEM
    int nflds = comp.getnumfields();
    if (comp.go(recno))
      for (int i = 0; i < nflds; i++)
	compgrid->SetCellValue(i, 0, comp.getstring(compgrid->GetRowLabelValue(i)));
    else
      for (int i = 0; i < nflds; i++)
	compgrid->SetCellValue(i, 0, _("ERRO"));
    aux = score.getstring(_T("REFREC"));
    aux.ToLong(&recno);
    nflds = ref.getnumfields();
    if (ref.go(recno))
      for (int i = 0; i < nflds; i++)
	refgrid->SetCellValue(i, 0, ref.getstring(refgrid->GetRowLabelValue(i)));
    else
      for (int i = 0; i < nflds; i++)
	refgrid->SetCellValue(i, 0, _("ERRO"));
    wxString stts = score.getstring(_T("MATCH"));
    if (stts == _T("+"))
      pairstatus->SetSelection(0);
    else if (stts == _T("?"))
      pairstatus->SetSelection(1);
    else if (stts == _T("-"))
      pairstatus->SetSelection(2);
    else if (stts == _T("*"))
      pairstatus->SetSelection(3);
    else
      pairstatus->SetSelection(-1);

    scorelbl->SetLabel(score.getstring(_T("SCORE")));
  }
}

void
inspect::OnvaluesgridCellSelect(wxGridEvent & event)
{
  currow = event.GetRow();
  relrec = 1L;
  valuesgrid->SelectRow(currow);
  //wxString refscore = valuesgrid->GetRowLabelValue(currow);
  wxString refcnt = valuesgrid->GetCellValue(currow, 0);
  if (read)
  {
    /*
       wxBeginBusyCursor();
       bool found = score.find(refscore);
       wxEndBusyCursor();
       if (found)
       {
       loadvalues();
       long count;
       if (refcnt.ToLong(&count))
       {
       Gauge1->SetRange((int)count);
       Gauge1->SetValue(1);
       }
       }
     */
    if ((currow >= 0) && (currow < initials.Count()))
      score.find(initials[currow]);
    loadvalues();
    long count;
    if (refcnt.ToLong(&count))
    {
      Gauge1->SetRange((int) count);
      Gauge1->SetValue(1);
    }
  }
}

void
inspect::loadsession(void)
{
  // ADD STUFF

  wxString cfgfilename = cfgfilectrl->GetValue();
  wxFileName matchfile = wxFileName(cfgfilename);
  matchfile.SetExt(_T("inspect"));
  cfgfilename = matchfile.GetFullPath();
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgfilename, _T(""), wxCONFIG_USE_LOCAL_FILE);

  wxString aux;
  long nlines = 0L;
  cfgfile->Read(_T("SCORES/NLINES"), &nlines);
  int glines = valuesgrid->GetNumberRows();
  if (glines > (int) nlines)
  {
    glines -= (int) nlines;
    valuesgrid->DeleteRows(0, glines);
  }
  else if (glines < (int) nlines)
  {
    glines = (int) nlines - glines;
    valuesgrid->AppendRows(glines);
  }
  wxString tmp;
  long num;
  for (int i = 0; i < (int) nlines; i++)
  {
    aux.Printf(_T("SCORES/VALUE%d"), i);
    tmp = _T("");
    cfgfile->Read(aux, &tmp);
    valuesgrid->SetRowLabelValue(i, tmp);
    aux.Printf(_T("SCORES/FREQ%d"), i);
    tmp = _T("");
    cfgfile->Read(aux, &tmp);
    valuesgrid->SetCellValue(i, 0, tmp);
    aux.Printf(_T("SCORES/INITIAL%d"), i);
    tmp = _T("");
    cfgfile->Read(aux, &tmp);
    tmp.ToLong(&num);
    initials.Add(num);
  }

  cfgfile->Read(_T("SCORES/RELREC"), &relrec);
  cfgfile->Read(_T("SCORES/CURROW"), &currow);

  delete cfgfile;
}

void
inspect::savesession(void)
{
  wxString cfgfilename = cfgfilectrl->GetValue();
  wxFileName matchfile = wxFileName(cfgfilename);
  matchfile.SetExt(_T("inspect"));
  cfgfilename = matchfile.GetFullPath();
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgfilename, _T(""), wxCONFIG_USE_LOCAL_FILE);

  long nlines = valuesgrid->GetNumberRows();
  cfgfile->Write(_T("SCORES/NLINES"), nlines);

  wxString aux, tmp;
  for (int i = 0; i < (int) nlines; i++)
  {
    aux.Printf(_T("SCORES/VALUE%d"), i);
    cfgfile->Write(aux, valuesgrid->GetRowLabelValue(i));
    aux.Printf(_T("SCORES/FREQ%d"), i);
    cfgfile->Write(aux, valuesgrid->GetCellValue(i, 0));
    aux.Printf(_T("SCORES/INITIAL%d"), i);
    tmp.Printf(_T("%d"), initials[i]);
    cfgfile->Write(aux, tmp);
  }

  aux.Printf(_T("%d"), relrec);
  cfgfile->Write(_T("SCORES/RELREC"), aux);

  aux.Printf(_T("%d"), currow);
  cfgfile->Write(_T("SCORES/CURROW"), aux);

  delete cfgfile;
}

void
inspect::OnokbtnClick(wxCommandEvent & event)
{
  if (read)
  {
    savesession();
    ops_log log;
    log.log_event(_T("INSP"), cfgfilectrl->GetValue());
  }
  Close();
}

void
inspect::OncancelbtnClick(wxCommandEvent & event)
{
  if (wxMessageBox
      (_("Deseja realmente cancelar a operação?"), _("ATENÇÃO"),
       wxYES_NO | wxICON_EXCLAMATION) == wxYES)
  {
    if (read)
    {
      if (wxMessageBox
	  (_("Deseja realmente descartar\na tabela de frequências?"), _("ATENÇÃO"),
	   wxYES_NO | wxICON_EXCLAMATION) != wxYES)
      {
	wxString cfgfilename = cfgfilectrl->GetValue();
	wxFileName matchfile = wxFileName(cfgfilename);
	matchfile.SetExt(_T("inspect"));
	cfgfilename = matchfile.GetFullPath();
	wxRemoveFile(cfgfilename);
	savesession();
      }
      ops_log log;
      log.log_event(_T("INSP"), cfgfilectrl->GetValue(), _T("N/A"), _("Cancelado"));
      Close();
    }
  }
}

/*
void inspect::OnrefgridMouseMove(wxMouseEvent& event)
{
    static int prev_row = 0, prev_col = 0;
    wxPoint pt;
    refgrid->CalcUnscrolledPosition(pt);
    int row = refgrid->YToRow(pt.y);
    int col = refgrid->XToCol(pt.x);

    if ((row != prev_row) && (col != prev_col) && (row >= 0) && (col >= 0))
    {
        prev_row = row;
        prev_col = col;
        wxString hinttext = refgrid->GetCellValue(row, col);
        refgrid->GetGridWindow()->SetToolTip(hinttext);
    }

    event.Skip();
}
*/

void
inspect::OnrefgridCellSelect(wxGridEvent & event)
{
  int row = event.GetRow();
  int col = event.GetCol();
  wxString val = refgrid->GetCellValue(row, col);
  wxTipWindow *tip = new wxTipWindow(refgrid, val);
}

void
inspect::OncompgridCellSelect(wxGridEvent & event)
{
  int row = event.GetRow();
  int col = event.GetCol();
  wxString val = compgrid->GetCellValue(row, col);
  wxTipWindow *tip = new wxTipWindow(compgrid, val);
}
