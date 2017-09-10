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
// Nome:        wizdup.cpp
// Propósito:   Classe (janela) para configurar deduplicação
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "wizdup.h"
#include "ntable.h"
#include "calc.h"
#include "ops_log.h"

#include "checksep.h"

#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>

//(*InternalHeaders(wizdup)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/tglbtn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(wizdup)
const long
  wizdup::ID_STATICTEXT1 = wxNewId();
const long
  wizdup::ID_PANEL3 = wxNewId();
const long
  wizdup::ID_TEXTCTRL2 = wxNewId();
const long
  wizdup::ID_BITMAPBUTTON2 = wxNewId();
const long
  wizdup::ID_TEXTCTRL3 = wxNewId();
const long
  wizdup::ID_BITMAPBUTTON3 = wxNewId();
const long
  wizdup::ID_STATICTEXT3 = wxNewId();
const long
  wizdup::ID_STATICTEXT4 = wxNewId();
const long
  wizdup::ID_PANEL4 = wxNewId();
const long
  wizdup::ID_GRID3 = wxNewId();
const long
  wizdup::ID_BUTTON12 = wxNewId();
const long
  wizdup::ID_BUTTON13 = wxNewId();
const long
  wizdup::ID_BUTTON14 = wxNewId();
const long
  wizdup::ID_BITMAPBUTTON7 = wxNewId();
const long
  wizdup::ID_BITMAPBUTTON6 = wxNewId();
const long
  wizdup::ID_PANEL5 = wxNewId();
const long
  wizdup::ID_STATICTEXT7 = wxNewId();
const long
  wizdup::ID_STATICTEXT8 = wxNewId();
const long
  wizdup::ID_STATICTEXT9 = wxNewId();
const long
  wizdup::ID_STATICTEXT10 = wxNewId();
const long
  wizdup::ID_STATICTEXT11 = wxNewId();
const long
  wizdup::ID_STATICTEXT12 = wxNewId();
const long
  wizdup::ID_TEXTCTRL6 = wxNewId();
const long
  wizdup::ID_PANEL7 = wxNewId();
const long
  wizdup::ID_TEXTCTRL4 = wxNewId();
const long
  wizdup::ID_STATICTEXT2 = wxNewId();
const long
  wizdup::ID_PANEL8 = wxNewId();
const long
  wizdup::ID_LISTBOOK1 = wxNewId();
const long
  wizdup::ID_BUTTON1 = wxNewId();
const long
  wizdup::ID_BUTTON2 = wxNewId();
