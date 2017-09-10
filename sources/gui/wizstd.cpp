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
// Nome:        wizstd.cpp
// Propósito:   Classe (janela) para configurar padronização
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "wizstd.h"
#include "ntable.h"
#include "ops_log.h"

#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/tokenzr.h>

#include "setoptsdlg.h"

//(*InternalHeaders(wizstd)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/tglbtn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

//(*IdInit(wizstd)
const long
  wizstd::ID_STATICTEXT1 = wxNewId();
const long
  wizstd::ID_PANEL3 = wxNewId();
const long
  wizstd::ID_TEXTCTRL1 = wxNewId();
const long
  wizstd::ID_BITMAPBUTTON1 = wxNewId();
const long
  wizstd::ID_PANEL2 = wxNewId();
const long
  wizstd::ID_GRID1 = wxNewId();
const long
  wizstd::ID_BUTTON3 = wxNewId();
const long
  wizstd::ID_BUTTON4 = wxNewId();
const long
  wizstd::ID_BUTTON5 = wxNewId();
const long
  wizstd::ID_BUTTON6 = wxNewId();
const long
  wizstd::ID_BITMAPBUTTON2 = wxNewId();
const long
  wizstd::ID_BITMAPBUTTON3 = wxNewId();
const long
  wizstd::ID_PANEL4 = wxNewId();
const long
  wizstd::ID_STATICTEXT3 = wxNewId();
const long
  wizstd::ID_STATICTEXT4 = wxNewId();
const long
  wizstd::ID_TEXTCTRL3 = wxNewId();
const long
  wizstd::ID_TEXTCTRL4 = wxNewId();
const long
  wizstd::ID_STATICTEXT5 = wxNewId();
const long
  wizstd::ID_TEXTCTRL5 = wxNewId();
const long
  wizstd::ID_PANEL5 = wxNewId();
const long
  wizstd::ID_TEXTCTRL2 = wxNewId();
const long
  wizstd::ID_STATICTEXT2 = wxNewId();
const long
  wizstd::ID_PANEL6 = wxNewId();
const long
  wizstd::ID_LISTBOOK1 = wxNewId();
const long
  wizstd::ID_BUTTON1 = wxNewId();
const long
  wizstd::ID_BUTTON2 = wxNewId();
