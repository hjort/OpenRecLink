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
// Nome:        wizjin.cpp
// Propósito:   Classe (janela) para configurar associação (join)
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "wizjin.h"
#include "ntable.h"
#include "ops_log.h"

#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>

//(*InternalHeaders(wizjin)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/tglbtn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(wizjin)
const long
  wizjin::ID_STATICTEXT1 = wxNewId();
const long
  wizjin::ID_PANEL3 = wxNewId();
const long
  wizjin::ID_TEXTCTRL1 = wxNewId();
const long
  wizjin::ID_BITMAPBUTTON1 = wxNewId();
const long
  wizjin::ID_STATICTEXT6 = wxNewId();
const long
  wizjin::ID_PANEL2 = wxNewId();
const long
  wizjin::ID_TEXTCTRL2 = wxNewId();
const long
  wizjin::ID_BITMAPBUTTON2 = wxNewId();
const long
  wizjin::ID_TEXTCTRL3 = wxNewId();
const long
  wizjin::ID_BITMAPBUTTON3 = wxNewId();
const long
  wizjin::ID_STATICTEXT3 = wxNewId();
const long
  wizjin::ID_STATICTEXT4 = wxNewId();
const long
  wizjin::ID_PANEL4 = wxNewId();
const long
  wizjin::ID_CHOICE2 = wxNewId();
const long
  wizjin::ID_CHOICE1 = wxNewId();
const long
  wizjin::ID_STATICTEXT5 = wxNewId();
const long
  wizjin::ID_STATICTEXT7 = wxNewId();
const long
  wizjin::ID_PANEL5 = wxNewId();
const long
  wizjin::ID_CHECKLISTBOX1 = wxNewId();
const long
  wizjin::ID_STATICTEXT8 = wxNewId();
const long
  wizjin::ID_PANEL6 = wxNewId();
const long
  wizjin::ID_STATICTEXT9 = wxNewId();
const long
  wizjin::ID_CHECKLISTBOX2 = wxNewId();
const long
  wizjin::ID_PANEL7 = wxNewId();
const long
  wizjin::ID_TEXTCTRL4 = wxNewId();
const long
  wizjin::ID_STATICTEXT2 = wxNewId();
const long
  wizjin::ID_PANEL8 = wxNewId();
const long
  wizjin::ID_LISTBOOK1 = wxNewId();
const long
  wizjin::ID_BUTTON1 = wxNewId();
const long
  wizjin::ID_BUTTON2 = wxNewId();
