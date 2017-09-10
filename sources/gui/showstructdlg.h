#ifndef SHOWSTRUCTDLG_H
#define SHOWSTRUCTDLG_H

//(*Headers(showstructdlg)
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
//*)

class showstructdlg:public wxDialog
{
public:

  showstructdlg(wxWindow * parent, wxWindowID id = wxID_ANY, const wxPoint & pos =
		wxDefaultPosition, const wxSize & size = wxDefaultSize);
    virtual ~ showstructdlg();

  //(*Declarations(showstructdlg)
  wxGrid *Grid1;
  //*)

protected:

  //(*Identifiers(showstructdlg)
  static const long ID_GRID1;
  //*)

private:

  //(*Handlers(showstructdlg)
  //*)

  DECLARE_EVENT_TABLE()};

#endif
