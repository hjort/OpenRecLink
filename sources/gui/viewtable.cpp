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
// Nome:        viewtable.cpp
// Propósito:   Classe (janela) para visualizar arquivo dbf
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "viewtable.h"
#include "ntable.h"
#include "ntable_grid.h"
#include "indexdialog.h"
#include "dbutils.h"
#include "progressdialog.h"
#include "importcsv.h"
#include "importdlg.h"
#include "bigfiledlg.h"
#include "ops_log.h"
#include "showstructdlg.h"

//(*InternalHeaders(viewtable)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

#include <wx/icon.h>
#include <wx/filename.h>
#include <wx/tipwin.h>

//(*IdInit(viewtable)
const long
  viewtable::ID_GRID1 = wxNewId();
const long
  viewtable::ID_MENUITEM1 = wxNewId();
const long
  viewtable::ID_MENUITEM9 = wxNewId();
const long
  viewtable::ID_MENUITEM8 = wxNewId();
const long
  viewtable::ID_MENUITEM4 = wxNewId();
const long
  viewtable::ID_MENUITEM2 = wxNewId();
const long
  viewtable::ID_MENUITEM5 = wxNewId();
const long
  viewtable::ID_MENUITEM3 = wxNewId();
const long
  viewtable::ID_MENUITEM6 = wxNewId();
const long
  viewtable::ID_MENUITEM7 = wxNewId();
//*)

BEGIN_EVENT_TABLE(viewtable, wxFrame)
  //(*EventTable(viewtable)
  //*)
  END_EVENT_TABLE()
// safeguard
// FrameIcon.CopyFromBitmap(wxBitmap(rl32x32_xpm));
     static const char **rl32x32_xpm;

viewtable::viewtable(wxWindow * parent, wxWindowID id, const wxPoint & pos, const wxSize & size)
{
  //(*Initialize(viewtable)
  Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE,
	 _T("id"));
  SetClientSize(wxSize(400, 193));
  Move(wxDefaultPosition);
  {
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(rl32x32_xpm));
    SetIcon(FrameIcon);
  }
  Grid1 = new wxGrid(this, ID_GRID1, wxPoint(96, 208), wxSize(400, 184), 0, _T("ID_GRID1"));
  Grid1->CreateGrid(1, 1);
  Grid1->EnableEditing(false);
  Grid1->EnableGridLines(true);
  Grid1->SetColLabelSize(20);
  Grid1->SetRowLabelSize(80);
  Grid1->SetColLabelValue(0, wxEmptyString);
  Grid1->SetDefaultCellFont(Grid1->GetFont());
  Grid1->SetDefaultCellTextColour(Grid1->GetForegroundColour());
  FileDialog1 =
    new wxFileDialog(this, _("Selecione o arquivo"), wxEmptyString, wxEmptyString, _("*.dat"),
		     wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize,
		     _T("wxFileDialog"));
  MenuBar1 = new wxMenuBar();
  Menu1 = new wxMenu();
  MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Visualiza"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem1);
  MenuItem9 = new wxMenuItem(Menu1, ID_MENUITEM9, _("Estrutura"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem9);
  MenuItem9->Enable(false);
  MenuItem8 = new wxMenuItem(Menu1, ID_MENUITEM8, _("Reinicia"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem8);
  MenuItem8->Enable(false);
  MenuItem4 = new wxMenuItem(Menu1, ID_MENUITEM4, _("Índice"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem4);
  MenuItem4->Enable(false);
  MenuItem2 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Sai"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem2);
  MenuBar1->Append(Menu1, _("Arquivo"));
  Menu2 = new wxMenu();
  MenuItem5 = new wxMenuItem(Menu2, ID_MENUITEM5, _("Anexa"), wxEmptyString, wxITEM_NORMAL);
  Menu2->Append(MenuItem5);
  MenuItem5->Enable(false);
  MenuItem3 = new wxMenuItem(Menu2, ID_MENUITEM3, _("Exporta"), wxEmptyString, wxITEM_NORMAL);
  Menu2->Append(MenuItem3);
  MenuItem3->Enable(false);
  MenuItem6 = new wxMenuItem(Menu2, ID_MENUITEM6, _("Importa"), wxEmptyString, wxITEM_NORMAL);
  Menu2->Append(MenuItem6);
  MenuItem7 = new wxMenuItem(Menu2, ID_MENUITEM7, _("Importa dbf"), wxEmptyString, wxITEM_NORMAL);
  Menu2->Append(MenuItem7);
  MenuBar1->Append(Menu2, _("Movimenta"));
  SetMenuBar(MenuBar1);

  Connect(ID_GRID1, wxEVT_GRID_SELECT_CELL, (wxObjectEventFunction) & viewtable::OnGrid1CellSelect);
  Connect(ID_MENUITEM1, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem2Selected);
  Connect(ID_MENUITEM9, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem9Selected1);
  Connect(ID_MENUITEM8, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem8Selected);
  Connect(ID_MENUITEM4, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem4Selected);
  Connect(ID_MENUITEM2, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem3Selected);
  Connect(ID_MENUITEM5, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem5Selected);
  Connect(ID_MENUITEM3, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem3Selected1);
  Connect(ID_MENUITEM6, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem6Selected);
  Connect(ID_MENUITEM7, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & viewtable::OnMenuItem7Selected);
  //*)
  Grid1->SetDefaultCellOverflow(false);
  wxIcon FrameIcon;
  FrameIcon.CopyFromBitmap(wxBitmap(rl32x32_xpm));
  SetIcon(FrameIcon);
}

viewtable::~viewtable()
{
  //(*Destroy(viewtable)
  //*)
}


void
viewtable::OnMenuItem3Selected(wxCommandEvent & event)
{
  if (tbl.isopen())
    tbl.close();
  //Close();
  Destroy();			// CHECK IF THIS WORKS PROPERLY
}

void
viewtable::dopen(void)
{
  wxFileName ofname(name);
  SetTitle(ofname.GetName());
  tbl.open(name);
  long maxrecs = tbl.gettotalrecs();
  ngrid *hbtbl = new ngrid();
  wxBeginBusyCursor();
  if (maxrecs > LOTSA_RECS)
  {
    MenuItem8->Enable(true);
    bigfiledlg dlg(this);
    wxString msg;
    msg.Printf(_("Este arquivo tem %d registros."), maxrecs);
    dlg.StaticText1->SetLabel(msg);
    long begin, end;
    if (dlg.ShowModal() == wxOK)
    {
      msg = dlg.TextCtrl1->GetValue();
      msg.ToLong(&begin);
    }
    else
      begin = 1L;
    if (begin < 1L)
      begin = 1L;
    if (begin > maxrecs)
      begin = maxrecs;
    if ((maxrecs - begin + 1) > LOTSA_RECS)
      end = begin + LOTSA_RECS - 1;
    else
      end = maxrecs;
    hbtbl->SetLimits(begin, end);
  }
  else
    MenuItem8->Enable(false);
  hbtbl->SetTable(&tbl);
  Grid1->SetTable(hbtbl);
  Grid1->ForceRefresh();
  wxEndBusyCursor();
  wxYieldIfNeeded();
  Grid1->Show();
  this->Raise();
}

void
viewtable::doview(void)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    if (tbl.isopen())
      tbl.close();
    name = FileDialog1->GetPath();
    if (wxFileExists(name))
    {
      MenuItem3->Enable(true);
      MenuItem4->Enable(true);
      MenuItem5->Enable(true);
      MenuItem9->Enable(true);
      dopen();
    }
    else
    {
      MenuItem3->Enable(false);
      MenuItem4->Enable(false);
      MenuItem5->Enable(false);
      MenuItem5->Enable(false);
    }
  }
}