const long
  wizdup::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wizdup, wxDialog)
  //(*EventTable(wizdup)
  //*)
  END_EVENT_TABLE()wizdup::wizdup(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				  const wxSize & size)
{
  //(*Initialize(wizdup)
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
    new wxStaticText(Panel3, ID_STATICTEXT1, _("Deduplica"), wxPoint(16, 8), wxDefaultSize, 0,
		     _T("ID_STATICTEXT1"));
  wxFont
    StaticText1Font(14, wxSWISS, wxFONTSTYLE_NORMAL, wxBOLD, false, _T("Sans"),
		    wxFONTENCODING_DEFAULT);
  StaticText1->SetFont(StaticText1Font);
  FlexGridSizer1->Add(Panel3, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  Listbook1 =
    new wxNotebook(this, ID_LISTBOOK1, wxDefaultPosition, wxSize(523, 276), 0, _T("ID_LISTBOOK1"));
  Panel4 =
    new wxPanel(Listbook1, ID_PANEL4, wxPoint(202, 14), wxSize(523, 260), wxTAB_TRAVERSAL,
		_T("ID_PANEL4"));
  updatefilenamectrl =
    new wxTextCtrl(Panel4, ID_TEXTCTRL2, wxEmptyString, wxPoint(40, 72), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
  openupdatefile =
    new wxBitmapButton(Panel4, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(448, 72), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  cfgfilenamectrl =
    new wxTextCtrl(Panel4, ID_TEXTCTRL3, wxEmptyString, wxPoint(40, 144), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
  opencfgfile =
    new wxBitmapButton(Panel4, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE")),
						wxART_BUTTON), wxPoint(448, 144), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
  StaticText3 =
    new wxStaticText(Panel4, ID_STATICTEXT3, _("Arquivo de atualização:"), wxPoint(48, 48),
		     wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  StaticText4 =
    new wxStaticText(Panel4, ID_STATICTEXT4, _("Arquivo de configuração:"), wxPoint(48, 120),
		     wxDefaultSize, 0, _T("ID_STATICTEXT4"));
  Panel5 =
    new wxPanel(Listbook1, ID_PANEL5, wxPoint(174, 11), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL5"));
  Grid3 = new wxGrid(Panel5, ID_GRID3, wxPoint(16, 24), wxSize(448, 168), 0, _T("ID_GRID3"));
  Grid3->CreateGrid(1, 6);
  Grid3->EnableEditing(true);
  Grid3->EnableGridLines(true);
  Grid3->SetColLabelSize(20);
  Grid3->SetRowLabelSize(40);
  Grid3->SetDefaultColSize(65, true);
  Grid3->SetColLabelValue(0, _("Campo"));
  Grid3->SetColLabelValue(1, _("Bloco"));
  Grid3->SetColLabelValue(2, _("Comp."));
  Grid3->SetColLabelValue(3, _("Corr."));
  Grid3->SetColLabelValue(4, _("Inc."));
  Grid3->SetColLabelValue(5, _("Lim."));
  Grid3->SetDefaultCellFont(Grid3->GetFont());
  Grid3->SetDefaultCellTextColour(Grid3->GetForegroundColour());
  btnadd3 =
    new wxButton(Panel5, ID_BUTTON12, _("Adiciona"), wxPoint(104, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON12"));
  btndel3 =
    new wxButton(Panel5, ID_BUTTON13, _("Remove"), wxPoint(224, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON13"));
  btnclear3 =
    new wxButton(Panel5, ID_BUTTON14, _("Limpa"), wxPoint(344, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON14"));
  BitmapButton3 =
    new wxBitmapButton(Panel5, ID_BITMAPBUTTON7,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),
						wxART_BUTTON), wxPoint(480, 40), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
  BitmapButton6 =
    new wxBitmapButton(Panel5, ID_BITMAPBUTTON6,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),
						wxART_BUTTON), wxPoint(480, 80), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
  BitmapButton6->SetDefault();
  Panel7 =
    new wxPanel(Listbook1, ID_PANEL7, wxPoint(160, 15), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL7"));
  StaticText7 =
    new wxStaticText(Panel7, ID_STATICTEXT7, _("Escore mínimo:"), wxPoint(60, 140), wxDefaultSize,
		     0, _T("ID_STATICTEXT7"));
  StaticText8 =
    new wxStaticText(Panel7, ID_STATICTEXT8, _("Máximo:"), wxPoint(80, 72), wxSize(64, 17), 0,
		     _T("ID_STATICTEXT8"));
  StaticText9 =
    new wxStaticText(Panel7, ID_STATICTEXT9,
		     _("Limites de escores possíveis\ncom a configuração corrente:"), wxPoint(60,
												 24),
		     wxDefaultSize, 0, _T("ID_STATICTEXT9"));
  StaticText10 =
    new wxStaticText(Panel7, ID_STATICTEXT10, _("Mínimo:"), wxPoint(80, 104), wxDefaultSize, 0,
		     _T("ID_STATICTEXT10"));
  maxscore =
    new wxStaticText(Panel7, ID_STATICTEXT11, _("NNNN"), wxPoint(180, 72), wxDefaultSize, 0,
		     _T("ID_STATICTEXT11"));
  minscore =
    new wxStaticText(Panel7, ID_STATICTEXT12, _("NNNN"), wxPoint(180, 104), wxDefaultSize, 0,
		     _T("ID_STATICTEXT12"));
  TextCtrl2 =
    new wxTextCtrl(Panel7, ID_TEXTCTRL6, _("0"), wxPoint(170, 135), wxDefaultSize, wxTE_RIGHT,
		   wxDefaultValidator, _T("ID_TEXTCTRL6"));
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
  Listbook1->AddPage(Panel4, _("Arquivos"), false);
  Listbook1->AddPage(Panel5, _("Processos"), false);
  Listbook1->AddPage(Panel7, _("Escore mínimo"), false);
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

  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::OnopenupdatefileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::OnopencfgfileClick);
  Connect(ID_BUTTON12, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::Onbtnadd3Click);
  Connect(ID_BUTTON13, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::Onbtndel3Click);
  Connect(ID_BUTTON14, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::Onbtnclear3Click);
  Connect(ID_BITMAPBUTTON7, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::OnBitmapButton3Click);
  Connect(ID_BITMAPBUTTON6, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::OnBitmapButton6Click);
  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & wizdup::OnokbtnClick);
  Connect(ID_LISTBOOK1, wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,
	  (wxObjectEventFunction) & wizdup::OnListbook1PageChanged);
  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::OnbackbtnClick);
  Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizdup::OnfwdbtnClick);
  //*)

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
    myAttr;
  myAttr = new wxGridCellAttr();
  wxGridCellBoolEditor *
    beditor = new wxGridCellBoolEditor();
  myAttr->SetEditor(beditor);
  wxGridCellBoolRenderer *
    brenderer = new wxGridCellBoolRenderer();
  myAttr->SetRenderer(brenderer);
  Grid3->SetColAttr(1, myAttr);
  wxGridCellChoiceEditor *
    editor;
  myAttr = new wxGridCellAttr();
  editor = new wxGridCellChoiceEditor();
  myAttr->SetEditor(editor);
  editor->SetParameters(_("EXATO,CARACTERE,DIFERENCA,APROX"));
  Grid3->SetColAttr(2, myAttr);
  myAttr = new wxGridCellAttr();
  myAttr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
  wxGridCellFloatEditor *
    feditor = new wxGridCellFloatEditor();
  myAttr->SetEditor(feditor);
  Grid3->SetColAttr(3, myAttr);
  myAttr = new wxGridCellAttr();
  myAttr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
  feditor = new wxGridCellFloatEditor();
  myAttr->SetEditor(feditor);
  Grid3->SetColAttr(4, myAttr);
  myAttr = new wxGridCellAttr();
  myAttr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
  feditor = new wxGridCellFloatEditor();
  myAttr->SetEditor(feditor);
  Grid3->SetColAttr(5, myAttr);
  Grid3->SetDefaultCellOverflow(false);
}

wizdup::~wizdup()
{
  //(*Destroy(wizdup)
  //*)
}

void
wizdup::Onbtnadd3Click(wxCommandEvent & event)
{
  Grid3->AppendRows();
}

void
wizdup::Onbtndel3Click(wxCommandEvent & event)
{
  //int current = Grid3->GetGridCursorRow();
  wxArrayInt selrows = Grid3->GetSelectedRows();
  for (int i = 0; i < selrows.Count(); i++)
    Grid3->DeleteRows(selrows[i]);
}

void
wizdup::Onbtnclear3Click(wxCommandEvent & event)
{
  int current = Grid3->GetGridCursorRow();
  for (int i = 0; i < 6; i++)
    Grid3->SetCellValue(current, i, _T(""));
}

void
wizdup::OnBitmapButton3Click(wxCommandEvent & event)
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
wizdup::OnBitmapButton6Click(wxCommandEvent & event)
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
wizdup::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog2->SetWildcard(_T("*.dupcfg"));
  FileDialog2->SetMessage(_("Selecione o arquivo de configuração"));
  //FileDialog1->SetStyle(wxOPEN);
  if (FileDialog2->ShowModal() == wxID_OK)
  {
    wxFileName cffilename = wxFileName(FileDialog2->GetPath());
    cffilename.SetExt(_T("dupcfg"));
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

wxString wizdup::loadfields(wxString fname)
{
  wxString
    retval = _T("");

  fieldnames.Clear();
  int
    nflds;
  try
  {
    ntable
      in_dbf;
    in_dbf.open(fname);
    nflds = in_dbf.getnumfields();
    wxString
      aux;
    for (int i = 0; i < nflds; i++)
    {
      aux = in_dbf.getfieldname(i);
      fieldnames.Add(aux);
    }
    in_dbf.close();
  } catch( ...)
  {
  };

  retval = fieldnames[0];
  nflds = fieldnames.Count();
  for (int i = 1; i < nflds; i++)
    retval = retval + _T(",") + fieldnames[i];

  return retval;
}

void
wizdup::OnopenupdatefileClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  FileDialog1->SetMessage(_("Selecione o arquivo de atualização"));
  //FileDialog1->SetStyle(wxOPEN | wxFILE_MUST_EXIST);
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    updatefilenamectrl->SetValue(FileDialog1->GetPath());
    wxString fname = updatefilenamectrl->GetValue();
    if (wxFileExists(fname))
    {
      wxString listoffields = loadfields(fname);
      wxGridCellAttr *myAttr = new wxGridCellAttr();
      wxGridCellChoiceEditor *editor = new wxGridCellChoiceEditor();
      myAttr->SetEditor(editor);
      editor->SetParameters(listoffields);
      Grid3->SetColAttr(0, myAttr);
    }
    else
    {
      updatefilenamectrl->SetValue(_T(""));
      wxMessageBox(_("Este arquivo não existe."), _T("ERRO"), wxICON_ERROR);
    }
  }
}

void
wizdup::OnokbtnClick(wxCommandEvent & event)
{
  savecfg();
  ops_log log;
  log.log_event(_T("DUPC"), cfgfilenamectrl->GetValue());
  EndModal(wxID_OK);
}

void
wizdup::OnbackbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(false);
}

void
wizdup::OnfwdbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(true);
}

void
wizdup::loadcfg(void)
{
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgfilenamectrl->GetValue(), _T(""), wxCONFIG_USE_LOCAL_FILE);
  wxString aux = _T("");
  cfgfile->Read(_T("FILES/UPDATENAME"), &aux);
  updatefilenamectrl->SetValue(aux);

  if (wxFileExists(aux))
  {
    wxString listoffields = loadfields(aux);
    wxGridCellAttr *myAttr = new wxGridCellAttr();
    wxGridCellChoiceEditor *editor = new wxGridCellChoiceEditor();
    myAttr->SetEditor(editor);
    editor->SetParameters(listoffields);
    Grid3->SetColAttr(0, myAttr);
  }

  wxString tmp;

  long nlines = 0l;
  cfgfile->Read(_T("PROCESS/NLINES"), &nlines);
  int glines = Grid3->GetNumberRows();
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
    aux.Printf(_T("PROCESS/UPDATE%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 0, tmp);
    tmp = _T("");
    aux.Printf(_T("PROCESS/BLOCK%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 1, tmp);
    tmp = _T("");
    aux.Printf(_T("PROCESS/PROC%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 2, tmp);
    tmp = _T("");
    aux.Printf(_T("PROCESS/CORRECT%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 3, tmp);
    tmp = _T("");
    aux.Printf(_T("PROCESS/INCORRECT%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 4, tmp);
    tmp = _T("");
    aux.Printf(_T("PROCESS/THRESH%d"), i);
    cfgfile->Read(aux, &tmp);
    Grid3->SetCellValue(i, 5, tmp);
    tmp = _T("");
  }
  aux = _T("");
  cfgfile->Read(_T("GENERAL/MINSCORE"), &aux);
  TextCtrl2->SetValue(aux);
}

void
wizdup::savecfg(void)
{
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgfilenamectrl->GetValue(), _T(""), wxCONFIG_USE_LOCAL_FILE);
  cfgfile->Write(_T("FILES/UPDATENAME"), updatefilenamectrl->GetValue());

  int nlines = Grid3->GetNumberRows();
  cfgfile->Write(_T("PROCESS/NLINES"), nlines);
  wxString aux;
  for (int i = 0; i < nlines; i++)
  {
    aux.Printf(_T("PROCESS/UPDATE%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 0));
    aux.Printf(_T("PROCESS/BLOCK%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 1));
    aux.Printf(_T("PROCESS/PROC%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 2));
    aux.Printf(_T("PROCESS/CORRECT%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 3));
    aux.Printf(_T("PROCESS/INCORRECT%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 4));
    aux.Printf(_T("PROCESS/THRESH%d"), i);
    cfgfile->Write(aux, Grid3->GetCellValue(i, 5));
  }
  cfgfile->Write(_T("GENERAL/MINSCORE"), TextCtrl2->GetValue());

  delete cfgfile;
}

void
wizdup::analyze(void)
{
  errrep->Clear();

  wxString tmp, ax;
  wxArrayString prevflds;

  if (cfgfilenamectrl->GetValue().IsEmpty())
    errrep->AppendText(_("Arquivo de configuração não definido\n"));

  if (updatefilenamectrl->GetValue().IsEmpty())
    errrep->AppendText(_("Arquivo de atualização não definido\n"));

  int nopts = Grid3->GetNumberRows();
  for (int i = 0; i < nopts; i++)
  {
    if (Grid3->GetCellValue(i, 0).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem campo de atualização\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    else
    {
      ax = Grid3->GetCellValue(i, 0);
      int j;
      int nflds = fieldnames.Count();
      for (j = 0; j < nflds; j++)
	if (ax == fieldnames[j])
	  break;
      if (j >= nflds)
      {
	tmp.Printf(_("Linha %d com campo de atualização inválido\n"), (i + 1));
	errrep->AppendText(tmp);
      }
    }
    ax = Grid3->GetCellValue(i, 2);
    if (Grid3->GetCellValue(i, 1) != _T("1"))
    {
      if (ax.IsEmpty())
      {
	tmp.Printf(_("Linha %d sem tipo de comparação\n"), (i + 1));
	errrep->AppendText(tmp);
      }
      if (Grid3->GetCellValue(i, 3).IsEmpty())
      {
	tmp.Printf(_("Linha %d sem valor correto\n"), (i + 1));
	errrep->AppendText(tmp);
      }
      if (Grid3->GetCellValue(i, 4).IsEmpty())
      {
	tmp.Printf(_("Linha %d sem valor incorreto\n"), (i + 1));
	errrep->AppendText(tmp);
      }
      if (Grid3->GetCellValue(i, 5).IsEmpty())
      {
	if (ax != _("EXATO"))
	{
	  tmp.Printf(_("Linha %d sem limiar\n"), (i + 1));
	  errrep->AppendText(tmp);
	}
      }
    }
    else			// REMOVER ESSE ELSE; SE O CAMPO É DE BLOCAGEM, NÃO PODE COMPARAR
    {
      if (!ax.IsEmpty())
      {
	if (Grid3->GetCellValue(i, 3).IsEmpty())
	{
	  tmp.Printf(_("Linha %d sem valor correto\n"), (i + 1));
	  errrep->AppendText(tmp);
	}
	if (Grid3->GetCellValue(i, 4).IsEmpty())
	{
	  tmp.Printf(_("Linha %d sem valor incorreto\n"), (i + 1));
	  errrep->AppendText(tmp);
	}
	if (Grid3->GetCellValue(i, 5).IsEmpty())
	{
	  if (ax != _("EXATO"))
	  {
	    tmp.Printf(_("Linha %d sem limiar\n"), (i + 1));
	    errrep->AppendText(tmp);
	  }
	}
      }
    }
  }
  if (TextCtrl2->GetValue().IsEmpty())
    errrep->AppendText(_("Score mínimo não definido\n"));
  if (nopts == 0)
    errrep->AppendText(_("Nenhum critério definido\n"));
}

void
wizdup::OnListbook1PageChanged(wxNotebookEvent & event)
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
wizdup::calcparms(void)
{
  double max = 0.0, min = 0.0, m, u;
  wxString val;
  int nlines = Grid3->GetNumberRows();
  int i;
  bool calcok = true;
  for (i = 0; i < nlines; i++)
  {
    if (!(Grid3->GetCellValue(i, 2).IsEmpty()))
    {
      val = Grid3->GetCellValue(i, 3);
      val.Replace(CVTFROM, CVTTO);
      if (val.ToDouble(&m))
      {
	m = m / 100.0;
	val = Grid3->GetCellValue(i, 4);
	val.Replace(CVTFROM, CVTTO);
	if (val.ToDouble(&u))
	{
	  u = u / 100.0;
	  max += ppos(m, u);
	  min += npos(m, u);
	}
	else
	{
	  calcok = false;
	  break;
	}
      }
      else
      {
	calcok = false;
	break;
      }
    }
  }

  if (calcok)
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
