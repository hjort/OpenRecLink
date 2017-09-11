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
// Nome:        viewtable.h
// Propósito:   Classe (janela) para visualizar arquivo dbf
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef VIEWTABLE_H
#define VIEWTABLE_H

//(*Headers(viewtable)
#include <wx/stopwatch.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
//*)

#include "exportdlg.h"
#include "ntable.h"
#include "ntable_grid.h"

class viewtable:public wxFrame
{
public:

  viewtable(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	    wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ viewtable();

  //(*Declarations(viewtable)
  wxMenuItem *MenuItem2;
  wxMenuItem *MenuItem1;
  wxMenu *Menu1;
  wxGrid *Grid1;
  wxMenuItem *MenuItem3;
  wxMenuItem *MenuItem9;
  wxFileDialog *FileDialog1;
  wxMenuItem *MenuItem5;
  wxMenuBar *MenuBar1;
  wxStopWatch StopWatch1;
  wxMenuItem *MenuItem7;
  wxMenuItem *MenuItem6;
  wxMenuItem *MenuItem4;
  wxMenu *Menu2;
  wxMenuItem *MenuItem8;
  //*)

protected:

  //(*Identifiers(viewtable)
  static const long ID_GRID1;
  static const long ID_MENUITEM1;
  static const long ID_MENUITEM9;
  static const long ID_MENUITEM8;
  static const long ID_MENUITEM4;
  static const long ID_MENUITEM2;
  static const long ID_MENUITEM5;
  static const long ID_MENUITEM3;
  static const long ID_MENUITEM6;
  static const long ID_MENUITEM7;
  //*)

private:

    ntable tbl;
  wxString name;
  wxArrayString selflds;
  wxArrayInt selops;
  wxArrayString selvals;
  wxArrayInt sellnks;
  void doindex(void);
  void doexport(void);
  void doview(void);
  void doappend(void);
  void doimport(void);
  void dopen(void);
  void doimportdbf(void);

  //(*Handlers(viewtable)
  void OnMenuItem3Selected(wxCommandEvent & event);
  void OnMenuItem2Selected(wxCommandEvent & event);
  void OnMenuItem3Selected1(wxCommandEvent & event);
  void OnMenuItem4Selected(wxCommandEvent & event);
  void OnMenuItem5Selected(wxCommandEvent & event);
  void OnMenuItem6Selected(wxCommandEvent & event);
  void OnMenuItem7Selected(wxCommandEvent & event);
  void OnMenuItem8Selected(wxCommandEvent & event);
  void OnGrid1CellSelect(wxGridEvent & event);
  //void OnMenuItem9Selected(wxCommandEvent& event);
  void OnMenuItem9Selected1(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
