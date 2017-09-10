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
// Nome:        wizlnk.cpp
// Propósito:   Classe (janela) para configurar relacionamento
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "wizlnk.h"
#include "ntable.h"
#include "calc.h"
#include "ops_log.h"

#include "checksep.h"

#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>

//(*InternalHeaders(wizlnk)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/tglbtn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(wizlnk)
const long
  wizlnk::ID_STATICTEXT1 = wxNewId();
const long
  wizlnk::ID_PANEL3 = wxNewId();
const long
  wizlnk::ID_TEXTCTRL1 = wxNewId();
const long
  wizlnk::ID_BITMAPBUTTON1 = wxNewId();
const long
  wizlnk::ID_STATICTEXT6 = wxNewId();
const long
  wizlnk::ID_PANEL2 = wxNewId();
const long
  wizlnk::ID_TEXTCTRL2 = wxNewId();
const long
  wizlnk::ID_BITMAPBUTTON2 = wxNewId();
const long
  wizlnk::ID_TEXTCTRL3 = wxNewId();
const long
  wizlnk::ID_BITMAPBUTTON3 = wxNewId();
const long
  wizlnk::ID_STATICTEXT3 = wxNewId();
const long
  wizlnk::ID_STATICTEXT4 = wxNewId();
const long
  wizlnk::ID_PANEL4 = wxNewId();
const long
  wizlnk::ID_GRID2 = wxNewId();
const long
  wizlnk::ID_BUTTON8 = wxNewId();
const long
  wizlnk::ID_BUTTON9 = wxNewId();
const long
  wizlnk::ID_BUTTON10 = wxNewId();
const long
  wizlnk::ID_BITMAPBUTTON4 = wxNewId();
const long
  wizlnk::ID_BITMAPBUTTON5 = wxNewId();
const long
  wizlnk::ID_TEXTCTRL5 = wxNewId();
const long
  wizlnk::ID_STATICTEXT5 = wxNewId();
const long
  wizlnk::ID_PANEL5 = wxNewId();
const long
  wizlnk::ID_GRID3 = wxNewId();
const long
  wizlnk::ID_BUTTON12 = wxNewId();
const long
  wizlnk::ID_BUTTON13 = wxNewId();
const long
  wizlnk::ID_BUTTON14 = wxNewId();
const long
  wizlnk::ID_BITMAPBUTTON7 = wxNewId();
const long
  wizlnk::ID_BITMAPBUTTON6 = wxNewId();
const long
  wizlnk::ID_PANEL6 = wxNewId();
const long
  wizlnk::ID_CHECKBOX1 = wxNewId();
const long
  wizlnk::ID_STATICTEXT7 = wxNewId();
const long
  wizlnk::ID_STATICTEXT8 = wxNewId();
const long
  wizlnk::ID_STATICTEXT9 = wxNewId();
const long
  wizlnk::ID_STATICTEXT10 = wxNewId();
const long
  wizlnk::ID_STATICTEXT11 = wxNewId();
const long
  wizlnk::ID_STATICTEXT12 = wxNewId();
const long
  wizlnk::ID_TEXTCTRL6 = wxNewId();
const long
  wizlnk::ID_PANEL7 = wxNewId();
const long
  wizlnk::ID_TEXTCTRL4 = wxNewId();
const long
  wizlnk::ID_STATICTEXT2 = wxNewId();
const long
  wizlnk::ID_PANEL8 = wxNewId();
const long
  wizlnk::ID_LISTBOOK1 = wxNewId();
const long
  wizlnk::ID_BUTTON1 = wxNewId();
const long
  wizlnk::ID_BUTTON2 = wxNewId();
