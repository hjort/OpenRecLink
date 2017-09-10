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
// Nome:        execlnk.cpp
// Propósito:   Classe (janela) para executar relacionamento de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "execlnk.h"
#include "dblink.h"
#include "ntable.h"
#include "ops_log.h"

#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>

//(*InternalHeaders(execlnk)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(execlnk)
const long
  execlnk::ID_GAUGE1 = wxNewId();
const long
  execlnk::ID_TEXTCTRL2 = wxNewId();
const long
  execlnk::ID_BITMAPBUTTON2 = wxNewId();
const long
  execlnk::ID_STATICTEXT1 = wxNewId();
const long
  execlnk::ID_STATICTEXT2 = wxNewId();
const long
  execlnk::ID_STATICTEXT5 = wxNewId();
const long
  execlnk::ID_BITMAPBUTTON3 = wxNewId();
const long
  execlnk::ID_STATICLINE1 = wxNewId();
const long
  execlnk::ID_STATICLINE2 = wxNewId();
const long
  execlnk::ID_SPINCTRL1 = wxNewId();
const long
  execlnk::ID_STATICTEXT7 = wxNewId();
const long
  execlnk::ID_STATICTEXT8 = wxNewId();
const long
  execlnk::ID_SPINCTRL2 = wxNewId();
const long
  execlnk::ID_GAUGE2 = wxNewId();
const long
  execlnk::ID_BITMAPBUTTON1 = wxNewId();
const long
  execlnk::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(execlnk, wxDialog)
  //(*EventTable(execlnk)
  //*)
  END_EVENT_TABLE()execlnk::execlnk(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(execlnk)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, wxID_ANY, _("Executa relacionamento"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(490, 350));
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(501, 305), wxTAB_TRAVERSAL,
		_T("ID_PANEL1"));
  Gauge1 =
    new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(32, 200), wxSize(424, 28), 0, wxDefaultValidator,
		_T("ID_GAUGE1"));
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
  StaticText2 =
    new wxStaticText(Panel1, ID_STATICTEXT2, _("Inicializando - aguarde..."), wxPoint(160, 160),
		     wxSize(192, 17), 0, _T("ID_STATICTEXT2"));
  StaticText2->Hide();
  StaticText5 =
    new wxStaticText(Panel1, ID_STATICTEXT5, _("0"), wxPoint(288, 160), wxSize(72, 17),
		     wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
  StaticText5->Hide();
  BitmapButton2 =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR
						(_T("wxART_EXECUTABLE_FILE")), wxART_BUTTON),
		       wxPoint(40, 152), wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator,
		       _T("ID_BITMAPBUTTON3"));
  BitmapButton2->SetToolTip(_("Executa"));
  StaticLine1 =
    new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(0, 130), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE1"));
  StaticLine2 =
    new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(0, 250), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE2"));
  initrec =
    new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("0"), wxPoint(120, 88), wxDefaultSize, 0, 1, 100, 0,
		   _T("ID_SPINCTRL1"));
  initrec->SetValue(_T("0"));
  StaticText3 =
    new wxStaticText(Panel1, ID_STATICTEXT7, _("Reg. inicial"), wxPoint(40, 88), wxDefaultSize, 0,
		     _T("ID_STATICTEXT7"));
  StaticText6 =
    new wxStaticText(Panel1, ID_STATICTEXT8, _("Reg. final"), wxPoint(240, 88), wxDefaultSize, 0,
		     _T("ID_STATICTEXT8"));
  endrec =
    new wxSpinCtrl(Panel1, ID_SPINCTRL2, _T("1"), wxPoint(312, 88), wxDefaultSize, 0, 1, 100, 1,
		   _T("ID_SPINCTRL2"));
  endrec->SetValue(_T("1"));
  Gauge2 =
    new wxGauge(Panel1, ID_GAUGE2, 100, wxPoint(368, 152), wxSize(80, 28), 0, wxDefaultValidator,
		_T("ID_GAUGE2"));
  BitmapButton3 =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ERROR")),
						wxART_BUTTON), wxPoint(112, 152), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  BitmapButton3->Disable();
  BitmapButton3->SetToolTip(_("Interrompe"));
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
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr,
		     wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition,
		     wxDefaultSize, _T("wxFileDialog"));
  SetSizer(FlexGridSizer1);
  Layout();

  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execlnk::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execlnk::OnBitmapButton2Click);
  Connect(ID_SPINCTRL1, wxEVT_COMMAND_SPINCTRL_UPDATED,
	  (wxObjectEventFunction) & execlnk::OninitrecChange);
  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execlnk::OnBitmapButton3Click);
  //*)

  stop = false;
  maxrecs = 1L;
}

execlnk::~execlnk()
{
  //(*Destroy(execlnk)
  //*)
}


void
execlnk::OnBitmapButton3Click(wxCommandEvent & event)
{
  BitmapButton3->Disable();
  stop = true;
  msg = _("Processamento interrompido");
}

