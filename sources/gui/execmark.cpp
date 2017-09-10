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
// Nome:        execmark.cpp
// Propósito:   Classe (janela) para marcar/desmarcar arquivo de pares
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "execmark.h"

#include "ops_log.h"
#include "ntable.h"

#include "checksep.h"

#include <wx/msgdlg.h>
#include <wx/filename.h>


//(*InternalHeaders(execmark)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(execmark)
const long
  execmark::ID_GAUGE1 = wxNewId();
const long
  execmark::ID_TEXTCTRL2 = wxNewId();
const long
  execmark::ID_BITMAPBUTTON2 = wxNewId();
const long
  execmark::ID_STATICTEXT1 = wxNewId();
const long
  execmark::ID_STATICTEXT5 = wxNewId();
const long
  execmark::ID_BITMAPBUTTON3 = wxNewId();
const long
  execmark::ID_STATICLINE1 = wxNewId();
const long
  execmark::ID_STATICLINE2 = wxNewId();
const long
  execmark::ID_BITMAPBUTTON1 = wxNewId();
const long
  execmark::ID_RADIOBOX1 = wxNewId();
const long
  execmark::ID_TEXTCTRL3 = wxNewId();
const long
  execmark::ID_TEXTCTRL1 = wxNewId();
const long
  execmark::ID_STATICTEXT2 = wxNewId();
const long
  execmark::ID_STATICTEXT4 = wxNewId();
const long
  execmark::ID_STATICTEXT3 = wxNewId();
const long
  execmark::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(execmark, wxDialog)
  //(*EventTable(execmark)
  //*)
  END_EVENT_TABLE()execmark::execmark(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				      const wxSize & size)
{
  //(*Initialize(execmark)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, wxID_ANY, _("Marca/Desmarca arquivo de pares"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(523, 309));
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
  StaticText5 =
    new wxStaticText(Panel1, ID_STATICTEXT5, _T("0"), wxPoint(288, 160), wxSize(72, 17),
		     wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
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
  BitmapButton3 =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ERROR")),
						wxART_BUTTON), wxPoint(112, 152), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  BitmapButton3->Disable();
  BitmapButton3->SetToolTip(_("Interrompe"));
  wxString __wxRadioBoxChoices_1[2] =
  {
  _("Desmarca"), _("Marca")};
  RadioBox1 =
    new wxRadioBox(Panel1, ID_RADIOBOX1, _(" Opção "), wxPoint(24, 80), wxSize(184, 48), 2,
		   __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
  text_minval =
    new wxTextCtrl(Panel1, ID_TEXTCTRL3, _T("0"), wxPoint(232, 96), wxDefaultSize, wxTE_RIGHT,
		   wxDefaultValidator, _T("ID_TEXTCTRL3"));
  text_minval->Hide();
  text_maxval =
    new wxTextCtrl(Panel1, ID_TEXTCTRL1, _T("0"), wxPoint(336, 96), wxDefaultSize, wxTE_RIGHT,
		   wxDefaultValidator, _T("ID_TEXTCTRL1"));
  text_maxval->Hide();
  StaticText2 =
    new wxStaticText(Panel1, ID_STATICTEXT2, _("Registro corrente:"), wxPoint(160, 160),
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  minlbl =
    new wxStaticText(Panel1, ID_STATICTEXT4, _("Min. par"), wxPoint(232, 80), wxDefaultSize, 0,
		     _T("ID_STATICTEXT4"));
  minlbl->Hide();
  maxlbl =
    new wxStaticText(Panel1, ID_STATICTEXT3, _("Max. n/par"), wxPoint(336, 80), wxDefaultSize, 0,
		     _T("ID_STATICTEXT3"));
  maxlbl->Hide();
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
	  (wxObjectEventFunction) & execmark::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execmark::OnBitmapButton2Click);
  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & execmark::OnBitmapButton3Click);
  Connect(ID_RADIOBOX1, wxEVT_COMMAND_RADIOBOX_SELECTED,
	  (wxObjectEventFunction) & execmark::OnRadioBox1Select);
  //*)
}

execmark::~execmark()
{
  //(*Destroy(execmark)
  //*)
}

void
execmark::OnRadioBox1Select(wxCommandEvent & event)
{
  int op = RadioBox1->GetSelection();
  if (op)
  {
    text_minval->Show();
    text_maxval->Show();
    minlbl->Show();
    maxlbl->Show();
  }
  else
  {
    text_minval->Hide();
    text_maxval->Hide();
    minlbl->Hide();
    maxlbl->Hide();
  }
}