const long
  wizlnk::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wizlnk, wxDialog)
  //(*EventTable(wizlnk)
  //*)
  END_EVENT_TABLE()wizlnk::wizlnk(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				  const wxSize & size)
{
  //(*Initialize(wizlnk)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, wxID_ANY, _("Assistente"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(523, 349));
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  Panel3 =
    new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxSize(523, 23), wxTAB_TRAVERSAL,
		_T("ID_PANEL3"));
  StaticText1 =
    new wxStaticText(Panel3, ID_STATICTEXT1, _("Relaciona"), wxPoint(16, 8), wxDefaultSize, 0,
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
  cfgfilenamectrl =
    new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(40, 104), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  opencfgfile =
    new wxBitmapButton(Panel2, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE")),
						wxART_BUTTON), wxPoint(448, 104), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  StaticText6 =
    new wxStaticText(Panel2, ID_STATICTEXT6, _("Arquivo de configuração:"), wxPoint(48, 80),
		     wxDefaultSize, 0, _T("ID_STATICTEXT6"));
  Panel4 =
    new wxPanel(Listbook1, ID_PANEL4, wxPoint(202, 14), wxSize(523, 260), wxTAB_TRAVERSAL,
		_T("ID_PANEL4"));
  compfilenamectrl =
    new wxTextCtrl(Panel4, ID_TEXTCTRL2, wxEmptyString, wxPoint(40, 72), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
  opencompfile =
    new wxBitmapButton(Panel4, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(448, 72), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  reffilenamectrl =
    new wxTextCtrl(Panel4, ID_TEXTCTRL3, wxEmptyString, wxPoint(40, 144), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
  openreffile =
    new wxBitmapButton(Panel4, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(448, 144), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
  StaticText3 =
    new wxStaticText(Panel4, ID_STATICTEXT3,
		     _("Arquivo de comparação (será lido integralmente)"), wxPoint(48, 48),
		     wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  StaticText4 =
    new wxStaticText(Panel4, ID_STATICTEXT4, _("Arquivo de referência (será lido por blocos):"),
		     wxPoint(48, 120), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
  Panel5 =
    new wxPanel(Listbook1, ID_PANEL5, wxPoint(188, 16), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL5"));
  Grid2 = new wxGrid(Panel5, ID_GRID2, wxPoint(160, 24), wxSize(256, 168), 0, _T("ID_GRID2"));
  Grid2->CreateGrid(1, 2);
  Grid2->EnableEditing(true);
  Grid2->EnableGridLines(true);
  Grid2->SetColLabelSize(20);
  Grid2->SetRowLabelSize(40);
  Grid2->SetDefaultColSize(100, true);
  Grid2->SetColLabelValue(0, _("Comparação"));
  Grid2->SetColLabelValue(1, _("Referência"));
  Grid2->SetDefaultCellFont(Grid2->GetFont());
  Grid2->SetDefaultCellTextColour(Grid2->GetForegroundColour());
  btnadd2 =
    new wxButton(Panel5, ID_BUTTON8, _("Adiciona"), wxPoint(104, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON8"));
  btndel2 =
    new wxButton(Panel5, ID_BUTTON9, _("Remove"), wxPoint(224, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON9"));
  btnclear2 =
    new wxButton(Panel5, ID_BUTTON10, _("Limpa"), wxPoint(344, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON10"));
  BitmapButton4 =
    new wxBitmapButton(Panel5, ID_BITMAPBUTTON4,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),
						wxART_BUTTON), wxPoint(424, 40), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
  BitmapButton5 =
    new wxBitmapButton(Panel5, ID_BITMAPBUTTON5,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),
						wxART_BUTTON), wxPoint(424, 80), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
  BitmapButton5->SetDefault();
  TextCtrl1 =
    new wxTextCtrl(Panel5, ID_TEXTCTRL5, wxEmptyString, wxPoint(16, 136), wxSize(120, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL5"));
  StaticText5 =
    new wxStaticText(Panel5, ID_STATICTEXT5, _("Nome do índice:"), wxPoint(16, 112), wxDefaultSize,
		     0, _T("ID_STATICTEXT5"));
  Panel6 =
    new wxPanel(Listbook1, ID_PANEL6, wxPoint(174, 11), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL6"));
  Grid3 = new wxGrid(Panel6, ID_GRID3, wxPoint(16, 24), wxSize(448, 168), 0, _T("ID_GRID3"));
  Grid3->CreateGrid(1, 6);
  Grid3->EnableEditing(true);
  Grid3->EnableGridLines(true);
  Grid3->SetColLabelSize(20);
  Grid3->SetRowLabelSize(40);
  Grid3->SetDefaultColSize(65, true);
  Grid3->SetColLabelValue(0, _("Comp."));
  Grid3->SetColLabelValue(1, _("Tipo"));
  Grid3->SetColLabelValue(2, _("Corr."));
  Grid3->SetColLabelValue(3, _("Inc."));
  Grid3->SetColLabelValue(4, _("Lim."));
  Grid3->SetColLabelValue(5, _("Ref."));
  Grid3->SetDefaultCellFont(Grid3->GetFont());
  Grid3->SetDefaultCellTextColour(Grid3->GetForegroundColour());
  btnadd3 =
    new wxButton(Panel6, ID_BUTTON12, _("Adiciona"), wxPoint(104, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON12"));
  btndel3 =
    new wxButton(Panel6, ID_BUTTON13, _("Remove"), wxPoint(224, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON13"));
  btnclear3 =
    new wxButton(Panel6, ID_BUTTON14, _("Limpa"), wxPoint(344, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON14"));
  BitmapButton3 =
    new wxBitmapButton(Panel6, ID_BITMAPBUTTON7,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),
						wxART_BUTTON), wxPoint(480, 40), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
  BitmapButton6 =
    new wxBitmapButton(Panel6, ID_BITMAPBUTTON6,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),
						wxART_BUTTON), wxPoint(480, 80), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
  BitmapButton6->SetDefault();
  Panel7 =
    new wxPanel(Listbook1, ID_PANEL7, wxPoint(160, 15), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL7"));
  CheckBox1 =
    new wxCheckBox(Panel7, ID_CHECKBOX1, _("Ignora escore baixo:"), wxPoint(304, 32), wxDefaultSize,
		   0, wxDefaultValidator, _T("ID_CHECKBOX1"));
  CheckBox1->SetValue(false);
  StaticText7 =
    new wxStaticText(Panel7, ID_STATICTEXT7, _("Escore mínimo:"), wxPoint(360, 88), wxDefaultSize,
		     0, _T("ID_STATICTEXT7"));
  StaticText8 =
    new wxStaticText(Panel7, ID_STATICTEXT8, _("Máximo:"), wxPoint(16, 72), wxSize(64, 17), 0,
		     _T("ID_STATICTEXT8"));
  StaticText9 =
    new wxStaticText(Panel7, ID_STATICTEXT9,
		     _("Limites de escores possíveis\ncom a configuração corrente:"), wxPoint(16,
												 24),
		     wxDefaultSize, 0, _T("ID_STATICTEXT9"));
  StaticText10 =
    new wxStaticText(Panel7, ID_STATICTEXT10, _("Mínimo:"), wxPoint(16, 104), wxDefaultSize, 0,
		     _T("ID_STATICTEXT10"));
  maxscore =
    new wxStaticText(Panel7, ID_STATICTEXT11, _("NNNN"), wxPoint(96, 72), wxDefaultSize, 0,
		     _T("ID_STATICTEXT11"));
  minscore =
    new wxStaticText(Panel7, ID_STATICTEXT12, _("NNNN"), wxPoint(96, 104), wxDefaultSize, 0,
		     _T("ID_STATICTEXT12"));
  TextCtrl2 =
    new wxTextCtrl(Panel7, ID_TEXTCTRL6, _("0"), wxPoint(360, 120), wxDefaultSize, wxTE_RIGHT,
		   wxDefaultValidator, _T("ID_TEXTCTRL6"));
  TextCtrl2->Disable();
  Panel8 =
    new wxPanel(Listbook1, ID_PANEL8, wxPoint(175, 19), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL8"));
  errrep =
    new wxTextCtrl(Panel8, ID_TEXTCTRL4, wxEmptyString, wxPoint(40, 32), wxSize(350, 176),
		   wxTE_MULTILINE | wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
  okbtn =
    new wxBitmapButton(Panel8, wxID_OK,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),
						wxART_BUTTON), wxPoint(416, 176), wxSize(36, 36),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("wxID_OK"));
  okbtn->Disable();
  okbtn->SetToolTip(_("Aceita"));
  cancelbtn =
    new wxBitmapButton(Panel8, wxID_CANCEL,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CROSS_MARK")),
						wxART_BUTTON), wxPoint(464, 176), wxSize(36, 36),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("wxID_CANCEL"));
  cancelbtn->SetToolTip(_("Abandona"));
  StaticText2 =
    new wxStaticText(Panel8, ID_STATICTEXT2, _("Status da configuração:"), wxPoint(40, 8),
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  Listbook1->AddPage(Panel2, _("Config."), false);
  Listbook1->AddPage(Panel4, _("Arq. dados"), false);
  Listbook1->AddPage(Panel5, _("Blocagem"), false);
  Listbook1->AddPage(Panel6, _("Comparação"), false);
  Listbook1->AddPage(Panel7, _("Opções adicionais"), false);
  Listbook1->AddPage(Panel8, _("Finaliza"), false);
  FlexGridSizer1->Add(Listbook1, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(523, 47), wxTAB_TRAVERSAL,
		_T("ID_PANEL1"));
  backbtn =
    new wxButton(Panel1, ID_BUTTON1, _("Volta"), wxPoint(340, 8), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON1"));
  fwdbtn =
    new wxButton(Panel1, ID_BUTTON2, _("Segue"), wxPoint(425, 8), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON2"));
  FlexGridSizer1->Add(Panel1, 1,
		      wxBOTTOM | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE | wxFD_OPEN,
		     wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FileDialog2 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_SAVE, wxDefaultPosition, wxDefaultSize,
		     _T("wxFileDialog"));
  SetSizer(FlexGridSizer1);
  Layout();

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnopencompfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnopenreffileClick);
  Connect(ID_BUTTON8, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::Onbtnadd2Click);
  Connect(ID_BUTTON9, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::Onbtndel2Click);
  Connect(ID_BUTTON10, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::Onbtnclear2Click);
  Connect(ID_BITMAPBUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnBitmapButton4Click);
  Connect(ID_BITMAPBUTTON5, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnBitmapButton5Click);
  Connect(ID_BUTTON12, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::Onbtnadd3Click);
  Connect(ID_BUTTON13, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::Onbtndel3Click);
  Connect(ID_BUTTON14, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::Onbtnclear3Click);
  Connect(ID_BITMAPBUTTON7, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnBitmapButton3Click);
  Connect(ID_BITMAPBUTTON6, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnBitmapButton6Click);
  Connect(ID_CHECKBOX1, wxEVT_COMMAND_CHECKBOX_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnCheckBox1Click);
  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & wizlnk::OnokbtnClick);
  Connect(ID_LISTBOOK1, wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,
	  (wxObjectEventFunction) & wizlnk::OnListbook1PageChanged);
  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnbackbtnClick);
  Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizlnk::OnfwdbtnClick);
  //*)

  // always check...
  //Connect(ID_LISTBOOK1,wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED,(wxObjectEventFunction)&wizlnk::OnListbook1PageChanged);

#if wxCHECK_VERSION(3,0,0)
  fwdbtn->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),
					     wxART_MAKE_CLIENT_ID_FROM_STR(wxString
									   (wxEmptyString))));
  backbtn->SetBitmap(wxArtProvider::GetBitmap
		     (wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),
		      wxART_MAKE_CLIENT_ID_FROM_STR(wxString(wxEmptyString))));
#else
  fwdbtn->SetLabel(_("Segue >>"));
  backbtn->SetLabel(_("<< Volta"));
#endif

  wxGridCellAttr *
    myAttr = new wxGridCellAttr();
  wxGridCellChoiceEditor *
    editor = new wxGridCellChoiceEditor();
  myAttr->SetEditor(editor);
  editor->SetParameters(_("EXATO,CARACTERE,DIFERENCA,APROX"));
  Grid3->SetColAttr(1, myAttr);
  myAttr = new wxGridCellAttr();
  myAttr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
  wxGridCellFloatEditor *
    feditor = new wxGridCellFloatEditor();
  myAttr->SetEditor(feditor);
  Grid3->SetColAttr(2, myAttr);
  myAttr = new wxGridCellAttr();
  myAttr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
  feditor = new wxGridCellFloatEditor();
  myAttr->SetEditor(feditor);
  Grid3->SetColAttr(3, myAttr);
  myAttr = new wxGridCellAttr();
  myAttr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
  feditor = new wxGridCellFloatEditor();
  myAttr->SetEditor(feditor);
  Grid3->SetColAttr(4, myAttr);

  Grid2->SetDefaultCellOverflow(false);
  Grid3->SetDefaultCellOverflow(false);
}

wizlnk::~wizlnk()
{
  //(*Destroy(wizlnk)
  //*)
}

void
wizlnk::Onbtnadd3Click(wxCommandEvent & event)
{
  Grid3->AppendRows();
}

void
wizlnk::Onbtndel3Click(wxCommandEvent & event)
{
  //int current = Grid3->GetGridCursorRow();
  wxArrayInt selrows = Grid3->GetSelectedRows();
  for (int i = 0; i < selrows.Count(); i++)
    Grid3->DeleteRows(selrows[i]);
}

void
wizlnk::Onbtnclear3Click(wxCommandEvent & event)
{
  int current = Grid3->GetGridCursorRow();
  for (int i = 0; i < 6; i++)
    Grid3->SetCellValue(current, i, _T(""));
}

void
wizlnk::OnBitmapButton3Click(wxCommandEvent & event)
{
  int row = Grid3->GetGridCursorRow();
  if (row > 0)
    if (Grid3->GetNumberRows() > row)
    {
      wxString swap;
      for (int i = 0; i < 6; i++)
      {
	swap = Grid3->GetCellValue(row, i);
	Grid3->SetCellValue(row, i, Grid3->GetCellValue(row - 1, i));
	Grid3->SetCellValue(row - 1, i, swap);
      }
      Grid3->SetGridCursor(row - 1, 0);
    }
}

void
wizlnk::OnBitmapButton6Click(wxCommandEvent & event)
{
  int row = Grid3->GetGridCursorRow();
  if (row < (Grid3->GetNumberRows() - 1))
    if (Grid3->GetNumberRows() > row)
    {
      wxString swap;
      for (int i = 0; i < 6; i++)
      {
	swap = Grid3->GetCellValue(row, i);
	Grid3->SetCellValue(row, i, Grid3->GetCellValue(row + 1, i));
	Grid3->SetCellValue(row + 1, i, swap);
      }
      Grid3->SetGridCursor(row + 1, 0);
    }
}

void
wizlnk::Onbtnadd2Click(wxCommandEvent & event)
{
  Grid2->AppendRows();
}

void
wizlnk::Onbtndel2Click(wxCommandEvent & event)
{
  //int current = Grid2->GetGridCursorRow();
  wxArrayInt selrows = Grid2->GetSelectedRows();
  for (int i = 0; i < selrows.Count(); i++)
    Grid2->DeleteRows(selrows[i]);
}

void
wizlnk::Onbtnclear2Click(wxCommandEvent & event)
{
  int current = Grid2->GetGridCursorRow();
  Grid2->SetCellValue(current, 0, _T(""));
  Grid2->SetCellValue(current, 1, _T(""));
}

void
wizlnk::OnBitmapButton4Click(wxCommandEvent & event)
{
  int row = Grid2->GetGridCursorRow();
  if (row > 0)
    if (Grid2->GetNumberRows() > row)
    {
      wxString swap;
      swap = Grid2->GetCellValue(row, 0);
      Grid2->SetCellValue(row, 0, Grid2->GetCellValue(row - 1, 0));
      Grid2->SetCellValue(row - 1, 0, swap);
      swap = Grid2->GetCellValue(row, 1);
      Grid2->SetCellValue(row, 1, Grid2->GetCellValue(row - 1, 1));
      Grid2->SetCellValue(row - 1, 1, swap);
    }
  Grid2->SetGridCursor(row - 1, 0);
}

void
wizlnk::OnBitmapButton5Click(wxCommandEvent & event)
{
  int row = Grid2->GetGridCursorRow();
  if (row < (Grid2->GetNumberRows() - 1))
    if (Grid2->GetNumberRows() > row)
    {
      wxString swap;
      swap = Grid2->GetCellValue(row, 0);
      Grid2->SetCellValue(row, 0, Grid2->GetCellValue(row + 1, 0));
      Grid2->SetCellValue(row + 1, 0, swap);
      swap = Grid2->GetCellValue(row, 1);
      Grid2->SetCellValue(row, 1, Grid2->GetCellValue(row + 1, 1));
      Grid2->SetCellValue(row + 1, 1, swap);
    }
  Grid2->SetGridCursor(row + 1, 0);
}

void
wizlnk::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog2->SetWildcard(_T("*.lnkcfg"));
  FileDialog2->SetMessage(_("Selecione o arquivo de configuração"));
  //FileDialog1->SetStyle(wxOPEN);
  if (FileDialog2->ShowModal() == wxID_OK)
  {
    wxFileName cffilename = wxFileName(FileDialog2->GetPath());
    cffilename.SetExt(_T("lnkcfg"));
    wxString fname = cffilename.GetFullPath();
    cfgfilenamectrl->SetValue(fname);
    if (wxFileExists(fname))
    {
      int answer =
	wxMessageBox(_
		     ("Já existe uma configuração associada\na este arquivo, deseja utilizá-la?"),
_("CONFIGURAÇÃO DISPONÍVEL"),
wxYES_NO);
      if (answer == wxYES)
	loadcfg();
    }
  }
}

wxString wizlnk::loadfields(wxArrayString * list, wxString fname)
{
  wxString
    retval = _T("");

  list->Clear();
  int
    nflds;
  try
  {
    ntable
      in_dbf;
    in_dbf.open(fname);
    nflds = in_dbf.getnumfields();
    for (int i = 0; i < nflds; i++)
      list->Add(in_dbf.getfieldname(i));
    in_dbf.close();
  } catch( ...)
  {
  };

  retval = list->Item(0);
  for (int i = 1; i < nflds; i++)
    retval = retval + _T(",") + list->Item(i);

  return retval;
}

void
wizlnk::OnopencompfileClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  FileDialog1->SetMessage(_("Selecione o arquivo de comparação"));

  if (FileDialog1->ShowModal() == wxID_OK)
  {
    compfilenamectrl->SetValue(FileDialog1->GetPath());
    if (comparenames())
    {
      compfilenamectrl->SetValue(_T(""));
      wxMessageBox(_("Os nomes dos arquivos\ndevem ser diferentes."), _("ERRO"), wxICON_ERROR);
    }
    else
    {
      wxString fname = compfilenamectrl->GetValue();
      if (wxFileExists(fname))
      {
	wxString listoffields = loadfields(&compflds, fname);
	wxGridCellAttr *myAttr = new wxGridCellAttr();
	wxGridCellChoiceEditor *editor = new wxGridCellChoiceEditor();
	myAttr->SetEditor(editor);
	editor->SetParameters(listoffields);
	Grid2->SetColAttr(0, myAttr);
	editor = new wxGridCellChoiceEditor();
	myAttr = new wxGridCellAttr();
	myAttr->SetEditor(editor);
	editor->SetParameters(listoffields);
	Grid3->SetColAttr(0, myAttr);
      }
      else
      {
	compfilenamectrl->SetValue(_T(""));
	wxMessageBox(_("Este arquivo não existe."), _("ERRO"), wxICON_ERROR);
      }
    }
  }
}

void
wizlnk::OnopenreffileClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  FileDialog1->SetMessage(_("Selecione o arquivo de referência"));

  if (FileDialog1->ShowModal() == wxID_OK)
  {
    reffilenamectrl->SetValue(FileDialog1->GetPath());
    if (comparenames())
    {
      reffilenamectrl->SetValue(_T(""));
      wxMessageBox(_("Os nomes dos arquivos\ndevem ser diferentes."), _("ERRO"), wxICON_ERROR);
    }
    else
    {
      wxString fname = reffilenamectrl->GetValue();
      if (wxFileExists(fname))
      {
	wxString listoffields = loadfields(&refflds, fname);
	wxGridCellAttr *myAttr = new wxGridCellAttr();
	wxGridCellChoiceEditor *editor = new wxGridCellChoiceEditor();
	myAttr->SetEditor(editor);
	editor->SetParameters(listoffields);
	Grid2->SetColAttr(1, myAttr);
	editor = new wxGridCellChoiceEditor();
	myAttr = new wxGridCellAttr();
	myAttr->SetEditor(editor);
	editor->SetParameters(listoffields);
	Grid3->SetColAttr(5, myAttr);
      }
      else
      {
	compfilenamectrl->SetValue(_T(""));
	wxMessageBox(_("Este arquivo não existe."), _("ERRO"), wxICON_ERROR);
      }
    }
  }
}

void
wizlnk::OnokbtnClick(wxCommandEvent & event)
{
  savecfg();
  ops_log log;
  log.log_event(_T("LNKC"), cfgfilenamectrl->GetValue());
  Close();
}

void
wizlnk::OnbackbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(false);
}

void
wizlnk::OnfwdbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(true);
}

void
wizlnk::loadcfg(void)
{
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgfilenamectrl->GetValue(), _T(""), wxCONFIG_USE_LOCAL_FILE);
  wxString aux = _T("");
  cfgfile->Read(_T("FILES/COMPNAME"), &aux);
  compfilenamectrl->SetValue(aux);

  if (wxFileExists(aux))
  {
    wxString listoffields = loadfields(&compflds, aux);
    wxGridCellAttr *myAttr = new wxGridCellAttr();
    wxGridCellChoiceEditor *editor = new wxGridCellChoiceEditor();
    myAttr->SetEditor(editor);
    editor->SetParameters(listoffields);
    Grid2->SetColAttr(0, myAttr);
    editor = new wxGridCellChoiceEditor();
    myAttr = new wxGridCellAttr();
    myAttr->SetEditor(editor);
    editor->SetParameters(listoffields);
    Grid3->SetColAttr(0, myAttr);
  }

  aux = _T("");
  cfgfile->Read(_T("FILES/REFNAME"), &aux);
  reffilenamectrl->SetValue(aux);

  if (wxFileExists(aux))
  {
    wxString listoffields = loadfields(&refflds, aux);
    wxGridCellAttr *myAttr = new wxGridCellAttr();
    wxGridCellChoiceEditor *editor = new wxGridCellChoiceEditor();
    myAttr->SetEditor(editor);
    editor->SetParameters(listoffields);
    Grid2->SetColAttr(1, myAttr);
    editor = new wxGridCellChoiceEditor();
    myAttr = new wxGridCellAttr();
    myAttr->SetEditor(editor);
    editor->SetParameters(listoffields);
    Grid3->SetColAttr(5, myAttr);
  }

  aux = _T("");
  cfgfile->Read(_T("GENERAL/IXNAME"), &aux);
  TextCtrl1->SetValue(aux);

  aux = _T("");
  cfgfile->Read(_T("GENERAL/IGNORE"), &aux);
  CheckBox1->SetValue((aux == _T("Y")));
  if (CheckBox1->GetValue())
    TextCtrl2->Enable();
  else
    TextCtrl2->Disable();

  aux = _T("");
  cfgfile->Read(_T("GENERAL/MINSCORE"), &aux);
  TextCtrl2->SetValue(aux);

  wxString tmp;

  long nlines = 0l;
  cfgfile->Read(_T("BLOCK/NLINES"), &nlines);
  int glines = Grid2->GetNumberRows();
  if (glines > (int) nlines)
  {
    glines -= (int) nlines;
    Grid2->DeleteRows(0, glines);
  }
  else if (glines < (int) nlines)
  {
    glines = (int) nlines - glines;
    Grid2->AppendRows(glines);
  }
  for (int i = 0; i < (int) nlines; i++)
  {
    tmp = _T("");
    aux.Printf(_T("BLOCK/COMP%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid2->SetCellValue(i, 0, tmp);
    tmp = _T("");
    aux.Printf(_T("BLOCK/REF%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid2->SetCellValue(i, 1, tmp);
  }

  nlines = 0L;
  cfgfile->Read(_T("COMPARE/NLINES"), &nlines);
  glines = Grid3->GetNumberRows();
  if (glines > (int) nlines)
  {
    glines -= (int) nlines;
    Grid3->DeleteRows(0, glines);
  }
  else if (glines < (int) nlines)
  {
    glines = (int) nlines - glines;
    Grid3->AppendRows(glines);
  }
  for (int i = 0; i < (int) nlines; i++)
  {
    tmp = _T("");
    aux.Printf(_T("COMPARE/COMP%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 0, tmp);
    tmp = _T("");
    aux.Printf(_T("COMPARE/PROC%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 1, tmp);
    tmp = _T("");
    aux.Printf(_T("COMPARE/CORRECT%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 2, tmp);
    tmp = _T("");
    aux.Printf(_T("COMPARE/INCORRECT%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 3, tmp);
    tmp = _T("");
    aux.Printf(_T("COMPARE/THRESH%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 4, tmp);
    tmp = _T("");
    aux.Printf(_T("COMPARE/REF%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 5, tmp);
  }
  delete cfgfile;
}

void
wizlnk::savecfg(void)
{
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgfilenamectrl->GetValue(), _T(""), wxCONFIG_USE_LOCAL_FILE);
  cfgfile->Write(_T("FILES/COMPNAME"), compfilenamectrl->GetValue());
  cfgfile->Write(_T("FILES/REFNAME"), reffilenamectrl->GetValue());
  cfgfile->Write(_T("GENERAL/IXNAME"), TextCtrl1->GetValue());
  wxString aux;
  if (CheckBox1->GetValue())
    aux = _T("Y");
  else
    aux = _T("N");
  cfgfile->Write(_T("GENERAL/IGNORE"), aux);

  cfgfile->Write(_T("GENERAL/MINSCORE"), TextCtrl2->GetValue());

  int nlines = Grid2->GetNumberRows();
  cfgfile->Write(_T("BLOCK/NLINES"), nlines);
  for (int i = 0; i < nlines; i++)
  {
    aux.Printf(_T("BLOCK/COMP%d"), i);
    cfgfile->Write(aux, Grid2->GetCellValue(i, 0));
    aux.Printf(_T("BLOCK/REF%d"), i);
    cfgfile->Write(aux, Grid2->GetCellValue(i, 1));
  }

  nlines = Grid3->GetNumberRows();
  cfgfile->Write(_T("COMPARE/NLINES"), nlines);
  for (int i = 0; i < nlines; i++)
  {
    aux.Printf(_T("COMPARE/COMP%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 0));
    aux.Printf(_T("COMPARE/PROC%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 1));
    aux.Printf(_T("COMPARE/CORRECT%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 2));
    aux.Printf(_T("COMPARE/INCORRECT%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 3));
    aux.Printf(_T("COMPARE/THRESH%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 4));
    aux.Printf(_T("COMPARE/REF%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 5));
  }
  delete cfgfile;
}

void
wizlnk::analyze(void)
{
  errrep->Clear();

  wxString tmp, ax;
  wxArrayString prevflds;

  if (cfgfilenamectrl->GetValue().IsEmpty())
    errrep->AppendText(_("Arquivo de configuração não definido\n"));

  if (compfilenamectrl->GetValue().IsEmpty())
    errrep->AppendText(_("Arquivo de comparação não definido\n"));
  if (compfilenamectrl->GetValue().IsEmpty())
    errrep->AppendText(_("Arquivo de referência não definido\n"));

  int j;

  int nopts = Grid2->GetNumberRows();
  for (int i = 0; i < nopts; i++)
  {
    if (Grid2->GetCellValue(i, 0).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem campo de blocagem (Comp)\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    else
    {
      ax = Grid2->GetCellValue(i, 0);
      int j;
      int nflds = compflds.Count();
      for (j = 0; j < nflds; j++)
	if (ax == compflds[j])
	  break;
      if (j >= nflds)
      {
	tmp.Printf(_("Linha %d com campo de blocagem inválido (Comp)\n"), (i + 1));
	errrep->AppendText(tmp);
      }
    }
    if (Grid2->GetCellValue(i, 1).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem campo de blocagem (Ref)\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    else
    {
      ax = Grid2->GetCellValue(i, 1);
      int nflds = refflds.Count();
      for (j = 0; j < nflds; j++)
	if (ax == refflds[j])
	  break;
      if (j >= nflds)
      {
	tmp.Printf(_("Linha %d com campo de blocagem inválido (Ref)\n"), (i + 1));
	errrep->AppendText(tmp);
      }
    }
  }
  if (nopts == 0)
    errrep->AppendText(_("Nenhum critério de blocagem definido\n"));
  if (TextCtrl1->GetValue().IsEmpty())
    errrep->AppendText(_("Nome de índice não definido\n"));

  nopts = Grid3->GetNumberRows();
  for (int i = 0; i < nopts; i++)
  {
    if (Grid3->GetCellValue(i, 0).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem campo de comparação (Comp)\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    else
    {
      ax = Grid3->GetCellValue(i, 0);
      int j;
      int nflds = compflds.Count();
      for (j = 0; j < nflds; j++)
	if (ax == compflds[j])
	  break;
      if (j >= nflds)
      {
	tmp.Printf(_("Linha %d com campo de comparação inválido (Comp)\n"), (i + 1));
	errrep->AppendText(tmp);
      }
    }
    if (Grid3->GetCellValue(i, 5).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem campo de comparação (Ref)\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    else
    {
      ax = Grid3->GetCellValue(i, 5);
      int nflds = refflds.Count();
      for (j = 0; j < nflds; j++)
	if (ax == refflds[j])
	  break;
      if (j >= nflds)
      {
	tmp.Printf(_("Linha %d com campo de comparação inválido (Ref)\n"), (i + 1));
	errrep->AppendText(tmp);
      }
    }
    ax = Grid3->GetCellValue(i, 1);
    if (ax.IsEmpty())
    {
      tmp.Printf(_("Linha %d sem tipo de comparação\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    if (Grid3->GetCellValue(i, 2).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem valor correto\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    if (Grid3->GetCellValue(i, 3).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem valor incorreto\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    if (Grid3->GetCellValue(i, 4).IsEmpty())
    {
      if (ax != _("EXATO"))
      {
	tmp.Printf(_("Linha %d sem limiar\n"), (i + 1));
	errrep->AppendText(tmp);
      }
    }
  }
  if (nopts == 0)
    errrep->AppendText(_("Nenhum critério de comparação definido\n"));
}

void
wizlnk::OnListbook1PageChanged(wxNotebookEvent & event)
{
  if (Listbook1->GetCurrentPage() == Panel8)
  {
    analyze();
    int nlines = errrep->GetNumberOfLines();
    if ((nlines == 1) && errrep->GetLineText(0).IsEmpty())
      okbtn->Enable();
    else
      okbtn->Disable();

  }
  if (Listbook1->GetCurrentPage() == Panel7)
    calcparms();
  event.Skip();
}

void
wizlnk::calcparms(void)
{
  double max = 0.0, min = 0.0, m, u;
  wxString val;
  int nlines = Grid3->GetNumberRows();
  int i;
  for (i = 0; i < nlines; i++)
  {
    if (!(Grid3->GetCellValue(i, 0).IsEmpty()))
    {
      val = Grid3->GetCellValue(i, 2);
      if (val.ToDouble(&m))
      {
	m = m / 100.0;
	val = Grid3->GetCellValue(i, 3);
	val.Replace(CVTFROM, CVTTO);
	if (val.ToDouble(&u))
	{
	  u = u / 100.0;
	  max += ppos(m, u);
	  min += npos(m, u);
	}
	else
	  break;
      }
      else
	break;
    }
    else
      break;
  }

  if (i >= nlines)
  {
    val.Printf(_T("%g"), max);
    maxscore->SetLabel(val);
    val.Printf(_T("%g"), min);
    minscore->SetLabel(val);
  }
  else
  {
    val = _("ERRO");
    maxscore->SetLabel(val);
    minscore->SetLabel(val);
    wxMessageBox(_("Verifique por favor os parâmetros."), _("ERRO DE CÁLCULO"), wxICON_ERROR);
  }
}

bool wizlnk::comparenames(void)
{
  bool
    retval = false;

  wxString
    f1 = compfilenamectrl->GetValue();
  wxString
    f2 = reffilenamectrl->GetValue();

  if (!f1.IsEmpty() && !f2.IsEmpty() && (!f1.Cmp(f2)))
    retval = true;

  return retval;
}

void
wizlnk::OnCheckBox1Click(wxCommandEvent & event)
{
  if (CheckBox1->GetValue())
    TextCtrl2->Enable();
  else
    TextCtrl2->Disable();
}
