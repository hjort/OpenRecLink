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
// Nome:        SQLexportdlg.cpp
// Propósito:   Classe (janela) para exportar dados para SQL
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "SQLexportdlg.h"

#include "ops_log.h"

//(*InternalHeaders(SQLexportdlg)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

#include <wx/filename.h>
#include <wx/fileconf.h>

//(*IdInit(SQLexportdlg)
const long
  SQLexportdlg::ID_TEXTCTRL4 = wxNewId();
const long
  SQLexportdlg::ID_BITMAPBUTTON1 = wxNewId();
const long
  SQLexportdlg::ID_STATICTEXT3 = wxNewId();
const long
  SQLexportdlg::ID_GAUGE1 = wxNewId();
const long
  SQLexportdlg::ID_STATICTEXT2 = wxNewId();
const long
  SQLexportdlg::ID_STATICTEXT5 = wxNewId();
const long
  SQLexportdlg::ID_BITMAPBUTTON3 = wxNewId();
const long
  SQLexportdlg::ID_STATICLINE1 = wxNewId();
const long
  SQLexportdlg::ID_STATICTEXT1 = wxNewId();
const long
  SQLexportdlg::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SQLexportdlg, wxDialog)
  //(*EventTable(SQLexportdlg)
  //*)
  END_EVENT_TABLE()SQLexportdlg::SQLexportdlg(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					      const wxSize & size)
{
  //(*Initialize(SQLexportdlg)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, wxID_ANY, _("Cria arquivos de exportação SQL"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  SetClientSize(wxSize(500, 259));
  FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
  Panel1 =
    new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(480, 205), wxTAB_TRAVERSAL,
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
    new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(24, 160), wxSize(424, 28), 0, wxDefaultValidator,
		_T("ID_GAUGE1"));
  StaticText2 =
    new wxStaticText(Panel1, ID_STATICTEXT2, _("Registro corrente:"), wxPoint(192, 112),
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  StaticText5 =
    new wxStaticText(Panel1, ID_STATICTEXT5, _T("0"), wxPoint(328, 112), wxSize(120, 17),
		     wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
  BitmapButton2 =
    new wxBitmapButton(Panel1, ID_BITMAPBUTTON3,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR
						(_T("wxART_EXECUTABLE_FILE")), wxART_BUTTON),
		       wxPoint(24, 104), wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator,
		       _T("ID_BITMAPBUTTON3"));
  BitmapButton2->Disable();
  BitmapButton2->SetToolTip(_("Executa"));
  StaticLine1 =
    new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(0, 208), wxSize(480, 0), wxLI_HORIZONTAL,
		     _T("ID_STATICLINE1"));
  StaticText1 =
    new wxStaticText(Panel1, ID_STATICTEXT1, _("Aguardando..."), wxPoint(16, 64), wxDefaultSize, 0,
		     _T("ID_STATICTEXT1"));
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
	  (wxObjectEventFunction) & SQLexportdlg::OnopenoutfileClick);
  Connect(ID_BITMAPBUTTON3, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & SQLexportdlg::OnBitmapButton2Click);
  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED,
	  (wxObjectEventFunction) & SQLexportdlg::OnBitmapButton1Click);
  //*)

  compname = _T("");
  refname = _T("");
  matchname = _T("");
}

SQLexportdlg::~SQLexportdlg()
{
  //(*Destroy(SQLexportdlg)
  //*)
}

void
SQLexportdlg::OnopenoutfileClick(wxCommandEvent & event)
{
  selectcfgfile();
}

void
SQLexportdlg::OnBitmapButton2Click(wxCommandEvent & event)
{
  BitmapButton2->Disable();
  execute();
}

void
SQLexportdlg::OnBitmapButton1Click(wxCommandEvent & event)
{
  EndModal(wxID_OK);
}

