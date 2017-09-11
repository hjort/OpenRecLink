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
// Nome:        execcopy.cpp
// Propósito:   Classe (janela) para executar cópia seletiva de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "execcopy.h"
#include "docopy.h"
#include "ops_log.h"

#include <wx/msgdlg.h>

//(*InternalHeaders(execcopy)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(execcopy)
const long
  execcopy::ID_TEXTCTRL2 = wxNewId();
const long
  execcopy::ID_BITMAPBUTTON2 = wxNewId();
const long
  execcopy::ID_TEXTCTRL4 = wxNewId();
const long
  execcopy::ID_BITMAPBUTTON1 = wxNewId();
const long
  execcopy::ID_STATICTEXT1 = wxNewId();
const long
  execcopy::ID_STATICTEXT3 = wxNewId();
const long
  execcopy::ID_GAUGE1 = wxNewId();
const long
  execcopy::ID_STATICTEXT2 = wxNewId();
const long
  execcopy::ID_STATICTEXT5 = wxNewId();
const long
  execcopy::ID_BITMAPBUTTON3 = wxNewId();
const long
  execcopy::ID_STATICLINE1 = wxNewId();
const long
  execcopy::ID_STATICLINE2 = wxNewId();
const long
  execcopy::ID_PANEL1 = wxNewId();

//*)
  BEGIN_EVENT_TABLE(execcopy, wxDialog)
  //(*EventTable(execcopy)
  //*)
  END_EVENT_TABLE()execcopy::execcopy(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				      const wxSize & size)
{
  //(*Initialize(execcopy)
  wxFlexGridSizer *
    FlexGridSizer1;
   Create(parent, wxID_ANY, _("Executa cópia seletiva"), wxDefaultPosition, wxDefaultSize,
	    wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(523, 349));
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
  outfilenamectrl =
    new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxPoint(24, 112), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
  openoutfile =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(432, 112), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  StaticText1 =
    new wxStaticText(Panel1, ID_STATICTEXT1, _("Arq. configuração"), wxPoint(32, 24),
		     wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  StaticText3 =
    new wxStaticText(Panel1, ID_STATICTEXT3, _("Arq. saída"), wxPoint(32, 96), wxDefaultSize, 0,
		     _T("ID_STATICTEXT3"));
  Gauge1 =
    new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(32, 240), wxSize(424, 28), 0, wxDefaultValidator,
		_T("ID_GAUGE1"));
  StaticText2 =
    new wxStaticText(Panel1, ID_STATICTEXT2, _("Registro corrente:"), wxPoint(192, 192),
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  StaticText5 =
    new wxStaticText(Panel1, ID_STATICTEXT5, _T("0"), wxPoint(336, 192), wxSize(120, 17),
		     wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
  BitmapButton2 =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR
						(_T("wxART_EXECUTABLE_FILE")), wxART_BUTTON),
		       wxPoint(40, 184), wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator,
		       _T("ID_BITMAPBUTTON3"));
  BitmapButton2->SetToolTip(_("Executa"));
  StaticLine1 =
    new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(0, 168), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE1"));
  StaticLine2 =
    new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(0, 290), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE2"));
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
  SetSizer(FlexGridSizer1);
  Layout();
   Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	     (wxObjectEventFunction) & execcopy::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	   (wxObjectEventFunction) & execcopy::OnopenoutfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	   (wxObjectEventFunction) & execcopy::OnBitmapButton2Click);
  
    //*)
}

execcopy::~execcopy()
{
  //(*Destroy(execcopy)
  //*)
}


void
execcopy::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog1->SetWildcard(_T("*.cpycfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));
  if (FileDialog1->ShowModal() == wxID_OK)
    cfgfilenamectrl->SetValue(FileDialog1->GetPath());
  else
    cfgfilenamectrl->SetValue(_T(""));
}

void
execcopy::OnopenoutfileClick(wxCommandEvent & event)
{
  ntable t;
  wxString ext = t.defdbext();
  FileDialog2->SetWildcard(_T("*") + ext);
  ext = ext.Right(4);
  FileDialog2->SetMessage(_("Selecione o arquivo de saída"));
  if (FileDialog2->ShowModal() == wxID_OK)
  {
    wxString fname = FileDialog2->GetPath();
    ntable t;
    if (fname.Right(4) != ext)
      fname += ext;
    outfilenamectrl->SetValue(fname);
    if (wxFileExists(fname))
      wxRemoveFile(fname);
  }
  else
    outfilenamectrl->SetValue(_T(""));
}

void
execcopy::OnBitmapButton2Click(wxCommandEvent & event)
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
  timestring.Printf(_("\nLidos: %d Escritos %d\nTempo de execução: %d:%02d:%02d"), crec, wrec,
		    hrs, mins, secs);

  if (msg.IsEmpty())
    wxMessageBox(_("Processamento OK.") + timestring, _("ENCERRADO"));
  else
    wxMessageBox(msg + timestring, _("ERRO"), wxICON_ERROR);

  ops_log log;
  timestring.Printf(_T("%d/%d - %d:%02d:%02d"), crec, wrec, hrs, mins, secs);
  log.log_event(_T("CPYX"), cfgfilenamectrl->GetValue(), timestring, msg);

  BitmapButton1->Enable();
}

void
execcopy::exec(void)
{
  StopWatch1.Start();
  wxBeginBusyCursor();
  dbcopy::docopy mycopy(cfgfilenamectrl->GetValue(), outfilenamectrl->GetValue());
  if (mycopy.init())
  {
    long nrecs = mycopy.numberofrecs();
    Gauge1->SetRange((int) nrecs);
    crec = 0l;
    wrec = 0l;
    wxString lbl;
    Gauge1->SetValue(0);
    int ticker = 0;
    while (!mycopy.isfinished())
    {
      if (mycopy.exec())
	wrec++;
      crec++;
      Gauge1->SetValue((int) crec);
      lbl.Printf(_T("%d"), crec);
      StaticText5->SetLabel(lbl);
      ticker++;
      if (ticker > 99)
      {
	wxYieldIfNeeded();
	ticker = 0;
      }
    }
    if (nrecs == crec)
      msg = _T("");
  }
  wxEndBusyCursor();
  StopWatch1.Pause();
}
