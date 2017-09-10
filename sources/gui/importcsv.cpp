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
// Nome:        importcsv.cpp
// Propósito:   Classe (janela) para importar dados de arquivo texto
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2010-01-23
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "importcsv.h"

#include "ops_log.h"

//(*InternalHeaders(importcsv)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <wx/tokenzr.h>
#include <wx/filefn.h>
#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <wx/textfile.h>

#include <iostream>
#include <fstream>

#include "ntable.h"
#include "dbutils.h"

//(*IdInit(importcsv)
const long
  importcsv::ID_TEXTCTRL1 = wxNewId();
const long
  importcsv::ID_BUTTON1 = wxNewId();
const long
  importcsv::ID_STATICTEXT1 = wxNewId();
const long
  importcsv::ID_TEXTCTRL2 = wxNewId();
const long
  importcsv::ID_STATICTEXT2 = wxNewId();
const long
  importcsv::ID_TEXTCTRL3 = wxNewId();
const long
  importcsv::ID_RADIOBOX1 = wxNewId();
const long
  importcsv::ID_GRID1 = wxNewId();
const long
  importcsv::ID_STATICTEXT3 = wxNewId();
const long
  importcsv::ID_STATICTEXT4 = wxNewId();
const long
  importcsv::ID_BUTTON2 = wxNewId();
const long
  importcsv::ID_BUTTON3 = wxNewId();
const long
  importcsv::ID_BUTTON4 = wxNewId();
