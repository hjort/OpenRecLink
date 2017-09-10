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
// Nome:        setoptsdlg.cpp
// Propósito:   Classe (janela) para selecionar algoritmo de padronização
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "setoptsdlg.h"
#include "fldconvert.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(setoptsdlg)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(setoptsdlg)
const long
  setoptsdlg::ID_RADIOBOX1 = wxNewId();

  setoptsdlg::ID_RADIOBOX2 = wxNewId();

  setoptsdlg::ID_STATICTEXT1 = wxNewId();

  setoptsdlg::ID_GRID1 = wxNewId();

  setoptsdlg::ID_BUTTON1 = wxNewId();

  setoptsdlg::ID_STATICTEXT5 = wxNewId();

  setoptsdlg::ID_SPINCTRL1 = wxNewId();

  setoptsdlg::ID_STATICTEXT6 = wxNewId();

  setoptsdlg::ID_SPINCTRL2 = wxNewId();

  setoptsdlg::ID_STATICTEXT2 = wxNewId();

  setoptsdlg::ID_TEXTCTRL1 = wxNewId();

  setoptsdlg::ID_STATICTEXT3 = wxNewId();

  setoptsdlg::ID_TEXTCTRL2 = wxNewId();

//*)
  BEGIN_EVENT_TABLE(setoptsdlg, wxDialog)
  //(*EventTable(setoptsdlg)
  //*)
  END_EVENT_TABLE()setoptsdlg::setoptsdlg(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					  const wxSize & size)
{
  //(*Initialize(setoptsdlg)
  wxFlexGridSizer *
    FlexGridSizer1;
  
  
  
  
  
  
	    wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
  
  
  
  {
  
      
  
    new wxRadioBox(this, ID_RADIOBOX1, _("Tipos de conversão"), wxDefaultPosition, wxDefaultSize,
		   7, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxDefaultValidator,
		   _T("ID_RADIOBOX1"));
  
		       wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  
  {
  
      
      
  
    new wxRadioBox(this, ID_RADIOBOX2, _("Tipos de data"), wxDefaultPosition, wxDefaultSize, 12,
		   __wxRadioBoxChoices_2, 2, wxRA_SPECIFY_COLS, wxDefaultValidator,
		   _T("ID_RADIOBOX2"));
  
  
		       wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  
		       0);
  
  
    new wxStaticText(this, ID_STATICTEXT1, _("Substituições"), wxDefaultPosition, wxDefaultSize,
		     0, _T("ID_STATICTEXT1"));
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
		       wxBOTTOM | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
		       5);
  
    new wxButton(this, ID_BUTTON1, _("Refaz"), wxDefaultPosition, wxDefaultSize, 0,
		 wxDefaultValidator, _T("ID_BUTTON1"));
  
  
  
  
    new wxStaticText(this, ID_STATICTEXT5, _("Início"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT5"));
  
  
  
    new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1,
		   _T("ID_SPINCTRL1"));
  
  
  
		       5);
  
    new wxStaticText(this, ID_STATICTEXT6, _("Caracteres"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT6"));
  
  
  
    new wxSpinCtrl(this, ID_SPINCTRL2, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 1,
		   _T("ID_SPINCTRL2"));
  
  
  
  
  
  
  
    new wxStaticText(this, ID_STATICTEXT2, _("Entrada"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT2"));
  
  
    new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(191, 162),
		   wxTE_MULTILINE | wxTE_READONLY | wxHSCROLL, wxDefaultValidator,
		   _T("ID_TEXTCTRL1"));
  
		       5);
  
    new wxStaticText(this, ID_STATICTEXT3, _("Saída"), wxDefaultPosition, wxDefaultSize, 0,
		     _T("ID_STATICTEXT3"));
  
  
    new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(191, 162),
		   wxTE_MULTILINE | wxTE_READONLY | wxHSCROLL, wxDefaultValidator,
		   _T("ID_TEXTCTRL2"));
  
		       5);
  
  
  
  
  
  
  
  
		       wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
  
  
  
  
	     (wxObjectEventFunction) & setoptsdlg::OnRadioBox1Select);
  
	   (wxObjectEventFunction) & setoptsdlg::OnRadioBox2Select);
  
	   (wxObjectEventFunction) & setoptsdlg::OnButton1Click);
  
	   (wxObjectEventFunction) & setoptsdlg::OnSpinCtrl1Change);
  
	   (wxObjectEventFunction) & setoptsdlg::OnSpinCtrl2Change);
  
    //*)
    Grid1->SetDefaultCellOverflow(false);
  RadioBox1->SetSelection(4);
}

setoptsdlg::~setoptsdlg()
{
  //(*Destroy(setoptsdlg)
  //*)
}

