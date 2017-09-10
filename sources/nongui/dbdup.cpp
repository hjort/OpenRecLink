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
// Nome:        dbdup.cpp
// Propósito:   Classe para deduplicação de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:     2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "dbdup.h"
#include "progressdialog.h"

#include "checksep.h"

#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/intl.h>
#include <wx/tokenzr.h>
#include <wx/longlong.h>
#include <wx/timer.h>

#ifdef __DEBUGCRACA__
#include <iostream>
#include <fstream>
#ifdef  debugmsg
#undef  debugmsg
#endif
#define debugmsg(msg) (msgfile <<  "line " << __LINE__ << ": " << msg.mb_str(wxConvUTF8) << std::endl)
std::ofstream msgfile;
#else
#define debugmsg(msg) (msg)
#endif

_dbdup::_dbdup(wxWindow * w)
{
  cpopts = 0;
  blockopts = 0;
  numrecs = 0;
  oldstring = _T("");
  parent = w;

#ifdef __DEBUGCRACA__
  msgfile.open("dbdup.log");
#endif

}

_dbdup::~_dbdup()
{
  if (cpopts)
    delete[]cpopts;
  if (blockopts)
    delete[]blockopts;

#ifdef __DEBUGCRACA__
  msgfile.close();
#endif


}

void
_dbdup::init(wxString cfgfile)
{
  loadcfg(cfgfile);
}

bool
_dbdup::copyrec(void)
{
  bool retval = true;

  if (!hasthefield)
  {
    if (tmp.isopen() && !tmp.eof())
    {
      copyfields();
      tmp.next();
      if (tmp.eof())
      {
	setupdfile();
	retval = false;
      }
    }
  }
  else
  {
    if (update.isopen() && !update.eof())
    {
      update.setfield(_T(""), _T("_UNIQ"));
      update.setfield(_T(""), _T("_SCORE"));
      update.replacerec();
      update.next();
      if (update.eof())
      {
	setupdfile();
	retval = false;
      }
    }
  }
  return retval;
}

void
_dbdup::setupdfile(void)
{
  if (!hasthefield)
    tmp.close();
  recno = 1L;
  update.go(recno);		// THIS HAS TO BE CHECKED!!!
  for (int i = 0; i < nopts; i++)
    storedvals[i] = update.getstring(cpopts[i].compfield);
  int i = update.getfieldnum(_T("_UNIQ"));
  if (i > -1)
    storedvals[i] = genuniq();

  storedblock.Clear();
  for (int i = 0; i < nblocks; i++)
    storedblock.Add(update.getstring(blockopts[i].compfield));
}

bool
_dbdup::checkblockvars(void)
{
  bool retval = true;

  for (int i = 0; i < nblocks; i++)
    
  {
    wxString upfld = blockopts[i].compfield;
    wxString upval = update.getstring(upfld);
    wxString mstval = storedblock[i];
    if (upval != mstval)
      
    {
      retval = false;
      break;
    }
  }

  return retval;
}

bool
_dbdup::checkrec(void)
{
  bool retval = (!update.eof() && checkblockvars());

  if (retval)
  {
    double compresult = 0.0;
    bool cpmatch;

    wxString valref;
    wxString valcomp;

    for (int i = 0; i < nopts; i++)
    {
      valref = storedvals[i];
      valcomp = update.getstring(cpopts[i].compfield);
      compresult = compresult + docompare(valref,
					  valcomp,
					  cpopts[i].comp,
					  cpopts[i].correct,
					  cpopts[i].incorrect, cpopts[i].lim, cpmatch);
    }
    if (compresult > minscore)
    {
      int i = update.getfieldnum(_T("_UNIQ"));
      if (i > -1)
      {
	wxString ax = update.getstring(_T("_UNIQ"));
	if (ax.IsEmpty())
	{
#ifdef __DEBUGCRACA__
	  debugmsg(storedvals[i]);
#endif
	  update.setfield(storedvals[i], _T("_UNIQ"));
	  i = update.getfieldnum(_T("_SCORE"));
	  if (i > -1)
	  {
	    wxString score;
	    score.Printf(_T("%16.12f"), compresult);
	    update.setfield(score, i);
	  }
	  update.replacerec();
	}
	else
	  storedvals[i] = ax;
      }
    }
  }

  update.next();
  return retval;
}

