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
// Nome:        execlnmatrix.cpp
// Propósito:   Classe (janela) para gerar as matrizes p/cálculo
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "execlnmatrix.h"
#include "dblnmatrix.h"
#include "ops_log.h"

#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/wfstream.h>

#include <stdlib.h>
#include <math.h>
#include <time.h>

//(*InternalHeaders(execlnmatrix)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(execlnmatrix)
const long
  execlnmatrix::ID_GAUGE1 = wxNewId();
const long
  execlnmatrix::ID_TEXTCTRL2 = wxNewId();
const long
  execlnmatrix::ID_BITMAPBUTTON2 = wxNewId();
const long
  execlnmatrix::ID_STATICTEXT1 = wxNewId();
const long
  execlnmatrix::ID_STATICTEXT2 = wxNewId();
const long
  execlnmatrix::ID_STATICTEXT5 = wxNewId();
const long
  execlnmatrix::ID_BITMAPBUTTON3 = wxNewId();
const long
  execlnmatrix::ID_STATICLINE1 = wxNewId();
const long
  execlnmatrix::ID_STATICLINE2 = wxNewId();
const long
  execlnmatrix::ID_GAUGE2 = wxNewId();
const long
  execlnmatrix::ID_BITMAPBUTTON1 = wxNewId();
const long
  execlnmatrix::ID_SPINCTRL1 = wxNewId();
const long
  execlnmatrix::ID_STATICTEXT3 = wxNewId();
const long
  execlnmatrix::ID_STATICTEXT4 = wxNewId();
const long
  execlnmatrix::ID_CHECKBOX1 = wxNewId();
const long
  execlnmatrix::ID_CHECKBOX2 = wxNewId();
const long
  execlnmatrix::ID_PANEL1 = wxNewId();

//*)
  BEGIN_EVENT_TABLE(execlnmatrix, wxDialog)
  //(*EventTable(execlnmatrix)
  //*)
  END_EVENT_TABLE()execlnmatrix::execlnmatrix(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					      const wxSize & size)
{
  //(*Initialize(execlnmatrix)
  wxFlexGridSizer *
    FlexGridSizer1;
   Create(parent, wxID_ANY, _("Gera matrizes"), wxDefaultPosition, wxDefaultSize,
	    wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(523, 323));
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
    new wxStaticText(Panel1, ID_STATICTEXT5, _T("0"), wxPoint(288, 160), wxSize(72, 17),
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
  samplesize =
    new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("0"), wxPoint(146, 88), wxSize(64, 27), 0, 1, 100, 0,
		   _T("ID_SPINCTRL1"));
  samplesize->SetValue(_T("0"));
  StaticText3 =
    new wxStaticText(Panel1, ID_STATICTEXT3, _("Fração amostral"), wxPoint(32, 93), wxDefaultSize,
		     0, _T("ID_STATICTEXT3"));
  StaticText4 =
    new wxStaticText(Panel1, ID_STATICTEXT4, _T("0/00"), wxPoint(213, 93), wxDefaultSize, 0,
		     _T("ID_STATICTEXT4"));
  randmtxcheck =
    new wxCheckBox(Panel1, ID_CHECKBOX1, _("Aleatória"), wxPoint(256, 88), wxDefaultSize, 0,
		   wxDefaultValidator, _T("ID_CHECKBOX1"));
  randmtxcheck->SetValue(false);
  blkmtxchk =
    new wxCheckBox(Panel1, ID_CHECKBOX2, _("Blocada"), wxPoint(368, 88), wxDefaultSize, 0,
		   wxDefaultValidator, _T("ID_CHECKBOX2"));
  blkmtxchk->SetValue(false);
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
	     (wxObjectEventFunction) & execlnmatrix::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	   (wxObjectEventFunction) & execlnmatrix::OnBitmapButton2Click);
  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	   (wxObjectEventFunction) & execlnmatrix::OnBitmapButton3Click);
  
    //*)
    stop = false;
}

execlnmatrix::~execlnmatrix()
{
  //(*Destroy(execlnmatrix)
  //*)
}

