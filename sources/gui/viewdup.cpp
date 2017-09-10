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
// Nome:        viewdup.cpp
// Propósito:   Classe (janela) para visualizar duplicações
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "viewdup.h"
#include "progressdialog.h"
#include "ntable_grid.h"
#include "ops_log.h"

#include "checksep.h"

#include <stdlib.h>
#include <wx/filename.h>
#include <wx/wfstream.h>
#include <wx/msgdlg.h>

//(*InternalHeaders(viewdup)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(viewdup)
const long
  viewdup::ID_STATICTEXT1 = wxNewId();
const long
  viewdup::ID_TEXTCTRL1 = wxNewId();
const long
  viewdup::ID_BITMAPBUTTON1 = wxNewId();
const long
  viewdup::ID_GRID2 = wxNewId();
const long
  viewdup::ID_GRID1 = wxNewId();
const long
  viewdup::ID_BUTTON1 = wxNewId();
const long
  viewdup::ID_BUTTON2 = wxNewId();
const long
  viewdup::ID_BUTTON3 = wxNewId();
const long
  viewdup::ID_BUTTON4 = wxNewId();
const long
  viewdup::ID_BITMAPBUTTON2 = wxNewId();
const long
  viewdup::ID_BITMAPBUTTON3 = wxNewId();