bool
_dbdup::findblockbeg(void)
{
  bool retval = false;

  if (((int) recno <= numrecs))
  {
    if (update.go(recno++))
    {
#ifdef __DEBUGCRACA__
      wxString meleca;
      meleca.Printf(_T("%d"), recno);
      debugmsg(meleca);
#endif
      for (int i = 0; i < nopts; i++)
	storedvals[i] = update.getstring(cpopts[i].compfield);
      for (int i = 0; i < nblocks; i++)
	storedblock[i] = update.getstring(blockopts[i].compfield);
      int i = update.getfieldnum(_T("_UNIQ"));
      if (i > -1)
      {
	wxString ax = update.getstring(_T("_UNIQ"));
	if (ax.IsEmpty())
	{
	  ax = genuniq();
	  update.setfield(ax, _T("_UNIQ"));
	  update.setfield(_T(">>>>>>>>>>>>>>>"), _T("_SCORE"));
	  update.replacerec();
	}
	storedvals[i] = ax;
      }
      wxString key = _T("");
      for (int i = 0; i < nblocks; i++)
	key += update.getstring(blockopts[i].compfield);
      retval = update.find(key);
#ifdef __DEBUGCRACA__
      if (retval)
	debugmsg(key);
      else
	debugmsg(wxString(_T("Whaaa?")));
#endif
    }
  }

  return retval;
}

void
_dbdup::loadcfg(wxString cfgname)
{
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgname, _T(""), wxCONFIG_USE_LOCAL_FILE);
  wxString aux = _T("");

  updatefilename = _T("");
  cfgfile->Read(_T("FILES/UPDATENAME"), &updatefilename);

  long nlines = 0l;
  cfgfile->Read(_T("PROCESS/NLINES"), &nlines);
  nblocks = 0;
  wxString _tmp;
  for (int i = 0; i < (int) nlines; i++)
  {
    aux.Printf(_T("PROCESS/BLOCK%d"), i);
    cfgfile->Read(aux, &_tmp);
    if (_tmp == _T("1"))
      nblocks++;
  }
  nopts = (int) nlines;
  cpopts = new reclink::comparecfg[nopts];
  blockopts = new reclink::blockcfg[nblocks];

  nblocks = 0;
  bool isblock;
  for (int i = 0; i < nopts; i++)
  {
    _tmp = _T("");
    aux.Printf(_T("PROCESS/BLOCK%d"), i);
    cfgfile->Read(aux, &_tmp);
    if (_tmp == _T("1"))
      isblock = true;
    else
      isblock = false;
    _tmp = _T("");
    aux.Printf(_T("PROCESS/UPDATE%d"), i);
    cfgfile->Read(aux, &_tmp);
    cpopts[i].compfield = _tmp;
    if (isblock)
      blockopts[nblocks].compfield = _tmp;
    _tmp = _T("");
    aux.Printf(_T("PROCESS/PROC%d"), i);
    cfgfile->Read(aux, &_tmp);
    if (_tmp == _("EXATO"))
      cpopts[i].comp = reclink::EXATO;
    else if (_tmp == _("CARACTERE"))
      cpopts[i].comp = reclink::CARACTERE;
    else if (_tmp == _("DIFERENCA"))
      cpopts[i].comp = reclink::DIFERENCA;
    else if (_tmp == _("APROX"))
      cpopts[i].comp = reclink::APROX;
    else
      cpopts[i].comp = reclink::ERRADO;
    _tmp = _T("");
    aux.Printf(_T("PROCESS/CORRECT%d"), i);
    cfgfile->Read(aux, &_tmp);
    _tmp.Replace(CVTFROM, CVTTO);
    _tmp.ToDouble(&(cpopts[i].correct));
    cpopts[i].correct = cpopts[i].correct / 100.0;
    _tmp = _T("");
    aux.Printf(_T("PROCESS/INCORRECT%d"), i);
    cfgfile->Read(aux, &_tmp);
    _tmp.Replace(CVTFROM, CVTTO);
    _tmp.ToDouble(&(cpopts[i].incorrect));
    cpopts[i].incorrect = cpopts[i].incorrect / 100.0;
    _tmp = _T("");
    aux.Printf(_T("PROCESS/THRESH%d"), i);
    cfgfile->Read(aux, &_tmp);
    _tmp.Replace(CVTFROM, CVTTO);
    _tmp.ToDouble(&(cpopts[i].lim));
    _tmp.Printf(_T("MASTER%d"), i);
    cpopts[i].reffield = _tmp;
    if (isblock)
    {
      blockopts[nblocks].reffield = _tmp;
      nblocks++;
    }
  }
  aux = _T("");
  cfgfile->Read(_T("GENERAL/MINSCORE"), &aux);
  aux.Replace(CVTFROM, CVTTO);
  aux.ToDouble(&minscore);

  delete cfgfile;
}