void
execmark::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog1->SetWildcard(_T("*.lnkcfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));
  if (FileDialog1->ShowModal() == wxID_OK)
    cfgfilenamectrl->SetValue(FileDialog1->GetPath());
  else
    cfgfilenamectrl->SetValue(_T(""));

  wxString cfgfilename = cfgfilenamectrl->GetValue();

  if (!wxIsEmpty(cfgfilename) && wxFileExists(cfgfilename))
  {
    wxFileName matchfile = wxFileName(cfgfilename);
    ntable t;
    matchfile.SetExt(t.defdbext().Right(3));
    wxString name = matchfile.GetName();
    name = name + _T("SCORE");
    matchfile.SetName(name);

    if (wxFileExists(matchfile.GetFullPath()))
      BitmapButton2->Enable();
    else
    {
      wxMessageBox(_("Arquivo de pares não existe"), _("ARQUIVO INEXISTENTE"), wxICON_ERROR);
      BitmapButton2->Disable();
    }
  }
}

void
execmark::markrecs(void)
{
  int op = RadioBox1->GetSelection();
  double valmin = 0.0;
  double valmax = 0.0;
  if (op)
  {
    wxString tmp = text_minval->GetValue();
    tmp.Replace(CVTFROM, CVTTO);
    tmp.ToDouble(&valmin);
    tmp = text_maxval->GetValue();
    tmp.Replace(CVTFROM, CVTTO);
    tmp.ToDouble(&valmax);
  }

  tbl.first();
  Gauge1->SetRange(tbl.gettotalrecs());
  int tic = 0;
  stop = false;
  wxString tmp;
  long nrecs;
  matchrecs = 0L;
  doubtrecs = 0L;
  notmrecs = 0L;
  unmrecs = 0L;
  double val;
  while (!tbl.eof() && !stop)
  {
    nrecs = tbl.getcurrentrec();
    tmp.Printf(_T("%d"), nrecs);
    StaticText5->SetLabel(tmp);
    Gauge1->SetValue(nrecs);
    ++tic;
    if (tic > 99)
    {
      tic = 0;
      wxYieldIfNeeded();
    }
    if (op)
    {
      tmp = tbl.getstring(_T("SCORE"));
      tmp.Replace(CVTFROM, CVTTO);
      if (tmp.ToDouble(&val))
      {
	if (val >= valmin)
	{
	  tmp = _T("+");
	  matchrecs++;
	}
	else if (val <= valmax)
	{
	  tmp = _T("-");
	  notmrecs++;
	}
	else
	{
	  tmp = _T("?");
	  doubtrecs++;
	}
      }
      else
      {
	unmrecs++;
	tmp = _T("*");
      }
    }
    else
    {
      tmp = _T("*");
    }
    tbl.setfield(tmp, _T("MATCH"));
    tbl.replacerec();
    tbl.next();
  }
  if (tbl.eof())
    msg = _T("");
  if (stop)
    msg = _("Processamento interrompido pelo usuário");
}

void
execmark::OnBitmapButton2Click(wxCommandEvent & event)
{
  msg = _("Erro no processamento");
  BitmapButton1->Disable();
  BitmapButton2->Disable();
  opencfgfile->Disable();
  BitmapButton3->Enable();
  StopWatch1.Start();
  wxBeginBusyCursor();
  wxFileName matchfile = wxFileName(cfgfilenamectrl->GetValue());
  matchfile.SetExt(tbl.defdbext().Right(3));
  wxString name = matchfile.GetName();
  name = name + _T("SCORE");
  matchfile.SetName(name);
  name = matchfile.GetFullPath();
  try
  {
    tbl.open(name);
    markrecs();
    tbl.close();
  } catch( ...)
  {
  };
  wxEndBusyCursor();
  StopWatch1.Pause();

  long time = StopWatch1.Time() / 1000L;	// time in seconds
  int secs = (int) (time % 60L);
  time /= 60L;			// time in minutes
  int mins = (int) (time % 60L);
  int hrs = (int) (time / 60L);
  wxString timestring;

  int op = RadioBox1->GetSelection();

  if (op)
    timestring.Printf(_
		      ("\nPares: %d Dúvidas: %d N/pares: %d Invál: %d\nTempo de execução: %d:%02d:%02d"),
		      matchrecs, doubtrecs, notmrecs, unmrecs, hrs, mins, secs);
  else
    timestring.Printf(_("\nTempo de execução: %d:%02d:%02d"), hrs, mins, secs);

  if (msg.IsEmpty())
    wxMessageBox(_("Processamento OK." + timestring), _("ENCERRADO"));
  else
    wxMessageBox(msg + timestring, _("ERRO"), wxICON_ERROR);

  ops_log log;
  if (op)
    timestring.Printf(_T("+:%d ?:%d -:%d *:%d %d:%02d:%02d"),
		      matchrecs, doubtrecs, notmrecs, unmrecs, hrs, mins, secs);
  else
    timestring.Printf(_T("%d:%02d:%02d"), hrs, mins, secs);
  if (op)
    log.log_event(_T("MARK"), cfgfilenamectrl->GetValue(), timestring, msg);
  else
    log.log_event(_T("UNMARK"), cfgfilenamectrl->GetValue(), timestring, msg);

  BitmapButton1->Enable();
  BitmapButton3->Disable();
}

void
execmark::OnBitmapButton3Click(wxCommandEvent & event)
{
  BitmapButton3->Disable();
  stop = true;
  msg = _("Processamento interrompido");
}
