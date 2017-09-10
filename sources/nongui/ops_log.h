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
// Nome:        ops_log.h
// Propósito:   Classe para registrar operações
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-04
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef OPS_LOG_H
#define OPS_LOG_H

#include <wx/fileconf.h>
#include <wx/string.h>

class ops_log
{
public:
  ops_log();
  virtual ~ ops_log();
  void log_event(wxString op, wxString name, wxString time = _T(""), wxString msg = _T(""));
protected:
private:
    wxFileConfig * cfgfile;
  void write(wxString where, wxString what);
};

#endif // OPS_LOG_H