void
SQLexportdlg::selectcfgfile(void)
{
  FileDialog1->SetWildcard(_T("*.lnkcfg"));
  FileDialog1->SetMessage(_("Selecione o arquivo de configuração"));
  //FileDialog1->SetStyle(wxOPEN | wxFILE_MUST_EXIST);

  if (FileDialog1->ShowModal() == wxID_OK)
  {
    wxString fname = FileDialog1->GetPath();
    if (wxFileExists(fname))
    {
      outfilenamectrl->SetValue(fname);
      if (loadcfgfile())
	BitmapButton2->Enable();
      else
      {
	outfilenamectrl->SetValue(_T(""));
	BitmapButton2->Disable();
      }
    }
    else
    {
      outfilenamectrl->SetValue(_T(""));
      BitmapButton2->Disable();
    }
  }
}

bool SQLexportdlg::loadcfgfile(void)
{
  bool
    retval = false;
  wxString
    fname = outfilenamectrl->GetValue();
  if (!fname.IsEmpty())
  {
    wxFileConfig *
      cfgfile = new wxFileConfig(_T(""), _T(""), fname, _T(""), wxCONFIG_USE_LOCAL_FILE);
    cfgfile->Read(_T("FILES/COMPNAME"), &compname);
    cfgfile->Read(_T("FILES/REFNAME"), &refname);
    delete
      cfgfile;
    wxFileName
      matchfile = wxFileName(fname);
    ntable
      t;
    matchfile.SetExt(t.defdbext().Right(3));
    fname = matchfile.GetName();
    fname = fname + _T("SCORE");
    matchfile.SetName(fname);
    matchname = matchfile.GetFullPath();
    retval = (!compname.IsEmpty() && !refname.IsEmpty() &&
	      wxFileExists(compname) && wxFileExists(refname) && wxFileExists(matchname));
  }
  return retval;
}

void
SQLexportdlg::write(const char *line)
{
  output << line << std::endl;
}

void
SQLexportdlg::write(wxString line)
{
  output << line.mb_str(wxConvUTF8) << std::endl;
}

void
SQLexportdlg::click(void)
{
  clicker++;
  if (clicker > 99)
  {
    clicker = 0;
    wxYieldIfNeeded();
  }
}

bool SQLexportdlg::exportdata(wxString fname)
{
  bool
    retval = false;
  ntable
    tbl;
  try
  {
    tbl.open(fname);
    long
      nrecs = tbl.gettotalrecs();
    Gauge1->SetRange((int) nrecs);
    wxFileName
      oname = wxFileName(fname);
    oname.SetExt(_T("csv"));
    fname = oname.GetFullPath();
    output.open(fname.mb_str(wxConvUTF8));
    tbl.first();
    long
      recno = 1;
    wxString
      lbl;
    clicker = 0;
    wxString
      record = _T("RECNO");
    for (int i = 0; i < tbl.getnumfields(); i++)
      record = record + _T(",") + tbl.getfieldname(i);
    write(record);
    lbl.Printf(_T("%d"), 0);
    StaticText5->SetLabel(lbl);
    wxYieldIfNeeded();
    while (!tbl.eof())
    {
      Gauge1->SetValue(recno);
      lbl.Printf(_T("%d"), recno);
      StaticText5->SetLabel(lbl);
      click();
      record.Printf(_T("\"%d\""), recno++);
      for (int i = 0; i < tbl.getnumfields(); i++)
	record = record + _T(",\"") + tbl.getstring(tbl.getfieldname(i)) + _T("\"");
      write(record);
      tbl.next();
    }
    output.close();
    tbl.close();
    retval = true;
  } catch( ...)
  {
  };
  return retval;
}

