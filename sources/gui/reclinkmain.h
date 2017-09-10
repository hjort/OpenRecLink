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
// Nome:        reclinkmain.h
// Propósito:   Classe (janela) da tela principal do programa
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef RECLINKMAIN_H
#define RECLINKMAIN_H

//(*Headers(reclinkmain)
#include <wx/menu.h>
#include <wx/app.h>
#include <wx/snglinst.h>
#include <wx/frame.h>
#include <wx/utils.h>
#include <wx/statbmp.h>
//*)

#include "viewtable.h"

#define MAXENTRIES 1000

class reclinkmain:public wxFrame
{
public:

  reclinkmain(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
	      wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ reclinkmain();

  //(*Declarations(reclinkmain)
  wxMenuItem *MenuItem2;
  wxMenuItem *MenuItem23;
  wxMenuItem *MenuItem1;
  wxMenu *Menu5;
  wxMenu *Menu1;
  wxMenuItem *MenuItem16;
  wxMenuItem *MenuItem12;
  wxMenu *Menu3;
  wxMenuItem *MenuItem19;
  wxMenuItem *MenuItem20;
  wxMenu *Menu6;
  wxMenuItem *MenuItem15;
  wxMenuItem *MenuItem21;
  wxMenuItem *MenuItem17;
  wxMenuItem *MenuItem3;
  wxMenuItem *MenuItem9;
  wxMenu *Menu7;
  wxMenu *Menu4;
  wxMenuItem *MenuItem11;
  wxMenuItem *MenuItem22;
  wxMenuItem *MenuItem5;
  wxMenuBar *MenuBar1;
  wxStaticBitmap *StaticBitmap1;
  wxMenuItem *MenuItem18;
  wxMenuItem *MenuItem6;
  wxMenuItem *MenuItem4;
  wxMenu *Menu2;
  wxSingleInstanceChecker SingleInstanceChecker1;
  wxMenuItem *doinspect;
  wxMenuItem *MenuItem8;
  wxMenuItem *MenuItem14;
  //*)

protected:

  //(*Identifiers(reclinkmain)
  static const long ID_STATICBITMAP1;
  static const long ID_MENUITEM1;
  static const long ID_MENUITEM17;
  static const long ID_MENUITEM10;
  static const long ID_MENUITEM2;
  static const long ID_MENUITEM23;
  static const long ID_MENUITEM24;
  static const long ID_MENUITEM3;
  static const long ID_MENUITEM4;
  static const long ID_MENUITEM5;
  static const long ID_MENUITEM20;
  static const long ID_MENUITEM21;
  static const long ID_MENUITEM14;
  static const long ID_MENUITEM15;
  static const long ID_MENUITEM6;
  static const long ID_MENUITEM18;
  static const long ID_MENUITEM19;
  static const long ID_MENUITEM22;
  static const long ID_MENUITEM7;
  static const long ID_MENUITEM8;
  static const long ID_MENUITEM16;
  static const long ID_MENUITEM9;
  static const long ID_MENUITEM11;
  static const long ID_MENUITEM12;
  static const long ID_MENUITEM13;
  //*)

private:

  void showlog(void);
  //void showabout(void);
  wxString xlateaction(wxString action);

  //(*Handlers(reclinkmain)
  void OnmenucloseSelected(wxCommandEvent & event);
   void OncfgdupSelected(wxCommandEvent & event);
   void OncfgstdSelected(wxCommandEvent & event);
   void OncfglnkSelected(wxCommandEvent & event);
   void OncfgjinSelected(wxCommandEvent & event);
   void OnMenuItem1Selected(wxCommandEvent & event);
   void OnrunstdSelected(wxCommandEvent & event);
   void OnrunlnkSelected(wxCommandEvent & event);
   void OninspectSelected(wxCommandEvent & event);
   void OndoexeccmbSelected(wxCommandEvent & event);
   void OndoexecjinSelected(wxCommandEvent & event);
   void OndodupSelected(wxCommandEvent & event);
   void OnaboutSelected(wxCommandEvent & event);
   void OncalcparmsSelected(wxCommandEvent & event);
   void OndocalcSelected(wxCommandEvent & event);
   void OnviewdupSelected(wxCommandEvent & event);
   void OnMenuItem19Selected(wxCommandEvent & event);
   void OnMenuItem20Selected(wxCommandEvent & event);
   void OnMenuItem21Selected(wxCommandEvent & event);
   void OnMenuItem16Selected(wxCommandEvent & event);
   void OnMenuItem17Selected(wxCommandEvent & event);
   void OnMenuItem18Selected(wxCommandEvent & event);
   void OnMenuItem22Selected(wxCommandEvent & event);
   void OnMenuItem23Selected(wxCommandEvent & event);
   
    //*)
    DECLARE_EVENT_TABLE()
    //viewtable* viewdlg;
};

#endif