void
_dbdup::dupstru(void)
{
  if (tmp.isopen())
  {
    int nflds = tmp.getnumfields();
    dbtable::fielddef * dbstruct = new dbtable::fielddef[nflds + 2];
    for (int i = 0; i < nflds; i++)
    {
      dbstruct[i].fdname = tmp.getfieldname(i);
      dbstruct[i].fdtype = tmp.getfieldtype(i);
      dbstruct[i].len = tmp.getfieldlen(i);
      dbstruct[i].dec = 0;
    }
    if (tmp.getfieldnum(_T("_UNIQ")) == -1)
    {
      dbstruct[nflds].fdname = _T("_UNIQ");
      dbstruct[nflds].fdtype = dbtable::CHAR;
      dbstruct[nflds].len = 8;
      dbstruct[nflds++].dec = 0;
    }
    if (tmp.getfieldnum(_T("_SCORE")) == -1)
    {
      dbstruct[nflds].fdname = _T("_SCORE");
      dbstruct[nflds].fdtype = dbtable::CHAR;
      dbstruct[nflds].len = 15;
      dbstruct[nflds++].dec = 0;
    }
    update.setstructure(dbstruct, nflds);
    storedvals.Clear();
    for (int i = 0; i < nflds; i++)
      storedvals.Add(_T(""));
  }
}

bool
_dbdup::initindex(void)
{
  bool retval = false;
  try
  {
    retval = checkmasterindex();
  } catch( ...)
  {
  };
  return retval;
}

bool
_dbdup::checkmasterindex(void)
{
  bool retval = false;
  wxFileName matchfile = wxFileName(updatefilename);
  ntable t;
  wxString ixfile = matchfile.GetPath(wxPATH_GET_SEPARATOR) + matchfile.GetName() + t.defixext();

  if (wxFileExists(ixfile))
    wxRemoveFile(ixfile);
  wxArrayString kyflds;
  for (int i = 0; i < nblocks; i++)
    kyflds.Add(blockopts[i].compfield);

  progressdialog *dlg = new progressdialog(parent);
  dlg->Show();
  dlg->Update();
  if (parent)
    parent->Update();
  wxYieldIfNeeded();
  if (update.makeindex(ixfile, &kyflds))
    retval = update.setindex(ixfile);
  dlg->Close();
  delete dlg;
  return retval;
}

void
_dbdup::copyfields(void)
{
  if (tmp.isopen())
  {
    int nflds = tmp.getnumfields();
    for (int i = 0; i < nflds; i++)
      try
    {
      update.setfield(tmp.getstring(tmp.getfieldname(i)), tmp.getfieldname(i));
    } catch( ...)
    {
    };
    update.setfield(_T(""), _T("_UNIQ"));
    update.setfield(_T(""), _T("_SCORE"));
    try
    {
      update.appendrec();
    } catch( ...)
    {
    };
  }
}

int
_dbdup::nrecs(void)
{
  return numrecs;
}

wxString
_dbdup::genuniq(void)
{
  wxLongLong now;
  wxString timestring;
  do
  {
    now = wxGetLocalTimeMillis();
    timestring.Printf(_T("%08X"), now.ToLong());
  }
  while (timestring == oldstring);
  oldstring = timestring;
  return timestring;
}

bool
_dbdup::checkfields(void)
{
  bool retval = false;

  if (nopts)
    if (!updatefilename.IsEmpty() && wxFileExists((updatefilename)))
      if (tmp.open(updatefilename))
      {
	numrecs = (int) tmp.gettotalrecs();
	int i;
	wxString aux;
	for (i = 0; i < nopts; i++)
	{
	  aux = cpopts[i].compfield;
	  if (tmp.getfieldnum(aux) == -1)
	    break;
	}
	//tmp.close();
	if (i >= nopts)
	{
	  hasthefield = checkfield(&tmp);
	  tmp.close();
	  wxFileName matchfile = wxFileName(updatefilename);
	  wxString ixfile =
	    matchfile.GetPath(wxPATH_GET_SEPARATOR) + matchfile.GetName() + tmp.defixext();
	  if (hasthefield)	// Already has the field
	  {
	    retval = update.open(updatefilename);
	    if (retval)
	    {
	      update.first();
	      storedvals.Clear();
	      int nflds = update.getnumfields();
	      for (int i = 0; i < nflds; i++)
		storedvals.Add(_T(""));
	    }
	  }
	  else
	  {
	    wxFileName fname = wxFileName(updatefilename);
	    wxString backup = _("Copia de ") + fname.GetName();
	    fname.SetName(backup);
	    backup = fname.GetFullPath();
	    if (wxFileExists(backup))
	      wxRemoveFile(backup);
	    wxRenameFile(updatefilename, backup);
	    if (tmp.open(backup))
	    {
	      tmp.first();
	      dupstru();
	      retval = update.open(updatefilename);
	    }
	  }
	}
      }

  if (!retval)
  {
    tmp.close();
    update.close();
  }

  return retval;
}

bool
_dbdup::checkfield(ntable * tbl)
{
  bool retval = (tbl->getfieldnum(_T("_UNIQ")) != -1);
  return retval;
}
