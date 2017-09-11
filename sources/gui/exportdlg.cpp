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
// Nome:        exportdlg.cpp
// Propósito:   Classe (janela) para executar exportação de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2010-01-23
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "exportdlg.h"
#include "ops_log.h"
  
//(*InternalHeaders(exportdlg)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)
  
#include <wx/msgdlg.h>
#include <wx/filename.h>
  
#include <iostream>
#include <fstream>
   
//(*IdInit(exportdlg)
  const long
  exportdlg::ID_STATICTEXT1 = wxNewId();
const long
  exportdlg::ID_STATICTEXT2 = wxNewId();
const long
  exportdlg::ID_TEXTCTRL2 = wxNewId();
const long
  exportdlg::ID_TEXTCTRL3 = wxNewId();
const long
  exportdlg::ID_GAUGE1 = wxNewId();
//*)
BEGIN_EVENT_TABLE(exportdlg, wxDialog) 
  //(*EventTable(exportdlg)
  //*)
  END_EVENT_TABLE() 
  exportdlg::exportdlg(wxWindow * parent, wxWindowID id, const wxPoint & pos,
			const wxSize & size) 
{
  
    //(*Initialize(exportdlg)
    wxFlexGridSizer * FlexGridSizer1;
  wxBoxSizer *
    BoxSizer2;
  wxBoxSizer *
    BoxSizer1;

  Create(parent, id, _("Exporta dados"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE,
	 _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
  BoxSizer2 = new wxBoxSizer(wxVERTICAL);
  StaticText1 =
    new wxStaticText(this, ID_STATICTEXT1, _("Separador de definições:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer2->Add(StaticText1, 1, wxTOP | wxBOTTOM | wxLEFT | wxALIGN_RIGHT, 5);
  StaticText2 =
    new wxStaticText(this, ID_STATICTEXT2, _("Separador de campos:"), wxDefaultPosition,
		     wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  BoxSizer2->Add(StaticText2, 1, wxTOP | wxBOTTOM | wxLEFT | wxALIGN_RIGHT, 5);
  FlexGridSizer1->Add(BoxSizer2, 1,
		      wxTOP | wxBOTTOM | wxLEFT | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL |
		      wxSHAPED, 5);
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  fldsep =
    new wxTextCtrl(this, ID_TEXTCTRL2, _(","), wxDefaultPosition, wxSize(27, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL2"));
  BoxSizer1->Add(fldsep, 1, wxTOP | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		 5);
  recsep =
    new wxTextCtrl(this, ID_TEXTCTRL3, _("|"), wxDefaultPosition, wxSize(27, 27), 0,
		   wxDefaultValidator, _T("ID_TEXTCTRL3"));
  BoxSizer1->Add(recsep, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  FlexGridSizer1->Add(BoxSizer1, 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxSHAPED, 5);
  Gauge1 =
    new wxGauge(this, ID_GAUGE1, 100, wxDefaultPosition, wxSize(202, 28), 0, wxDefaultValidator,
		_T("ID_GAUGE1"));
  FlexGridSizer1->Add(Gauge1, 1,
		      wxLEFT | wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  okbtn =
    new wxBitmapButton(this, wxID_OK,
		       wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),
						wxART_BUTTON), wxDefaultPosition, wxSize(36, 36),
		       wxBU_AUTODRAW, wxDefaultValidator, _T("wxID_OK"));
  okbtn->SetToolTip(_("Exporta"));
  FlexGridSizer1->Add(okbtn, 1, wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString,
		     wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition,
		     wxDefaultSize, _T("wxFileDialog"));
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);

  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & exportdlg::OnokbtnClick);
  //*)
}  exportdlg::~exportdlg() 
{
  
    //(*Destroy(exportdlg)
    //*)
} int

exportdlg::export_recs(void)
{
  bool wasopen = tbl->isopen();
  long curr_rec;
  int rslt = wxID_ABORT;
  if (!wasopen)
    
  {
    if (fname.IsEmpty())
      if (FileDialog1->ShowModal() == wxID_OK)
	fname = FileDialog1->GetPath();

    if (fname.IsEmpty())
      wxMessageBox(_("Selecione um arquivo de entrada"), _("ERRO"));
    
    else if (!wxFileExists(fname))
      wxMessageBox(_("O arquivo selecionado não existe"), _("ERRO"));
    else
      tbl->open(fname);
  }
  else
    curr_rec = tbl->getcurrentrec();
   if (tbl->isopen())
    
  {
    wxString rcsep = recsep->GetValue();
    wxString flsep = fldsep->GetValue();
    if (!flsep.IsEmpty() && !rcsep.IsEmpty() && (flsep != rcsep))
      
    {
      wxFileName tmp = fname;
      tmp.SetExt(_T("sql"));
      wxString expname = tmp.GetFullPath();
      std::ofstream exportfile;
      exportfile.open(expname.mb_str(wxConvUTF8));
      wxString line, aux;
      aux = _T("CREATE TABLE ") + tmp.GetName() + _T("(");
      exportfile << aux.mb_str(wxConvUTF8) << std::endl;
      aux = _T("\tRECNO char(8) PRIMARY KEY NOT NULL,");
      exportfile << aux.mb_str(wxConvUTF8) << std::endl;

      int nflds = tbl->getnumfields();
      for (int i = 0; i < nflds; i++)
      {
	aux = tbl->getfieldname(i);
	line = _T("\t") + aux;
	switch (tbl->getfieldtype(i))
	{
	case dbtable::CHAR:
	  aux.Printf(_T(" char(%d)"), tbl->getfieldlen(i));
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
	  aux.Printf(_T(" char(%d)"), tbl->getfieldlen(i));
	  break;
	}
	line += aux;
	if (i < (nflds - 1))
	  line += _T(",");
	exportfile << line.mb_str(wxConvUTF8) << std::endl;
      }
      aux = _T(");");
      exportfile << aux.mb_str(wxConvUTF8) << std::endl;
      exportfile.close();

      tmp.SetExt(_T("csv"));
      expname = tmp.GetFullPath();
      exportfile.open(expname.mb_str(wxConvUTF8));
      long maxrecs = tbl->gettotalrecs();
      Gauge1->SetRange(maxrecs);
      Gauge1->SetValue(0);
      if (tbl->getfieldnum(_T("RECNO")) == -1)
	aux = _T("RECNO,N,8,0|") + tbl->getheader();
      else
	aux = tbl->getheader();
      if ((rcsep != _T("|")) || (flsep != _T(",")))
	
      {
	int len = aux.Len();
	for (int i = 0; i < len; i++)
	  
	{
	  if ((rcsep != _T("|")) && (aux[i] == _T('|')))
	    aux[i] = rcsep[0];
	  
	  else if ((flsep != _T(",")) && (aux[i] == _T(',')))
	    aux[i] = flsep[0];
	}
      }
      exportfile << aux.mb_str(wxConvUTF8) << std::endl;
      tbl->first();
      long nrecs = 0l;
      int ticker = 0;
      while (!tbl->eof() && (nrecs <= maxrecs))
	
      {
	nrecs++;
	Gauge1->SetValue(nrecs);
	ticker++;
	if (ticker > 99)
	  
	{
	  ticker = 0;
	  wxYieldIfNeeded();
	}
	if (tbl->getfieldnum(_T("RECNO")) == -1)
	{
	  aux.Printf(_T("%d|"), nrecs);
	  aux += tbl->getrecord();
	}
	
	else
	  aux = tbl->getrecord();
	if (rcsep != _T('|'))
	  
	{
	  int len = aux.Len();
	  for (int i = 0; i < len; i++)
	    if (aux[i] == _T('|'))
	      aux[i] = rcsep[0];
	}
	exportfile << aux.mb_str(wxConvUTF8) << std::endl;
	tbl->next();
      }
      exportfile.close();
       wxString msg;
      msg.Printf(_("Copiados %d registros"), nrecs);
      wxMessageBox(msg, _("ENCERRADO"));
      ops_log log;
      msg.Printf(_T("%d"), nrecs);
      log.log_event(_T("EXPORT"), fname, _T("N/A"), msg);
      rslt = wxID_OK;
    }
    
    else if (flsep.IsEmpty())
      wxMessageBox(_("Separador de campos vazio"), _("ERRO"));
    
    else if (rcsep.IsEmpty())
      wxMessageBox(_("Separador de registros vazio"), _("ERRO"));
    
    else if (flsep == rcsep)
      wxMessageBox(_("Os separadores não podem ser iguais"), _("ERRO"));
    if (!wasopen)
      tbl->close();
    else
      tbl->go(curr_rec);
  }
  return rslt;
}

void
exportdlg::OnokbtnClick(wxCommandEvent & event) 
{
  int rslt = export_recs();
  EndModal(rslt);
}  void

exportdlg::settbl(ntable * ptbl, wxString name) 
{
  tbl = ptbl;
  fname = name;
} 