const long
  wizjin::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wizjin, wxDialog)
  //(*EventTable(wizjin)
  //*)
  END_EVENT_TABLE()wizjin::wizjin(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				  const wxSize & size)
{
  //(*Initialize(wizjin)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, wxID_ANY, _("Assistente"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(523, 349));
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  Panel3 =
    new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxSize(523, 23), wxTAB_TRAVERSAL,
		_T("ID_PANEL3"));
  StaticText1 =
    new wxStaticText(Panel3, ID_STATICTEXT1, _("Associa"), wxPoint(16, 8), wxDefaultSize, 0,
		     _T("ID_STATICTEXT1"));
  wxFont
    StaticText1Font(14, wxSWISS, wxFONTSTYLE_NORMAL, wxBOLD, false, _T("Sans"),
		    wxFONTENCODING_DEFAULT);
  StaticText1->SetFont(StaticText1Font);
  FlexGridSizer1->Add(Panel3, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  Listbook1 =
    new wxNotebook(this, ID_LISTBOOK1, wxDefaultPosition, wxSize(523, 276), 0, _T("ID_LISTBOOK1"));
  Panel2 =
    new wxPanel(Listbook1, ID_PANEL2, wxPoint(56, 8), wxSize(523, 260), wxTAB_TRAVERSAL,
		_T("ID_PANEL2"));
  cfgfilenamectrl =
    new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(40, 104), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  opencfgfile =
    new wxBitmapButton(Panel2, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE")),
						wxART_BUTTON), wxPoint(448, 104), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  StaticText6 =
    new wxStaticText(Panel2, ID_STATICTEXT6, _("Arquivo de configuração:"), wxPoint(48, 80),
		     wxDefaultSize, 0, _T("ID_STATICTEXT6"));
  Panel4 =
    new wxPanel(Listbook1, ID_PANEL4, wxPoint(202, 14), wxSize(523, 260), wxTAB_TRAVERSAL,
		_T("ID_PANEL4"));
  masterfilenamectrl =
    new wxTextCtrl(Panel4, ID_TEXTCTRL2, wxEmptyString, wxPoint(40, 72), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
  openmasterfile =
    new wxBitmapButton(Panel4, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(448, 72), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  updatefilenamectrl =
    new wxTextCtrl(Panel4, ID_TEXTCTRL3, wxEmptyString, wxPoint(40, 144), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
  openupdatefile =
    new wxBitmapButton(Panel4, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(448, 144), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
  StaticText3 =
    new wxStaticText(Panel4, ID_STATICTEXT3, _("Arquivo mestre (será indexado)"), wxPoint(48, 48),
		     wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  StaticText4 =
    new wxStaticText(Panel4, ID_STATICTEXT4,
		     _("Arquivo de atualização (será lido por inteiro):"), wxPoint(48, 120),
		     wxDefaultSize, 0, _T("ID_STATICTEXT4"));
  Panel5 =
    new wxPanel(Listbook1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL5"));
  masterkey =
    new wxChoice(Panel5, ID_CHOICE2, wxPoint(200, 70), wxSize(192, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE2"));
  updatekey =
    new wxChoice(Panel5, ID_CHOICE1, wxPoint(200, 150), wxSize(192, 29), 0, 0, 0,
		 wxDefaultValidator, _T("ID_CHOICE1"));
  StaticText5 =
    new wxStaticText(Panel5, ID_STATICTEXT5, _("Campo-chave do arquivo mestre:"), wxPoint(48, 40),
		     wxDefaultSize, 0, _T("ID_STATICTEXT5"));
  StaticText7 =
    new wxStaticText(Panel5, ID_STATICTEXT7, _("Campo-chave do arquivo de atualização:"),
		     wxPoint(48, 120), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
  Panel6 =
    new wxPanel(Listbook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL6"));
  masterfields =
    new wxCheckListBox(Panel6, ID_CHECKLISTBOX1, wxPoint(192, 32), wxSize(205, 174), 0, 0, 0,
		       wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
  StaticText8 =
    new wxStaticText(Panel6, ID_STATICTEXT8,
		     _("Selecione os campos \ndesejados do arquivo\nmestre na caixa ao\nlado:"),
		     wxPoint(16, 48), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
  Panel7 =
    new wxPanel(Listbook1, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL7"));
  StaticText9 =
    new wxStaticText(Panel7, ID_STATICTEXT9,
		     _
		     ("Selecione os campos \ndesejados do arquivo\nde atualização na caixa\nao lado:"),
		     wxPoint(16, 48), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
  updatefields =
    new wxCheckListBox(Panel7, ID_CHECKLISTBOX2, wxPoint(192, 32), wxSize(205, 174), 0, 0, 0,
		       wxDefaultValidator, _T("ID_CHECKLISTBOX2"));
  Panel8 =
    new wxPanel(Listbook1, ID_PANEL8, wxPoint(175, 19), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL8"));
  errrep =
    new wxTextCtrl(Panel8, ID_TEXTCTRL4, wxEmptyString, wxPoint(40, 32), wxSize(350, 176),
		   wxTE_MULTILINE | wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
  okbtn =
    new wxBitmapButton(Panel8, wxID_OK,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),
						wxART_BUTTON), wxPoint(416, 176), wxSize(36, 36),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("wxID_OK"));
  okbtn->Disable();
  okbtn->SetToolTip(_("Aceita"));
  cancelbtn =
    new wxBitmapButton(Panel8, wxID_CANCEL,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CROSS_MARK")),
						wxART_BUTTON), wxPoint(464, 176), wxSize(36, 36),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("wxID_CANCEL"));
  cancelbtn->SetToolTip(_("Abandona"));
  StaticText2 =
    new wxStaticText(Panel8, ID_STATICTEXT2, _("Status da configuração:"), wxPoint(40, 8),
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  Listbook1->AddPage(Panel2, _("Config."), false);
  Listbook1->AddPage(Panel4, _("Arq. dados"), false);
  Listbook1->AddPage(Panel5, _("Chave"), false);
  Listbook1->AddPage(Panel6, _("Mestre"), false);
  Listbook1->AddPage(Panel7, _("Atualização"), false);
  Listbook1->AddPage(Panel8, _("Finaliza"), false);
  FlexGridSizer1->Add(Listbook1, 1,
		      wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(523, 47), wxTAB_TRAVERSAL,
		_T("ID_PANEL1"));
  backbtn =
    new wxButton(Panel1, ID_BUTTON1, _("Volta"), wxPoint(340, 8), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON1"));
  fwdbtn =
    new wxButton(Panel1, ID_BUTTON2, _("Segue"), wxPoint(425, 8), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON2"));
  FlexGridSizer1->Add(Panel1, 1,
		      wxBOTTOM | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE | wxFD_OPEN,
		     wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FileDialog2 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_SAVE, wxDefaultPosition, wxDefaultSize,
		     _T("wxFileDialog"));
  SetSizer(FlexGridSizer1);
  Layout();

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizjin::OnopencfgfileClick);
  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizjin::OnopenmasterfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizjin::OnopenupdatefileClick);
  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & wizjin::OnokbtnClick);
  Connect(ID_LISTBOOK1, wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,
	  (wxObjectEventFunction) & wizjin::OnListbook1PageChanged);
  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizjin::OnbackbtnClick);
  Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizjin::OnfwdbtnClick);
  //*)

#if wxCHECK_VERSION(3,0,0)
  fwdbtn->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),
					     wxART_MAKE_CLIENT_ID_FROM_STR(wxString
									   (wxEmptyString))));
  backbtn->SetBitmap(wxArtProvider::GetBitmap
		     (wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),
		      wxART_MAKE_CLIENT_ID_FROM_STR(wxString(wxEmptyString))));
#else
  fwdbtn->SetLabel(_("Segue >>"));
  backbtn->SetLabel(_("<< Volta"));
#endif
}

wizjin::~wizjin()
{
  //(*Destroy(wizjin)
  //*)
}

void
wizjin::OnopencfgfileClick(wxCommandEvent & event)
{
  FileDialog2->SetWildcard(_T("*.jincfg"));
  FileDialog2->SetMessage(_("Selecione o arquivo de configuração"));
  if (FileDialog2->ShowModal() == wxID_OK)
  {
    wxFileName cffilename = wxFileName(FileDialog2->GetPath());
    cffilename.SetExt(_T("jincfg"));
    wxString fname = cffilename.GetFullPath();
    cfgfilenamectrl->SetValue(fname);
    if (wxFileExists(fname))
    {
      int answer =
	wxMessageBox(_
		     ("Já existe uma configuração associada\na este arquivo, deseja utilizá-la?"),
_("CONFIGURAÇÃO DISPONÍVEL"),
wxYES_NO);
      if (answer == wxYES)
	loadcfg();
    }
  }
}

void
wizjin::OnopenmasterfileClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  FileDialog1->SetMessage(_("Selecione o arquivo mestre"));
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    masterfilenamectrl->SetValue(FileDialog1->GetPath());
    if (comparenames())
    {
      masterfilenamectrl->SetValue(_T(""));
      wxMessageBox(_("Os nomes dos arquivos\ndevem ser diferentes."), _T("ERRO"), wxICON_ERROR);
    }
    else
    {
      wxString fname = masterfilenamectrl->GetValue();
      if (wxFileExists(fname))
      {
	if (!(updatefilenamectrl->GetValue()).IsEmpty()
	    && wxFileExists(updatefilenamectrl->GetValue()))
	  initlists();
      }
      else
      {
	masterfilenamectrl->SetValue(_T(""));
	wxMessageBox(_("Este arquivo não existe."), _("ERRO"), wxICON_ERROR);
      }
    }
  }
}

void
wizjin::OnopenupdatefileClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  FileDialog1->SetMessage(_("Selecione o arquivo de atualização"));
  //FileDialog1->SetStyle(wxOPEN | wxFILE_MUST_EXIST);
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    updatefilenamectrl->SetValue(FileDialog1->GetPath());
    if (comparenames())
    {
      updatefilenamectrl->SetValue(_T(""));
      wxMessageBox(_("Os nomes dos arquivos\ndevem ser diferentes."), _("ERRO"), wxICON_ERROR);
    }
    else
    {
      wxString fname = updatefilenamectrl->GetValue();
      if (wxFileExists(fname))
      {
	if (!(masterfilenamectrl->GetValue()).IsEmpty()
	    && wxFileExists(masterfilenamectrl->GetValue()))
	  initlists();
      }
      else
      {
	updatefilenamectrl->SetValue(_T(""));
	wxMessageBox(_("Este arquivo não existe."), _("ERRO"), wxICON_ERROR);
      }
    }
  }
}

void
wizjin::OnokbtnClick(wxCommandEvent & event)
{
  savecfg();
  ops_log log;
  log.log_event(_T("JOINC"), cfgfilenamectrl->GetValue());
  Close();
}

void
wizjin::OnbackbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(false);
}

void
wizjin::OnfwdbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(true);
}

void
wizjin::loadcfg(void)
{
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgfilenamectrl->GetValue(), _T(""), wxCONFIG_USE_LOCAL_FILE);

  wxString aux = _T("");
  cfgfile->Read(_T("FILES/MASTER"), &aux);
  masterfilenamectrl->SetValue(aux);
  aux = _T("");
  cfgfile->Read(_T("FILES/UPDATE"), &aux);
  updatefilenamectrl->SetValue(aux);
  if (!(masterfilenamectrl->GetValue()).IsEmpty() &&
      wxFileExists(masterfilenamectrl->GetValue()) &&
      !(updatefilenamectrl->GetValue()).IsEmpty() && wxFileExists(updatefilenamectrl->GetValue()))
  {
    if (initlists())
    {
      long nitems = 0l;
      cfgfile->Read(_T("KEYS/MASTERSEL"), &nitems);
      masterkey->SetSelection((int) nitems);
      cfgfile->Read(_T("KEYS/UPDATESEL"), &nitems);
      updatekey->SetSelection((int) nitems);
      int items = masterfields->GetCount();
      wxString tmp;
      for (int i = 0; i < items; i++)
      {
	tmp = _T("");
	aux.Printf(_T("FIELDS/MASTER%d"), i);
	cfgfile->Read(aux, &tmp);
	masterfields->Check(i, (tmp == _T("Y")));
      }
      items = updatefields->GetCount();
      for (int i = 0; i < items; i++)
      {
	tmp = _T("");
	aux.Printf(_T("FIELDS/UPDATE%d"), i);
	cfgfile->Read(aux, &tmp);
	updatefields->Check(i, (tmp == _T("Y")));
      }
    }
  }
  delete cfgfile;
}

