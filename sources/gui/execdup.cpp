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
// Nome:        execdup.cpp
// Propósito:   Classe (janela) para executar deduplicação de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "execdup.h"
#include "dbdup.h"
#include "ops_log.h"

#include <wx/msgdlg.h>

//(*InternalHeaders(execdup)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(execdup)
const long
  execdup::ID_TEXTCTRL2 = wxNewId();
const long
  execdup::ID_BITMAPBUTTON2 = wxNewId();
const long
  execdup::ID_STATICTEXT1 = wxNewId();
const long
  execdup::ID_GAUGE1 = wxNewId();
const long
  execdup::ID_STATICTEXT2 = wxNewId();
const long
  execdup::ID_STATICTEXT5 = wxNewId();
const long
  execdup::ID_BITMAPBUTTON3 = wxNewId();
const long
  execdup::ID_STATICLINE1 = wxNewId();
const long
  execdup::ID_STATICLINE2 = wxNewId();
const long
  execdup::ID_GAUGE2 = wxNewId();
const long
  execdup::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(execdup, wxDialog)
  //(*EventTable(execdup)
  //*)
  END_EVENT_TABLE()execdup::execdup(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(execdup)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, wxID_ANY, _("Executa deduplica"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(523, 269));
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(501, 305), wxTAB_TRAVERSAL,
		_T("ID_PANEL1"));
  cfgfilenamectrl =
    new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(24, 40), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
  opencfgfile =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(432, 40), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  StaticText1 =
    new wxStaticText(Panel1, ID_STATICTEXT1, _("Arq. configuração"), wxPoint(32, 24),
		     wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  Gauge1 =
    new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(32, 168), wxSize(424, 28), 0, wxDefaultValidator,
		_T("ID_GAUGE1"));
  StaticText2 =
    new wxStaticText(Panel1, ID_STATICTEXT2, _("Registro corrente:"), wxPoint(96, 120),
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  StaticText5 =
    new wxStaticText(Panel1, ID_STATICTEXT5, _T("0"), wxPoint(225, 120), wxSize(120, 17),
		     wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
  BitmapButton2 =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR
						(_T("wxART_EXECUTABLE_FILE")), wxART_BUTTON),
		       wxPoint(40, 112), wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator,
		       _T("ID_BITMAPBUTTON3"));
  BitmapButton2->SetToolTip(_("Executa"));
  StaticLine1 =
    new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(0, 90), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE1"));
  StaticLine2 =
    new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(0, 220), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE2"));
  Gauge2 =
    new wxGauge(Panel1, ID_GAUGE2, 100, wxPoint(352, 112), wxDefaultSize, 0, wxDefaultValidator,
		_T("ID_GAUGE2"));
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
  SetSizer(FlexGridSizer1);
  Layout();

  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execdup::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execdup::OnBitmapButton2Click);
  //*)
}

execdup::~execdup()
{
  //(*Destroy(execdup)
  //*)
}

void
execdup::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog1->SetWildcard(_T("*.dupcfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));
  if (FileDialog1->ShowModal() == wxID_OK)
    cfgfilenamectrl->SetValue(FileDialog1->GetPath());
  else
    cfgfilenamectrl->SetValue(_T(""));
}

void
execdup::exec(void)
{
  StopWatch1.Start();
  wxBeginBusyCursor();
  dbdup mydbdup(this);

  mydbdup.init(cfgfilenamectrl->GetValue());
  if (mydbdup.checkfields())
  {
    int nrecs = mydbdup.nrecs();
    Gauge1->SetRange(nrecs);
    int crec = 1;
    wxString lbl;
    Gauge1->SetValue(1);
    int clicker = 0;
    while (mydbdup.copyrec())
    {
      lbl.Printf(_T("%d"), crec);
      StaticText5->SetLabel(lbl);
      Gauge1->SetValue(crec++);
      clicker++;
      if (clicker > 99)
      {
	clicker = 0;
	wxYieldIfNeeded();
      }
    }

    if (mydbdup.initindex())
    {
      clicker = 0;
      crec = 1;
      Gauge1->SetValue(1);
      StaticText5->SetLabel(_T("1"));
      wxYieldIfNeeded();
      while (mydbdup.findblockbeg())
      {
	lbl.Printf(_T("%d"), crec);
	StaticText5->SetLabel(lbl);
	Gauge1->SetValue(crec++);
	clicker++;
	//
	clicker = 100;
	if (clicker > 19)
	{
	  clicker = 0;
	  wxYieldIfNeeded();
	}
	int clocker = 0;
	while (mydbdup.checkrec())
	{
	  Gauge2->Pulse();
	  clocker++;
	  if (clocker > 19)
	  {
	    clocker = 0;
	    wxYieldIfNeeded();
	  }
	}
      }
      if (nrecs <= crec)
	msg = _T("");
    }
    else
      msg = _("Erro ao inicializar índice");
  }
  else
    msg = _("O arquivo de atualizaçào não tem os campos necessários");
  wxEndBusyCursor();
  StopWatch1.Pause();
}

void
execdup::OnBitmapButton2Click(wxCommandEvent & event)
{
  msg = _("Erro no processamento");
  BitmapButton1->Disable();
  BitmapButton2->Disable();

  if (!(cfgfilenamectrl->GetValue()).IsEmpty())
  {
    if (wxFileExists(cfgfilenamectrl->GetValue()))
      exec();
    else
      msg = _("Não existe arquivo de configuração com esse nome");
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
  log.log_event(_T("DUPX"), cfgfilenamectrl->GetValue(), timestring, msg);

  BitmapButton1->Enable();
  //BitmapButton2->Enable();
}
