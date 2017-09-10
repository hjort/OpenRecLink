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
// Nome:        runcalc.cpp
// Propósito:   Classe (janela) para executar cálculo de parâmetros de linkagem
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "runcalc.h"

#include "checksep.h"

//(*InternalHeaders(runcalc)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

#include "matrix.h"
#include "parameters.h"

//(*IdInit(runcalc)
const long
  runcalc::ID_STATICTEXT1 = wxNewId();
const long
  runcalc::ID_TEXTCTRL1 = wxNewId();
const long
  runcalc::ID_BITMAPBUTTON1 = wxNewId();
const long
  runcalc::ID_STATICTEXT2 = wxNewId();
const long
  runcalc::ID_TEXTCTRL3 = wxNewId();
const long
  runcalc::ID_STATICTEXT3 = wxNewId();
const long
  runcalc::ID_TEXTCTRL4 = wxNewId();
const long
  runcalc::ID_STATICTEXT4 = wxNewId();
const long
  runcalc::ID_TEXTCTRL5 = wxNewId();
const long
  runcalc::ID_STATICTEXT5 = wxNewId();
const long
  runcalc::ID_TEXTCTRL6 = wxNewId();
const long
  runcalc::ID_STATICTEXT6 = wxNewId();
const long
  runcalc::ID_TEXTCTRL7 = wxNewId();
const long
  runcalc::ID_STATICTEXT7 = wxNewId();
const long
  runcalc::ID_TEXTCTRL8 = wxNewId();
const long
  runcalc::ID_STATICTEXT8 = wxNewId();
const long
  runcalc::ID_TEXTCTRL9 = wxNewId();
const long
  runcalc::ID_TEXTCTRL2 = wxNewId();
const long
  runcalc::ID_BITMAPBUTTON2 = wxNewId();
