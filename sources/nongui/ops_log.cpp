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
// Nome:        ops_log.cpp
// Propósito:   Classe para registrar operações
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-04
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "ops_log.h"

#include <wx/msgdlg.h>
#include <wx/longlong.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/datetime.h>
#include <wx/timer.h>

ops_log::ops_log()
{
  wxString m_app_path = wxStandardPaths::Get().GetUserLocalDataDir();

  if (!::wxDirExists(m_app_path))
    ::wxMkdir(m_app_path);

  m_app_path += _T("/.openreclink.cfg");

  cfgfile = new wxFileConfig(_T(""), _T(""), m_app_path, _T(""), wxCONFIG_USE_LOCAL_FILE);
}

ops_log::~ops_log()
{
  //dtor
  delete cfgfile;
}

void
ops_log::write(wxString where, wxString what)
{
  const wxString path = where;
  const wxString obj = what;
  cfgfile->Write(path, obj);
#ifdef __DEBUG__
  //wxMessageBox(path, obj);
#endif
}

void
ops_log::log_event(wxString op, wxString name, wxString time, wxString msg)
{
  wxFileName fname(name);
  wxDateTime now = wxDateTime::Now();
  wxLongLong mnow = wxGetLocalTimeMillis();
  wxString reftime;
  reftime.Printf(_T("%08X"), mnow);
  write(_T("LOG/") + reftime, op);
  write(reftime + _T("/DATE"), now.Format(_T("%c"), wxDateTime::UTC));
  write(reftime + _T("/NAME"), fname.GetName());
  wxString aux = fname.GetPath();
  write(reftime + _T("/PATH"), aux);
  if (time.IsEmpty())
    aux = _T("N/A");
  else
    aux = time;
  write(reftime + _T("/DURATION"), aux);
  if (msg.IsEmpty())
    msg = _T("OK");
  write(reftime + _T("/FULLRUN"), msg);
}
