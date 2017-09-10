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

#ifndef EXPORTDLG_H
#define EXPORTDLG_H

//(*Headers(exportdlg)
#include <wx/gauge.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "ntable.h"

class exportdlg:public wxDialog
{
public:

  exportdlg(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	    wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ exportdlg();
  void settbl(ntable * ptbl, wxString name);

  //(*Declarations(exportdlg)
  wxTextCtrl *recsep;
  wxStaticText *StaticText1;
  wxBitmapButton *okbtn;
  wxFileDialog *FileDialog1;
  wxTextCtrl *fldsep;
  wxStaticText *StaticText2;
  wxGauge *Gauge1;
  //*)

protected:

  //(*Identifiers(exportdlg)
  static const long ID_STATICTEXT1;
  static const long ID_STATICTEXT2;
  static const long ID_TEXTCTRL2;
  static const long ID_TEXTCTRL3;
  static const long ID_GAUGE1;
  //*)

private:

    ntable * tbl;
  wxString fname;
  int export_recs(void);

  //(*Handlers(exportdlg)
  void OnokbtnClick(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
