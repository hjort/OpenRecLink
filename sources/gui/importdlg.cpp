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
// Nome:        importdlg.cpp
// Propósito:   Classe (janela) para importação de dados de arquivo .dbf
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2010-01-23
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "importdlg.h"

#include "ops_log.h"

//(*InternalHeaders(importdlg)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <wx/msgdlg.h>
#include <wx/filename.h>

#include "xbtable.h"
#include "ntable.h"

//(*IdInit(importdlg)
const long
  importdlg::ID_GAUGE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(importdlg, wxDialog)
  //(*EventTable(importdlg)
  //*)
  END_EVENT_TABLE()importdlg::importdlg(wxWindow * parent, wxWindowID id, const wxPoint & pos,
					const wxSize & size)
{
  //(*Initialize(importdlg)
  wxFlexGridSizer *
    FlexGridSizer1;

  Create(parent, id, _("Importa dados"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE,
	 _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
  Gauge1 =
    new wxGauge(this, ID_GAUGE1, 100, wxDefaultPosition, wxSize(282, 28), 0, wxDefaultValidator,
		_T("ID_GAUGE1"));
  FlexGridSizer1->Add(Gauge1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(FlexGridSizer1);
  FileDialog1 =
    new wxFileDialog(this, _("Seleciona arquivo"), wxEmptyString, wxEmptyString, _("*.dbf"),
		     wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FlexGridSizer1->Fit(this);
  FlexGridSizer1->SetSizeHints(this);
  //*)
}

importdlg::~importdlg()
{
  //(*Destroy(importdlg)
  //*)
}

int
importdlg::doimport(void)
{
  int retval = wxID_CANCEL;
  try
  {
    wxString dbfname = FileDialog1->GetPath();
    wxFileName tmp = dbfname;
    ntable htbl;
    tmp.SetExt(htbl.defdbext().Right(3));
    wxString hamname = tmp.GetFullPath();
    xbtable xtbl;
    xtbl.open(dbfname);
    Gauge1->SetRange(xtbl.gettotalrecs());
    Gauge1->SetValue(0);
    if (wxFileExists(hamname))
      wxRemoveFile(hamname);

    htbl.copystru(&xtbl);
    htbl.open(hamname);
    xtbl.first();
    int nrecs = 0;
    int ticker = 0;
    long copied = 0l;
    wxBeginBusyCursor();
    htbl.copyrec(0);		// initialize
    while (!xtbl.eof() && (copied < xtbl.gettotalrecs()))
    {
      ticker++;
      if (ticker > 99)
      {
	ticker = 0;
	wxYieldIfNeeded();
      }
      Gauge1->SetValue(++nrecs);
      if (htbl.copyrec(&xtbl))
	copied++;
      xtbl.next();
    }
    xtbl.close();
    htbl.close();
    wxEndBusyCursor();
    wxString msg;
    msg.Printf(_("Copiados %d de %d registros"), copied, nrecs);
    wxMessageBox(msg, _("ENCERRADO"));
    ops_log log;
    msg.Printf(_T("%d/%d"), copied, nrecs);
    log.log_event(_T("IMPDBF"), dbfname, _T("N/A"), msg);
    retval = wxID_OK;
  }
  catch( ...)
  {
  };
  return retval;
}