void
execlnmatrix::OnBitmapButton3Click(wxCommandEvent & event)
{
  BitmapButton3->Disable();
  stop = true;
  msg = _("Processamento interrompido");
}

void
execlnmatrix::OnBitmapButton2Click(wxCommandEvent & event)
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

    Gauge1->SetRange(0);
    long nrecs = 0L;

    stop = false;

    StaticText2->Show();
    wxYield();

    dblnmatrix::domatrix mygmatrix(cfgfile);

    if (mygmatrix.init(this))
    {
      wxArrayString results;
      wxFileOutputStream *matrix;

      StaticText2->SetLabel(_("Registro corrente:"));
      StaticText5->Show();
      wxYieldIfNeeded();

      wxFileName matchfile = wxFileName(cfgfile);
      char buffer[1024];
      wxString tmp;
      int comprecs = mygmatrix.getcomprecs();	// wxMessageBox(wxString::Format(_T("%d"),comprecs),_T("comprecs"));
      int refrecs = mygmatrix.getrefrecs();	// wxMessageBox(wxString::Format(_T("%d"),refrecs),_T("refrecs"));

      if (!randmtxcheck->IsChecked() && !blkmtxchk->IsChecked())
	msg = _("Deve-se selecionar ao menos uma das opções");

      if (randmtxcheck->IsChecked())
      {
	int ssize = samplesize->GetValue();	// wxMessageBox(wxString::Format(_T("%d"),ssize),_T("ssize"));
	int maxcomp = (comprecs * ssize) / 1000;	// wxMessageBox(wxString::Format(_T("%d"),maxcomp),_T("maxcomp"));
	int maxref = (refrecs * ssize) / 1000;	// wxMessageBox(wxString::Format(_T("%d"),maxref),_T("maxref"));

	matchfile.SetExt(_T("mtrx"));
	wxString name = matchfile.GetFullPath();
	if (wxFileExists(name))
	  wxRemoveFile(name);
	matrix = new wxFileOutputStream(name);

	long refno;
	long compno;

	long totalcomps = maxref * maxcomp;	//wxMessageBox(wxString::Format(_T("%d"),totalcomps),_T("DUUUH"));

	Gauge1->SetRange(totalcomps);

	int ticker = 0;

	time_t t;
	srand((unsigned) time(&t));

	for (long i = 0; (i < maxref) && !stop; i++)
	  for (long j = 0; (j < maxcomp) && !stop; j++)
	  {
	    compno = (((double) rand() / (double) (RAND_MAX)) * (double) (comprecs - 1)) + 1;
	    refno = (((double) rand() / (double) (RAND_MAX)) * (double) (refrecs - 1)) + 1;
	    mygmatrix.domatrix_nb(&results, refno, compno);
	    Gauge1->SetValue(++nrecs);
	    tmp.Printf(_T("%d"), nrecs);
	    StaticText5->SetLabel(tmp);
	    tmp = _T("");
	    for (int i = 0; i < results.Count(); i++)
	      tmp += results[i];
	    tmp += _T("\n");
	    strcpy(buffer, tmp.mb_str(wxConvUTF8));
	    matrix->Write(buffer, strlen(buffer));
	    ticker++;
	    if (ticker > 49)
	    {
	      wxYieldIfNeeded();
	      ticker = 0;
	    }
	  }

	// Just to ensure the algorithm works

	if (!mygmatrix.checkmatches(nrecs))
	{
	  /*
	     tmp = _T("");
	     for (int i = 0; i < results.Count(); i++)
	     tmp += _T("1 ");
	     tmp += _T("\n");
	     strcpy(buffer, tmp.mb_str(wxConvUTF8));
	     matrix->Write(buffer, strlen(buffer));
	     nrecs++;
	     totalcomps++;
	     wxString notice = _("Uma das frequências calculadas foi igual a zero.\nUma linha artificial foi incluida na matriz para\nforçar valores diferentes de zero.\nPode ser conveniente executar novamente a rotina\n com uma fração amostral maior.");
	   */
	  wxString notice =
	    _
	    ("Uma das frequências calculadas foi igual a zero.\nÉ recomendado executar novamente a rotina\ncom uma fração amostral maior.");
	  wxMessageBox(notice, _("NOTA"), wxICON_INFORMATION);
	}


	delete matrix;

	matchfile.SetExt(_T("ctrl"));
	name = matchfile.GetFullPath();
	if (wxFileExists(name))
	  wxRemoveFile(name);

	matrix = new wxFileOutputStream(name);
	tmp.Printf(_T("%d %d\n%d %d\n"), nrecs, results.Count(), maxref, maxcomp);
	strcpy(buffer, tmp.mb_str(wxConvUTF8));
	matrix->Write(buffer, strlen(buffer));
	delete matrix;
	/*
	   if (!mygmatrix.checkmatches(nrecs))
	   {
	   msg = _("Uma das frequências calculadas foi igual a zero.\nExecute novamente a rotina com uma fração amostral maior.");
	   wxMessageBox(msg,_("ERRO"),wxICON_ERROR);
	   } else */
	if (nrecs < totalcomps)
	  msg = _("Erro no processamento da matriz não-blocada");
	else
	  msg = _T("");
      }
      else
	msg = _T("");

      if (blkmtxchk->IsChecked() && msg.IsEmpty())
      {
	matchfile.SetExt(_T("blmtrx"));
	wxString name = matchfile.GetFullPath();
	if (wxFileExists(name))
	  wxRemoveFile(name);
	matrix = new wxFileOutputStream(name);

	nrecs = 0L;
	Gauge1->SetRange(comprecs);

	int tocker = 0;

	mygmatrix.reset();

	while (mygmatrix.findblockbeg() && !stop)
	{
	  tocker++;
	  if (tocker > 49)
	  {
	    wxYieldIfNeeded();
	    tocker = 0;
	  }
	  nrecs = mygmatrix.therecno();
	  Gauge1->SetValue(nrecs);
	  tmp.Printf(_T("%d"), nrecs);
	  StaticText5->SetLabel(tmp);
	  int ticker = 0;
	  while (mygmatrix.isinblock() && !stop)
	  {
	    Gauge2->Pulse();
	    mygmatrix.domatrix(&results);
	    tmp = _T("");
	    for (int i = 0; i < results.Count(); i++)
	      tmp += results[i];
	    tmp += _T("\n");
	    strcpy(buffer, tmp.mb_str(wxConvUTF8));
	    matrix->Write(buffer, strlen(buffer));
	    ticker++;
	    if (ticker > 19)
	    {
	      wxYieldIfNeeded();
	      ticker = 0;
	    }
	  }
	}
	Gauge2->SetValue(0);

	delete matrix;

	matchfile.SetExt(_T("blctrl"));
	name = matchfile.GetFullPath();
	if (wxFileExists(name))
	  wxRemoveFile(name);
	matrix = new wxFileOutputStream(name);
	tmp.Printf(_T("%d %d\n%d %d\n"), nrecs, results.Count(), refrecs, comprecs);
	strcpy(buffer, tmp.mb_str(wxConvUTF8));
	matrix->Write(buffer, strlen(buffer));
	delete matrix;

	if (mygmatrix.reachedend())
	  msg = _T("");
	else
	  msg = _("Erro no processamento da matriz blocada");
      }
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
  log.log_event(_T("MTRXX"), cfgfilenamectrl->GetValue(), timestring, msg);

  BitmapButton1->Enable();
  BitmapButton3->Disable();
}

void
execlnmatrix::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog1->SetWildcard(_T("*.lnkcfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));
  if (FileDialog1->ShowModal() == wxID_OK)
    cfgfilenamectrl->SetValue(FileDialog1->GetPath());
  else
    cfgfilenamectrl->SetValue(_T(""));

  wxString cfgfilename = cfgfilenamectrl->GetValue();

  if (!wxIsEmpty(cfgfilename) && wxFileExists(cfgfilename))
    BitmapButton2->Enable();
}