void
viewtable::OnMenuItem2Selected(wxCommandEvent & event)
{
  doview();
}

void
viewtable::doexport(void)
{
  if (tbl.isopen())
  {
    exportdlg *dlg = new exportdlg(this);
    dlg->settbl(&tbl, name);
    dlg->ShowModal();
    dlg->Destroy();
  }
}

void
viewtable::OnMenuItem3Selected1(wxCommandEvent & event)
{
  doexport();
}

void
viewtable::doindex(void)
{
  if (tbl.isopen())
  {
    indexdialog *dlg = new indexdialog(this);
    wxFileName refname(FileDialog1->GetPath());
    refname.SetExt(tbl.defixext().Right(3));
    dlg->filecontrol->SetValue(refname.GetFullPath());
    if (dlg->ShowModal() == wxID_OK)
    {
      wxString fname = dlg->filecontrol->GetValue();
      if (!fname.IsEmpty())
      {
	if (!wxFileExists(fname))
	{
	  wxString vars = dlg->varcontrol->GetValue();
	  if (!vars.IsEmpty())
	  {
	    wxArrayString tmp = unpackarray(vars, _T(","));
	    bool oktogo = false;
	    if (tmp.Count())
	    {
	      oktogo = true;
	      for (int i = 0; i < tmp.Count(); i++)
		if (tbl.getfieldnum(tmp[i]) == -1)
		{
		  oktogo = false;
		  break;
		}
	    }
	    if (oktogo)
	    {
	      wxBeginBusyCursor();
	      progressdialog *dlg = new progressdialog(this);
	      dlg->Show();
	      dlg->Update();
	      wxYieldIfNeeded();
	      StopWatch1.Start();
	      try
	      {
		tbl.makeindex(fname, &tmp);
	      }
	      catch( ...)
	      {
	      };
	      StopWatch1.Pause();
	      dlg->Close();
	      delete dlg;
	      wxEndBusyCursor();
	      wxString timestring;
	      long time = StopWatch1.Time() / 1000L;	// time in seconds
	      int secs = (int) (time % 60L);
	      time /= 60L;	// time in minutes
	      int mins = (int) (time % 60L);
	      int hrs = (int) (time / 60L);
	      timestring.Printf(_("Tempo de indexação: %d:%02d:%02d"), hrs, mins, secs);
	      wxMessageBox(timestring, _("NOTA"));
	      timestring.Printf(_T("%d:%02d:%02d"), hrs, mins, secs);
	      ops_log log;
	      log.log_event(_T("INX"), refname.GetFullPath(), timestring);
	    }
	    else
	      wxMessageBox(_("Especificação de campos inválida."), _("NOTA"));
	  }
	  else
	    wxMessageBox(_("Não é possível criar índice sem especificar campos."), _("NOTA"));
	}

	if (wxFileExists(fname))
	{
	  wxFileName ofname(fname);
	  wxString aux = GetTitle() + _T(" (") + ofname.GetName() + _T(")");
	  SetTitle(aux);
	  tbl.setindex(fname);
	  tbl.first();
	  Grid1->ForceRefresh();
	}
      }
      else
      {
	wxFileName ofname(name);
	SetTitle(ofname.GetName());
	tbl.setindex(fname);
	tbl.first();
	Grid1->ForceRefresh();
      }
    }
    dlg->Close();
    delete dlg;
  }
}