const long
  wizstd::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wizstd, wxDialog)
  //(*EventTable(wizstd)
  //*)
  END_EVENT_TABLE()wizstd::wizstd(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				  const wxSize & size)
{
  //(*Initialize(wizstd)
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
    new wxStaticText(Panel3, ID_STATICTEXT1, _("Padroniza"), wxPoint(16, 8), wxDefaultSize, 0,
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
  filenamectrl =
    new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(40, 104), wxSize(400, 27),
		   wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  openfile =
    new wxBitmapButton(Panel2, ID_BITMAPBUTTON1,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),
						wxART_BUTTON), wxPoint(448, 104), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
  Panel4 =
    new wxPanel(Listbook1, ID_PANEL4, wxPoint(89, 30), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL4"));
  Grid1 = new wxGrid(Panel4, ID_GRID1, wxPoint(112, 24), wxSize(304, 160), 0, _T("ID_GRID1"));
  Grid1->CreateGrid(1, 3);
  Grid1->EnableEditing(true);
  Grid1->EnableGridLines(true);
  Grid1->SetColLabelSize(20);
  Grid1->SetRowLabelSize(40);
  Grid1->SetColLabelValue(0, _("Entrada"));
  Grid1->SetColLabelValue(1, _("Processo"));
  Grid1->SetColLabelValue(2, _("Saída"));
  Grid1->SetDefaultCellFont(Grid1->GetFont());
  Grid1->SetDefaultCellTextColour(Grid1->GetForegroundColour());
  Button1 =
    new wxButton(Panel4, ID_BUTTON3, _("Adiciona\n todos\ncampos"), wxPoint(16, 96), wxDefaultSize,
		 0, wxDefaultValidator, _T("ID_BUTTON3"));
  btnadd =
    new wxButton(Panel4, ID_BUTTON4, _("Adiciona"), wxPoint(104, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON4"));
  btndel =
    new wxButton(Panel4, ID_BUTTON5, _("Remove"), wxPoint(224, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON5"));
  btnclear =
    new wxButton(Panel4, ID_BUTTON6, _("Limpa"), wxPoint(344, 208), wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON6"));
  BitmapButton1 =
    new wxBitmapButton(Panel4, ID_BITMAPBUTTON2,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),
						wxART_BUTTON), wxPoint(424, 40), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
  BitmapButton2 =
    new wxBitmapButton(Panel4, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),
						wxART_BUTTON), wxPoint(424, 80), wxDefaultSize,
		       wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
  BitmapButton2->SetDefault();
  Panel5 =
    new wxPanel(Listbook1, ID_PANEL5, wxPoint(159, 7), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL5"));
  StaticText3 =
    new wxStaticText(Panel5, ID_STATICTEXT3, _("Exclusões:"), wxPoint(48, 24), wxDefaultSize, 0,
		     _T("ID_STATICTEXT3"));
  StaticText4 =
    new wxStaticText(Panel5, ID_STATICTEXT4, _("Pontuação:"), wxPoint(48, 96), wxDefaultSize, 0,
		     _T("ID_STATICTEXT4"));
  exclctrl =
    new wxTextCtrl(Panel5, ID_TEXTCTRL3, _("DE,DO,DA,DOS,DAS"), wxPoint(48, 48), wxSize(184, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL3"));
  punctctrl =
    new wxTextCtrl(Panel5, ID_TEXTCTRL4, _("()/\'.,;:-"), wxPoint(48, 120), wxDefaultSize, 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL4"));
  StaticText5 =
    new wxStaticText(Panel5, ID_STATICTEXT5, _("Apêndices:"), wxPoint(48, 168), wxDefaultSize, 0,
		     _T("ID_STATICTEXT5"));
  sufixctrl =
    new wxTextCtrl(Panel5, ID_TEXTCTRL5, _("JUNIOR JR FILHO FO NETO SOBRINHO"), wxPoint(48, 192),
		   wxSize(264, 27), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
  Panel6 =
    new wxPanel(Listbook1, ID_PANEL6, wxPoint(175, 19), wxDefaultSize, wxTAB_TRAVERSAL,
		_T("ID_PANEL6"));
  errrep =
    new wxTextCtrl(Panel6, ID_TEXTCTRL2, wxEmptyString, wxPoint(40, 32), wxSize(350, 176),
		   wxTE_MULTILINE | wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
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
  Listbook1->AddPage(Panel4, _("Opções gerais"), false);
  Listbook1->AddPage(Panel5, _("Opções adicionais"), false);
  Listbook1->AddPage(Panel6, _("Finaliza"), false);
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
    new wxFileDialog(this, _("Selecione o arquivo"), wxEmptyString, wxEmptyString, _("*.dat"),
		     wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition,
		     wxDefaultSize, _T("wxFileDialog"));
  SetSizer(FlexGridSizer1);
  Layout();

  Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnopenfileClick);
  Connect(ID_GRID1, wxEVT_GRID_EDITOR_SHOWN, (wxObjectEventFunction) & wizstd::OnGrid1EditorShown);
  Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnButton1Click);
  Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnbtnaddClick);
  Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnbtndelClick);
  Connect(ID_BUTTON6, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnbtnclearClick);
  Connect(ID_BITMAPBUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnBitmapButton1Click);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnBitmapButton2Click);
  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & wizstd::OnokbtnClick);
  Connect(ID_LISTBOOK1, wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,
	  (wxObjectEventFunction) & wizstd::OnListbook1PageChanged);
  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnbackbtnClick);
  Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & wizstd::OnfwdbtnClick);
  //*)

  Grid1->SetDefaultCellOverflow(false);

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

wizstd::~wizstd()
{
  //(*Destroy(wizstd)
  //*)
}

void
wizstd::OnopenfileClick(wxCommandEvent & event)
{
  ntable t;
  FileDialog1->SetWildcard(_T("*") + t.defdbext());
  if (FileDialog1->ShowModal() == wxID_OK)
  {
    filenamectrl->SetValue(FileDialog1->GetPath());
    wxString fname = filenamectrl->GetValue();
    if (wxFileExists(fname))
    {
      fieldnames.Clear();
      fieldtypes.Clear();
      try
      {
	ntable in_dbf;
	in_dbf.open(fname);
	int nflds = in_dbf.getnumfields();
	for (int i = 0; i < nflds; i++)
	{
	  wxString aux = in_dbf.getfieldname(i);
	  dbtable::ftype fltype = in_dbf.getfieldtype(aux);
	  if (fltype == dbtable::CHAR || fltype == dbtable::INT ||
	      fltype == dbtable::FLOAT || fltype == dbtable::DATE || fltype == dbtable::BOOLEAN)
	  {
	    fieldnames.Add(aux);
	    switch (fltype)
	    {
	    case dbtable::CHAR:
	      fieldtypes.Add(_T("C"));
	      break;
	    case dbtable::INT:
	      fieldtypes.Add(_T("I"));
	      break;
	    case dbtable::FLOAT:
	      fieldtypes.Add(_T("F"));
	      break;
	    case dbtable::DATE:
	      fieldtypes.Add(_T("D"));
	      break;
	    case dbtable::BOOLEAN:
	      fieldtypes.Add(_T("B"));
	      break;
	    }
	  }
	}
	in_dbf.close();
      }
      catch( ...)
      {
      };
      int nlines = fieldnames.Count();
      wxString listoffields = fieldnames[0];
      for (int i = 1; i < nlines; i++)
	listoffields = listoffields + _T(",") + fieldnames[i];
      wxGridCellAttr *myAttr = new wxGridCellAttr();
      wxGridCellChoiceEditor *editor = new wxGridCellChoiceEditor();
      myAttr->SetEditor(editor);
      editor->SetParameters(listoffields);
      Grid1->SetColAttr(0, myAttr);
      readcfg(fname);
    }
  }
}

void
wizstd::OnbackbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(false);
}

void
wizstd::OnfwdbtnClick(wxCommandEvent & event)
{
  Listbook1->AdvanceSelection(true);
}

void
wizstd::OnbtnaddClick(wxCommandEvent & event)
{
  Grid1->AppendRows();
}

void
wizstd::OnbtndelClick(wxCommandEvent & event)
{
  //int current = Grid1->GetGridCursorRow();
  wxArrayInt selrows = Grid1->GetSelectedRows();
  for (int i = 0; i < selrows.Count(); i++)
    Grid1->DeleteRows(selrows[i]);
}

void
wizstd::OnButton1Click(wxCommandEvent & event)
{
  wxString aux;
  for (int i = 0; i < fieldnames.Count(); i++)
  {
    aux = fieldnames[i];
    if ((i + 1) > Grid1->GetNumberRows())
      Grid1->AppendRows();
    Grid1->SetCellValue(i, 0, aux);
    Grid1->SetCellValue(i, 2, aux);
    aux = fieldtypes[i];
    switch ((char) aux[0])
    {
    case _T('I'):
      Grid1->SetCellValue(i, 1, _T("NUMERO"));
      break;
    case _T('F'):
      Grid1->SetCellValue(i, 1, _T("NUMERO"));
      break;
    case _T('D'):
      Grid1->SetCellValue(i, 1, _T("DATASC"));
      break;
    case _T('B'):
      Grid1->SetCellValue(i, 1, _T("LOGICO"));
      break;
    }
  }
}

void
wizstd::OnbtnclearClick(wxCommandEvent & event)
{
  int current = Grid1->GetGridCursorRow();
  Grid1->SetCellValue(current, 0, _T(""));
  Grid1->SetCellValue(current, 1, _T(""));
  Grid1->SetCellValue(current, 2, _T(""));
}

void
wizstd::OnGrid1EditorShown(wxGridEvent & event)
{
  int row = Grid1->GetGridCursorRow();
  int col = Grid1->GetGridCursorCol();
  if (col == 1)
  {
    wxString aux = Grid1->GetCellValue(row, 0);
    int nflds = fieldnames.Count();
    int i;
    for (i = 0; i < nflds; i++)
    {
      if (fieldnames[i] == aux)
	break;
    }
    if (i < nflds)
    {
      if (fieldtypes[i] == _T("C") /*|| fieldtypes[i] == _T("N") */ )
      {
	setoptsdlg wizdlg(this);
	wizdlg.setparms(exclctrl->GetValue(), punctctrl->GetValue(), sufixctrl->GetValue());
	wxString fname = filenamectrl->GetValue();
	if (wxFileExists(fname))
	{
	  try
	  {
	    ntable in_dbf;
	    in_dbf.open(fname);
	    in_dbf.first();
	    wxString fldvalue;
	    for (int i = 0; i < 20; i++)
	    {
	      fldvalue = in_dbf.getstring(aux) + _T("\n");
	      wizdlg.inlist->AppendText(fldvalue);
	      wizdlg.examples->AppendText(fldvalue);
	      in_dbf.next();
	      if (in_dbf.eof())
		break;
	    }
	    wizdlg.inlist->SetInsertionPoint(0);
	    wizdlg.examples->SetInsertionPoint(0);
	    in_dbf.close();
	  }
	  catch( ...)
	  {
	  }
	}
	wxString opt = Grid1->GetCellValue(row, 1);
	if (opt == _("CDATA0"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA1"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA2"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA3"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA4"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA5"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA6"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA7"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA8"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATA9"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("CDATAA"))
	{
	  wizdlg.RadioBox1->SetSelection(0);
	  wizdlg.RadioBox2->Enable();
	}
	else if (opt == _("NADA"))
	{
	  wizdlg.RadioBox1->SetSelection(4);
	}
	else if (opt == _("CNOMES"))
	{
	  wizdlg.RadioBox1->SetSelection(1);
	}
	else if (opt == _("CPONTO"))
	{
	  wizdlg.RadioBox1->SetSelection(2);
	}
	else if (opt == _("FNOMEP"))
	{
	  wizdlg.RadioBox1->SetSelection(5);
	}
	else if (opt == _("FNOMEU"))
	{
	  wizdlg.RadioBox1->SetSelection(5);
	}
	else if (opt == _("FNOMEI"))
	{
	  wizdlg.RadioBox1->SetSelection(5);
	}
	else if (opt == _("FNOMEA"))
	{
	  wizdlg.RadioBox1->SetSelection(5);
	}
	else if (opt == _("PBLOCO"))
	{
	  wizdlg.RadioBox1->SetSelection(5);
	}
	else if (opt == _("UBLOCO"))
	{
	  wizdlg.RadioBox1->SetSelection(5);
	}
	else if (opt.Mid(0, 6) == _("SUBSTR"))
	{
	  wizdlg.RadioBox1->SetSelection(3);
	  wizdlg.SpinCtrl1->Enable();
	  wizdlg.SpinCtrl2->Enable();
	  wizdlg.StaticText5->Enable();
	  wizdlg.StaticText6->Enable();
	  wxString aux = _("SUBSTR");
	  int nc = aux.Len();
	  opt.Remove(0, nc + 1);
	  wxArrayString vals = wxStringTokenize(opt, _T("-"));
	  int nv = vals.Count();
	  long num;
	  if (nv)
	  {
	    if (vals[0].ToLong(&num))
	      wizdlg.SpinCtrl1->SetValue((int) num - 1);
	  }
	  else
	    wizdlg.SpinCtrl1->SetValue((int) num - 1);
	  if (nv > 1)
	  {
	    if (vals[1].ToLong(&num))
	      wizdlg.SpinCtrl2->SetValue((int) num);
	  }
	  else
	    wizdlg.SpinCtrl2->SetValue(1);
	}
	else if (opt.Mid(0, 5) == _("TROCA"))
	{
	  wizdlg.RadioBox1->SetSelection(6);
	  wizdlg.StaticText1->Enable();
	  wizdlg.Grid1->Enable();
	  wizdlg.Button1->Enable();
	  wxString aux = _("TROCA");
	  int nc = aux.Len();
	  opt.Remove(0, nc + 1);
	  wxArrayString lines = wxStringTokenize(opt, _T("^"));
	  int ref = 0;
	  for (int i = 0; i < lines.Count(); i++)
	  {
	    if (!lines[i].IsEmpty())
	    {
	      wxArrayString cells = wxStringTokenize(lines[i], _T("|"));
	      if (cells.Count() == 2)
	      {
		if (ref < 10)
		{
		  wizdlg.Grid1->SetCellValue(ref, 0, cells[0]);
		  wizdlg.Grid1->SetCellValue(ref, 1, cells[1]);
		}
		ref++;
	      }
	    }
	  }
	}
	wizdlg.provideexamples();
	if (wizdlg.ShowModal() == wxID_OK)
	{
	  int selected;
	  selected = wizdlg.RadioBox1->GetSelection();
	  int sel2, beg, nchars;
	  wxString in, out;

	  switch (selected)
	  {
	  case 0:
	    sel2 = wizdlg.RadioBox2->GetSelection();
	    switch (sel2)
	    {
	    case 0:
	      aux = _("CDATA0");
	      break;
	    case 1:
	      aux = _("CDATA1");
	      break;
	    case 2:
	      aux = _("CDATA2");
	      break;
	    case 3:
	      aux = _("CDATA3");
	      break;
	    case 4:
	      aux = _("CDATA4");
	      break;
	    case 5:
	      aux = _("CDATA5");
	      break;
	    case 6:
	      aux = _("CDATA6");
	      break;
	    case 7:
	      aux = _("CDATA7");
	      break;
	    case 8:
	      aux = _("CDATA8");
	      break;
	    case 9:
	      aux = _("CDATA9");
	      break;
	    case 10:
	      aux = _("CDATAA");
	      break;
	    case 11:
	      aux = _("NADA");	//No conversion needed
	      break;
	    }
	    break;
	  case 1:
	    aux = _("CNOMES");
	    break;
	  case 2:
	    aux = _("CPONTO");
	    break;
	  case 3:
	    aux = _("SUBSTR %d-%d");
	    beg = wizdlg.SpinCtrl1->GetValue() - 1;
	    nchars = wizdlg.SpinCtrl2->GetValue();
	    aux.Printf(aux, beg, nchars);
	    break;
	  case 4:
	    aux = _("NADA");
	    break;
	  case 5:
	    aux = _("FNOMEP");
	    break;
	  case 6:
	    aux = _("TROCA ");
	    for (int i = 0; i < 10; i++)
	    {
	      in = wizdlg.Grid1->GetCellValue(i, 0);
	      if (in.IsEmpty())
		break;
	      out = wizdlg.Grid1->GetCellValue(i, 1);
	      aux = aux + _T("^") + in + _T("|") + out;
	    }
	    aux = aux + _T("^");
	    break;
	  }
	  if (aux != _("FNOMEP"))
	    Grid1->SetCellValue(row, col, aux);
	  else
	  {
	    aux = Grid1->GetCellValue(row, 0);
	    int answer = wxMessageBox(_("Cria só os campos de blocagem\n(PBLOCO e UBLOCO)?"),
				      _("OPÇÃO DE SUBDIVISÃO"),
				      wxYES_NO);
	    if (answer == wxYES)
	    {
	      Grid1->InsertRows(row, 1);
	      Grid1->SetCellValue(row, 1, _("PBLOCO"));
	      Grid1->SetCellValue(row, 2, _("PBLOCO"));
	      Grid1->SetCellValue(row, 0, aux);
	      Grid1->SetCellValue(row + 1, 1, _("UBLOCO"));
	      Grid1->SetCellValue(row + 1, 2, _("UBLOCO"));
	    }
	    else
	    {
	      Grid1->InsertRows(row, 5);
	      Grid1->SetCellValue(row, 1, _("FNOMEP"));
	      Grid1->SetCellValue(row, 0, aux);
	      Grid1->SetCellValue(row, 2, _("FNOMEP"));
	      Grid1->SetCellValue(row + 1, 1, _("FNOMEU"));
	      Grid1->SetCellValue(row + 1, 0, aux);
	      Grid1->SetCellValue(row + 1, 2, _("FNOMEU"));
	      Grid1->SetCellValue(row + 2, 1, _("FNOMEI"));
	      Grid1->SetCellValue(row + 2, 0, aux);
	      Grid1->SetCellValue(row + 2, 2, _("FNOMEI"));
	      Grid1->SetCellValue(row + 3, 1, _("FNOMEA"));
	      Grid1->SetCellValue(row + 3, 0, aux);
	      Grid1->SetCellValue(row + 3, 2, _("FNOMEA"));
	      Grid1->SetCellValue(row + 4, 1, _("PBLOCO"));
	      Grid1->SetCellValue(row + 4, 0, aux);
	      Grid1->SetCellValue(row + 4, 2, _("PBLOCO"));
	      Grid1->SetCellValue(row + 5, 1, _("UBLOCO"));
	      Grid1->SetCellValue(row + 5, 2, _("UBLOCO"));
	    }
	  }
	}
      }
      else if (fieldtypes[i] == _T("I") || (fieldtypes[i] == _T("F")))
	Grid1->SetCellValue(row, 1, _T("NUMERO"));
      else if (fieldtypes[i] == _T("D"))
	Grid1->SetCellValue(row, 1, _T("DATASC"));
      else if (fieldtypes[i] == _T("B"))
	Grid1->SetCellValue(row, 1, _T("LOGICO"));
      Grid1->Update();
    }
  }
  event.Skip();
}

void
wizstd::readcfg(wxString fname)
{
  wxFileName dbfilename = wxFileName(fname);
  dbfilename.SetExt(_T("stdcfg"));
  wxString name = dbfilename.GetFullPath();
  wxString aux;
  long nlines;
  if (wxFileExists(name))
  {
    int answer =
      wxMessageBox(_
		   ("Já existe uma configuração associada\na este arquivo, deseja utilizá-la?"),
_("CONFIGURAÇÃO DISPONÍVEL"),
wxYES_NO);
    if (answer == wxYES)
    {
      wxFileConfig *cfgfile =
	new wxFileConfig(_T(""), _T(""), name, _T(""), wxCONFIG_USE_LOCAL_FILE);
      aux = _T("");
      cfgfile->Read(_T("GENERAL/EXCL"), &aux);
      exclctrl->SetValue(aux);
      aux = _T("");
      cfgfile->Read(_T("GENERAL/PUNCT"), &aux);
      punctctrl->SetValue(aux);
      aux = _T("");
      cfgfile->Read(_T("GENERAL/SUFFIX"), &aux);
      sufixctrl->SetValue(aux);
      nlines = 1;
      cfgfile->Read(_T("OPTIONS/NLINES"), &nlines);
      int glines = Grid1->GetNumberRows();
      if (glines > (int) nlines)
      {
	glines -= (int) nlines;
	Grid1->DeleteRows(0, glines);
      }
      else if (glines < (int) nlines)
      {
	glines = (int) nlines - glines;
	Grid1->AppendRows(glines);
      }
      for (int i = 0; i < nlines; i++)
      {
	wxString tmp;
	aux.Printf(_T("OPTIONS/INVAR%d"), i);
	tmp = _T("");
	cfgfile->Read(aux, &tmp);
	Grid1->SetCellValue(i, 0, tmp);
	aux.Printf(_T("OPTIONS/PROC%d"), i);
	tmp = _T("");
	cfgfile->Read(aux, &tmp);
	Grid1->SetCellValue(i, 1, tmp);
	aux.Printf(_T("OPTIONS/OUTVAR%d"), i);
	tmp = _T("");
	cfgfile->Read(aux, &tmp);
	Grid1->SetCellValue(i, 2, tmp);
      }
      delete cfgfile;
    }
  }
}

void
wizstd::OnokbtnClick(wxCommandEvent & event)
{
  wxString fname = filenamectrl->GetValue();
  if (wxFileExists(fname))
  {
    wxFileName tmp = wxFileName(fname);
    tmp.SetExt(_T("stdcfg"));
    fname = tmp.GetFullPath();
    wxFileConfig *cfgfile =
      new wxFileConfig(_T(""), _T(""), fname, _T(""), wxCONFIG_USE_LOCAL_FILE);
    cfgfile->Write(_T("GENERAL/FILENAME"), filenamectrl->GetValue());
    cfgfile->Write(_T("GENERAL/EXCL"), exclctrl->GetValue());
    cfgfile->Write(_T("GENERAL/PUNCT"), punctctrl->GetValue());
    cfgfile->Write(_T("GENERAL/SUFFIX"), sufixctrl->GetValue());
    int nlines = Grid1->GetNumberRows();
    cfgfile->Write(_T("OPTIONS/NLINES"), nlines);
    wxString aux;
    for (int i = 0; i < nlines; i++)
    {
      aux.Printf(_T("OPTIONS/INVAR%d"), i);
      cfgfile->Write(aux, Grid1->GetCellValue(i, 0));
      aux.Printf(_T("OPTIONS/PROC%d"), i);
      cfgfile->Write(aux, Grid1->GetCellValue(i, 1));
      aux.Printf(_T("OPTIONS/OUTVAR%d"), i);
      cfgfile->Write(aux, Grid1->GetCellValue(i, 2));
    }
    delete cfgfile;
  }
  ops_log log;
  log.log_event(_T("STDC"), filenamectrl->GetValue());
  event.Skip();
}

void
wizstd::analyze(void)
{
  errrep->Clear();

  int nopts = Grid1->GetNumberRows();
  wxString tmp, ax;
  wxArrayString prevflds;
  for (int i = 0; i < nopts; i++)
  {
    if (Grid1->GetCellValue(i, 0).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem campo de entrada\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    else
    {
      ax = Grid1->GetCellValue(i, 0);
      int j;
      int nflds = fieldnames.Count();
      for (j = 0; j < nflds; j++)
	if (ax == fieldnames[j])
	  break;
      if (j >= nflds)
      {
	tmp.Printf(_("Linha %d com campo de entrada inválido\n"), (i + 1));
	errrep->AppendText(tmp);
      }
    }
    if (Grid1->GetCellValue(i, 1).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem tipo de processo\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    if (Grid1->GetCellValue(i, 2).IsEmpty())
    {
      tmp.Printf(_("Linha %d sem campo de saída\n"), (i + 1));
      errrep->AppendText(tmp);
    }
    else
    {
      ax = Grid1->GetCellValue(i, 2);
      int n, nflds = prevflds.Count();
      for (n = 0; n < nflds; n++)
	if (prevflds[n] == ax.Upper())
	  break;
      if (n < nflds)
      {
	tmp.Printf(_("Linha %d tem campo de saída repetido\n"), (i + 1));
	errrep->AppendText(tmp);
      }
      prevflds.Add(ax.Upper());
    }
  }
  if (nopts == 0)
    errrep->AppendText(_("Nenhum critério de padronização definido\n"));
}

void
wizstd::OnListbook1PageChanged(wxNotebookEvent & event)
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
wizstd::OnBitmapButton1Click(wxCommandEvent & event)	// row up
{
  int row = Grid1->GetGridCursorRow();
  if (row > 0)
    if (Grid1->GetNumberRows() > row)
    {
      wxString swap;
      swap = Grid1->GetCellValue(row, 0);
      Grid1->SetCellValue(row, 0, Grid1->GetCellValue(row - 1, 0));
      Grid1->SetCellValue(row - 1, 0, swap);
      swap = Grid1->GetCellValue(row, 1);
      Grid1->SetCellValue(row, 1, Grid1->GetCellValue(row - 1, 1));
      Grid1->SetCellValue(row - 1, 1, swap);
      swap = Grid1->GetCellValue(row, 2);
      Grid1->SetCellValue(row, 2, Grid1->GetCellValue(row - 1, 2));
      Grid1->SetCellValue(row - 1, 2, swap);
      Grid1->SetGridCursor(row - 1, 0);
    }
}

void
wizstd::OnBitmapButton2Click(wxCommandEvent & event)	// row down
{
  int row = Grid1->GetGridCursorRow();
  if (row < (Grid1->GetNumberRows() - 1))
    if (Grid1->GetNumberRows() > row)
    {
      wxString swap;
      swap = Grid1->GetCellValue(row, 0);
      Grid1->SetCellValue(row, 0, Grid1->GetCellValue(row + 1, 0));
      Grid1->SetCellValue(row + 1, 0, swap);
      swap = Grid1->GetCellValue(row, 1);
      Grid1->SetCellValue(row, 1, Grid1->GetCellValue(row + 1, 1));
      Grid1->SetCellValue(row + 1, 1, swap);
      swap = Grid1->GetCellValue(row, 2);
      Grid1->SetCellValue(row, 2, Grid1->GetCellValue(row + 1, 2));
      Grid1->SetCellValue(row + 1, 2, swap);
      Grid1->SetGridCursor(row + 1, 0);
    }
}