void
SQLexportdlg::exporthdr(wxString fname, bool isscore)
{
  wxFileName oname;
  wxString line;

  try
  {
    if (isscore)
    {
      oname = wxFileName(outfilenamectrl->GetValue());
      oname.SetExt(_T("csv"));
      wxString aux = oname.GetName();
      oname.SetName(aux + _T("SCORE"));
      line = _T("CREATE TABLE ") + aux + _T("(");
      write(line);
      line = _T("\tRECNO char(8) PRIMARY KEY NOT NULL,");
      write(line);
      line = _T("\tCOMPREC char(8),");
      write(line);
      line = _T("\tREFREC char(8),");
      write(line);
      line = _T("\tSCORE double precision,");
      write(line);
      line = _T("\tMATCH char(1)");
      write(line);
      line = _T(");");
      write(line);
      line = _T("");
      write(line);
      line = _T("COPY ") + aux + _T(" FROM \'") + oname.GetFullPath() + _T("\' WITH CSV HEADER;");
      write(line);
      line = _T("");
      write(line);
      line = _T("-- Cria índice");
      write(line);
      line = _T("CREATE INDEX ") + aux + _T("_scores on ") + aux + _T(" (SCORE DESC);");
      write(line);
    }
    else
    {
      ntable tbl;
      tbl.open(fname);
      oname = wxFileName(fname);
      oname.SetExt(_T("csv"));
      line = _T("CREATE TABLE ") + oname.GetName() + _T("(");
      write(line);
      wxString aux;
      line = _T("\tRECNO char(8) PRIMARY KEY NOT NULL,");
      write(line);
      int nflds = tbl.getnumfields();
      for (int i = 0; i < nflds; i++)
      {
	aux = tbl.getfieldname(i);
	line = _T("\t") + aux;
	switch (tbl.getfieldtype(i))
	{
	case dbtable::CHAR:
	  aux.Printf(_T(" char(%d)"), tbl.getfieldlen(i));
	  break;
	case dbtable::INT:
	  aux = _T(" int8");
	  break;
	case dbtable::FLOAT:
	  aux = _T(" float8");
	  break;
	case dbtable::BOOLEAN:
	  aux = _T(" bool");
	  break;
	case dbtable::DATE:
	  aux = _T(" date");
	  break;
	default:
	  aux.Printf(_T(" char(%d)"), tbl.getfieldlen(i));
	  break;
	}
	line += aux;
	if (i < (nflds - 1))
	  line += _T(",");
	write(line);
      }
      line = _T(");");
      write(line);
      line = _T("");
      write(line);
      line =
	_T("COPY ") + oname.GetName() + _T(" FROM \'") + oname.GetFullPath() +
	_T("\' WITH CSV HEADER;");
      write(line);
      tbl.close();
    }
  }
  catch( ...)
  {
  };
}

void
SQLexportdlg::exportcommand(void)
{
  ntable tbl;
  try
  {
    wxString sqlname = outfilenamectrl->GetValue();
    wxFileName oname = wxFileName(sqlname);
    sqlname = oname.GetName();
    oname = wxFileName(compname);
    wxString comptbl = oname.GetName();
    oname = wxFileName(refname);
    wxString reftbl = oname.GetName();
    wxString line = _T("SELECT ");
    write(line);
    line = _T("\t") + sqlname + _T(".SCORE,");
    write(line);
    line = _T("\t") + comptbl + _T(".RECNO,");
    write(line);
    tbl.open(compname);
    int nflds = tbl.getnumfields();
    for (int i = 0; i < nflds; i++)
    {
      line = _T("\t") + comptbl + _T(".") + tbl.getfieldname(i) + _T(",");
      write(line);
    }
    line = _T("\t") + reftbl + _T(".RECNO,");
    write(line);
    tbl.close();
    tbl.open(refname);
    nflds = tbl.getnumfields();
    for (int i = 0; i < nflds; i++)
    {
      line = _T("\t") + reftbl + _T(".") + tbl.getfieldname(i);
      if (i < (nflds - 1))
	line += _T(",");
      write(line);
    }
    line = _T("FROM ") + sqlname + _T(", ") + comptbl + _T(", ") + reftbl;
    write(line);
    line = _T("WHERE ") + sqlname + _T(".COMPREC = ") + comptbl + _T(".RECNO AND ") +
      sqlname + _T(".REFREC = ") + reftbl + _T(".RECNO");
    write(line);
    line = _T("ORDER BY ") + sqlname + _T(".SCORE DESC;");
    write(line);
    line = _T("");
    write(line);
  }
  catch( ...)
  {
  };
}

