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
// Nome:        freqdlg.cpp
// Propósito:   Classe (janela) para gerar frequencia de scores
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "freqdlg.h"

#include "ops_log.h"

//(*InternalHeaders(freqdlg)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

#include <wx/filename.h>
#include <wx/fileconf.h>

//(*IdInit(freqdlg)
const long
  freqdlg::ID_TEXTCTRL4 = wxNewId();
const long
  freqdlg::ID_BITMAPBUTTON1 = wxNewId();
const long
  freqdlg::ID_STATICTEXT3 = wxNewId();
const long
  freqdlg::ID_GAUGE1 = wxNewId();
const long
  freqdlg::ID_STATICTEXT2 = wxNewId();
const long
  freqdlg::ID_STATICTEXT5 = wxNewId();
const long
  freqdlg::ID_BITMAPBUTTON3 = wxNewId();
const long
  freqdlg::ID_STATICLINE1 = wxNewId();
const long
  freqdlg::ID_STATICLINE2 = wxNewId();
const long
  freqdlg::ID_CHECKLISTBOX1 = wxNewId();
const long
  freqdlg::ID_STATICTEXT1 = wxNewId();
const long
  freqdlg::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(freqdlg, wxDialog)
  //(*EventTable(freqdlg)
  //*)
  END_EVENT_TABLE()freqdlg::freqdlg(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(freqdlg)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, wxID_ANY, _("Calcula frequência de valores em campos"), wxDefaultPosition,
	 wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(523, 349));
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(501, 305), wxTAB_TRAVERSAL,
		_T("ID_PANEL1"));
  outfilenamectrl =
    new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxPoint(16, 24), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
  openoutfile =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(432, 24), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  StaticText3 =
    new wxStaticText(Panel1, ID_STATICTEXT3, _("Arq. configuração:"), wxPoint(16, 8),
		     wxDefaultSize, 0, _T("ID_STATICTEXT3"));
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
  BitmapButton2->Disable();
  BitmapButton2->SetToolTip(_("Executa"));
  StaticLine1 =
    new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(0, 168), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE1"));
  StaticLine2 =
    new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(0, 290), wxSize(480, 1), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE2"));
  CheckListBox1 =
    new wxCheckListBox(Panel1, ID_CHECKLISTBOX1, wxPoint(240, 72), wxSize(176, 87), 0, 0, 0,
		       wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
  StaticText1 =
    new wxStaticText(Panel1, ID_STATICTEXT1, _("Campos para determinar freq."), wxPoint(16, 64),
		     wxDefaultSize, 0, _T("ID_STATICTEXT1"));
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

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & freqdlg::OnopenoutfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & freqdlg::Run);
  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & freqdlg::OnBitmapButton1Click);
  //*)
}

freqdlg::~freqdlg()
{
  //(*Destroy(freqdlg)
  //*)
}

