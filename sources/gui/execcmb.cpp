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
// Nome:        execcmb.cpp
// Propósito:   Classe (janela) para executar combinação de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "execcmb.h"

#include "ops_log.h"

//(*InternalHeaders(execcmb)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

#include <wx/msgdlg.h>
//(*IdInit(execcmb)
  const long
  execcmb::ID_TEXTCTRL2 = wxNewId();
const long
  execcmb::ID_BITMAPBUTTON2 = wxNewId();
const long
  execcmb::ID_TEXTCTRL4 = wxNewId();
const long
  execcmb::ID_BITMAPBUTTON4 = wxNewId();
const long
  execcmb::ID_BITMAPBUTTON5 = wxNewId();
const long
  execcmb::ID_BITMAPBUTTON1 = wxNewId();
const long
  execcmb::ID_STATICTEXT1 = wxNewId();
const long
  execcmb::ID_STATICTEXT4 = wxNewId();
const long
  execcmb::ID_STATICTEXT6 = wxNewId();
const long
  execcmb::ID_STATICTEXT3 = wxNewId();
const long
  execcmb::ID_GAUGE1 = wxNewId();
const long
  execcmb::ID_STATICTEXT2 = wxNewId();
const long
  execcmb::ID_STATICTEXT5 = wxNewId();
const long
  execcmb::ID_BITMAPBUTTON3 = wxNewId();
const long
  execcmb::ID_STATICLINE1 = wxNewId();
const long
  execcmb::ID_STATICLINE2 = wxNewId();
const long
  execcmb::ID_TEXTCTRL3 = wxNewId();
const long
  execcmb::ID_TEXTCTRL1 = wxNewId();
const long
  execcmb::ID_CHECKBOX1 = wxNewId();
const long
  execcmb::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(execcmb, wxDialog)
  //(*EventTable(execcmb)
  //*)
  END_EVENT_TABLE()execcmb::execcmb(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(execcmb)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, wxID_ANY, _("Executa combinação"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(523, 349));
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(501, 305), wxTAB_TRAVERSAL,
		_T("ID_PANEL1"));
  cfgfilenamectrl =
    new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(24, 32), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
  opencfgfile =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(432, 32), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  outfilenamectrl =
    new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxPoint(24, 80), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
  BitmapButton3 =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON4,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(432, 80), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
  opennewref =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON5,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(432, 128), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
  opennewref->Disable();
  opennewcomp =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(432, 176), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  opennewcomp->Disable();
  StaticText1 =
    new wxStaticText(Panel1, ID_STATICTEXT1, _("Arq. configuração de relacionamento"),
		     wxPoint(32, 16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  StaticText4 =
    new wxStaticText(Panel1, ID_STATICTEXT4, _("Arq. combinado"), wxPoint(32, 64), wxDefaultSize, 0,
		     _T("ID_STATICTEXT4"));
  StaticText6 =
    new wxStaticText(Panel1, ID_STATICTEXT6, _("Novo arq. referência"), wxPoint(32, 112),
		     wxDefaultSize, 0, _T("ID_STATICTEXT6"));
  StaticText6->Disable();
  StaticText3 =
    new wxStaticText(Panel1, ID_STATICTEXT3, _("Novo arq. comparação"), wxPoint(32, 160),
		     wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  StaticText3->Disable();
  Gauge1 =
    new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(32, 304), wxSize(424, 28), 0, wxDefaultValidator,
		_T("ID_GAUGE1"));
  StaticText2 =
    new wxStaticText(Panel1, ID_STATICTEXT2, _("Registro corrente:"), wxPoint(192, 264),
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  StaticText5 =
    new wxStaticText(Panel1, ID_STATICTEXT5, _T("0"), wxPoint(336, 264), wxSize(120, 17),
		     wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
  BitmapButton2 =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR
						(_T("wxART_EXECUTABLE_FILE")), wxART_BUTTON),
		       wxPoint(40, 256), wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator,
		       _T("ID_BITMAPBUTTON3"));
  BitmapButton2->SetToolTip(_("Executa"));
  StaticLine1 =
    new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(0, 240), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE1"));
  StaticLine2 =
    new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(0, 360), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE2"));
  newrefnamectrl =
    new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(24, 128), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
  newrefnamectrl->Disable();
  newcompnamectrl =
    new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(24, 176), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  newcompnamectrl->Disable();
  CheckBox1 =
    new wxCheckBox(Panel1, ID_CHECKBOX1, _("Gera novos arqs."), wxPoint(32, 208), wxDefaultSize, 0,
		   wxDefaultValidator, _T("ID_CHECKBOX1"));
  CheckBox1->SetValue(false);
  FlexGridSizer1->Add(Panel1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  BitmapButton1 =
    new wxBitmapButton(this, wxID_OK,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_UNDO")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("wxID_OK"));
  BitmapButton1->SetToolTip(_("Retorna"));
  FlexGridSizer1->Add(BitmapButton1, 0,
		      wxBOTTOM | wxRIGHT | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr,
		     wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition,
		     wxDefaultSize, _T("wxFileDialog"));
  FileDialog2 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_SAVE | wxFD_OVERWRITE_PROMPT,
		     wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FileDialog3 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_SAVE | wxFD_OVERWRITE_PROMPT,
		     wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FileDialog4 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_SAVE | wxFD_OVERWRITE_PROMPT,
		     wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  SetSizer(FlexGridSizer1);
  Layout();

  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execcmb::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execcmb::OnopenoutfileClick);
  Connect(ID_BITMAPBUTTON5, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execcmb::OnopennewrefClick);
  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execcmb::OnopennewcompClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execcmb::OnBitmapButton2Click);
  Connect(ID_CHECKBOX1, wxEVT_COMMAND_CHECKBOX_CLICKED,
	  (wxObjectEventFunction) & execcmb::OnCheckBox1Click);
  //*)
}

execcmb::~execcmb()
{
  //(*Destroy(execcmb)
  //*)
}

void
execcmb::OnopenoutfileClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog2->SetWildcard(_T("*") + t.defdbext());
  FileDialog2->SetMessage(_("Selecione o arquivo de saída"));
  if (FileDialog2->ShowModal() == wxID_OK)
  {
    wxString fname = FileDialog2->GetPath();
    wxString ext = t.defdbext();
    if (fname.Right(4) != ext)
      fname += ext;
    outfilenamectrl->SetValue(fname);
  }
  else
    outfilenamectrl->SetValue(_T(""));
}