const long
  runcalc::ID_BITMAPBUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(runcalc, wxDialog)
  //(*EventTable(runcalc)
  //*)
  END_EVENT_TABLE()runcalc::runcalc(wxWindow * parent, wxWindowID id,
				    const wxPoint & pos, const wxSize & size)
{
  //(*Initialize(runcalc)
  wxFlexGridSizer *
    FlexGridSizer1;
  wxFlexGridSizer *
    FlexGridSizer2;
  wxFlexGridSizer *
    FlexGridSizer4;
  wxFlexGridSizer *
    FlexGridSizer3;
  wxFlexGridSizer *
    FlexGridSizer5;

  Create(parent, wxID_ANY, _("Calcula parâmetros"), wxDefaultPosition,
	 wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  FlexGridSizer2 = new wxFlexGridSizer(1, 3, 0, 0);
  StaticText1 =
    new wxStaticText(this, ID_STATICTEXT1, _("Arq. conf:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  FlexGridSizer2->Add(StaticText1, 1,
		      wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  cfgnamectrl =
    new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition,
		   wxSize(408, 27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  FlexGridSizer2->Add(cfgnamectrl, 1,
		      wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  opencfg =
    new wxBitmapButton(this, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR
						(_T("wxART_FILE_OPEN")), wxART_BUTTON),
		       wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW,
		       wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  opencfg->SetToolTip(_("Abre o arquivo\nde configuração"));
  FlexGridSizer2->Add(opencfg, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer2, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3 = new wxFlexGridSizer(1, 2, 0, 0);
  FlexGridSizer4 = new wxFlexGridSizer(7, 2, 0, 0);
  StaticText2 =
    new wxStaticText(this, ID_STATICTEXT2, _("Valor inicial para os m_i:"),
		     wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  FlexGridSizer4->Add(StaticText2, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  m_ini =
    new wxTextCtrl(this, ID_TEXTCTRL3, _("0.9"), wxDefaultPosition,
		   wxSize(60, 27), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL3"));
  FlexGridSizer4->Add(m_ini, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  StaticText3 =
    new wxStaticText(this, ID_STATICTEXT3, _("Valor inicial para os u_i:"),
		     wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  FlexGridSizer4->Add(StaticText3, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  u_ini =
    new wxTextCtrl(this, ID_TEXTCTRL4, _("0.1"), wxDefaultPosition,
		   wxSize(60, -1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL4"));
  FlexGridSizer4->Add(u_ini, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  StaticText4 =
    new wxStaticText(this, ID_STATICTEXT4, _("Valor inicial para o p:"),
		     wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
  FlexGridSizer4->Add(StaticText4, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  p_ini =
    new wxTextCtrl(this, ID_TEXTCTRL5, _("0.05"), wxDefaultPosition,
		   wxSize(60, -1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL5"));
  FlexGridSizer4->Add(p_ini, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  StaticText5 =
    new wxStaticText(this, ID_STATICTEXT5, _("Número máx. de iterações:"),
		     wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
  FlexGridSizer4->Add(StaticText5, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  maxiterctrl =
    new wxTextCtrl(this, ID_TEXTCTRL6, _("1000"), wxDefaultPosition,
		   wxSize(60, -1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL6"));
  FlexGridSizer4->Add(maxiterctrl, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  StaticText6 =
    new wxStaticText(this, ID_STATICTEXT6,
		     _("Convergência relativa (epsilon):"),
		     wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
  FlexGridSizer4->Add(StaticText6, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  epsilonctrl =
    new wxTextCtrl(this, ID_TEXTCTRL7, _("0.001"), wxDefaultPosition,
		   wxSize(60, -1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL7"));
  FlexGridSizer4->Add(epsilonctrl, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  StaticText7 =
    new wxStaticText(this, ID_STATICTEXT7,
		     _("Probabilidade de rejeitar par:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT7"));
  FlexGridSizer4->Add(StaticText7, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  falsoneg =
    new wxTextCtrl(this, ID_TEXTCTRL8, _("0.1"), wxDefaultPosition,
		   wxSize(60, -1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL8"));
  FlexGridSizer4->Add(falsoneg, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  StaticText8 =
    new wxStaticText(this, ID_STATICTEXT8,
		     _("Prob. de não rejeitar não par:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT8"));
  FlexGridSizer4->Add(StaticText8, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  falsopos =
    new wxTextCtrl(this, ID_TEXTCTRL9, _("0.1"), wxDefaultPosition,
		   wxSize(60, -1), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL9"));
  FlexGridSizer4->Add(falsopos, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3->Add(FlexGridSizer4, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  textout =
    new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition,
		   wxSize(238, 77),
		   wxTE_MULTILINE | wxTE_READONLY | wxVSCROLL | wxHSCROLL,
		   wxDefaultValidator, _T("ID_TEXTCTRL2"));
  FlexGridSizer3->Add(textout, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer3, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer5 = new wxFlexGridSizer(1, 3, 0, 0);
  gobtn =
    new wxBitmapButton(this, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR
						(_T("wxART_EXECUTABLE_FILE")), wxART_BUTTON),
		       wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW,
		       wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  gobtn->Disable();
  gobtn->SetToolTip(_("Calcula"));
  FlexGridSizer5->Add(gobtn, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer5->Add(436, 20, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  closebtn =
    new wxBitmapButton(this, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_UNDO")),
						wxART_BUTTON), wxDefaultPosition,
		       wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
  closebtn->SetDefault();
  closebtn->SetToolTip(_("Retorna"));
  FlexGridSizer5->Add(closebtn, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer5, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString,
		     wxEmptyString, wxFileSelectorDefaultWildcardStr,
		     wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST,
		     wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & runcalc::OnopencfgClick);
  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & runcalc::OngobtnClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & runcalc::OnclosebtnClick);
  //*)
}

runcalc::~runcalc()
{
  //(*Destroy(runcalc)
  //*)
}

void
runcalc::OnopencfgClick(wxCommandEvent & event)
{
  FileDialog1->SetWildcard(_T("*.lnkcfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    cfgnamectrl->SetValue(FileDialog1->GetPath());
    if (!wxIsEmpty(cfgnamectrl->GetValue()) && wxFileExists(cfgnamectrl->GetValue()))
      gobtn->Enable();
  }
  else
    cfgnamectrl->SetValue(_T(""));
}

void
runcalc::OnclosebtnClick(wxCommandEvent & event)
{
  Close();
}

void
runcalc::OngobtnClick(wxCommandEvent & event)
{
  closebtn->Disable();

  StopWatch1.Start();
  wxBeginBusyCursor();

  parest();

  wxEndBusyCursor();
  StopWatch1.Pause();

  long time = StopWatch1.Time() / 1000L;	// time in seconds
  int secs = (int) (time % 60L);
  time /= 60L;			// time in minutes
  int mins = (int) (time % 60L);
  int hrs = (int) (time / 60L);
  wxString timestring;
  timestring.Printf(_("Tempo de execução: %d:%02d:%02d\n"), hrs, mins, secs);
  textout->SetInsertionPoint(0);
  textout->WriteText(timestring);
  if (wxMessageBox
      (_("Deseja transferir os valores para a configuração?"),
       _T("ENCERRADO"), wxICON_QUESTION | wxYES_NO) == wxYES)
    replace_values();

  closebtn->Enable();
}

void
runcalc::replace_values(void)
{
  wxFileConfig *cfgfile = new wxFileConfig(_T(""), _T(""), cfgnamectrl->GetValue(), _T(""),
					   wxCONFIG_USE_LOCAL_FILE);

  int nlines = m_estimates.Count();
  wxString aux;

  for (int i = 0; i < nlines; i++)
  {
    aux.Printf(_T("COMPARE/CORRECT%d"), i);
    cfgfile->Write(aux, m_estimates[i]);
    aux.Printf(_T("COMPARE/INCORRECT%d"), i);
    cfgfile->Write(aux, u_estimates[i]);
  }

  delete cfgfile;
}

using namespace std;

void
runcalc::parest(void)
{
  int err;
  unsigned int icols, irows;
  unsigned int sizea, sizeb;
  double *mf;
  double *uf;
  double pf;
  double *wf;
  double ltf, htf;
  unsigned int i;
  unsigned int j;
  double uin, min, pin;
  unsigned maxiter, npat;
  double epsilon, loglik;
  double max_m_p, max_u_p;	//threshold probabilities
  unsigned int c_u;
  unsigned int *fr;
  matrix_short *mdata;
  matrix_uint *datapat;

  string ctrlfile, datafile, uctrlfile, udatafile;

  wxString cfgfile = cfgnamectrl->GetValue();

  wxFileName matchfile = wxFileName(cfgfile);
  matchfile.SetExt(_T("blmtrx"));
  wxString name = matchfile.GetFullPath();
  datafile = string(name.mb_str());

  ifstream ctrlfla;
  ctrlfla.open(ctrlfile.c_str(), ios::in);
  ctrlfla >> irows >> icols;
  ctrlfla.close();

  matchfile.SetExt(_T("blctrl"));
  name = matchfile.GetFullPath();
  ctrlfile = string(name.mb_str());

  matchfile.SetExt(_T("mtrx"));
  name = matchfile.GetFullPath();
  udatafile = string(name.mb_str());

  matchfile.SetExt(_T("ctrl"));
  name = matchfile.GetFullPath();
  uctrlfile = string(name.mb_str());

  wxString aux = m_ini->GetValue();
  aux.Replace(CVTFROM, CVTTO);
  aux.ToDouble(&min);

  aux = u_ini->GetValue();
  aux.Replace(CVTFROM, CVTTO);
  aux.ToDouble(&uin);

  aux = p_ini->GetValue();
  aux.Replace(CVTFROM, CVTTO);
  aux.ToDouble(&pin);

  long tmp;

  aux = maxiterctrl->GetValue();
  aux.ToLong(&tmp);
  maxiter = (unsigned int) tmp;

  aux = epsilonctrl->GetValue();
  aux.Replace(CVTFROM, CVTTO);
  aux.ToDouble(&epsilon);

  aux = falsoneg->GetValue();
  aux.Replace(CVTFROM, CVTTO);
  aux.ToDouble(&max_m_p);

  aux = falsopos->GetValue();
  aux.Replace(CVTFROM, CVTTO);
  aux.ToDouble(&max_u_p);

  mdata = readdata(ctrlfile, datafile, &irows, &icols, &sizea, &sizeb, &err);

  unsigned int icols2 = (unsigned int) pow_int(2, icols);

  // arrays for m and u
  mf = new double[icols];
  uf = new double[icols];
  wf = new double[icols2];	// room for the scores: 2^n
  fr = new unsigned int[icols];

  for (i = 0; i < icols; i++)
  {
    mf[i] = min;
    uf[i] = uin;
  }
  pf = pin;

  estimatepars(mf, uf, &pf, &sizea, &sizeb, &maxiter, &epsilon, &loglik, ctrlfile, datafile, &err);

  estimateu(uf, fr, &c_u, uctrlfile, udatafile, &err);

  computethresh(mf, uf, &max_m_p, &max_u_p, &ltf, &htf, wf, ctrlfile, datafile, &err);

  m_estimates.Clear();
  u_estimates.Clear();
  for (i = 0; i < icols; i++)
  {
    aux.Printf(_T("%g"), (mf[i] * 100.0));
    m_estimates.Add(aux);
    aux.Printf(_T("%g"), (uf[i] * 100.0));
    u_estimates.Add(aux);
  }

  textout->Clear();
  textout->AppendText(_("Parâmetros de saida\n"));
  textout->AppendText(_("-------------------\n"));
  aux.Printf(_("Número de iterações do algoritmo EM: %d\n"), maxiter);
  textout->AppendText(aux);
  aux.Printf(_("Menor diferença da log-verossimilhanca entre iterações: %g\n"), epsilon);
  textout->AppendText(aux);
  aux.Printf(_("Maior valor da funcao de log-verossimilhança: %12g\n"), loglik);
  textout->AppendText(aux);

  textout->AppendText(_("Parâmetros estimados\n"));
  textout->AppendText(_("--------------------\n"));
  textout->AppendText(_("Probabilidade m(i) do campo concordar dado que é um par:\n"));
  for (i = 0; i < icols; i++)
  {
    aux.Printf(_T("m(%d) = %12g\n"), i + 1, mf[i]);
    textout->AppendText(aux);
  }
  textout->AppendText(_("Probabilidade u(i) do campo concordar dado que é um não-par:\n"));
  for (i = 0; i < icols; i++)
  {
    aux.Printf(_T("m(%d) = %12g\n"), i + 1, uf[i]);
    textout->AppendText(aux);
  }
  aux.Printf(_("Probabilidade (p) de ser par: %12g\n"), pf);
  textout->AppendText(aux);
  textout->AppendText(_("Frequência de concordância (f) do campo i:\n"));
  for (i = 0; i < icols; i++)
  {
    aux.Printf(_T("f(%d) = %d\n"), i + 1, fr[i]);
    textout->AppendText(aux);
  }
  aux.Printf(_("Limiar inferior (na escala do escore): %12g\n"), ltf);
  textout->AppendText(aux);
  aux.Printf(_("Limiar superior (na escala do escore): %12g\n"), htf);
  textout->AppendText(aux);
  textout->AppendText(_("Pesos da concordancia A(i) [log(mi/ui)]:\n"));
  for (i = 0; i < icols; i++)
  {
    aux.Printf(_T("A(%d) = %12g\n"), i + 1, log2(mf[i] / uf[i]));
    textout->AppendText(aux);
  }
  textout->AppendText(_("Pesos da discordancia D(i) [log((1-mi)/(1-ui))]:\n"));
  for (i = 0; i < icols; i++)
  {
    aux.Printf(_T("D(%d) = %12g\n"), i + 1, log2((1 - mf[i]) / (1 - uf[i])));
    textout->AppendText(aux);
  }
  textout->AppendText(_("Poder discriminante do campo P(i) [A(i)-D(i)]:\n"));
  for (i = 0; i < icols; i++)
  {
    aux.Printf(_T("P(%d) = %12g\n"), i + 1, log2(mf[i] / uf[i]) - log2((1 - mf[i]) / (1 - uf[i])));
    textout->AppendText(aux);
  }
  textout->AppendText(_("Padrões, frequências e escores observados:\n"));

  npat = (int) pow_int(2, icols);
  double *wpat = new double[npat];

  datapat = getpattern(irows, icols, mdata);

  for (j = 0; j < npat; j++)
  {
    aux.Printf(_("Padrão: %d frequência: %d configuração: "), j + 1,
	       matrix_uint_get(datapat, j, 0));
    for (i = 1; i < (icols + 1); i++)
    {
      aux.Printf(_T("%d / "), matrix_uint_get(datapat, j, i));
      textout->AppendText(aux);
    }
    aux.Printf(_T("score: %12g\n"), wf[j]);
    textout->AppendText(aux);
  }

  // housekeeping
  delete[]mf;
  delete[]uf;
  delete[]wf;
  delete[]fr;
  matrix_short_free(mdata);
  matrix_uint_free(datapat);
  delete[]wpat;
}
