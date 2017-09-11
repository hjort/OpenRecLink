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
// Nome:        reclinkmain.cpp
// Propósito:   Classe (janela) da tela principal do programa
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "reclinkmain.h"
#include "wizdup.h"
#include "wizjin.h"
#include "wizlnk.h"
#include "wizstd.h"
#include "viewtable.h"
#include "importdlg.h"
#include "importcsv.h"
#include "exportdlg.h"
#include "execstd.h"
#include "execlnk.h"
#include "inspect.h"
#include "execcmb.h"
#include "execjin.h"
#include "execdup.h"
#include "execlnmatrix.h"
#include "runcalc.h"
#include "viewdup.h"
#include "freqdlg.h"
#include "freqanalysis.h"
#include "SQLexportdlg.h"
#include "viewlog.h"
#include "execpurge.h"
#include "execmark.h"
#include "aboutpanel.h"
#include "viewtable.h"
#include "execcopy.h"
#include "wizcopy.h"

#include "splash.xpm"
#include "rl.xpm"

//(*InternalHeaders(reclinkmain)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

#include <wx/msgdlg.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/datetime.h>

//(*IdInit(reclinkmain)
const long
  reclinkmain::ID_STATICBITMAP1 = wxNewId();
const long
  reclinkmain::ID_MENUITEM1 = wxNewId();
const long
  reclinkmain::ID_MENUITEM17 = wxNewId();
const long
  reclinkmain::ID_MENUITEM10 = wxNewId();
const long
  reclinkmain::ID_MENUITEM2 = wxNewId();
const long
  reclinkmain::ID_MENUITEM23 = wxNewId();
const long
  reclinkmain::ID_MENUITEM24 = wxNewId();
const long
  reclinkmain::ID_MENUITEM3 = wxNewId();
const long
  reclinkmain::ID_MENUITEM4 = wxNewId();
const long
  reclinkmain::ID_MENUITEM5 = wxNewId();
const long
  reclinkmain::ID_MENUITEM20 = wxNewId();
const long
  reclinkmain::ID_MENUITEM21 = wxNewId();
const long
  reclinkmain::ID_MENUITEM14 = wxNewId();
const long
  reclinkmain::ID_MENUITEM15 = wxNewId();
const long
  reclinkmain::ID_MENUITEM6 = wxNewId();
const long
  reclinkmain::ID_MENUITEM18 = wxNewId();
const long
  reclinkmain::ID_MENUITEM19 = wxNewId();
const long
  reclinkmain::ID_MENUITEM22 = wxNewId();
const long
  reclinkmain::ID_MENUITEM7 = wxNewId();
const long
  reclinkmain::ID_MENUITEM8 = wxNewId();
const long
  reclinkmain::ID_MENUITEM16 = wxNewId();
const long
  reclinkmain::ID_MENUITEM9 = wxNewId();
const long
  reclinkmain::ID_MENUITEM11 = wxNewId();
const long
  reclinkmain::ID_MENUITEM12 = wxNewId();
const long
  reclinkmain::ID_MENUITEM13 = wxNewId();
//*)

BEGIN_EVENT_TABLE(reclinkmain, wxFrame)
  //(*EventTable(reclinkmain)
  //*)
  END_EVENT_TABLE()
