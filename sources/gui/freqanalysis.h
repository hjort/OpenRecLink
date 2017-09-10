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
// Nome:        freqanalysis.h
// Propósito:   Classe (janela) para analisar frequencia de scores
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef FREQANALYSIS_H
#define FREQANALYSIS_H

//(*Headers(freqanalysis)
#include <wx/bmpbuttn.h>
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/radiobox.h>
//*)

#include <iostream>
#include <fstream>

class freqanalysis:public wxDialog
{
public:

  freqanalysis(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	       wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ freqanalysis();
  void setfilename(wxString fname = _T(""));

  //(*Declarations(freqanalysis)
  wxGrid *Grid1;
  wxStaticText *StaticText1;
  wxChoice *Choice1;
  wxFileDialog *FileDialog1;
  wxRadioBox *RadioBox1;
  wxBitmapButton *BitmapButton1;
  //*)

protected:

  //(*Identifiers(freqanalysis)
  static const long ID_STATICTEXT1;
  static const long ID_CHOICE1;
  static const long ID_GRID1;
  static const long ID_RADIOBOX1;
  static const long ID_BITMAPBUTTON1;
  //*)

private:

    wxString filename;
    std::ifstream inputfile;
  wxString readline(void);
  void process(void);
  void processvalue(double val);
  void processvalue(wxString vname, double val);
  void sorttable(void);
  void sorttable_vals(void);
  void calcfreqs(int n);
  void calcfreqs(void);
  void swap(int n1, int n2);

  //(*Handlers(freqanalysis)
  void OnBitmapButton1Click(wxCommandEvent & event);
  void OnChoice1Select(wxCommandEvent & event);
  //*)

  DECLARE_EVENT_TABLE()};

#endif