const long
  importcsv::ID_BUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(importcsv, wxDialog)
  //(*EventTable(importcsv)
  //*)
  END_EVENT_TABLE()importcsv::importcsv(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					const wxSize & size)
{
  //(*Initialize(importcsv)
  wxFlexGridSizer *
    FlexGridSizer1;
  wxFlexGridSizer *
    FlexGridSizer2;
  wxFlexGridSizer *
    FlexGridSizer4;
  wxFlexGridSizer *
    FlexGridSizer3;
  wxBoxSizer *
    BoxSizer1;
  wxFlexGridSizer *
    FlexGridSizer5;

  Create(parent, id, _("Importa arquivo texto"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(7, 1, 0, 0);
  FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
  filenamectrl =
    new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(378, 29), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL1"));
  FlexGridSizer2->Add(filenamectrl, 1,
		      wxTOP | wxLEFT | wxEXPAND | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  selfilenamebtnButton1 =
    new wxButton(this, ID_BUTTON1, _T("..."), wxDefaultPosition, wxSize(28, 29), 0,
		 wxDefaultValidator, _T("ID_BUTTON1"));
  selfilenamebtnButton1->SetToolTip(_("Seleciona o arquivo"));
  FlexGridSizer2->Add(selfilenamebtnButton1, 1,
		      wxTOP | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer2, 1,
		      wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3 = new wxFlexGridSizer(0, 4, 0, 0);
  StaticText1 =
    new wxStaticText(this, ID_STATICTEXT1, _("Separador de definições:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  FlexGridSizer3->Add(StaticText1, 1,
		      wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  fldsep =
    new wxTextCtrl(this, ID_TEXTCTRL2, _T(","), wxDefaultPosition, wxSize(27, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL2"));
  FlexGridSizer3->Add(fldsep, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  StaticText2 =
    new wxStaticText(this, ID_STATICTEXT2, _("Separador de campos:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  FlexGridSizer3->Add(StaticText2, 1,
		      wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  recsep =
    new wxTextCtrl(this, ID_TEXTCTRL3, _T("|"), wxDefaultPosition, wxSize(27, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL3"));
  FlexGridSizer3->Add(recsep, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer3, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
  wxString __wxRadioBoxChoices_1[3] =
  {
  _("Primeira linha"), _("Arquivo separado"), _("Entrada manual")};
  RadioBox1 =
    new wxRadioBox(this, ID_RADIOBOX1, _(" Cabeçalho "), wxDefaultPosition, wxDefaultSize, 3,
		   __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
  BoxSizer1->Add(RadioBox1, 1,
		 wxBOTTOM | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		 5);
  FlexGridSizer1->Add(BoxSizer1, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(412, 165), 0, _T("ID_GRID1"));
  Grid1->CreateGrid(5, 4);
  Grid1->EnableEditing(true);
  Grid1->EnableGridLines(true);
  Grid1->SetColLabelValue(0, _("Nome"));
  Grid1->SetColLabelValue(1, _("Tipo"));
  Grid1->SetColLabelValue(2, _("Tamanho"));
  Grid1->SetColLabelValue(3, _("Decimais"));
  Grid1->SetDefaultCellFont(Grid1->GetFont());
  Grid1->SetDefaultCellTextColour(Grid1->GetForegroundColour());
  FlexGridSizer1->Add(Grid1, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
  StaticText3 =
    new wxStaticText(this, ID_STATICTEXT3, _("Registro corrente:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  FlexGridSizer5->Add(StaticText3, 1, wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  reclabel =
    new wxStaticText(this, ID_STATICTEXT4, _T("0"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT4"));
  FlexGridSizer5->Add(reclabel, 1, wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer5, 1, wxBOTTOM | wxLEFT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL,
		      5);
  FlexGridSizer4 = new wxFlexGridSizer(0, 5, 0, 0);
  adbtn =
    new wxButton(this, ID_BUTTON2, _("Adiciona"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON2"));
  FlexGridSizer4->Add(adbtn, 1,
		      wxBOTTOM | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  delbtn =
    new wxButton(this, ID_BUTTON3, _("Apaga"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON3"));
  FlexGridSizer4->Add(delbtn, 1,
		      wxBOTTOM | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer4->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  cancelbtn =
    new wxButton(this, ID_BUTTON4, _("Cancela"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON4"));
  FlexGridSizer4->Add(cancelbtn, 1,
		      wxBOTTOM | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  okbtn =
    new wxButton(this, ID_BUTTON5, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator,
		 _T("ID_BUTTON5"));
  FlexGridSizer4->Add(okbtn, 1,
		      wxBOTTOM | wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL |
		      wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer4, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr,
		     wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition,
		     wxDefaultSize, _T("wxFileDialog"));
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & importcsv::OnselfilenamebtnButton1Click);
  Connect(ID_RADIOBOX1, wxEVT_COMMAND_RADIOBOX_SELECTED,
	  (wxObjectEventFunction) & importcsv::OnRadioBox1Select);
  //Connect(ID_GRID1,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&importcsv::OnGrid1CellSelect);
  Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & importcsv::OnadbtnClick);
  Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & importcsv::OndelbtnClick);
  Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & importcsv::OncancelbtnClick);
  Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & importcsv::OnokbtnClick);
  //*)

  wxArrayString fldtypes;
  fldtypes.Add(_("Caractere"));
  fldtypes.Add(_("Inteiro"));
  fldtypes.Add(_("Fracionário"));
  fldtypes.Add(_("Booleano"));
  fldtypes.Add(_("Data"));
  edit = new wxGridCellChoiceEditor(fldtypes);
  for (int i = 0; i < 6; i++)
    Grid1->SetCellEditor(i, 1, edit);
}

importcsv::~importcsv()
{
  //(*Destroy(importcsv)
  //*)
}

void
importcsv::OnadbtnClick(wxCommandEvent & event)
{
  Grid1->AppendRows();
  int row = Grid1->GetNumberRows() - 1;
  Grid1->SetCellEditor(row, 1, edit);
}

void
importcsv::OndelbtnClick(wxCommandEvent & event)
{
  wxArrayInt selrows = Grid1->GetSelectedRows();
  for (int i = 0; i < selrows.Count(); i++)
    Grid1->DeleteRows(selrows[i]);
}

void
importcsv::OncancelbtnClick(wxCommandEvent & event)
{
  Close();
}

void
importcsv::OnokbtnClick(wxCommandEvent & event)
{
  wxString filename = filenamectrl->GetValue();
  wxString rcsep = recsep->GetValue();
  int retcode = wxID_CANCEL;
  if (!filename.IsEmpty() && wxFileExists(filename) && !rcsep.IsEmpty())
  {
    int nflds = Grid1->GetNumberRows();
    wxArrayString strarray, fldspec;
    wxString aux;
    for (int i = 0; i < nflds; i++)
    {
      fldspec.Clear();
      for (int j = 0; j < 4; j++)
      {
	aux = Grid1->GetCellValue(i, j);
	{
	  if (j == 1)
	    fldspec.Add(aux[0]);
	  else
	    fldspec.Add(aux);
	}
      }
      if (fldspec.GetCount() && !fldspec[0].IsEmpty())
      {
	aux = packarray(fldspec, _T(","));
	strarray.Add(aux);
      }
    }
    if (strarray.GetCount())
    {
      ntable tb;
      tb.setstructure(strarray);
      wxFileName tmp(filename);
      tmp.SetExt(tb.defdbext().Right(3));
      filename = tmp.GetFullPath();
      if (wxFileExists(filename))
	wxRemoveFile(filename);
      if (tb.open(filename))
      {
	std::ifstream infile;
	filename = filenamectrl->GetValue();
	infile.open(filename.mb_str(wxConvUTF8));
	char bigbuffer[MAX_BYTES];
	wxArrayString list, fld;
	wxString aux;
	long nlines = 0l;
	long nrecs = 0l;
	int ticker = 0;
	if (RadioBox1->GetSelection() == 0)
	  infile.getline(bigbuffer, MAX_BYTES);
	while (!infile.eof() && !infile.fail())
	{
	  infile.getline(bigbuffer, MAX_BYTES);
	  aux = wxString(bigbuffer, wxConvUTF8);
	  if (!aux.IsEmpty())
	  {
	    if (tb.str2rec(aux, rcsep))
	      nrecs++;
	    nlines++;
	    reclabel->SetLabel(wxString::Format(_T("%d"), nlines));
	    ticker++;
	    if (ticker > 99)
	    {
	      ticker = 0;
	      wxYieldIfNeeded();
	    }
	  }
	}
	infile.close();
	tb.close();
	aux.Printf(_T("%d/%d"), nlines, nrecs);
	aux = _("Resultado:\nLidos/escritos:\n") + aux;
	wxMessageBox(aux, _("ENCERRADO"));
	retcode = wxID_OK;
	ops_log log;
	log.log_event(_T("IMPCSV"), filenamectrl->GetValue(), _T("N/A"), aux);
      }
    }
  }
  EndModal(retcode);
}

void
importcsv::OnRadioBox1Select(wxCommandEvent & event)
{
  if (RadioBox1->GetSelection() == 0)
  {
    wxString flsep = fldsep->GetValue();
    wxString rcsep = recsep->GetValue();
    if (!rcsep.IsEmpty() && !flsep.IsEmpty())
    {
      std::ifstream infile;
      wxString fname = filenamectrl->GetValue();
      infile.open(fname.char_str(wxConvUTF8));
      char bigbuffer[MAX_BYTES];
      infile.getline(bigbuffer, MAX_BYTES);
      infile.close();
      fname = wxString(bigbuffer, wxConvUTF8);
      wxArrayString list, fld;
      list = unpackarray(fname, rcsep);
      int nflds = list.GetCount();
      int nrows = Grid1->GetNumberRows();
      if (nrows < nflds)
	Grid1->AppendRows((nflds - nrows));
      for (int i = 0; i < nflds; i++)
      {
	fld = unpackarray(list[i], flsep);
	while (fld.GetCount() < 4)
	  fld.Add(_T(""));
	wxString aux;
	for (int j = 0; j < 4; j++)
	  try
	{
	  aux = fld[j].Upper();
	  if (j == 1)
	  {
	    switch ((char) aux[0])
	    {
	    case _T('C'):
	      aux = _("Caractere");
	      break;
	    case _T('I'):
	      aux = _("Inteiro");
	      break;
	    case _T('F'):
	      aux = _("Fracionário");
	      break;
	    case _T('B'):
	      aux = _("Booleano");
	      break;
	    case _T('D'):
	      aux = _("Data");
	      break;
	    case _T('N'):
	      aux = _("Numérico");
	      break;
	    default:
	      aux = _("Erro");
	      break;
	    }
	  };
	  Grid1->SetCellValue(i, j, aux);
	}
	catch( ...)
	{
	};
      }
    }
  }
  else if (RadioBox1->GetSelection() == 1)
  {
    wxString flsep = fldsep->GetValue();
    if (!flsep.IsEmpty())
    {
      if (FileDialog1->ShowModal() == wxID_OK)
      {
	std::ifstream infile;
	wxString fname = FileDialog1->GetPath();
	infile.open(fname.mb_str(wxConvUTF8));
	char bigbuffer[MAX_BYTES];
	wxArrayString list, fld;
	while (!infile.eof() && !infile.fail())
	{
	  infile.getline(bigbuffer, MAX_BYTES);
	  fname = wxString(bigbuffer, wxConvUTF8);
	  if (!fname.IsEmpty())
	    list.Add(fname);
	}
	infile.close();
	int nflds = list.GetCount();
	int nrows = Grid1->GetNumberRows();
	if (nrows < nflds)
	  Grid1->AppendRows((nflds - nrows));
	for (int i = 0; i < nflds; i++)
	{
	  fld = unpackarray(list[i], flsep);
	  wxString aux;
	  while (fld.GetCount() < 4)
	    fld.Add(_T(""));
	  for (int j = 0; j < 4; j++)
	    try
	  {
	    aux = fld[j].Upper();
	    if (j == 1)
	    {
	      switch ((char) aux[0])
	      {
	      case _T('C'):
		aux = _("Caractere");
		break;
	      case _T('I'):
		aux = _("Inteiro");
		break;
	      case _T('F'):
		aux = _("Fracionário");
		break;
	      case _T('B'):
		aux = _("Booleano");
		break;
	      case _T('D'):
		aux = _("Data");
		break;
	      case _T('N'):
		aux = _("Numérico");
		break;
	      default:
		aux = _("Erro");
		break;
	      }
	    }
	    Grid1->SetCellValue(i, j, aux);
	  }
	  catch( ...)
	  {
	  };
	}
      }
    }
  }
}

void
importcsv::OnselfilenamebtnButton1Click(wxCommandEvent & event)
{
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    filenamectrl->SetValue(FileDialog1->GetPath());
    wxString fname = filenamectrl->GetValue();
    if (!fname.IsEmpty() && wxFileExists(fname))
    {
      if (RadioBox1->GetSelection() == 0)
      {
	wxString flsep = fldsep->GetValue();
	wxString rcsep = recsep->GetValue();
	if (!rcsep.IsEmpty() && !flsep.IsEmpty())
	{
	  std::ifstream infile;
	  infile.open(fname.char_str(wxConvUTF8));
	  char bigbuffer[MAX_BYTES];
	  infile >> bigbuffer;
	  infile.close();
	  fname = wxString(bigbuffer, wxConvUTF8);
	  wxArrayString list, fld;
	  list = unpackarray(fname, rcsep);
	  int nflds = list.GetCount();
	  int nrows = Grid1->GetNumberRows();
	  if (nrows < nflds)
	    Grid1->AppendRows((nflds - nrows));
	  for (int i = 0; i < nflds; i++)
	  {
	    fld = unpackarray(list[i], flsep);
	    while (fld.GetCount() < 4)
	      fld.Add(_T(""));
	    wxString aux;
	    for (int j = 0; j < 4; j++)
	      try
	    {
	      aux = fld[j].Upper();
	      if (j == 1)
	      {
		switch ((char) aux[0])
		{
		case _T('C'):
		  aux = _("Caractere");
		  break;
		case _T('I'):
		  aux = _("Inteiro");
		  break;
		case _T('F'):
		  aux = _("Fracionário");
		  break;
		case _T('B'):
		  aux = _("Booleano");
		  break;
		case _T('D'):
		  aux = _("Data");
		  break;
		case _T('N'):
		  aux = _("Numérico");
		  break;
		default:
		  aux = _("Erro");
		  break;
		}
	      };
	      Grid1->SetCellValue(i, j, aux);
	    }
	    catch( ...)
	    {
	    };
	  }
	}
      }
    }
  }
}