void
SQLexportdlg::execute(void)
{
  openoutfile->Disable();
  wxString msg = _T("Erro no processamento");

  StopWatch1.Start();
  wxBeginBusyCursor();

  try
  {
    StaticText1->SetLabel(_("Exportando arquivo de pares..."));
    if (exportdata(matchname))
    {
      StaticText1->SetLabel(_("Exportando arquivo de comparação..."));
      if (exportdata(compname))
      {
	StaticText1->SetLabel(_("Exportando arquivo de referência..."));
	if (exportdata(refname))
	{
	  StaticText1->SetLabel(_("Gerando comandos SQL..."));
	  wxYieldIfNeeded();
	  wxString sqlname = outfilenamectrl->GetValue();
	  wxFileName oname = wxFileName(sqlname);
	  oname.SetExt(_T("sql"));
	  sqlname = oname.GetName();
	  oname.SetName(_T("create_") + sqlname);
	  sqlname = oname.GetFullPath();
	  output.open(sqlname.mb_str(wxConvUTF8));
	  wxString line = _T("-- Este arquivo de comandos foi testado com PostgresSQL.");
	  write(line);
	  line = _T("-- Pode ser necessário editá-lo para usar com outros SGBDs.");
	  write(line);
	  line = _T("");
	  write(line);
	  line = _T("-- O campo MATCH da tabela de pares segue o seguinte padrão:");
	  write(line);
	  line = _T("-- + é par");
	  write(line);
	  line = _T("-- ? é dúvida");
	  write(line);
	  line = _T("-- - é não par");
	  write(line);
	  line = _T("-- * é ignorado");
	  write(line);
	  line = _T("");
	  write(line);
	  line = _T("-- Tabela de pares");
	  write(line);
	  sqlname = outfilenamectrl->GetValue();
	  exporthdr(sqlname, true);
	  line = _T("");
	  write(line);
	  line = _T("-- Tabela de comparação");
	  write(line);
	  exporthdr(compname);
	  line = _T("");
	  write(line);
	  line = _T("-- Tabela de referência");
	  write(line);
	  exporthdr(refname);
	  output.close();
	  sqlname = outfilenamectrl->GetValue();
	  oname = wxFileName(sqlname);
	  oname.SetExt(_T("sql"));
	  sqlname = oname.GetName();
	  oname.SetName(_T("inspect_") + sqlname);
	  sqlname = oname.GetFullPath();
	  output.open(sqlname.mb_str(wxConvUTF8));
	  line = _T("-- Este arquivo de comandos foi testado com PostgresSQL.");
	  write(line);
	  line = _T("-- Pode ser necessário editá-lo para usar com outros SGBDs.");
	  write(line);
	  line = _T("-- O comando abaixo faz um join lateral das duas");
	  write(line);
	  line = _T("-- tabelas com o arquivo de pares, permitindo a");
	  write(line);
	  line = _T("-- inspeção do relacionamento.");
	  write(line);
	  line = _T("-- Todos os campos são mostrados.");
	  write(line);
	  exportcommand();
	  output.close();
	  msg = _T("");
	}
	else
	  msg = _T("Erro ao exportar arquivo de referência.");
      }
      else
	msg = _T("Erro ao exportar arquivo de comparação.");
    }
    else
      msg = _T("Erro ao exportar arquivo de pares.");
  }
  catch( ...)
  {
  };

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
  log.log_event(_T("IMPDBF"), outfilenamectrl->GetValue(), timestring, msg);
}
