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
// Nome:        wizcopy.cpp
// Propósito:   Classe (janela) para configurar cópia seletiva de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "wizcopy.h"

#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>

#include "ops_log.h"
#include "ntable.h"

//(*InternalHeaders(wizcopy)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(wizcopy)
const long
  wizcopy::ID_STATICTEXT1 = wxNewId();
const long
  wizcopy::ID_PANEL3 = wxNewId();
const long
  wizcopy::ID_TEXTCTRL1 = wxNewId();
const long
  wizcopy::ID_BITMAPBUTTON1 = wxNewId();
const long
  wizcopy::ID_PANEL2 = wxNewId();
const long
  wizcopy::ID_STATICTEXT10 = wxNewId();
const long
  wizcopy::ID_STATICTEXT11 = wxNewId();
const long
  wizcopy::ID_STATICTEXT12 = wxNewId();
const long
  wizcopy::ID_STATICTEXT13 = wxNewId();
const long
  wizcopy::ID_CHOICE1 = wxNewId();
const long
  wizcopy::ID_CHOICE2 = wxNewId();
const long
  wizcopy::ID_TEXTCTRL6 = wxNewId();
const long
  wizcopy::ID_CHOICE3 = wxNewId();
const long
  wizcopy::ID_CHOICE4 = wxNewId();
const long
  wizcopy::ID_CHOICE5 = wxNewId();
const long
  wizcopy::ID_TEXTCTRL2 = wxNewId();
const long
  wizcopy::ID_CHOICE6 = wxNewId();
const long
  wizcopy::ID_CHOICE7 = wxNewId();
const long
  wizcopy::ID_CHOICE8 = wxNewId();
const long
  wizcopy::ID_TEXTCTRL3 = wxNewId();
const long
  wizcopy::ID_CHOICE9 = wxNewId();
const long
  wizcopy::ID_CHOICE10 = wxNewId();
const long
  wizcopy::ID_CHOICE11 = wxNewId();
const long
  wizcopy::ID_TEXTCTRL4 = wxNewId();
const long
  wizcopy::ID_CHOICE12 = wxNewId();
const long
  wizcopy::ID_CHOICE13 = wxNewId();
const long
  wizcopy::ID_CHOICE14 = wxNewId();
const long
  wizcopy::ID_TEXTCTRL5 = wxNewId();
const long
  wizcopy::ID_PANEL4 = wxNewId();
const long
  wizcopy::ID_CHECKLISTBOX1 = wxNewId();
const long
  wizcopy::ID_STATICTEXT8 = wxNewId();
const long
  wizcopy::ID_BUTTON3 = wxNewId();
const long
  wizcopy::ID_BUTTON6 = wxNewId();
const long
  wizcopy::ID_PANEL5 = wxNewId();
const long
  wizcopy::ID_TEXTCTRL7 = wxNewId();
const long
  wizcopy::ID_STATICTEXT2 = wxNewId();
const long
  wizcopy::ID_PANEL6 = wxNewId();
const long
  wizcopy::ID_LISTBOOK1 = wxNewId();
const long
  wizcopy::ID_BUTTON1 = wxNewId();
const long
  wizcopy::ID_BUTTON2 = wxNewId();