const long
  viewdup::ID_BITMAPBUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(viewdup, wxDialog)
  //(*EventTable(viewdup)
  //*)
  END_EVENT_TABLE()viewdup::viewdup(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(viewdup)
  wxFlexGridSizer *
    FlexGridSizer1;
  wxFlexGridSizer *
    FlexGridSizer2;
  wxFlexGridSizer *
    FlexGridSizer3;

  Create(parent, id, _("Visualiza duplicações"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  FlexGridSizer2 = new wxFlexGridSizer(1, 3, 0, 0);
  StaticText1 =
    new wxStaticText(this, ID_STATICTEXT1, _("Arquivo:"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT1"));
  FlexGridSizer2->Add(StaticText1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  filenamectrl =
    new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(415, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  FlexGridSizer2->Add(filenamectrl, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  openfilebtn =
    new wxBitmapButton(this, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  openfilebtn->SetToolTip(_("Abre o arquivo"));
  FlexGridSizer2->Add(openfilebtn, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  FlexGridSizer1->Add(FlexGridSizer2, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  Grid1 = new wxGrid(this, ID_GRID2, wxDefaultPosition, wxSize(526, 203), 0, _T("ID_GRID2"));
  Grid1->CreateGrid(1, 4);
  Grid1->EnableEditing(true);
  Grid1->EnableGridLines(true);
  Grid1->SetColLabelSize(20);
  Grid1->SetDefaultColSize(110, true);
  Grid1->SetColLabelValue(0, _("_UNIQ"));
  Grid1->SetColLabelValue(1, _("REC"));
  Grid1->SetColLabelValue(2, _("FREQ"));
  Grid1->SetColLabelValue(3, _("SCOREMIN"));
  Grid1->SetDefaultCellFont(Grid1->GetFont());
  Grid1->SetDefaultCellTextColour(Grid1->GetForegroundColour());
  FlexGridSizer1->Add(Grid1, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  dispgrid = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(526, 116), 0, _T("ID_GRID1"));
  dispgrid->CreateGrid(1, 1);
  dispgrid->Disable();
  dispgrid->EnableEditing(false);
  dispgrid->EnableGridLines(true);
  dispgrid->SetColLabelSize(20);
  dispgrid->SetColLabelValue(0, _("\?"));
  dispgrid->SetRowLabelValue(0, _("..."));
  dispgrid->SetDefaultCellFont(dispgrid->GetFont());
  dispgrid->SetDefaultCellTextColour(dispgrid->GetForegroundColour());
  FlexGridSizer1->Add(dispgrid, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3 = new wxFlexGridSizer(0, 8, 0, 0);
  clrbtn =
    new wxButton(this, ID_BUTTON1, _("Apaga"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON1"));
  clrbtn->SetToolTip(_("Apaga identificador corrente"));
  FlexGridSizer3->Add(clrbtn, 1, wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  cpybtn =
    new wxButton(this, ID_BUTTON2, _("Copia"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON2"));
  cpybtn->SetToolTip(_("Copia identificador corrente para  memória"));
  FlexGridSizer3->Add(cpybtn, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  newbtn =
    new wxButton(this, ID_BUTTON3, _("Gera"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON3"));
  newbtn->SetToolTip(_("Gera novo identificador na memória"));
  FlexGridSizer3->Add(newbtn, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  stampbtn =
    new wxButton(this, ID_BUTTON4, _("Grava"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON4"));
  stampbtn->SetToolTip(_("Grava  identificador na memória"));
  FlexGridSizer3->Add(stampbtn, 1, wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		      5);
  back =
    new wxBitmapButton(this, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  back->Disable();
  back->SetToolTip(_("Retrocede"));
  FlexGridSizer3->Add(back, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  forward =
    new wxBitmapButton(this, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
  forward->Disable();
  forward->SetToolTip(_("Avança"));
  FlexGridSizer3->Add(forward, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer3->Add(167, 34, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  closebtn =
    new wxBitmapButton(this, ID_BITMAPBUTTON4,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_UNDO")),
						wxART_BUTTON), wxDefaultPosition, wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
  closebtn->SetDefault();
  closebtn->SetToolTip(_("Retorna"));
  FlexGridSizer3->Add(closebtn, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(FlexGridSizer3, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString, _("*.dat"),
		     wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition,
		     wxDefaultSize, _T("wxFileDialog"));
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & viewdup::OnopenfilebtnClick);
  Connect(ID_GRID2, wxEVT_GRID_SELECT_CELL, (wxObjectEventFunction) & viewdup::OnGrid1CellSelect);
  Connect(ID_GRID1, wxEVT_GRID_SELECT_CELL,
	  (wxObjectEventFunction) & viewdup::OndispgridCellSelect);
  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & viewdup::OnclrbtnClick);
  Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & viewdup::OncpybtnClick);
  Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & viewdup::OnnewbtnClick);
  Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & viewdup::OnstampbtnClick);
  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & viewdup::OnbackClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & viewdup::OnforwardClick);
  Connect(ID_BITMAPBUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & viewdup::OnclosebtnClick);
  //*)

  timestring = _T("");
}

viewdup::~viewdup()
{
  //(*Destroy(viewdup)
  //*)
}


void
viewdup::OnopenfilebtnClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    filenamectrl->SetValue(FileDialog1->GetPath());
    if (!wxIsEmpty(filenamectrl->GetValue()) && wxFileExists(filenamectrl->GetValue()))
      init();
  }
  else
    filenamectrl->SetValue(_T(""));
}

void
viewdup::OnbackClick(wxCommandEvent & event)
{
  if (tbl.isopen())
    goback();
}

void
viewdup::OnforwardClick(wxCommandEvent & event)
{
  if (tbl.isopen())
    goforward();
}

void
viewdup::summarytbl(void)
{
  wxString dbfile = filenamectrl->GetValue();
  wxFileName sumfile = wxFileName(dbfile);
  dbfile = sumfile.GetPath(wxPATH_GET_SEPARATOR) + sumfile.GetName() + _T("SUM") + t.defdbext();
  bool use = false;
  if (wxFileExists(dbfile))
  {
    if (wxMessageBox
	(_
	 ("Já existe um arquivo de resumo associado.\nUtiliza o mesmo? (\"Não\" apaga o arquivo)"),
	 _("ARQUIVO JÁ EXISTENTE"), wxYES_NO) == wxYES)
      use = true;
    else
    {
      wxRemoveFile(sumfile.GetPath(wxPATH_GET_SEPARATOR) + sumfile.GetName() + _T("SUM") +
		   t.defdbext());
      //wxRemoveFile(sumfile.GetPath(wxPATH_GET_SEPARATOR) + sumfile.GetName() + _T("SUM") + t.defixext());
    }
  }
  if (!use)
  {
    progressdialog *dlg = new progressdialog(this);
    dlg->msglabel->SetLabel(_T("Resumindo..."));
    dlg->Show();
    dlg->Update();
    Update();
    wxYieldIfNeeded();
    wxBeginBusyCursor();
    dbtable::fielddef stru[] =
    {
      {
      _T("_UNIQ"), dbtable::CHAR, 12, 0}
      ,
      {
      _T("FREQ"), dbtable::CHAR, 12, 0}
      ,
      {
      _T("SCOREMIN"), dbtable::CHAR, 15, 0}
      ,
      {
      _T("SCOREMAX"), dbtable::CHAR, 15, 0}
    };
    t.setstructure(stru, 4);
    try
    {
      if (t.open(dbfile))
      {
	tbl.first();
	while (checkifdup())
	{
	  wxString ref = tbl.getstring(_T("_UNIQ"));
	  wxString val = tbl.getstring(_T("_SCORE"));
	  double min, max;
	  bool init = false;
	  long count = 0;
	  if (val != _T(">>>>>>>>>>>>>>>"))
	  {
	    val.Replace(CVTFROM, CVTTO);
	    val.ToDouble(&min);
	    val.ToDouble(&max);
	    init = true;
	  }
	  while ((ref == tbl.getstring(_T("_UNIQ"))) && !tbl.eof())
	  {
	    count++;
	    double score;
	    val = tbl.getstring(_T("_SCORE"));
	    if (!init && (val != _T(">>>>>>>>>>>>>>>")))
	    {
	      val.Replace(CVTFROM, CVTTO);
	      val.ToDouble(&min);
	      val.ToDouble(&max);
	      init = true;
	    }
	    else
	    {
	      if (val != _T(">>>>>>>>>>>>>>>"))
	      {
		val.Replace(CVTFROM, CVTTO);
		val.ToDouble(&score);
		if (score < min)
		  min = score;
		if (score > max)
		  max = score;
	      }
	    }
	    tbl.next();
	  }
	  wxString aux;
	  if (!ref.IsEmpty())
	  {
	    t.setfield(ref, _T("_UNIQ"));
	    aux.Printf(_T("%12d"), count);
	    t.setfield(aux, _T("FREQ"));
	    aux.Printf(_T("%16.12f"), min);
	    t.setfield(aux, _T("SCOREMIN"));
	    aux.Printf(_T("%16.12f"), max);
	    t.setfield(aux, _T("SCOREMAX"));
	    t.appendrec();
	  }
	}
      }
    }
    catch( ...)
    {
    };
    dlg->Close();
    wxEndBusyCursor();
  }
  else
    t.open(dbfile);
}

void
viewdup::init(void)
{
  if (tbl.isopen())
    tbl.close();
  if (t.isopen())
    t.close();
  //Grid1->Hide();
  if (tbl.open(filenamectrl->GetValue()))
  {
    if (tbl.getfieldnum(_T("_UNIQ")) != -1)
    {
      wxFileName matchfile = wxFileName(filenamectrl->GetValue());
      wxString name = matchfile.GetName();
      name += _T("_UNIQ");
      matchfile.SetName(name);
      matchfile.SetExt(t.defixext().Right(3));
      name = matchfile.GetFullPath();
      wxArrayString keyflds;
      keyflds.Add(_T("_UNIQ"));
      progressdialog *dlg = new progressdialog(this);
      dlg->Show();
      dlg->Update();
      wxYieldIfNeeded();
      wxBeginBusyCursor();
      if (!wxFileExists(name))
	tbl.makeindex(name, &keyflds);
      wxEndBusyCursor();
      tbl.setindex(name);
      dlg->Close();
      delete dlg;

      summarytbl();

      if (t.isopen())
	try
      {
	ngrid *tgrid = new ngrid();
	tgrid->SetTable(&t);
	Grid1->SetTable(tgrid);
	//Grid1->Show();
	Grid1->ForceRefresh();
      }
      catch( ...)
      {
      };

      tbl.first();
      if (checkifdup())
      {
	int ncols = dispgrid->GetNumberCols();
	int nfields = tbl.getnumfields();
	if (ncols < nfields)
	  dispgrid->InsertCols(0, (nfields - ncols));
	else if (ncols > nfields)
	  dispgrid->DeleteCols(0, (ncols - nfields));
	for (int i = 0; i < nfields; i++)
	  dispgrid->SetColLabelValue(i, tbl.getfieldname(i));
	loaddups();
	dispgrid->Enable();
	back->Enable();
	forward->Enable();
      }
      else
      {
	dispgrid->Disable();
	back->Disable();
	forward->Disable();
	tbl.close();
	info(_("O arquivo não contém duplicações"));
      }
    }
    else
      wxMessageBox(_("Este arquivo não passou\npelo processo de deduplicação"), _("ERRO"),
		   wxICON_ERROR);
  }
}

bool viewdup::checkifdup(void)
{
  bool
    retval = false;
  wxBeginBusyCursor();
  wxString
    id = tbl.getstring(_T("_UNIQ"));
  tbl.next();
  while (!tbl.eof())
  {
    if (id == tbl.getstring(_T("_UNIQ")))
    {
      tbl.prev();
      retval = true;
      break;
    }
    else
    {
      id = tbl.getstring(_T("_UNIQ"));
      tbl.next();
    }
  }
  wxEndBusyCursor();
  return retval;
}

void
viewdup::loaddups(void)
{
  selrow = -1;
  id = tbl.getstring(_T("_UNIQ"));
  int nlines = dispgrid->GetNumberRows();
  int ncols = dispgrid->GetNumberCols();
  int row = 0;
  wxString aux;
  int ref = -1;
  while ((id == tbl.getstring(_T("_UNIQ"))) && !tbl.eof())
  {
    if (tbl.getstring(_T("_SCORE")) == _T(">>>>>>>>>>>>>>>"))
      ref = row;
    if (row > (nlines - 1))
    {
      dispgrid->InsertRows(row, 1);
      nlines++;
    }
    aux.Printf(_T("%d"), tbl.getcurrentrec());
    dispgrid->SetRowLabelValue(row, aux);
    for (int i = 0; i < ncols; i++)
    {
      aux = tbl.getfieldname(i);
      if ((ref == row) && (aux == _T("_SCORE")))
	aux = _T("<ref>");
      else
	aux = tbl.getstring(aux);
      dispgrid->SetCellValue(row, i, aux);
    }
    tbl.next();
    row++;
  }
  if (row < nlines)
  {
    row++;
    dispgrid->DeleteRows((row - 1), nlines - row + 1);
  }
  if (ref > 0)
  {
    wxString swap;
    for (int i = 0; i < ncols; i++)
    {
      swap = dispgrid->GetCellValue(ref, i);
      dispgrid->SetCellValue(ref, i, dispgrid->GetCellValue(0, i));
      dispgrid->SetCellValue(0, i, swap);
    }
  }
}

void
viewdup::goback(void)
{
  bool retval = false;
  wxString id;
  wxString oldid = tbl.getstring(_T("_UNIQ"));

  wxBeginBusyCursor();
  tbl.prev();

  if (!tbl.bof())
  {
    id = tbl.getstring(_T("_UNIQ"));
    while ((id == tbl.getstring(_T("_UNIQ")) && !tbl.bof()))
      tbl.prev();
    id = tbl.getstring(_T("_UNIQ"));

    tbl.prev();
    if (!tbl.bof())
    {
      while (!tbl.bof())
      {
	if (id == tbl.getstring(_T("_UNIQ")))
	{
	  retval = true;
	  break;
	}
	else
	{
	  id = tbl.getstring(_T("_UNIQ"));
	  tbl.prev();
	}
      }
    }
  }
  wxEndBusyCursor();

  if (retval)
  {
    tbl.find(id);
    loaddups();
  }
  else
  {
    tbl.find(oldid);
    info(_("O arquivo não contém duplicações anteriores"));
  }
}

void
viewdup::goforward(void)
{
  wxString oldid = tbl.getstring(_T("_UNIQ"));
  if (checkifdup())
    loaddups();
  else
  {
    tbl.find(oldid);
    info(_("O arquivo não contém duplicações posteriores"));
  }
}

void
viewdup::info(wxString msg)
{
  wxMessageBox(msg, _("ATENÇÃO"), wxICON_WARNING);
}


void
viewdup::OnclosebtnClick(wxCommandEvent & event)
{
  if (wxMessageBox(_("Deseja gravar arquivo de log?"), _("ATENÇÃO"), wxICON_QUESTION | wxYES_NO)
      == wxYES)
    dump();
  tbl.close();
  t.close();
  ops_log log;
  log.log_event(_T("VWDUP"), filenamectrl->GetValue());
  EndModal(wxID_OK);
}

void
viewdup::dump()
{
  wxFileName matchfile = wxFileName(filenamectrl->GetValue());
  matchfile.SetExt(_T("log"));

  wxFileOutputStream strm(matchfile.GetFullPath());
  tbl.first();
  wxString aux;
  char buff[1024];
  //int total;
  wxBeginBusyCursor();
  t.first();
  double score;
  wxString scorestring;
  wxString refstring = _T(">>>>>>>>>>>>>>>");
  wxString id;
  wxArrayString addrs;
  wxArrayString scores;
  while (!t.eof())
  {
    id = t.getstring(_T("_UNIQ"));
    aux = t.getstring(_T("FREQ"));
    tbl.find(id);
    aux.Trim(false);
    aux = _("Identificador ") + id + _T(" - ") + aux + _(" registros:\n");
    strcpy(buff, aux.mb_str(wxConvUTF8));
    strm.Write(buff, strlen(buff));
    if (addrs.Count())
      addrs.Clear();
    if (scores.Count())
      scores.Clear();

    while ((id == tbl.getstring(_T("_UNIQ"))) && !tbl.eof())
    {
      aux.Printf(_T("\t%d"), tbl.getcurrentrec());
      addrs.Add(aux);
      try
      {
	scorestring = tbl.getstring(_T("_SCORE"));
	if (scorestring == refstring)
	  aux = _T("\t<ref>\n");
	else
	{
	  scorestring.Replace(CVTFROM, CVTTO);
	  scorestring.ToDouble(&score);
	  aux.Printf(_T("\t%16.12f\n"), score);
	}
      }
      catch( ...)
      {
	aux = _T("\t<inv>\n");
      };
      scores.Add(aux);
      tbl.next();
    }
    int i;
    for (i = 0; i < scores.Count(); i++)
      if (scores[i] == _T("\t<ref>\n"))
	break;
    aux = _T("");
    if (i < scores.Count())
    {
      if (i < addrs.Count())
	aux = addrs[i] + scores[i];
      else
	aux = addrs[i] + _T("\t<inv>\n");
      strcpy(buff, aux.mb_str(wxConvUTF8));
      strm.Write(buff, strlen(buff));
    }
    for (int j = 0; j < addrs.Count(); j++)
    {
      if (j != i)
      {
	if (j < scores.Count())
	  aux = addrs[j] + scores[j];
	else
	  aux = addrs[j] + _T("\t<inv>\n");
	strcpy(buff, aux.mb_str(wxConvUTF8));
	strm.Write(buff, strlen(buff));
      }
    }
    aux = _T("********\n");
    strcpy(buff, aux.mb_str(wxConvUTF8));
    strm.Write(buff, strlen(buff));

    t.next();
  }
  /*
     while (checkifdup())
     {
     wxString id = tbl.getstring(_T("_UNIQ"));
     aux = _("Identificador ") + id + _(" - registros:\n");
     strcpy(buff, aux.mb_str(wxConvUTF8));
     strm.Write(buff, strlen(buff));
     total = 0;
     double score;
     wxString scorestring;
     wxString refstring = _T(">>>>>>>>>>>>>>>");
     //wxString refstring = _T("REFERENCE");
     while ((id == tbl.getstring(_T("_UNIQ"))) && !tbl.eof())
     {
     try {
     scorestring = tbl.getstring(_T("_SCORE"));
     if (scorestring == refstring)
     {
     aux.Printf(_T("\t%d\t<ref>\n"), tbl.getcurrentrec());
     }
     else
     {
     scorestring.ToDouble(&score);
     aux.Printf(_T("\t%d\t%16.12f\n"), tbl.getcurrentrec(), score);
     }
     } catch(...) {
     aux.Printf(_T("\t%d\t%<inv>\n"), tbl.getcurrentrec());
     };

     strcpy(buff, aux.mb_str(wxConvUTF8));
     strm.Write(buff, strlen(buff));
     tbl.next();
     total++;
     }
     aux.Printf(_T("******** Total: %d\n"), total);
     strcpy(buff, aux.mb_str(wxConvUTF8));
     strm.Write(buff, strlen(buff));
     }
   */
  wxEndBusyCursor();
}

void
viewdup::OnGrid1CellSelect(wxGridEvent & event)
{
  int row = event.GetRow();
  Grid1->SelectRow(row);
  wxString aux = Grid1->GetCellValue(row, 0);
  tbl.find(aux);
  loaddups();
}

void
viewdup::genuniq(void)
{
  wxLongLong now = wxGetLocalTimeMillis();
  timestring.Printf(_T("%08X"), now.ToLong());
}

void
viewdup::OnclrbtnClick(wxCommandEvent & event)
{
  if (wxMessageBox(_("Apaga o identificador?"), _("CONFIRMA"), wxYES_NO) == wxYES)
    eraseuid();
}

void
viewdup::OncpybtnClick(wxCommandEvent & event)
{
  readuid();
}

void
viewdup::OnnewbtnClick(wxCommandEvent & event)
{
  genuniq();
}

void
viewdup::writeuid(wxString uid)
{
  if (selrow > -1)
  {
    wxString aux = dispgrid->GetRowLabelValue(selrow);
    long recno;
    if (aux.ToLong(&recno))
    {
      tbl.go(recno);
      tbl.setfield(uid, (_T("_UNIQ")));
      tbl.replacerec();
    }
  }
  else
    wxMessageBox(_("Nenhum registro selecionado"), _("ERRO"), wxOK | wxICON_ERROR);

}

void
viewdup::replaceuid(void)
{
  writeuid(timestring);
}

void
viewdup::eraseuid(void)
{
  readuid();
  writeuid(_T(""));
}

void
viewdup::readuid(void)
{
  timestring = id;
}

void
viewdup::OnstampbtnClick(wxCommandEvent & event)
{
  if (timestring.IsEmpty())
    wxMessageBox(_("Sem identificador na memoria"), _("ERRO"), wxOK | wxICON_ERROR);
  else
  {
    wxString msg = _("Grava o identificador ") + timestring + _T(" ?");
    if (wxMessageBox(msg, _("CONFIRMA"), wxYES_NO) == wxYES)
      replaceuid();
  }
}

void
viewdup::OndispgridCellSelect(wxGridEvent & event)
{
  int row = event.GetRow();
  dispgrid->SelectRow(row);
  selrow = row;
}
