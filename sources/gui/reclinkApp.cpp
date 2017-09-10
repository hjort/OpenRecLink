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
// Nome:        reclinkApp.cpp
// Propósito:   Classe da aplicação
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "reclinkApp.h"
#include "langdlg.h"

#if defined(__WXMSW__)
#include "wxwinartprovider.h"
#endif

//(*AppHeaders
#include "reclinkmain.h"
#include <wx/image.h>
//*)

#include <wx/intl.h>
#include <wx/fileconf.h>
#include <wx/msgdlg.h>
#include <wx/string.h>

#include <wx/stdpaths.h>

IMPLEMENT_APP(reclinkApp);

wxString
wxFindAppPath(const wxString & argv0, const wxString & cwd, const wxString & appVariableName)
{
  wxString str;

  // Try appVariableName
  if (!appVariableName.IsEmpty())
  {
    str = wxGetenv(appVariableName);
    if (!str.IsEmpty())
      return str;
  }

#if defined(__WXMAC__) && !defined(__DARWIN__)
  // On Mac, the current directory is the relevant one when
  // the application starts.
  return cwd;
#endif

  if (wxIsAbsolutePath(argv0))
    return wxPathOnly(argv0);
  else
  {
    // Is it a relative path?
    wxString currentDir(cwd);
    if (currentDir.Last() != wxFILE_SEP_PATH)
      currentDir += wxFILE_SEP_PATH;

    str = currentDir + argv0;
    if (wxFileExists(str))
      return wxPathOnly(str);
  }

  // OK, it's neither an absolute path nor a relative path.
  // Search PATH.

  wxPathList pathList;
  pathList.AddEnvList(wxT("PATH"));
  str = pathList.FindAbsoluteValidPath(argv0);
  if (!str.IsEmpty())
    return wxPathOnly(str);

  // Failed
  return wxEmptyString;
}


wxLocale m_locale;

bool convertOK;

bool reclinkApp::OnInit()
{
  bool
    retval = false;
  try
  {

    /*
       if (convertOK)
       wxMessageBox("Convert OK", "INFO");
     */
    //(*AppInitialize
    bool
      wxsOK = true;

    wxInitAllImageHandlers();

    wxString
      app_path = wxFindAppPath(wxTheApp->argv[0], wxGetCwd(), _T("openreclink")) + _T("/");

    wxString
      m_app_path = wxStandardPaths::Get().GetUserLocalDataDir();

    if (!::wxDirExists(m_app_path))
      ::wxMkdir(m_app_path);

    m_app_path += _T("/.openreclink.cfg");

    int
      language;
    long
      lang = -1L;
    wxFileConfig *
      cfgfile = new wxFileConfig(_T(""), _T(""), m_app_path, _T(""), wxCONFIG_USE_LOCAL_FILE);
    cfgfile->Read(_T("GENERAL/LANG"), &lang);

    if (lang == -1)
    {
      langdlg
      dlg(0);
      if (dlg.ShowModal() == wxID_OK)
      {
	switch (dlg.RadioBox1->GetSelection())
	{
	case 0:
	  lang = (long) wxLANGUAGE_ENGLISH;
	  break;
	case 1:
	  lang = (long) wxLANGUAGE_PORTUGUESE_BRAZILIAN;
	  break;
	}
      }
      else
	lang = (long) wxLANGUAGE_DEFAULT;
    }

    wxString
      aux;
    aux.Printf(_T("%d"), lang);

    cfgfile->Write(_T("GENERAL/LANG"), aux);
    language = (int) lang;

    delete
      cfgfile;

    wxLocale::AddCatalogLookupPathPrefix(app_path);

    if (m_locale.Init(language /*, wxLOCALE_LOAD_DEFAULT */ ))
    {
      m_locale.AddCatalog(_T("openreclink"));
      m_locale.AddCatalog(_T("pt_BR"));
#ifdef __LINUX__
      m_locale.AddCatalog(_T("fileutils"));
#endif
    }

    wxString
      test = _("0.5");
    double
      dbl;
    convertOK = false;
    if (test.ToDouble(&dbl))
    {
      if (dbl == 0.5)
	convertOK = true;
    }

    if (wxsOK)
    {
#if defined(__WXMSW__)
      wxArtProvider::Push(new wxWinArtProvider);
#endif
      reclinkmain *
	Frame = new reclinkmain(0);
      Frame->Show();
      SetTopWindow(Frame);
    }
    //*)
    retval = true;
  }
  catch( ...)
  {
    wxMessageBox(_("Execução do programa interrompida!"), _("ERRO"), wxICON_ERROR);
  };

  return retval;
}
