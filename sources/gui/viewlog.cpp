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
// Nome:        viewlog.cpp
// Propósito:   Classe (janela) para visualização de log de atividades
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "viewlog.h"

#include <wx/tipwin.h>

//(*InternalHeaders(viewlog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(viewlog)
const long
  viewlog::ID_GRID1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(viewlog, wxDialog)
  //(*EventTable(viewlog)
  //*)
  END_EVENT_TABLE()viewlog::viewlog(wxWindow * parent, wxWindowID id, const wxPoint & pos,
				    const wxSize & size)
{
  //(*Initialize(viewlog)
  wxGridBagSizer *
    GridBagSizer1;

  Create(parent, id, _("Log de atividade"), wxDefaultPosition, wxDefaultSize,
	 wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  GridBagSizer1 = new wxGridBagSizer(0, 0);
  Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(597, 133), 0, _T("ID_GRID1"));
  Grid1->CreateGrid(4, 5);
  Grid1->EnableEditing(false);
  Grid1->EnableGridLines(true);
  Grid1->SetColLabelSize(20);
  Grid1->SetDefaultColSize(100, true);
  Grid1->SetColLabelValue(0, _("Hora (UTC)"));
  Grid1->SetColLabelValue(1, _("Atividade"));
  Grid1->SetColLabelValue(2, _("Configuração"));
  Grid1->SetColLabelValue(3, _("Tempo"));
  Grid1->SetColLabelValue(4, _("Mensagem"));
  Grid1->SetDefaultCellFont(Grid1->GetFont());
  Grid1->SetDefaultCellTextColour(Grid1->GetForegroundColour());
  GridBagSizer1->Add(Grid1, wxGBPosition(0, 0), wxDefaultSpan,
		     wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(GridBagSizer1);
  GridBagSizer1->Fit(this);
  GridBagSizer1->SetSizeHints(this);

  Connect(ID_GRID1, wxEVT_GRID_SELECT_CELL, (wxObjectEventFunction) & viewlog::OnGrid1CellSelect);
  //*)
}

viewlog::~viewlog()
{
  //(*Destroy(viewlog)
  //*)
}

void
viewlog::OnGrid1CellSelect(wxGridEvent & event)
{
  int row = event.GetRow();
  int col = event.GetCol();
  wxString val = Grid1->GetCellValue(row, col);
  wxTipWindow *tip = new wxTipWindow(Grid1, val);

  //event.Skip();
}