bool wizjin::initlists(void)
{
  bool
    retval = false;
  ntable
    tbl;

  masterkey->Clear();
  masterfields->Clear();

  if (tbl.open(masterfilenamectrl->GetValue()))
  {
    int
      nfields = tbl.getnumfields();
    wxString
      fld;
    for (int i = 0; i < nfields; i++)
    {
      fld = tbl.getfieldname(i);
      masterkey->Append(fld);
      masterfields->Append(fld);
    }
    masterkey->Append(_T("@RECNO"));
    masterfields->Append(_T("@RECNO"));
    retval = true;
  }
  else
    wxMessageBox(_("Erro ao abrir arquivo mestre"), _("ERRO"), wxICON_ERROR);
  tbl.close();
  updatekey->Clear();
  updatefields->Clear();
  if (retval && tbl.open(updatefilenamectrl->GetValue()))
  {
    int
      nfields = tbl.getnumfields();
    wxString
      fld;
    for (int i = 0; i < nfields; i++)
    {
      fld = tbl.getfieldname(i);
      updatekey->Append(fld);
      updatefields->Append(fld);
    }
    updatekey->Append(_T("@RECNO"));
    updatefields->Append(_T("@RECNO"));
  }
  else
  {
    wxMessageBox(_("Erro ao abrir arquivo de atualização"), _("ERRO"), wxICON_ERROR);
    retval = false;
  }
  tbl.close();

  return retval;
}

