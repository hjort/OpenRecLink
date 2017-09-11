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
// Nome:        importdlg.h
// Propósito:   Classe (janela) para importação de dados de arquivo .dbf
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2010-01-23
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef IMPORTDLG_H
#define IMPORTDLG_H

//(*Headers(importdlg)
#include <wx/gauge.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
//*)

class importdlg:public wxDialog
{
public:

  importdlg(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	    wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ importdlg();
  int doimport(void);
  //(*Declarations(importdlg)
  wxFileDialog *FileDialog1;
  wxGauge *Gauge1;
  //*)

protected:

  //(*Identifiers(importdlg)
  static const long ID_GAUGE1;
  //*)

private:

  //(*Handlers(importdlg)
  //*)

  DECLARE_EVENT_TABLE()};

#endif