void
viewtable::OnMenuItem4Selected(wxCommandEvent & event)
{
  doindex();
}

void
viewtable::doappend(void)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    wxString in_name = FileDialog1->GetPath();
    if (!in_name.IsEmpty() && wxFileExists(in_name))
    {
      wxString msg;
      ntable intbl;
      intbl.open(in_name);
      tbl.setindex(_T(""));
      wxBeginBusyCursor();
      intbl.first();
      int pu = 0;
      long nrecs = 0l;
      long maxrecs = intbl.gettotalrecs();
      while (!intbl.eof() && (nrecs <= maxrecs))
      {
	nrecs++;
	tbl.copyrec(&intbl);
	intbl.next();
	pu++;
	if (pu > 99)
	{
	  msg.Printf(_T("Lidos: %d"), nrecs);
	  SetTitle(msg);
	  Refresh();
	  pu = 0;
	  wxYieldIfNeeded();
	}
      }
      intbl.close();
      tbl.close();
      wxEndBusyCursor();
      dopen();
      wxYieldIfNeeded();
      msg.Printf(_("Anexados %d registros."), nrecs);
      ops_log log;
      msg.Printf(_T("%d"), nrecs);
      log.log_event(_T("APPND"), in_name, _T("N/A"), msg);
      wxMessageBox(msg, _("NOTA"));
    }
  }
}

void
viewtable::OnMenuItem5Selected(wxCommandEvent & event)
{
  //wxMessageBox(_("Não implementado ainda."), _("NOTA"));
  doappend();
}

void
viewtable::doimport(void)
{
  importcsv dlg(this);
  if (dlg.ShowModal() == wxID_OK)
  {
    if (tbl.isopen())
      tbl.close();
    wxFileName ofname(dlg.filenamectrl->GetValue());
    ofname.SetExt(tbl.defdbext().Right(3));
    name = ofname.GetFullPath();
    dopen();
  }
}

void
viewtable::OnMenuItem6Selected(wxCommandEvent & event)
{
  doimport();
}

void
viewtable::doimportdbf(void)
{
  importdlg dlg(this);
  if (dlg.FileDialog1->ShowModal() == wxID_OK)
  {
    wxFileName ofname(dlg.FileDialog1->GetPath());
    dlg.Show();
    MenuBar1->EnableTop(0, false);
    if (dlg.doimport() == wxID_OK)
    {
      if (tbl.isopen())
	tbl.close();
      ofname.SetExt(tbl.defdbext().Right(3));
      name = ofname.GetFullPath();
      dopen();
    }
    dlg.Close();
    MenuBar1->EnableTop(0, true);
  }
}

void
viewtable::OnMenuItem7Selected(wxCommandEvent & event)
{
  doimportdbf();
}

void
viewtable::OnMenuItem8Selected(wxCommandEvent & event)
{
  dopen();
}

void
viewtable::OnGrid1CellSelect(wxGridEvent & event)
{
  int row = event.GetRow();
  int col = event.GetCol();
  wxString val = Grid1->GetCellValue(row, col);
  wxTipWindow *tip = new wxTipWindow(Grid1, val);
}

void
viewtable::OnMenuItem9Selected1(wxCommandEvent & event)
{
  showstructdlg dlg(this);
  wxArrayString stru = stru2array(tbl.getstructure());
  int nflds = tbl.getnumfields();
  while (dlg.Grid1->GetNumberRows() < nflds)
    dlg.Grid1->AppendRows();
  wxArrayString fld;
  for (int i = 0; i < nflds; i++)
  {
    if (fld.Count())
      fld.Clear();
    fld = unpackarray(stru[i], _T(","));
    for (int j = 0; j < 4; j++)
      dlg.Grid1->SetCellValue(i, j, fld[j]);
  }
  dlg.ShowModal();
}