void
execlnk::OnBitmapButton2Click(wxCommandEvent & event)
{
  msg = _("Erro no processamento");
  BitmapButton1->Disable();
  BitmapButton2->Disable();
  opencfgfile->Disable();
  BitmapButton3->Enable();
  StopWatch1.Start();
  wxBeginBusyCursor();

  if (!wxIsEmpty(cfgfilenamectrl->GetValue()) && wxFileExists(cfgfilenamectrl->GetValue()))
  {
    wxString cfgfile = cfgfilenamectrl->GetValue();
    int firstrec = initrec->GetValue();
    int lastrec = endrec->GetValue();
    Gauge1->SetRange(lastrec - firstrec + 1);
    long nrecs = 0;

    stop = false;

    StaticText2->Show();
    wxYield();

    dblink::dolink mylink(cfgfile, firstrec, lastrec);

    wxString tmp;

    if (mylink.init(this))
    {
      StaticText2->SetLabel(_("Registro corrente:"));
      StaticText5->Show();
      wxYieldIfNeeded();
      int tocker = 0;
      while (mylink.findblockbeg() && !stop)
      {
	tocker++;
	if (tocker > 49)	// SCREEN UPDATE CONTROL
	{
	  wxYieldIfNeeded();
	  tocker = 0;
	}
	nrecs = mylink.therecno();
	Gauge1->SetValue(nrecs - firstrec + 1);
	tmp.Printf(_T("%d"), nrecs);
	StaticText5->SetLabel(tmp);
	int ticker = 0;
	while (mylink.isinblock() && !stop)
	{
	  Gauge2->Pulse();
	  mylink.docalc();
	  ticker++;
	  if (ticker > 19)	// SCREEN UPDATE CONTROL
	  {
	    wxYieldIfNeeded();
	    ticker = 0;
	  }
	}
	Gauge2->SetValue(0);
      }
      nrecs = mylink.therecno();
      if (nrecs >= lastrec)
	msg = _T("");
    }
    else
      msg = _("Erro na inicialização");
  }
  else
    msg = _("Selecione um arquivo de configuração primeiro");

  wxEndBusyCursor();
  StopWatch1.Pause();

  long time = StopWatch1.Time() / 1000L;	// time in seconds
  int secs = (int) (time % 60L);
  time /= 60L;			// time in minutes
  int mins = (int) (time % 60L);
  int hrs = (int) (time / 60L);
  wxString timestring;
  timestring.Printf(_("\nTempo de execução: %d:%02d:%02d"), hrs, mins, secs);

  if (msg.IsEmpty())
    wxMessageBox(_("Processamento OK." + timestring), _("ENCERRADO"));
  else
    wxMessageBox(msg + timestring, _("ERRO"), wxICON_ERROR);

  ops_log log;
  timestring.Printf(_T("%d:%02d:%02d"), hrs, mins, secs);
  log.log_event(_T("LNKX"), cfgfilenamectrl->GetValue(), timestring, msg);

  BitmapButton1->Enable();
  BitmapButton3->Disable();
}

void
execlnk::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog1->SetWildcard(_T("*.lnkcfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));
  if (FileDialog1->ShowModal() == wxID_OK)
    cfgfilenamectrl->SetValue(FileDialog1->GetPath());
  else
    cfgfilenamectrl->SetValue(_T(""));

  endrec->SetRange(1, 10);
  endrec->SetValue(1);
  initrec->SetRange(1, 10);
  initrec->SetValue(1);

  wxString cfgfilename = cfgfilenamectrl->GetValue();

  if (!wxIsEmpty(cfgfilename) && wxFileExists(cfgfilename))
  {
    wxFileConfig *cfgfile =
      new wxFileConfig(_T(""), _T(""), cfgfilename, _T(""), wxCONFIG_USE_LOCAL_FILE);
    wxString aux = _T("");
    cfgfile->Read(_T("FILES/COMPNAME"), &aux);

    if (wxFileExists(aux))
    {
      ntable tb;
      if (tb.open(aux))
      {
	maxrecs = tb.gettotalrecs();
	endrec->SetRange(1, (int) maxrecs);
	endrec->SetValue((int) maxrecs);
	initrec->SetRange(1, (int) maxrecs);
	initrec->SetValue(1);
	tb.close();
      }
    }
    aux = _T("");
    cfgfile->Read(_T("FILES/REFNAME"), &aux);

    wxFileName matchfile = wxFileName(cfgfilename);
    ntable t;
    matchfile.SetExt(t.defdbext().Right(3));
    wxString name = matchfile.GetName();
    name = name + _T("SCORE");
    matchfile.SetName(name);

    if (wxFileExists(matchfile.GetFullPath()))
      if (wxMessageBox
	  (_
	   ("Já existe um arquivo de pares associado.\nUtiliza o mesmo? (\"Não\" apaga o arquivo)"),
	   _("ARQUIVO JÁ EXISTENTE"), wxYES_NO) == wxNO)
      {
	wxRemoveFile(matchfile.GetFullPath());
	matchfile.SetExt(t.defixext().Right(3));
	wxRemoveFile(matchfile.GetFullPath());
      }

    aux = _T("");
    cfgfile->Read(_T("GENERAL/IXNAME"), &aux);
    wxString ixfile = matchfile.GetPath(wxPATH_GET_SEPARATOR) + aux.Upper() + t.defixext();
    if (wxFileExists(ixfile))
      if (wxMessageBox
	  (_
	   ("Já existe um arquivo de índice\nassociado a esta configuração.\nDevo utilizá-lo?"),
	   _("ATENÇÃO"), wxYES_NO | wxICON_QUESTION) == wxNO)
	wxRemoveFile(ixfile);

    delete cfgfile;

    BitmapButton2->Enable();
  }
}

void
execlnk::OninitrecChange(wxSpinEvent & event)
{
  endrec->SetRange(initrec->GetValue(), (int) maxrecs);
}
