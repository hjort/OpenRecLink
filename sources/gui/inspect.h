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
// Nome:        inspect.h
// Propósito:   Classe (janela) para inspecionar arquivo de pares
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef INSPECT_H
#define INSPECT_H

//(*Headers(inspect)
#include <wx/gauge.h>
#include <wx/stopwatch.h>
#include <wx/bmpbuttn.h>
#include <wx/grid.h>
#include <wx/spinctrl.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/radiobox.h>
//*)

#include "ntable.h"
class inspect:public wxDialog
{
public:

  inspect(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	  wxDefaultPosition, const wxSize & size = wxDefaultSize);
  virtual ~ inspect();

  //(*Declarations(inspect)
  wxSpinCtrl *stepctrl;
  wxGrid *compgrid;
  wxTextCtrl *scorenmax;
  wxBitmapButton *compup;
  wxBitmapButton *opencfgfile;
  wxGrid *refgrid;
  wxButton *clearall;
  wxStaticText *StaticText1;
  wxBitmapButton *refdown;
  wxBitmapButton *compdown;
  wxStaticText *StaticText3;
  wxTextCtrl *cfgfilectrl;
  wxButton *golast;
  wxBitmapButton *okbtn;
  wxFileDialog *FileDialog1;
  wxStaticText *StaticText7;
  wxTextCtrl *scoremmin;
  wxButton *gofirst;
  wxStaticText *StaticText4;
  wxStaticText *StaticText5;
  wxStaticText *StaticText2;
  wxBitmapButton *refup;
  wxStopWatch StopWatch1;
  wxStaticText *StaticText6;
  wxGauge *Gauge1;
  wxBitmapButton *cancelbtn;
  wxRadioBox *pairstatus;
  wxButton *goback;
  wxStaticText *scorelbl;
  wxButton *markall;
  wxButton *goforward;
  wxGrid *valuesgrid;
  //*)

protected:

  //(*Identifiers(inspect)
  static const long ID_STATICTEXT1;
  static const long ID_TEXTCTRL1;
  static const long ID_BITMAPBUTTON1;
  static const long ID_BITMAPBUTTON2;
  static const long ID_BITMAPBUTTON3;
  static const long ID_STATICTEXT2;
  static const long ID_GRID1;
  static const long ID_STATICTEXT3;
  static const long ID_GRID2;
  static const long ID_BITMAPBUTTON4;
  static const long ID_BITMAPBUTTON5;
  static const long ID_STATICTEXT7;
  static const long ID_STATICTEXT8;
  static const long ID_RADIOBOX1;
  static const long ID_STATICTEXT9;
  static const long ID_TEXTCTRL2;
  static const long ID_STATICTEXT10;
  static const long ID_TEXTCTRL3;
  static const long ID_BUTTON5;
  static const long ID_BUTTON6;
  static const long ID_GRID3;
  static const long ID_GAUGE1;
  static const long ID_BUTTON4;
  static const long ID_BUTTON3;
  static const long ID_BUTTON2;
  static const long ID_BUTTON1;
  static const long ID_STATICTEXT4;
  static const long ID_SPINCTRL1;
  static const long ID_OK;
  static const long ID_CANCEL;
  //*)

private:

  ntable ref;
  ntable comp;
  ntable score;
  long filepos;
  wxArrayLong initials;
  //wxArrayLong finals;
  int currow;
  long relrec;
  bool read;
  void loadsession(void);
  void savesession(void);
  void initialize(void);
  void moveup(void);
  void movetop(void);
  void movedown(void);
  void movebottom(void);
  void swap(wxGrid * grid, int row1, int row2, bool arrays = false);
  void loadvalues(void);
  //int getblocksize(wxString value);


  //(*Handlers(inspect)
  void OnopencfgfileClick(wxCommandEvent & event);
  void OnrefupClick(wxCommandEvent & event);
  void OnrefdownClick(wxCommandEvent & event);
  void OncompupClick(wxCommandEvent & event);
  void OncompdownClick(wxCommandEvent & event);
  void OngofirstClick(wxCommandEvent & event);
  void OngobackClick(wxCommandEvent & event);
  void OngoforwardClick(wxCommandEvent & event);
  void OnpairstatusSelect(wxCommandEvent & event);
  void OnmarkallClick(wxCommandEvent & event);
  void OnclearallClick(wxCommandEvent & event);
  void OngolastClick(wxCommandEvent & event);
  void OnvaluesgridCellSelect(wxGridEvent & event);
  void OnokbtnClick(wxCommandEvent & event);
  void OncancelbtnClick(wxCommandEvent & event);
  //void OnrefgridMouseMove(wxMouseEvent& event);
  void OnrefgridCellSelect(wxGridEvent & event);
  void OncompgridCellSelect(wxGridEvent & event);
  //*)

DECLARE_EVENT_TABLE()};

#endif