void
wizjin::savecfg(void)
{
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgfilenamectrl->GetValue(), _T(""), wxCONFIG_USE_LOCAL_FILE);

  cfgfile->Write(_T("FILES/MASTER"), masterfilenamectrl->GetValue());
  cfgfile->Write(_T("FILES/UPDATE"), updatefilenamectrl->GetValue());
  cfgfile->Write(_T("KEYS/MASTERSEL"), (long) masterkey->GetSelection());
  cfgfile->Write(_T("KEYS/UPDATESEL"), (long) updatekey->GetSelection());
  int nitems = masterfields->GetCount();
  bool checked;
  wxString aux;
  for (int i = 0; i < nitems; i++)
  {
    checked = masterfields->IsChecked(i);
    aux.Printf(_T("FIELDS/MASTER%d"), i);
    if (checked)
      cfgfile->Write(aux, _T("Y"));
    else
      cfgfile->Write(aux, _T("N"));
  }
  nitems = updatefields->GetCount();
  for (int i = 0; i < nitems; i++)
  {
    checked = updatefields->IsChecked(i);
    aux.Printf(_T("FIELDS/UPDATE%d"), i);
    if (checked)
      cfgfile->Write(aux, _T("Y"));
    else
      cfgfile->Write(aux, _T("N"));
  }

  delete cfgfile;
}

