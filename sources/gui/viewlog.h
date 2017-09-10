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
// Nome:        viewlog.h
// Propósito:   Classe (janela) para visualização de log de atividades
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef VIEWLOG_H
#define VIEWLOG_H

//(*Headers(viewlog)
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/gbsizer.h>
//*)

class viewlog:public wxDialog
{
public:

  viewlog(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ viewlog();

  //(*Declarations(viewlog)
  wxGrid *Grid1;
  //*)

protected:

  //(*Identifiers(viewlog)
  static const long ID_GRID1;
  //*)

private:

  //(*Handlers(viewlog)
  void OnGrid1CellSelect(wxGridEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