void
setoptsdlg::OnRadioBox1Select(wxCommandEvent & event)
{
  int sel = RadioBox1->GetSelection();
  if (sel == 0)
    RadioBox2->Enable();
  else
  {
    RadioBox2->Disable();
  }
  if (sel == 3)
  {
    StaticText5->Enable();
    StaticText6->Enable();
    SpinCtrl1->Enable();
    SpinCtrl2->Enable();
  }
  else
  {
    StaticText5->Disable();
    StaticText6->Disable();
    SpinCtrl1->Disable();
    SpinCtrl2->Disable();
  }
  if (sel == 6)
  {
    StaticText1->Enable();
    Grid1->Enable();
    Button1->Enable();
  }
  else
  {
    StaticText1->Disable();
    Grid1->Disable();
    Button1->Disable();
    provideexamples();
  }
}

void
setoptsdlg::provideexamples(void)
{
  int sel = RadioBox1->GetSelection();
  int sel2, beg = 0, nchars = 0;
  reclink::convref tconv;
  reclink::opconv cnvspec;

  switch (sel)
  {
  case 0:
    sel2 = RadioBox2->GetSelection();
    switch (sel2)
    {
    case 0:
      tconv = reclink::CDATA0;
      break;
    case 1:
      tconv = reclink::CDATA1;
      break;
    case 2:
      tconv = reclink::CDATA2;
      break;
    case 3:
      tconv = reclink::CDATA3;
      break;
    case 4:
      tconv = reclink::CDATA4;
      break;
    case 5:
      tconv = reclink::CDATA5;
      break;
    case 6:
      tconv = reclink::CDATA6;
      break;
    case 7:
      tconv = reclink::CDATA7;
      break;
    case 8:
      tconv = reclink::CDATA8;
      break;
    case 9:
      tconv = reclink::CDATA9;
      break;
    case 10:
      tconv = reclink::CDATAA;
      break;
    case 11:
      tconv = reclink::NADA;	//No conversion needed
      break;
    }
    break;
  case 1:
    tconv = reclink::CNOMES;
    break;
  case 2:
    tconv = reclink::CPONTO;
    break;
  case 3:
    tconv = reclink::SUBSTR;
    beg = SpinCtrl1->GetValue() - 1;
    nchars = SpinCtrl2->GetValue();
    break;
  case 4:
    tconv = reclink::NADA;
    break;
  case 5:
    tconv = reclink::FNOMEP;
    break;
  case 6:
    tconv = reclink::TROCA;
    break;
  default:
    tconv = reclink::ERRO;
    break;
  }
  cnvspec.ref = tconv;
  if (tconv == reclink::SUBSTR)
  {
    cnvspec.beg = beg;
    cnvspec.nchars = nchars;
  }
  if (tconv == reclink::TROCA)
  {
    wxString aux = _T(""), in, out;
    for (int i = 0; i < 10; i++)
    {
      in = Grid1->GetCellValue(i, 0);
      if (in.IsEmpty())
	break;
      out = Grid1->GetCellValue(i, 1);
      aux = aux + _T("^") + in + _T("|") + out;
    }
    aux = aux + _T("^");
    cnvspec.extra = aux;
  }

  int nlines = inlist->GetNumberOfLines();
  examples->Clear();
  fldcvt::fldcv converter;
  converter.initparms(excl, punct, suffixes);
  wxString aux;
  for (int i = 0; i < nlines; i++)
  {
    aux = inlist->GetLineText(i);
    aux = converter.convstring(aux, cnvspec);
    examples->AppendText(aux);
    if (tconv == reclink::FNOMEP)
    {
      cnvspec.ref = reclink::FNOMEU;
      aux = converter.convstring(_T("="), cnvspec);
      examples->AppendText(_T(",") + aux);
      
      aux = converter.convstring(_T("="), cnvspec);
      examples->AppendText(_T(",") + aux);
      
      aux = converter.convstring(_T("="), cnvspec);
      examples->AppendText(_T(",") + aux);
      
      aux = converter.convstring(_T("="), cnvspec);
      examples->AppendText(_T(",") + aux);
      
      aux = converter.convstring(_T("="), cnvspec);
      examples->AppendText(_T(",") + aux);
      cnvspec.ref = tconv;
    }
    examples->AppendText(_T("\n"));
  }
}

void
setoptsdlg::OnSpinCtrl1Change(wxSpinEvent & event)
{
  provideexamples();
}

void
setoptsdlg::OnSpinCtrl2Change(wxSpinEvent & event)
{
  provideexamples();
}

void
setoptsdlg::OnRadioBox2Select(wxCommandEvent & event)
{
  provideexamples();
}

void
setoptsdlg::setparms(wxString exclu, wxString punctu, wxString suffs)
{
  excl = exclu;
  punct = punctu;
  suffixes = suffs;
}

void
setoptsdlg::OnButton1Click(wxCommandEvent & event)
{
  provideexamples();
}