void
wizjin::analyze(void)
{
  errrep->Clear();
  if (cfgfilenamectrl->GetValue().IsEmpty())
    errrep->AppendText(_("Selecione o arquivo de configuração\n"));
  if (masterfilenamectrl->GetValue().IsEmpty())
    errrep->AppendText(_("Selecione o arquivo mestre\n"));
  if (updatefilenamectrl->GetValue().IsEmpty())
    errrep->AppendText(_("Selecione o arquivo de atualização\n"));
  if (masterkey->GetSelection() == wxNOT_FOUND)
    errrep->AppendText(_("Selecione o campo-chave do arquivo mestre\n"));
  if (updatekey->GetSelection() == wxNOT_FOUND)
    errrep->AppendText(_("Selecione o campo-chave do arquivo de atualização\n"));
  wxString mastersel = masterkey->GetStringSelection();
  wxString updatesel = updatekey->GetStringSelection();
  if (((mastersel == _T("@RECNO")) || (updatesel == _T("@RECNO"))) && (mastersel != updatesel))
    errrep->AppendText(_("O uso do numero de registro como chave tem que ser nos dois arquivos\n"));
  int i;
  int nitems = masterfields->GetCount();
  for (i = 0; i < nitems; i++)
    if (masterfields->IsChecked(i))
      break;
  if (i >= nitems)
    errrep->AppendText(_("Selecione ao menos um campo do arquivo mestre\n"));
  nitems = updatefields->GetCount();
  for (i = 0; i < nitems; i++)
    if (updatefields->IsChecked(i))
      break;
  if (i >= nitems)
    errrep->AppendText(_("Selecione ao menos um campo do arquivo de atualização\n"));
}

void
wizjin::OnListbook1PageChanged(wxNotebookEvent & event)
{
  if (Listbook1->GetCurrentPage() == Panel8)
  {
    analyze();
    int nlines = errrep->GetNumberOfLines();
    if ((nlines == 1) && errrep->GetLineText(0).IsEmpty())
      okbtn->Enable();
    else
      okbtn->Disable();

  }
  event.Skip();
}

bool wizjin::comparenames(void)
{
  bool
    retval = false;

  wxString
    f1 = masterfilenamectrl->GetValue();
  wxString
    f2 = updatefilenamectrl->GetValue();

  if (!f1.IsEmpty() && !f2.IsEmpty() && (!f1.Cmp(f2)))
    retval = true;

  return retval;
}