void
execcmb::OnopennewrefClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog4->SetWildcard(_T("*") + t.defdbext());
  FileDialog4->SetMessage(_("Selecione o novo arquivo de referência"));

  if (FileDialog4->ShowModal() == wxID_OK)
  {
    wxString fname = FileDialog4->GetPath();
    wxString ext = t.defdbext();
    if (fname.Right(4) != ext)
      fname += ext;
    newrefnamectrl->SetValue(fname);
  }
  else
    newrefnamectrl->SetValue(_T(""));
}

void
execcmb::OnopennewcompClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog3->SetWildcard(_T("*") + t.defdbext());
  FileDialog3->SetMessage(_("Selecione o novo arquivo de comparação"));

  if (FileDialog3->ShowModal() == wxID_OK)
  {
    wxString fname = FileDialog3->GetPath();
    if (fname.Right(4) != t.defdbext())
      fname += t.defdbext();
    newcompnamectrl->SetValue(fname);
  }
  else
    newcompnamectrl->SetValue(_T(""));
}

void
execcmb::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog1->SetWildcard(_T("*.lnkcfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));
  if (FileDialog1->ShowModal() == wxID_OK)
    cfgfilenamectrl->SetValue(FileDialog1->GetPath());
  else
    cfgfilenamectrl->SetValue(_T(""));
}

void
execcmb::exec(void)
{
  StopWatch1.Start();
  wxBeginBusyCursor();
  wxString cfgname = cfgfilenamectrl->GetValue();
  wxString newname = outfilenamectrl->GetValue();

  dbcomb mycomb;

  bool proceed = false;

  if (CheckBox1->GetValue())
  {
    wxString newref;
    wxString newcomp;
    newref = newrefnamectrl->GetValue();
    newcomp = newcompnamectrl->GetValue();
    proceed = mycomb.init(cfgname, newname, newref, newcomp);
  }
  else
    proceed = mycomb.init(cfgname, newname);

  if (proceed)
  {
    int nrecs = (int) mycomb.nrecs();
    int reads = 1;
    Gauge1->SetRange(nrecs);
    Gauge1->SetValue(0);
    wxString aux;
    int ticker = 0;
    while (mycomb.process())
    {
      Gauge1->SetValue(++reads);
      aux.Printf(_T("%d"), reads);
      StaticText5->SetLabel(aux);
      ticker++;
      if (ticker > 99)
      {
	wxYieldIfNeeded();
	ticker = 0;
      }
    }
    if (reads >= nrecs)
    {
      msg = _T("");
      if (!mycomb.purge())
	msg = _("Erro durante processamento");
    }
    else
      msg = _("Erro durante processamento");
  }
  else
    msg = _("Erro na inicialização");

  wxEndBusyCursor();
  StopWatch1.Pause();
}

void
execcmb::OnBitmapButton2Click(wxCommandEvent & event)
{
  msg = _("Erro no processamento");
  BitmapButton1->Disable();
  BitmapButton2->Disable();

  if (!(cfgfilenamectrl->GetValue()).IsEmpty())
  {
    if (!(outfilenamectrl->GetValue()).IsEmpty())
    {
      if (wxFileExists(outfilenamectrl->GetValue()))
	wxRemoveFile(outfilenamectrl->GetValue());
      if (wxFileExists(cfgfilenamectrl->GetValue()))
	exec();
      else
	msg = _("Não existe arquivo de configuração com esse nome");
    }
    else
      msg = _("Selecione primeiro o arquivo de saída");
  }
  else
    msg = _("Selecione primeiro o arquivo de configuração");

  long time = StopWatch1.Time() / 1000L;	// time in seconds
  int secs = (int) (time % 60L);
  time /= 60L;			// time in minutes
  int mins = (int) (time % 60L);
  int hrs = (int) (time / 60L);
  wxString timestring;
  timestring.Printf(_("\nTempo de execução: %d:%02d:%02d"), hrs, mins, secs);

  if (msg.IsEmpty())
    wxMessageBox(_("Processamento OK.") + timestring, _("ENCERRADO"));
  else
    wxMessageBox(msg + timestring, _("ERRO"), wxICON_ERROR);

  ops_log log;
  timestring.Printf(_T("%d:%02d:%02d"), hrs, mins, secs);
  log.log_event(_T("COMBX"), cfgfilenamectrl->GetValue(), timestring, msg);

  BitmapButton1->Enable();
  BitmapButton2->Enable();
}

void
execcmb::OnCheckBox1Click(wxCommandEvent & event)
{
  bool state = CheckBox1->GetValue();
  if (state)
  {
    StaticText6->Enable();
    newrefnamectrl->Enable();
    opennewref->Enable();
    StaticText3->Enable();
    newcompnamectrl->Enable();
    opennewcomp->Enable();
  }
  else
  {
    StaticText6->Disable();
    newrefnamectrl->Disable();
    opennewref->Disable();
    StaticText3->Disable();
    newcompnamectrl->Disable();
    opennewcomp->Disable();
  }
}