void
freqdlg::OnopenoutfileClick(wxCommandEvent & event)
{
  FileDialog1->SetWildcard(_T("*.lnkcfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));

  if (FileDialog1->ShowModal() == wxID_OK)
  {
    wxString fname = FileDialog1->GetPath();
    if (wxFileExists(fname))
    {
      outfilenamectrl->SetValue(fname);
      CheckListBox1->Clear();

      wxFileConfig *cfgfile =
	new wxFileConfig(_T(""), _T(""), fname, _T(""), wxCONFIG_USE_LOCAL_FILE);
      compname = _T("");
      cfgfile->Read(_T("FILES/COMPNAME"), &compname);
      refname = _T("");
      cfgfile->Read(_T("FILES/REFNAME"), &refname);
      long nlines = 0L;
      cfgfile->Read(_T("COMPARE/NLINES"), &nlines);
      reffields.Clear();
      compfields.Clear();
      wxString tmp, aux, line;
      for (int i = 0; i < nlines; i++)
      {
	tmp = _T("");
	aux.Printf(_T("COMPARE/COMP%d"), i);
	cfgfile->Read(aux, &tmp);
	compfields.Add(tmp);
	tmp = _T("");
	aux.Printf(_T("COMPARE/REF%d"), i);
	cfgfile->Read(aux, &tmp);
	reffields.Add(tmp);
      }
      delete cfgfile;

      wxArrayString tmparr;
      //tbl.open(fname);
      for (int i = 0; i < nlines; i++)
	tmparr.Add(reffields[i] + _T("/") + compfields[i]);
      CheckListBox1->InsertItems(tmparr, 0);
      BitmapButton2->Enable();
    }
    else
    {
      outfilenamectrl->SetValue(_T(""));
      CheckListBox1->Clear();
      BitmapButton2->Disable();
      wxMessageBox(_("Arquivo inexistente"), _("ERRO"), wxOK);
    }
  }
  else
    outfilenamectrl->SetValue(_T(""));
}

void
freqdlg::OnBitmapButton1Click(wxCommandEvent & event)
{
  EndModal(wxID_OK);
}

bool freqdlg::processfile(wxString fname, wxArrayString fields)
{
  ntable
    ptbl;
  ptbl.open(fname);
  bool
    retval = false;

  long
    nrecs = ptbl.gettotalrecs();
  Gauge1->SetRange((int) nrecs);
  ptbl.first();
  long
    crec = 0l;
  wxString
    lbl;
  Gauge1->SetValue(0);
  int
    ticker = 0;
  wxArrayString *
    values = 0;
  wxArrayInt *
    counts = 0;
  wxArrayInt
    totals;
  int
    nchecks = fields.Count();
  try
  {
    values = new wxArrayString[nchecks];
    counts = new wxArrayInt[nchecks];

    wxString
      aux;

    for (int i = 0; i < nchecks; i++)
      totals.Add(0);

    while (!ptbl.eof())
    {
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
      for (int i = 0; i < nchecks; i++)
      {
	aux = fields[i];
	aux = ptbl.getstring(aux);
	if (!aux.IsEmpty())
	{
	  totals[i] = totals[i] + 1;
	  int
	    j;
	  for (j = 0; j < values[i].Count(); j++)
	    if (aux == values[i][j])
	      break;
	  if (j >= values[i].Count())
	  {
	    values[i].Add(aux);
	    counts[i].Add(1);
	  }
	  else
	  {
	    int
	      n = counts[i][j];
	    n++;
	    counts[i][j] = n;
	  }
	}
      }
      ptbl.next();
    }
    wxFileName
      ofname = wxFileName(fname);
    ofname.SetExt(_T("freq"));
    fname = ofname.GetFullPath();
    msgfile.open(fname.mb_str(wxConvUTF8));
    msgfile << "[BEGINVARS]" << std::endl;
    for (int i = 0; i < nchecks; i++)
      msgfile << fields[i].mb_str(wxConvUTF8) << std::endl;
    msgfile << "[ENDVARS]" << std::endl;
    msgfile << "[BEGINDATA]" << std::endl;
    for (int i = 0; i < nchecks; i++)
    {
      msgfile << "[BEGIN" << fields[i].mb_str(wxConvUTF8) << "]" << std::endl;
      for (int j = 0; j < values[i].Count(); j++)
	msgfile << values[i][j].mb_str(wxConvUTF8) << " "
	  << double ((double) counts[i][j] / (double) totals[i]) <<
	std::endl;
      msgfile << "[END" << fields[i].mb_str(wxConvUTF8) << "]" << std::endl;
    }
    msgfile << "[ENDDATA]" << std::endl;
    msgfile.close();
    delete[]values;
    delete[]counts;
    retval = true;
  } catch( ...)
  {
    if (values)
      delete[]values;
    if (counts)
      delete[]counts;
  };
  ptbl.close();
  return retval;
}

bool freqdlg::compute(void)
{
  bool
    retval = false;

  wxArrayString *
    compvalues = 0;
  wxArrayDouble *
    compfreqs = 0;
  wxArrayString *
    refvalues = 0;
  wxArrayDouble *
    reffreqs = 0;

  try
  {
    wxFileName
      ofname;
    char
      buff[1024];
    wxString
      aux;
    wxString
      fname;
    wxString
      vname;
    double
      freq;

    ofname = wxFileName(refname);
    ofname.SetExt(_T("freq"));

    fname = ofname.GetFullPath();
    inputfile.open(fname.mb_str(wxConvUTF8));

    inputfile >> buff;
    aux = wxString::FromUTF8(buff);
    wxArrayString
      refvars;

    aux = wxString::FromUTF8(buff);
    if (aux == _T("[BEGINVARS]"))
    {
      inputfile >> buff;
      aux = wxString::FromUTF8(buff);
      while ((aux != _T("[ENDVARS]")) && !inputfile.eof())
      {
	if (aux != _T("[ENDVARS]"))
	  refvars.Add(aux);
	inputfile >> buff;
	aux = wxString::FromUTF8(buff);
      }

      inputfile >> buff;
      aux = wxString::FromUTF8(buff);
      int
	nvars = refvars.Count();

      if (nvars && (aux == _T("[BEGINDATA]")))
      {
	refvalues = new wxArrayString[nvars];
	reffreqs = new wxArrayDouble[nvars];
	for (int i = 0; i < nvars; i++)
	{
	  vname = _T("[BEGIN") + refvars[i] + _T("]");
	  inputfile >> buff;
	  aux = wxString::FromUTF8(buff);
	  if (aux == vname)
	  {
	    vname = _T("[END") + refvars[i] + _T("]");
	    inputfile >> buff;
	    aux = wxString::FromUTF8(buff);
	    while ((aux != vname) && (aux != _T("[ENDDATA]")) && !inputfile.eof())
	    {
	      refvalues[i].Add(aux);
	      inputfile >> freq;
	      reffreqs[i].Add(freq);
	      inputfile >> buff;
	      aux = wxString::FromUTF8(buff);
	    }
	  }
	}
      }
    }

    inputfile.close();

    ofname = wxFileName(compname);
    ofname.SetExt(_T("freq"));

    fname = ofname.GetFullPath();
    inputfile.open(fname.mb_str(wxConvUTF8));

    inputfile >> buff;
    aux = wxString::FromUTF8(buff);
    wxArrayString
      compvars;

    if (aux == _T("[BEGINVARS]"))
    {
      inputfile >> buff;
      aux = wxString::FromUTF8(buff);
      while ((aux != _T("[ENDVARS]")) && !inputfile.eof())
      {
	if (aux != _T("[ENDVARS]"))
	  compvars.Add(aux);
	inputfile >> buff;
	aux = wxString::FromUTF8(buff);
      }
      inputfile >> buff;
      aux = wxString::FromUTF8(buff);
      int
	nvars = compvars.Count();
      if (nvars && (aux == _T("[BEGINDATA]")))
      {
	compvalues = new wxArrayString[nvars];
	compfreqs = new wxArrayDouble[nvars];
	for (int i = 0; i < nvars; i++)
	{
	  vname = _T("[BEGIN") + compvars[i] + _T("]");
	  inputfile >> buff;
	  aux = wxString::FromUTF8(buff);
	  if (aux == vname)
	  {
	    vname = _T("[END") + compvars[i] + _T("]");
	    inputfile >> buff;
	    aux = wxString::FromUTF8(buff);
	    while ((aux != vname) && (aux != _T("[ENDDATA]")) && !inputfile.eof())
	    {
	      compvalues[i].Add(aux);
	      inputfile >> freq;
	      compfreqs[i].Add(freq);
	      inputfile >> buff;
	      aux = wxString::FromUTF8(buff);
	    }
	  }
	}
      }
    }

    inputfile.close();

    if (compvalues && refvalues)
    {
      int
	nvars = refvars.Count();
      int
	nrefs,
	ncomps;
      double
	fval1,
	fval2;
      for (int i = 0; i < nvars; i++)
      {
	int
	  j,
	  k;
	nrefs = refvalues[i].Count();
	ncomps = compvalues[i].Count();
	for (j = 0; j < nrefs; j++)
	{
	  for (k = 0; k < ncomps; k++)
	    if (refvalues[i][j] == compvalues[i][k])
	      break;
	  if (k < ncomps)
	  {
	    fval1 = reffreqs[i][j];
	    fval2 = compfreqs[i][k];
	    reffreqs[i][j] = fval1 * fval2;
	  }
	  else
	    reffreqs[i][j] = -1.0;
	}
      }

      fname = FileDialog1->GetPath();
      ofname = wxFileName(fname);
      ofname.SetExt(_T("xfreq"));
      fname = ofname.GetFullPath();
      msgfile.open(fname.mb_str(wxConvUTF8));
      msgfile << "[BEGIN*VARS]" << std::endl;
      for (int i = 0; i < nvars; i++)
	msgfile << refvars[i].
	  mb_str(wxConvUTF8) << "/" << compvars[i].mb_str(wxConvUTF8) << std::endl;
      msgfile << "[END*VARS]" << std::endl;
      msgfile << "[BEGIN*DATA]" << std::endl;
      for (int i = 0; i < nvars; i++)
      {
	msgfile << "[BEGIN" << refvars[i].
	  mb_str(wxConvUTF8) << "/" << compvars[i].mb_str(wxConvUTF8) << "]" << std::endl;
	for (int j = 0; j < refvalues[i].Count(); j++)
	  if (reffreqs[i][j] > -1.0)
	    msgfile << refvalues[i][j].mb_str(wxConvUTF8) << " " << reffreqs[i][j] << std::endl;
	msgfile << "[END" << refvars[i].
	  mb_str(wxConvUTF8) << "/" << compvars[i].mb_str(wxConvUTF8) << "]" << std::endl;
      }
      msgfile << "[END*DATA]" << std::endl;
      msgfile.close();
    }
    retval = true;
  }
  catch( ...)
  {
  };

  if (compvalues)
    delete[]compvalues;
  if (refvalues)
    delete[]refvalues;
  if (compfreqs)
    delete[]compfreqs;
  if (reffreqs)
    delete[]reffreqs;


  return retval;
};


void
freqdlg::Run(wxCommandEvent & event)
{
  execute();
}

void
freqdlg::execute(void)
{
  int nitems = CheckListBox1->GetCount();

  int nchecks = 0;
  for (int i = 0; i < nitems; i++)
    if (CheckListBox1->IsChecked(i))
      nchecks++;
  wxString msg = _T("Erro no processamento");

  if (nchecks)
  {
    openoutfile->Disable();
    StopWatch1.Start();
    wxBeginBusyCursor();

    wxArrayString tmp;

    for (int i = 0; i < nitems; i++)
      if (CheckListBox1->IsChecked(i))
	tmp.Add(reffields[i]);

    if (processfile(refname, tmp))
    {
      tmp.Clear();
      for (int i = 0; i < nitems; i++)
	if (CheckListBox1->IsChecked(i))
	  tmp.Add(compfields[i]);
      if (processfile(compname, tmp))
	if (compute())
	  msg = _T("");
    }
  }
  else
    msg = _("Escolha pelo menos um campo!");

  wxString timestring;
  wxEndBusyCursor();
  StopWatch1.Pause();
  long time = StopWatch1.Time() / 1000L;	// time in seconds
  int secs = (int) (time % 60L);
  time /= 60L;			// time in minutes
  int mins = (int) (time % 60L);
  int hrs = (int) (time / 60L);
  timestring.Printf(_("\nTempo de execução: %d:%02d:%02d"), hrs, mins, secs);

  if (msg.IsEmpty())
    wxMessageBox(_("Processamento OK.") + timestring, _("ENCERRADO"));
  else
    wxMessageBox(msg + timestring, _("ERRO"), wxICON_ERROR);

  ops_log log;
  timestring.Printf(_T("%d:%02d:%02d"), hrs, mins, secs);
  log.log_event(_T("FREQG"), outfilenamectrl->GetValue(), timestring, msg);
}
