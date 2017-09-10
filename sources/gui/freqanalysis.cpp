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
// Nome:        freqanalysis.cpp
// Propósito:   Classe (janela) para analisar frequencia de scores
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "freqanalysis.h"

#include "checksep.h"

#include "ops_log.h"

//(*InternalHeaders(freqanalysis)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

#include <wx/filename.h>

//(*IdInit(freqanalysis)
const long
  freqanalysis::ID_STATICTEXT1 = wxNewId();
const long
  freqanalysis::ID_CHOICE1 = wxNewId();
const long
  freqanalysis::ID_GRID1 = wxNewId();
const long
  freqanalysis::ID_RADIOBOX1 = wxNewId();
const long
  freqanalysis::ID_BITMAPBUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(freqanalysis, wxDialog)
  //(*EventTable(freqanalysis)
  //*)
  END_EVENT_TABLE()freqanalysis::freqanalysis(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					      const wxSize & size)
{
  //(*Initialize(freqanalysis)
  wxFlexGridSizer *
    FlexGridSizer1;
  wxFlexGridSizer *
    FlexGridSizer2;
  wxFlexGridSizer *
    FlexGridSizer3;

  Create(parent, wxID_ANY, _("Frequência de valores"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
  FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
  StaticText1 =
    new wxStaticText(this, ID_STATICTEXT1, _("Campo:"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT1"));
  FlexGridSizer2->Add(StaticText1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  Choice1 =
    new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(251, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE1"));
  FlexGridSizer2->Add(Choice1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer2, 1,
		      wxTOP | wxLEFT | wxRIGHT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
  Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(323, 196), 0, _T("ID_GRID1"));
  Grid1->CreateGrid(1, 3);
  Grid1->EnableEditing(false);
  Grid1->EnableGridLines(true);
  Grid1->SetColLabelValue(0, _("Valor"));
  Grid1->SetColLabelValue(1, _("Freq"));
  Grid1->SetColLabelValue(2, _("Cum"));
  Grid1->SetDefaultCellFont(Grid1->GetFont());
  Grid1->SetDefaultCellTextColour(Grid1->GetForegroundColour());
  FlexGridSizer1->Add(Grid1, 1,
		      wxBOTTOM | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
  wxString __wxRadioBoxChoices_1[2] =
  {
  _("Frequências"), _("Valores")};
  RadioBox1 =
    new wxRadioBox(this, ID_RADIOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2,
		   __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
  FlexGridSizer3->Add(RadioBox1, 1,
		      wxBOTTOM | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  BitmapButton1 =
    new wxBitmapButton(this, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_UNDO")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  BitmapButton1->SetToolTip(_("Retorna"));
  FlexGridSizer3->Add(BitmapButton1, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Selecione o arquivo de frequências"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_OPEN | wxFD_FILE_MUST_EXIST,
		     wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(ID_CHOICE1, wxEVT_COMMAND_CHOICE_SELECTED,
	  (wxObjectEventFunction) & freqanalysis::OnChoice1Select);
  Connect(ID_RADIOBOX1, wxEVT_COMMAND_RADIOBOX_SELECTED,
	  (wxObjectEventFunction) & freqanalysis::OnChoice1Select);
  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & freqanalysis::OnBitmapButton1Click);
  //*)

  filename = _T("");
}

freqanalysis::~freqanalysis()
{
  //(*Destroy(freqanalysis)
  //*)
}


void
freqanalysis::OnBitmapButton1Click(wxCommandEvent & event)
{
  ops_log log;
  log.log_event(_T("FANL"), filename);
  Close();
}

wxString freqanalysis::readline(void)
{
  char
    buff[1024];
  wxString
    aux;
  inputfile >> buff;
  aux = wxString::FromUTF8(buff);
  return aux;
}

void
freqanalysis::setfilename(wxString fname)
{
  if (fname.IsEmpty())
  {
    FileDialog1->SetWildcard(_T("*.xfreq"));
    FileDialog1->SetMessage(_T(""));

    if (FileDialog1->ShowModal() == wxID_OK)
    {
      fname = FileDialog1->GetPath();
      if (fname.IsEmpty() || !wxFileExists(fname))
	Close();
    }
    else
      Close();
  }

  filename = fname;
  inputfile.open(filename.mb_str(wxConvUTF8));

  wxString aux = readline();
  while ((aux != _T("[BEGIN*VARS]") && !inputfile.eof()))
    aux = readline();

  while ((aux != _T("[END*VARS]") && !inputfile.eof()))
  {
    aux = readline();
    if (!aux.IsEmpty() && (aux != _T("[BEGIN*VARS]")) && (aux != _T("[END*VARS]")))
      Choice1->AppendString(aux);
  }

  inputfile.close();
}

void
freqanalysis::processvalue(wxString vname, double val)
{
  wxString aux;
  aux.Printf(_T("%10.6f"), val);

  if (Grid1->GetCellValue(0, 0) == _T("?"))
  {
    Grid1->SetCellValue(0, 0, vname);
    Grid1->SetCellValue(0, 1, aux);
  }
  else
  {
    Grid1->AppendRows(1);
    int i = Grid1->GetNumberRows() - 1;
    Grid1->SetCellValue(i, 0, vname);
    Grid1->SetCellValue(i, 1, aux);
  }
}

void
freqanalysis::processvalue(double val)
{
  wxString aux;
  aux.Printf(_T("%10.6f"), val);

  if (Grid1->GetCellValue(0, 0) == _T("?"))
  {
    Grid1->SetCellValue(0, 0, aux);
    Grid1->SetCellValue(0, 1, _T("1"));
  }
  else
  {
    int i;
    int nrows = Grid1->GetNumberRows();
    bool found = false;
    for (i = 0; i < nrows; i++)
      if (aux == Grid1->GetCellValue(i, 0))
      {
	found = true;
	break;
      };
    long ntimes;
    if (found)
    {
      aux = Grid1->GetCellValue(i, 1).Trim(false);
      aux.ToLong(&ntimes);
      aux.Printf(_T("%d"), ++ntimes);
      Grid1->SetCellValue(i, 1, aux);
    }
    else
    {
      Grid1->AppendRows(1);
      Grid1->SetCellValue(i, 0, aux);
      aux.Printf(_T("%d"), 1);
      Grid1->SetCellValue(i, 1, aux);
    }
  }
}

void
freqanalysis::swap(int n1, int n2)
{
  wxString swapstr = Grid1->GetCellValue(n1, 0);
  Grid1->SetCellValue(n1, 0, Grid1->GetCellValue(n2, 0));
  Grid1->SetCellValue(n2, 0, swapstr);
  swapstr = Grid1->GetCellValue(n1, 1);
  Grid1->SetCellValue(n1, 1, Grid1->GetCellValue(n2, 1));
  Grid1->SetCellValue(n2, 1, swapstr);
}

void
freqanalysis::sorttable_vals(void)
{
  int gridlines = Grid1->GetNumberRows();
  double n1, n2;
  wxString lbl;

  bool swapped;
  do
  {
    swapped = false;
    for (int i = 0; i < (gridlines - 1); i++)
    {
      lbl = Grid1->GetCellValue(i, 1);
      lbl.Trim(false);
      lbl.Replace(CVTFROM, CVTTO);
      lbl.ToDouble(&n1);
      lbl = Grid1->GetCellValue(i + 1, 1);
      lbl.Trim(false);
      lbl.Replace(CVTFROM, CVTTO);
      lbl.ToDouble(&n2);
      if (n2 > n1)
      {
	swap(i, i + 1);
	swapped = true;
      }
    }
  }
  while (swapped);
}

void
freqanalysis::sorttable(void)
{
  int gridlines = Grid1->GetNumberRows();
  double n1, n2;
  wxString lbl;

  bool swapped;
  do
  {
    swapped = false;
    for (int i = 0; i < (gridlines - 1); i++)
    {
      lbl = Grid1->GetCellValue(i, 0);
      lbl.Trim(false);
      lbl.Replace(CVTFROM, CVTTO);
      lbl.ToDouble(&n1);
      lbl = Grid1->GetCellValue(i + 1, 0);
      lbl.Trim(false);
      lbl.Replace(CVTFROM, CVTTO);
      lbl.ToDouble(&n2);
      if (n2 > n1)
      {
	swap(i, i + 1);
	swapped = true;
      }
    }
  }
  while (swapped);
}

void
freqanalysis::calcfreqs(void)
{
  wxString aux;
  double num;
  int gridlines = Grid1->GetNumberRows();
  for (int i = 0; i < gridlines; i++)
  {
    aux = Grid1->GetCellValue(i, 1).Trim(false);
    aux.Replace(CVTFROM, CVTTO);
    aux.ToDouble(&num);
    if (i)
    {
      double cum;
      aux = Grid1->GetCellValue((i - 1), 2).Trim(false);
      aux.Replace(CVTFROM, CVTTO);
      aux.ToDouble(&cum);
      num += cum;
      aux.Printf(_T("%10.6f"), num);
      Grid1->SetCellValue(i, 2, aux);
    }
    else
      Grid1->SetCellValue(i, 2, aux);
    Grid1->SetCellAlignment(wxALIGN_LEFT, i, 0);
    Grid1->SetCellAlignment(wxALIGN_RIGHT, i, 1);
    Grid1->SetCellAlignment(wxALIGN_RIGHT, i, 2);
  }
}

void
freqanalysis::calcfreqs(int n)
{
  wxString aux;
  long num;
  int gridlines = Grid1->GetNumberRows();
  for (int i = 0; i < gridlines; i++)
  {
    aux = Grid1->GetCellValue(i, 1).Trim(false);
    aux.ToLong(&num);
    double perc = (double) num * 100.0 / (double) n;
    aux.Printf(_T("%10.6f"), perc);
    //Grid1->SetCellValue(i, 1, aux);
    if (i)
    {
      double cum = perc;
      aux = Grid1->GetCellValue((i - 1), 2).Trim(false);
      aux.ToDouble(&perc);
      cum += perc;
      aux.Printf(_T("%10.6f"), cum);
      Grid1->SetCellValue(i, 2, aux);
    }
    else
      Grid1->SetCellValue(i, 2, aux);
    Grid1->SetCellAlignment(wxALIGN_RIGHT, i, 0);
    Grid1->SetCellAlignment(wxALIGN_RIGHT, i, 1);
    Grid1->SetCellAlignment(wxALIGN_RIGHT, i, 2);
  }
}

void
freqanalysis::process(void)
{
  wxBeginBusyCursor();

  int sel = Choice1->GetSelection();
  wxString selval;
  if (sel != wxNOT_FOUND)
  {
    Grid1->Hide();

    int nrows = Grid1->GetNumberRows();

    Grid1->DeleteRows(1, --nrows);

    selval = Choice1->GetString(sel);
    inputfile.open(filename.mb_str(wxConvUTF8));
    wxString aux = readline();
    wxString beg = _T("[BEGIN") + selval + _T("]");
    wxString end = _T("[END") + selval + _T("]");
    while ((aux != beg && !inputfile.eof()))
      aux = readline();

    double fval;
    Grid1->SetCellValue(0, 0, _T("?"));
    int nvals = 0;
    while ((aux != end && !inputfile.eof()))
    {
      aux = readline();
      if (!aux.IsEmpty() && (aux != beg) && (aux != end))
      {
	inputfile >> fval;
	nvals++;
	if (RadioBox1->GetSelection())
	  processvalue(aux, fval * 100);
	else
	  processvalue(fval * 100);
      }
    }

    inputfile.close();

    if (RadioBox1->GetSelection())
      sorttable_vals();
    else
      sorttable();

    if (RadioBox1->GetSelection())
      calcfreqs();
    else
      calcfreqs(nvals);
    Grid1->Show();
  }

  wxEndBusyCursor();
}

void
freqanalysis::OnChoice1Select(wxCommandEvent & event)
{
  process();
}
