#include "showstructdlg.h"

//(*InternalHeaders(showstructdlg)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(showstructdlg)
const long
  showstructdlg::ID_GRID1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(showstructdlg, wxDialog)
  //(*EventTable(showstructdlg)
  //*)
  END_EVENT_TABLE()showstructdlg::showstructdlg(wxWindow * parent, wxWindowID id,
						const wxPoint & pos, const wxSize & size)
{
  //(*Initialize(showstructdlg)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, id, _("Estrutura do arquivo"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
  Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(412, 186), 0, _T("ID_GRID1"));
  Grid1->CreateGrid(1, 4);
  Grid1->EnableEditing(true);
  Grid1->EnableGridLines(true);
  Grid1->SetColLabelSize(20);
  Grid1->SetColLabelValue(0, _("NOME"));
  Grid1->SetColLabelValue(1, _("TIPO"));
  Grid1->SetColLabelValue(2, _("TAM"));
  Grid1->SetColLabelValue(3, _("DEC"));
  Grid1->SetDefaultCellFont(Grid1->GetFont());
  Grid1->SetDefaultCellTextColour(Grid1->GetForegroundColour());
  FlexGridSizer1->Add(Grid1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);
  //*)
}

showstructdlg::~showstructdlg()
{
  //(*Destroy(showstructdlg)
  //*)
}