// safeguard
// SetClientSize(wxSize(663,451));
// StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(splash_xpm), wxDefaultPosition, wxSize(663,451), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
// FrameIcon.CopyFromBitmap(wxBitmap(rl32x32_xpm));
  reclinkmain::reclinkmain(wxWindow * parent, wxWindowID id, const wxPoint & pos,
			   const wxSize & size)
{
  //(*Initialize(reclinkmain)
  wxMenuItem *MenuItem10;
  wxMenuItem *MenuItem7;
  wxMenuItem *MenuItem13;

  Create(parent, wxID_ANY, _("OpenRecLink"), wxDefaultPosition, wxDefaultSize,
	 wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX | wxMINIMIZE_BOX | wxFULL_REPAINT_ON_RESIZE,
	 _T("wxID_ANY"));
  SetClientSize(wxSize(663, 451));
  SetExtraStyle(GetExtraStyle() | wxFRAME_EX_METAL);
  {
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(rl32x32_xpm));
    SetIcon(FrameIcon);
  }
  StaticBitmap1 =
    new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(splash_xpm), wxDefaultPosition,
		       wxSize(663, 451), 0, _T("ID_STATICBITMAP1"));
  MenuBar1 = new wxMenuBar();
  Menu1 = new wxMenu();
  MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Ferramentas"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem1);
  MenuItem16 =
    new wxMenuItem(Menu1, ID_MENUITEM17, _("Log atividade"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem16);
  MenuItem9 = new wxMenuItem(Menu1, ID_MENUITEM10, _("Sobre"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem9);
  MenuItem2 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Sai"), wxEmptyString, wxITEM_NORMAL);
  Menu1->Append(MenuItem2);
  MenuBar1->Append(Menu1, _("Arquivo"));
  Menu7 = new wxMenu();
  MenuItem22 = new wxMenuItem(Menu7, ID_MENUITEM23, _("Configura"), wxEmptyString, wxITEM_NORMAL);
  Menu7->Append(MenuItem22);
  MenuItem23 = new wxMenuItem(Menu7, ID_MENUITEM24, _("Executa"), wxEmptyString, wxITEM_NORMAL);
  Menu7->Append(MenuItem23);
  MenuBar1->Append(Menu7, _("Copia"));
  Menu2 = new wxMenu();
  MenuItem3 = new wxMenuItem(Menu2, ID_MENUITEM3, _("Configura"), wxEmptyString, wxITEM_NORMAL);
  Menu2->Append(MenuItem3);
  MenuItem4 = new wxMenuItem(Menu2, ID_MENUITEM4, _("Executa"), wxEmptyString, wxITEM_NORMAL);
  Menu2->Append(MenuItem4);
  MenuBar1->Append(Menu2, _("Padroniza"));
  Menu3 = new wxMenu();
  MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM5, _("Configura"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem5);
  MenuItem19 = new wxMenuItem(Menu3, ID_MENUITEM20, _("Gera freq"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem19);
  MenuItem20 =
    new wxMenuItem(Menu3, ID_MENUITEM21, _("Analisa freq"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem20);
  MenuItem10 =
    new wxMenuItem(Menu3, ID_MENUITEM14, _("Gera matrizes"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem10);
  MenuItem14 = new wxMenuItem(Menu3, ID_MENUITEM15, _("Calcula"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem14);
  MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM6, _("Executa"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem6);
  MenuItem17 = new wxMenuItem(Menu3, ID_MENUITEM18, _("Reduz pares"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem17);
  MenuItem18 =
    new wxMenuItem(Menu3, ID_MENUITEM19, _("Marca/Desmarca"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem18);
  MenuItem21 = new wxMenuItem(Menu3, ID_MENUITEM22, _("Exporta SQL"), wxEmptyString, wxITEM_NORMAL);
  Menu3->Append(MenuItem21);
  MenuBar1->Append(Menu3, _("Relaciona"));
  Menu4 = new wxMenu();
  MenuItem7 = new wxMenuItem(Menu4, ID_MENUITEM7, _("Configura"), wxEmptyString, wxITEM_NORMAL);
  Menu4->Append(MenuItem7);
  MenuItem8 = new wxMenuItem(Menu4, ID_MENUITEM8, _("Executa"), wxEmptyString, wxITEM_NORMAL);
  Menu4->Append(MenuItem8);
  MenuItem15 = new wxMenuItem(Menu4, ID_MENUITEM16, _("Examina"), wxEmptyString, wxITEM_NORMAL);
  Menu4->Append(MenuItem15);
  MenuBar1->Append(Menu4, _("Deduplica"));
  Menu5 = new wxMenu();
  doinspect = new wxMenuItem(Menu5, ID_MENUITEM9, _("Examina"), wxEmptyString, wxITEM_NORMAL);
  Menu5->Append(doinspect);
  MenuItem11 = new wxMenuItem(Menu5, ID_MENUITEM11, _("Executa"), wxEmptyString, wxITEM_NORMAL);
  Menu5->Append(MenuItem11);
  MenuBar1->Append(Menu5, _("Combina"));
  Menu6 = new wxMenu();
  MenuItem12 = new wxMenuItem(Menu6, ID_MENUITEM12, _("Configura"), wxEmptyString, wxITEM_NORMAL);
  Menu6->Append(MenuItem12);
  MenuItem13 = new wxMenuItem(Menu6, ID_MENUITEM13, _("Executa"), wxEmptyString, wxITEM_NORMAL);
  Menu6->Append(MenuItem13);
  MenuBar1->Append(Menu6, _("Associa"));
  SetMenuBar(MenuBar1);
  SingleInstanceChecker1.Create(wxTheApp->GetAppName() + _T("_") + wxGetUserId() + _T("_Guard"));

  Connect(ID_MENUITEM1, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem1Selected);
  Connect(ID_MENUITEM17, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem16Selected);
  Connect(ID_MENUITEM10, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnaboutSelected);
  Connect(ID_MENUITEM2, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnmenucloseSelected);
  Connect(ID_MENUITEM23, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem22Selected);
  Connect(ID_MENUITEM24, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem23Selected);
  Connect(ID_MENUITEM3, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OncfgstdSelected);
  Connect(ID_MENUITEM4, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnrunstdSelected);
  Connect(ID_MENUITEM5, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OncfglnkSelected);
  Connect(ID_MENUITEM20, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem19Selected);
  Connect(ID_MENUITEM21, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem20Selected);
  Connect(ID_MENUITEM14, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OncalcparmsSelected);
  Connect(ID_MENUITEM15, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OndocalcSelected);
  Connect(ID_MENUITEM6, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnrunlnkSelected);
  Connect(ID_MENUITEM18, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem17Selected);
  Connect(ID_MENUITEM19, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem18Selected);
  Connect(ID_MENUITEM22, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnMenuItem21Selected);
  Connect(ID_MENUITEM7, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OncfgdupSelected);
  Connect(ID_MENUITEM8, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OndodupSelected);
  Connect(ID_MENUITEM16, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OnviewdupSelected);
  Connect(ID_MENUITEM9, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OninspectSelected);
  Connect(ID_MENUITEM11, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OndoexeccmbSelected);
  Connect(ID_MENUITEM12, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OncfgjinSelected);
  Connect(ID_MENUITEM13, wxEVT_COMMAND_MENU_SELECTED,
	  (wxObjectEventFunction) & reclinkmain::OndoexecjinSelected);
  //*)

  if (SingleInstanceChecker1.IsAnotherRunning())
  {
    if (wxMessageBox(_("Já há uma cópia do programa\nem execução. Continua?"),
		     _("AVISO"), wxICON_EXCLAMATION | wxYES_NO) == wxNO)
      //Close();
      Destroy();
  }
}

reclinkmain::~reclinkmain()
{
  //(*Destroy(reclinkmain)
  //*)
}


void
reclinkmain::OnmenucloseSelected(wxCommandEvent & event)
{
  //Close();
  DestroyChildren();
  Destroy();
}

void
reclinkmain::OncfgdupSelected(wxCommandEvent & event)
{
  wizdup dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnviewdupSelected(wxCommandEvent & event)
{
  viewdup dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OncfgstdSelected(wxCommandEvent & event)
{
  wizstd dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OncfglnkSelected(wxCommandEvent & event)
{
  wizlnk dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OncalcparmsSelected(wxCommandEvent & event)
{
  execlnmatrix dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OndocalcSelected(wxCommandEvent & event)
{
  runcalc dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OncfgjinSelected(wxCommandEvent & event)
{
  wizjin dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem1Selected(wxCommandEvent & event)
{
  viewtable *dlg = new viewtable(this);
  wxPoint pt = GetPosition();
  dlg->SetPosition(pt);
  //MenuBar1->EnableTop(0, false);
  dlg->Show();
  //MenuBar1->EnableTop(0, true);
}

void
reclinkmain::OnrunstdSelected(wxCommandEvent & event)
{
  execstd dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnrunlnkSelected(wxCommandEvent & event)
{
  execlnk dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OninspectSelected(wxCommandEvent & event)
{
  inspect dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OndoexeccmbSelected(wxCommandEvent & event)
{
  execcmb dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OndoexecjinSelected(wxCommandEvent & event)
{
  execjin dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OndodupSelected(wxCommandEvent & event)
{
  execdup dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem19Selected(wxCommandEvent & event)
{
  freqdlg dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem20Selected(wxCommandEvent & event)
{
  freqanalysis dlg(this);
  dlg.setfilename();
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem21Selected(wxCommandEvent & event)
{
  SQLexportdlg dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem17Selected(wxCommandEvent & event)
{
  execpurge dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem18Selected(wxCommandEvent & event)
{
  execmark dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem22Selected(wxCommandEvent & event)
{
  wizcopy dlg(this);
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem23Selected(wxCommandEvent & event)
{
  execcopy dlg(this);
  dlg.ShowModal();
}

wxString reclinkmain::xlateaction(wxString action)
{
  wxString
    retval = _("Não identificada");

  if (action == _T("APPND"))
    retval = _("Anexa arq");
  else if (action == _T("COMBX"))
    retval = _("Exec combina");
  else if (action == _T("DUPC"))
    retval = _("Cfg duplicidade");
  else if (action == _T("DUPX"))
    retval = _("Exec duplicidade");
  else if (action == _T("EXPORT"))
    retval = _("Exporta");
  else if (action == _T("FANL"))
    retval = _("Análise freq");
  else if (action == _T("FREQG"))
    retval = _("Gera freq");
  else if (action == _T("IMPCSV"))
    retval = _("Importa CSV");
  else if (action == _T("IMPDBF"))
    retval = _("Importa DBF");
  else if (action == _T("INSP"))
    retval = _("Inspeciona");
  else if (action == _T("INX"))
    retval = _("Indexa");
  else if (action == _T("JOINC"))
    retval = _("Cfg associa");
  else if (action == _T("JOINX"))
    retval = _("Exec associa");
  else if (action == _T("CPYC"))
    retval = _("Configura cópia");
  else if (action == _T("CPYX"))
    retval = _("Executa cópia");
  else if (action == _T("LNKC"))
    retval = _("Cfg relaciona");
  else if (action == _T("LNKX"))
    retval = _("Exec relaciona");
  else if (action == _T("MTRXX"))
    retval = _("Exec matriz");
  else if (action == _T("PURGE"))
    retval = _("Reduz pares");
  else if (action == _T("STDC"))
    retval = _("Cfg padroniza");
  else if (action == _T("STDX"))
    retval = _("Exec padroniza");
  else if (action == _T("VWDUP"))
    retval = _("Insp duplicidade");
  else if (action == _T("MARK"))
    retval = _("Marca pares");
  else if (action == _T("UNMARK"))
    retval = _("Desmarca pares");

  return retval;
}

void
reclinkmain::showlog(void)
{
  wxString m_app_path = wxStandardPaths::Get().GetUserLocalDataDir();

  if (!::wxDirExists(m_app_path))
    ::wxMkdir(m_app_path);

  m_app_path += _T("/.openreclink.cfg");

  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), m_app_path, _T(""), wxCONFIG_USE_LOCAL_FILE);

  wxArrayString entries;
  wxArrayString actions;
  wxString key;
  long dummy;
  wxString value;
  cfgfile->SetPath(_T("/LOG"));
  bool cont = cfgfile->GetFirstEntry(key, dummy);
  while (cont)
  {
    value = cfgfile->Read(key, _T(""));
    entries.Add(key);
    actions.Add(xlateaction(value));
    cont = cfgfile->GetNextEntry(key, dummy);
  }

  int nevents = entries.Count();

  if (nevents > MAXENTRIES)
  {
    int todelete = nevents - MAXENTRIES;
    nevents = MAXENTRIES;
    for (int i = 0; i < todelete; i++)
    {
      cfgfile->SetPath(_T("/LOG"));
      cfgfile->DeleteEntry(entries[i]);
      cfgfile->SetPath(_T("/"));
      cfgfile->DeleteGroup(entries[i]);
      entries.RemoveAt(0);
      actions.RemoveAt(0);
    }
  }

  bool swapped;
  do
  {
    swapped = false;
    wxString lbl;
    long lnum;
    wxLongLong ll1, ll2;
    for (int i = 0; i < (nevents - 1); i++)
    {
      lbl = _T("0x") + entries[i];
      lbl.Trim(false);
      lbl.ToLong(&lnum, 16);
      ll1 = (wxLongLong) lnum;
      lbl = _T("0x") + entries[i + 1];
      lbl.Trim(false);
      lbl.ToLong(&lnum, 16);
      ll2 = (wxLongLong) lnum;
      if (ll2 > ll1)
      {
	lbl = entries[i];
	entries[i] = entries[i + 1];
	entries[i + 1] = lbl;
	lbl = actions[i];
	actions[i] = actions[i + 1];
	actions[i + 1] = lbl;
	swapped = true;
      }
    }
  }
  while (swapped);

  cfgfile->SetPath(_T("/"));
  viewlog dlg(this);
  if (nevents > dlg.Grid1->GetNumberRows())
  {
    nevents -= dlg.Grid1->GetNumberRows();
    dlg.Grid1->AppendRows(nevents);
  }
  else if (nevents < dlg.Grid1->GetNumberRows())
  {
    nevents = dlg.Grid1->GetNumberRows() - nevents;
    dlg.Grid1->DeleteRows(0, nevents);
  }
  nevents = entries.Count();
  //int j;
  for (int i = 0; i < nevents; i++)
  {
    //j = nevents - (i + 1);
    value = entries[i] + _T("/DATE");
    value = cfgfile->Read(value, _T(""));
    dlg.Grid1->SetCellValue(i, 0, value);
    dlg.Grid1->SetCellValue(i, 1, actions[i]);
    value = entries[i] + _T("/NAME");
    value = cfgfile->Read(value, _T(""));
    dlg.Grid1->SetCellValue(i, 2, value);
    value = entries[i] + _T("/DURATION");
    value = cfgfile->Read(value, _T(""));
    /*
       if (value != _T("N/A"))
       {
       value = _T("0x") + value;
       value.ToLong(&dummy, 0);
       int secs = (int) (dummy % 60L);
       dummy /= 60L; // time in minutes
       int mins = (int) (dummy % 60L);
       int hrs = (int) (dummy / 60L);
       value.Printf(_T("%d:%02d:%02d"), hrs, mins, secs);
       }
     */
    dlg.Grid1->SetCellValue(i, 3, value);
    value = entries[i] + _T("/FULLRUN");
    value = cfgfile->Read(value, _T(""));
    dlg.Grid1->SetCellValue(i, 4, value);
  }
  delete cfgfile;
  dlg.ShowModal();
}

void
reclinkmain::OnMenuItem16Selected(wxCommandEvent & event)
{
  showlog();
}

/*
void reclinkmain::showabout(void)
{
    wxString wxbuild(wxVERSION_STRING);
#if defined(__WXMSW__)
    wxbuild << _T("-Windows");
#elif defined(__UNIX__)
    wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
    wxbuild << _T("-Unicode");
#else
    wxbuild << _T("-ANSI");
#endif

    wxString year = wxString(AutoVersion::YEAR, wxConvUTF8);
    wxString month = wxString(AutoVersion::MONTH, wxConvUTF8);
    wxString day = wxString(AutoVersion::DATE, wxConvUTF8);
    wxString status = wxString(AutoVersion::STATUS, wxConvUTF8);
    wxString fullversion = wxString(AutoVersion::FULLVERSION_STRING, wxConvUTF8);

    wxString msg = _("Versão ") + fullversion + _T(" ") + status + _T(" (") + year + _T(".") + month + _T(".") + day + _T(")\n") + wxbuild;

    wxMessageBox(msg, _("OpenRecLink"),wxICON_INFORMATION);
}
*/

void
reclinkmain::OnaboutSelected(wxCommandEvent & event)
{
  //showabout();
  wxRect rect = GetClientRect();
  wxPoint pt(rect.GetBottomRight());
  aboutpanel *panel = new aboutpanel(this, wxID_ANY, pt);
  panel->Show();
}