const long
  wizcopy::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wizcopy, wxDialog)
  //(*EventTable(wizcopy)
  //*)
  END_EVENT_TABLE()wizcopy::wizcopy(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(wizcopy)
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
    new wxStaticText(Panel3, ID_STATICTEXT1, _("Cópia seletiva"), wxPoint(16, 8), wxDefaultSize, 0,
		     _T("ID_STATICTEXT1"));
  wxFont
    StaticText1Font(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false,
		    _T("Sans"), wxFONTENCODING_DEFAULT);
  StaticText1->SetFont(StaticText1Font);
  FlexGridSizer1->Add(Panel3, 1, wxALL | wxEXPAND, 0);
  Listbook1 =
    new wxNotebook(this, ID_LISTBOOK1, wxDefaultPosition, wxSize(523, 276), 0, _T("ID_LISTBOOK1"));
  Panel2 =
    new wxPanel(Listbook1, ID_PANEL2, wxPoint(56, 8), wxSize(523, 260), wxTAB_TRAVERSAL,
		_T("ID_PANEL2"));
  filenamectrl =
    new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(40, 104), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  openfile =
    new wxBitmapButton(Panel2, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(448, 104), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  Panel4 =
    new wxPanel(Listbook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL4"));
  StaticText10 =
    new wxStaticText(Panel4, ID_STATICTEXT10, _("Campo"), wxPoint(5, 28), wxDefaultSize, 0,
		     _T("ID_STATICTEXT10"));
  StaticText11 =
    new wxStaticText(Panel4, ID_STATICTEXT11, _("Op. lógico"), wxPoint(160, 28), wxDefaultSize, 0,
		     _T("ID_STATICTEXT11"));
  StaticText12 =
    new wxStaticText(Panel4, ID_STATICTEXT12, _("Valor"), wxPoint(266, 28), wxDefaultSize, 0,
		     _T("ID_STATICTEXT12"));
  StaticText13 =
    new wxStaticText(Panel4, ID_STATICTEXT13, _("Conector"), wxPoint(446, 28), wxDefaultSize, 0,
		     _T("ID_STATICTEXT13"));
  fld1 =
    new wxChoice(Panel4, ID_CHOICE1, wxPoint(5, 48), wxSize(155, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE1"));
  op1 =
    new wxChoice(Panel4, ID_CHOICE2, wxPoint(160, 48), wxSize(104, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE2"));
  op1->Append(_("Maior que"));
  op1->Append(_("Maior ou igual a"));
  op1->SetSelection(op1->Append(_("Igual a")));
  op1->Append(_("Menor ou igual a"));
  op1->Append(_("Menor que"));
  op1->Append(_("Diferente de"));
  value1 =
    new wxTextCtrl(Panel4, ID_TEXTCTRL6, wxEmptyString, wxPoint(266, 48), wxSize(180, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL6"));
  link1 =
    new wxChoice(Panel4, ID_CHOICE3, wxPoint(446, 48), wxSize(55, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE3"));
  link1->Append(_("e"));
  link1->Append(_("ou"));
  link1->SetSelection(link1->Append(_(".")));
  fld2 =
    new wxChoice(Panel4, ID_CHOICE4, wxPoint(5, 78), wxSize(155, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE4"));
  op2 =
    new wxChoice(Panel4, ID_CHOICE5, wxPoint(160, 78), wxSize(104, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE5"));
  op2->Append(_("Maior que"));
  op2->Append(_("Maior ou igual a"));
  op2->SetSelection(op2->Append(_("Igual a")));
  op2->Append(_("Menor ou igual a"));
  op2->Append(_("Menor que"));
  op2->Append(_("Diferente de"));
  value2 =
    new wxTextCtrl(Panel4, ID_TEXTCTRL2, wxEmptyString, wxPoint(266, 78), wxSize(180, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL2"));
  link2 =
    new wxChoice(Panel4, ID_CHOICE6, wxPoint(446, 78), wxSize(55, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE6"));
  link2->Append(_("e"));
  link2->Append(_("ou"));
  link2->SetSelection(link2->Append(_(".")));
  fld3 =
    new wxChoice(Panel4, ID_CHOICE7, wxPoint(5, 108), wxSize(155, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE7"));
  op3 =
    new wxChoice(Panel4, ID_CHOICE8, wxPoint(160, 108), wxSize(104, 29), 0, 0, 0,
		 wxDefaultValidator, _T("ID_CHOICE8"));
  op3->Append(_("Maior que"));
  op3->Append(_("Maior ou igual a"));
  op3->SetSelection(op3->Append(_("Igual a")));
  op3->Append(_("Menor ou igual a"));
  op3->Append(_("Menor que"));
  op3->Append(_("Diferente de"));
  value3 =
    new wxTextCtrl(Panel4, ID_TEXTCTRL3, wxEmptyString, wxPoint(266, 108), wxSize(180, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL3"));
  link3 =
    new wxChoice(Panel4, ID_CHOICE9, wxPoint(446, 108), wxSize(55, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE9"));
  link3->Append(_("e"));
  link3->Append(_("ou"));
  link3->SetSelection(link3->Append(_(".")));
  fld4 =
    new wxChoice(Panel4, ID_CHOICE10, wxPoint(5, 138), wxSize(155, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE10"));
  op4 =
    new wxChoice(Panel4, ID_CHOICE11, wxPoint(160, 138), wxSize(104, 29), 0, 0, 0,
		 wxDefaultValidator, _T("ID_CHOICE11"));
  op4->Append(_("Maior que"));
  op4->Append(_("Maior ou igual a"));
  op4->SetSelection(op4->Append(_("Igual a")));
  op4->Append(_("Menor ou igual a"));
  op4->Append(_("Menor que"));
  op4->Append(_("Diferente de"));
  value4 =
    new wxTextCtrl(Panel4, ID_TEXTCTRL4, wxEmptyString, wxPoint(266, 138), wxSize(180, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL4"));
  link4 =
    new wxChoice(Panel4, ID_CHOICE12, wxPoint(446, 138), wxSize(55, 29), 0, 0, 0,
		 wxDefaultValidator, _T("ID_CHOICE12"));
  link4->Append(_("e"));
  link4->Append(_("ou"));
  link4->SetSelection(link4->Append(_(".")));
  fld5 =
    new wxChoice(Panel4, ID_CHOICE13, wxPoint(5, 168), wxSize(155, 29), 0, 0, 0, wxDefaultValidator,
		 _T("ID_CHOICE13"));
  op5 =
    new wxChoice(Panel4, ID_CHOICE14, wxPoint(160, 168), wxSize(104, 29), 0, 0, 0,
		 wxDefaultValidator, _T("ID_CHOICE14"));
  op5->Append(_("Maior que"));
  op5->Append(_("Maior ou igual a"));
  op5->SetSelection(op5->Append(_("Igual a")));
  op5->Append(_("Menor ou igual a"));
  op5->Append(_("Menor que"));
  op5->Append(_("Diferente de"));
  value5 =
    new wxTextCtrl(Panel4, ID_TEXTCTRL5, wxEmptyString, wxPoint(266, 168), wxSize(180, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL5"));
  Panel5 =
    new wxPanel(Listbook1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL5"));
  masterfields =
    new wxCheckListBox(Panel5, ID_CHECKLISTBOX1, wxPoint(260, 28), wxSize(205, 174), 0, 0, 0,
		       wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
  StaticText8 =
    new wxStaticText(Panel5, ID_STATICTEXT8,
		     _("Selecione os campos \ndesejados do arquivo\nmestre na caixa ao\nlado:"),
		     wxPoint(110, 28), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
  Button1 =
    new wxButton(Panel5, ID_BUTTON3, _("Marca\n todos\ncampos"), wxPoint(16, 143), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON3"));
  Button4 =
    new wxButton(Panel5, ID_BUTTON6, _("Desmarca\n todos\ncampos"), wxPoint(124, 143),
		 wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
  Panel6 =
    new wxPanel(Listbook1, ID_PANEL6, wxPoint(175, 19), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL6"));
  errrep =
    new wxTextCtrl(Panel6, ID_TEXTCTRL7, wxEmptyString, wxPoint(40, 32), wxSize(350, 176),
		   wxTE_MULTILINE | wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL7"));
  okbtn =
    new wxBitmapButton(Panel6, wxID_OK,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),
						wxART_BUTTON), wxPoint(416, 176), wxSize(36, 36),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("wxID_OK"));
  okbtn->Disable();
  okbtn->SetToolTip(_("Aceita"));
  cancelbtn =
    new wxBitmapButton(Panel6, wxID_CANCEL,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CROSS_MARK")),
						wxART_BUTTON), wxPoint(464, 176), wxSize(36, 36),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("wxID_CANCEL"));
  cancelbtn->SetToolTip(_("Abandona"));
  StaticText2 =
    new wxStaticText(Panel6, ID_STATICTEXT2, _("Status da configuração:"), wxPoint(40, 8),
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  Listbook1->AddPage(Panel2, _("Arq. entrada"), true);
  Listbook1->AddPage(Panel4, _("Condições"), false);
  Listbook1->AddPage(Panel5, _("Campos"), false);
  Listbook1->AddPage(Panel6, _("Finaliza"), false);
  FlexGridSizer1->Add(Listbook1, 1, wxALL | wxEXPAND, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(523, 47), wxTAB_TRAVERSAL,
		_T("ID_PANEL1"));
  backbtn =
    new wxButton(Panel1, ID_BUTTON1, _("Volta"), wxPoint(340, 8), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON1"));
  fwdbtn =
    new wxButton(Panel1, ID_BUTTON2, _("Segue"), wxPoint(425, 8), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON2"));
  FlexGridSizer1->Add(Panel1, 1, wxBOTTOM | wxEXPAND, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Selecione o arquivo"), wxEmptyString, wxEmptyString, _("*.dat"),
		     wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition,
		     wxDefaultSize, _T("wxFileDialog"));
  SetSizer(FlexGridSizer1);
  Layout();

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizcopy::OnopenfileClick);
  Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizcopy::OnAddAllFieldsClick);
  Connect(ID_BUTTON6, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizcopy::OnRemoveAllFieldsClick);
  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & wizcopy::OnokbtnClick);
  Connect(wxID_CANCEL, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizcopy::OncancelbtnClick);
  Connect(ID_LISTBOOK1, wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,
	  (wxObjectEventFunction) & wizcopy::OnListbook1PageChanged);
  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizcopy::OnbackbtnClick);
  Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizcopy::OnfwdbtnClick);
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

wizcopy::~wizcopy()
{
  //(*Destroy(wizcopy)
  //*)
}

void
wizcopy::init(void)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    filenamectrl->SetValue(FileDialog1->GetPath());
    wxString fname = filenamectrl->GetValue();
    if (wxFileExists(fname))
    {
      fld1->Clear();
      fld2->Clear();
      fld3->Clear();
      fld4->Clear();
      fld5->Clear();
      op1->SetSelection(2);
      op2->SetSelection(2);
      op3->SetSelection(2);
      op4->SetSelection(2);
      op5->SetSelection(2);
      value1->Clear();
      value2->Clear();
      value3->Clear();
      value4->Clear();
      value5->Clear();
      link1->SetSelection(2);
      link2->SetSelection(2);
      link3->SetSelection(2);
      link4->SetSelection(2);
      masterfields->Clear();
      errrep->Clear();
      try
      {
	ntable in_dbf;
	in_dbf.open(fname);
	int nflds = in_dbf.getnumfields();
	for (int i = 0; i < nflds; i++)
	{
	  fld1->Append(in_dbf.getfieldname(i));
	  fld2->Append(in_dbf.getfieldname(i));
	  fld3->Append(in_dbf.getfieldname(i));
	  fld4->Append(in_dbf.getfieldname(i));
	  fld5->Append(in_dbf.getfieldname(i));
	  masterfields->Append(in_dbf.getfieldname(i));
	}
	in_dbf.close();
      } catch( ...)
      {
      };
      //readcfg(fname);
    }
  }
}

void
wizcopy::checkifload(void)
{
  wxFileName pname(filenamectrl->GetValue());
  pname.SetExt(_T("cpycfg"));
  wxString fname = pname.GetFullPath();
  if (wxFileExists(fname))
    if (wxMessageBox
	(_("Já existe uma configuração associada\na este arquivo, deseja utilizá-la?"),
	 _("CONFIGURAÇÃO DISPONÍVEL"), wxYES_NO) == wxYES)
      loadcfg(fname);
}

void
wizcopy::OnopenfileClick(wxCommandEvent & event)
{
  init();
  checkifload();
}

void
wizcopy::OnAddAllFieldsClick(wxCommandEvent & event)
{
  int nitems = masterfields->GetCount();
  for (int i = 0; i < nitems; i++)
    masterfields->Check(i, true);
}

void
wizcopy::OnRemoveAllFieldsClick(wxCommandEvent & event)
{
  int nitems = masterfields->GetCount();
  for (int i = 0; i < nitems; i++)
    masterfields->Check(i, false);
}

void
wizcopy::loadcfg(wxString fname)
{
  if (wxFileExists(fname))
  {
    wxFileName pname = wxFileName(fname);
    pname.SetExt(_T("cpycfg"));
    wxString cfgname = pname.GetFullPath();
    wxFileConfig *cfgfile =
      new wxFileConfig(_T(""), _T(""), cfgname, _T(""), wxCONFIG_USE_LOCAL_FILE);
    long nitems = masterfields->GetCount();
    wxString aux, tmp;
    int n;
    for (int i = 0; i < nitems; i++)
    {
      aux.Printf(_T("FIELDS/STATE%d"), i);
      tmp = cfgfile->Read(aux, _T(""));
      masterfields->Check(i, (tmp == _T("Y")));
    }
    int s;
    aux = _T("SELECTIONS/FIELD1");
    s = cfgfile->Read(aux, -1);
    fld1->SetSelection(s);
    aux = _T("SELECTIONS/OP1");
    s = cfgfile->Read(aux, -1);
    op1->SetSelection(s);
    aux = _T("SELECTIONS/VALUE1");
    tmp = cfgfile->Read(aux, _T(""));
    value1->SetValue(tmp);
    aux = _T("SELECTIONS/CONNECT1");
    s = cfgfile->Read(aux, -1);
    link1->SetSelection(s);
    aux = _T("SELECTIONS/FIELD2");
    s = cfgfile->Read(aux, -1);
    fld2->SetSelection(s);
    aux = _T("SELECTIONS/OP2");
    s = cfgfile->Read(aux, -1);
    op2->SetSelection(s);
    aux = _T("SELECTIONS/VALUE2");
    tmp = cfgfile->Read(aux, _T(""));
    value2->SetValue(tmp);
    aux = _T("SELECTIONS/CONNECT2");
    s = cfgfile->Read(aux, -1);
    link2->SetSelection(s);
    aux = _T("SELECTIONS/FIELD3");
    s = cfgfile->Read(aux, -1);
    fld3->SetSelection(s);
    aux = _T("SELECTIONS/OP3");
    s = cfgfile->Read(aux, -1);
    op3->SetSelection(s);
    aux = _T("SELECTIONS/VALUE3");
    tmp = cfgfile->Read(aux, _T(""));
    value3->SetValue(tmp);
    aux = _T("SELECTIONS/CONNECT3");
    s = cfgfile->Read(aux, -1);
    link3->SetSelection(s);
    aux = _T("SELECTIONS/FIELD4");
    s = cfgfile->Read(aux, -1);
    fld4->SetSelection(s);
    aux = _T("SELECTIONS/OP4");
    s = cfgfile->Read(aux, -1);
    op4->SetSelection(s);
    aux = _T("SELECTIONS/VALUE4");
    tmp = cfgfile->Read(aux, _T(""));
    value4->SetValue(tmp);
    aux = _T("SELECTIONS/CONNECT4");
    s = cfgfile->Read(aux, -1);
    link4->SetSelection(s);
    aux = _T("SELECTIONS/FIELD5");
    s = cfgfile->Read(aux, -1);
    fld5->SetSelection(s);
    aux = _T("SELECTIONS/OP5");
    s = cfgfile->Read(aux, -1);
    op5->SetSelection(s);
    aux = _T("SELECTIONS/VALUE5");
    tmp = cfgfile->Read(aux, _T(""));
    value5->SetValue(tmp);
    delete cfgfile;
  }
}

void
wizcopy::savecfg(wxString fname)
{
  if (wxFileExists(fname))
  {
    wxFileName pname = wxFileName(fname);
    pname.SetExt(_T("cpycfg"));
    wxString cfgname = pname.GetFullPath();
    wxFileConfig *cfgfile =
      new wxFileConfig(_T(""), _T(""), cfgname, _T(""), wxCONFIG_USE_LOCAL_FILE);
    cfgfile->Write(_T("GENERAL/FILENAME"), fname);
    long nitems = masterfields->GetCount();
    bool checked;
    wxString aux, tmp;
    for (int i = 0; i < nitems; i++)
    {
      checked = masterfields->IsChecked(i);
      aux.Printf(_T("FIELDS/STATE%d"), i);
      if (checked)
	cfgfile->Write(aux, _T("Y"));
      else
	cfgfile->Write(aux, _T("N"));
    }
    aux = _T("SELECTIONS/FIELD1");
    cfgfile->Write(aux, fld1->GetSelection());
    aux = _T("SELECTIONS/OP1");
    cfgfile->Write(aux, op1->GetSelection());
    aux = _T("SELECTIONS/VALUE1");
    cfgfile->Write(aux, value1->GetValue());
    aux = _T("SELECTIONS/CONNECT1");
    cfgfile->Write(aux, link1->GetSelection());
    aux = _T("SELECTIONS/FIELD2");
    cfgfile->Write(aux, fld2->GetSelection());
    aux = _T("SELECTIONS/OP2");
    cfgfile->Write(aux, op2->GetSelection());
    aux = _T("SELECTIONS/VALUE2");
    cfgfile->Write(aux, value2->GetValue());
    aux = _T("SELECTIONS/CONNECT2");
    cfgfile->Write(aux, link2->GetSelection());
    aux = _T("SELECTIONS/FIELD3");
    cfgfile->Write(aux, fld3->GetSelection());
    aux = _T("SELECTIONS/OP3");
    cfgfile->Write(aux, op3->GetSelection());
    aux = _T("SELECTIONS/VALUE3");
    cfgfile->Write(aux, value3->GetValue());
    aux = _T("SELECTIONS/CONNECT3");
    cfgfile->Write(aux, link3->GetSelection());
    aux = _T("SELECTIONS/FIELD4");
    cfgfile->Write(aux, fld4->GetSelection());
    aux = _T("SELECTIONS/OP4");
    cfgfile->Write(aux, op4->GetSelection());
    aux = _T("SELECTIONS/VALUE4");
    cfgfile->Write(aux, value4->GetValue());
    aux = _T("SELECTIONS/CONNECT4");
    cfgfile->Write(aux, link4->GetSelection());
    aux = _T("SELECTIONS/FIELD5");
    cfgfile->Write(aux, fld5->GetSelection());
    aux = _T("SELECTIONS/OP5");
    cfgfile->Write(aux, op5->GetSelection());
    aux = _T("SELECTIONS/VALUE5");
    cfgfile->Write(aux, value5->GetValue());
    delete cfgfile;
    ops_log log;
    log.log_event(_T("CPYC"), fname);
  }
}

void
wizcopy::OnokbtnClick(wxCommandEvent & event)
{
  wxString fname = filenamectrl->GetValue();
  savecfg(fname);
  event.Skip();
}

void
wizcopy::OncancelbtnClick(wxCommandEvent & event)
{
  event.Skip();
}

void
wizcopy::analyze(void)
{
  errrep->Clear();
  int nchoices = masterfields->GetCount();
  bool hassels = false;
  for (int i = 0; i < nchoices; i++)
  {
    if (masterfields->IsChecked(i))
    {
      hassels = true;
      break;
    }
  }
  if (!hassels)
    errrep->AppendText(_("É obrigatório selecionar pelo menos um campo.\n"));
  if (fld1->GetSelection() == -1)
    errrep->AppendText(_("É obrigatório selecionar o nome do campo 1.\n"));
  if (link1->GetSelection() != 2)
  {
    if (fld2->GetSelection() == -1)
      errrep->AppendText(_("É obrigatório selecionar o nome do campo 2.\n"));
    if (link2->GetSelection() != 2)
    {
      if (fld3->GetSelection() == -1)
	errrep->AppendText(_("É obrigatório selecionar o nome do campo 3.\n"));
      if (link3->GetSelection() != 2)
      {
	if (fld4->GetSelection() == -1)
	  errrep->AppendText(_("É obrigatório selecionar o nome do campo 4.\n"));
	if (link4->GetSelection() != 2)
	{
	  if (fld5->GetSelection() == -1)
	    errrep->AppendText(_("É obrigatório selecionar o nome do campo 5.\n"));
	}
      }
    }
  }
}

void
wizcopy::OnListbook1PageChanged(wxNotebookEvent & event)
{
  if (Listbook1->GetCurrentPage() == Panel6)
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

void
wizcopy::OnbackbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(false);
}

void
wizcopy::OnfwdbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(true);
}
