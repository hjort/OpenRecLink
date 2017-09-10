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
// Nome:        viewdup.cpp
// Propósito:   Classe (janela) para visualizar duplicações
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef VIEWDUP_H
#define VIEWDUP_H

//(*Headers(viewdup)
#include <wx/bmpbuttn.h>
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "ntable.h"

class viewdup:public wxDialog
{
public:

  viewdup(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ viewdup();

  //(*Declarations(viewdup)
  wxTextCtrl *filenamectrl;
  wxButton *cpybtn;
  wxButton *stampbtn;
  wxBitmapButton *openfilebtn;
  wxBitmapButton *forward;
  wxGrid *Grid1;
  wxStaticText *StaticText1;
  wxFileDialog *FileDialog1;
  wxGrid *dispgrid;
  wxBitmapButton *back;
  wxButton *newbtn;
  wxBitmapButton *closebtn;
  wxButton *clrbtn;
  //*)

protected:

  //(*Identifiers(viewdup)
  static const long ID_STATICTEXT1;
  static const long ID_TEXTCTRL1;
  static const long ID_BITMAPBUTTON1;
  static const long ID_GRID2;
  static const long ID_GRID1;
  static const long ID_BUTTON1;
  static const long ID_BUTTON2;
  static const long ID_BUTTON3;
  static const long ID_BUTTON4;
  static const long ID_BITMAPBUTTON2;
  static const long ID_BITMAPBUTTON3;
  static const long ID_BITMAPBUTTON4;
  //*)

private:

    ntable tbl;
  ntable t;
  wxString id;
  wxString timestring;
  int selrow;
  void init(void);
  void goback(void);
  void goforward(void);
  void loaddups(void);
  bool checkifdup(void);
  void info(wxString msg);
  void dump(void);
  void summarytbl(void);
  void genuniq(void);
  void replaceuid(void);
  void eraseuid(void);
  void readuid(void);
  void writeuid(wxString uid);

  //(*Handlers(viewdup)
  void OnopenfilebtnClick(wxCommandEvent & event);
  void OnbackClick(wxCommandEvent & event);
  void OnforwardClick(wxCommandEvent & event);
  void OnclosebtnClick(wxCommandEvent & event);
  void OnGrid1CellSelect(wxGridEvent & event);
  void OnclrbtnClick(wxCommandEvent & event);
  void OncpybtnClick(wxCommandEvent & event);
  void OnnewbtnClick(wxCommandEvent & event);
  void OnstampbtnClick(wxCommandEvent & event);
  void OndispgridCellSelect(wxGridEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
