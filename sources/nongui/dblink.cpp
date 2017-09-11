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
// Nome:        dblink.cpp
// Propósito:   Classe para relacionamento (join) de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "dblink.h"
#include "progressdialog.h"

#include "checksep.h"

#include <wx/filename.h>
#include <wx/fileconf.h>

#ifdef __DEBUG__
#include <iostream>
#include <fstream>
#ifdef  linkdebugmsg
#undef  linkdebugmsg
#endif
#define linkdebugmsg(msg) (debugstream << __FILE__ << " line " << __LINE__ << ": " << msg.mb_str(wxConvUTF8) << std::endl)
std::ofstream debugstream;
#else
#define linkdebugmsg(msg) (msg)
#endif

namespace dblink
{

  _dolink::_dolink(wxString cfgfile, long firstrec, long lastrec)
  {
    cfg = cfgfile;
    first = firstrec;
    last = lastrec;
    blockopts = 0;
    cpopts = 0;
#ifdef __DEBUG__
    debugstream.open("linkdebug.log");
#endif
  };

  _dolink::~_dolink()
  {
    if (blockopts)
      delete[]blockopts;
    if (cpopts)
      delete[]cpopts;

    tbcomp.close();
    tbref.close();
    tbscore.close();
#ifdef __DEBUG__
    debugstream.close();
#endif
  };

  bool _dolink::init(wxWindow * w)
  {
    bool retval = false;
    parent = w;

    wxFileConfig *cfgfile = new wxFileConfig(_T(""), _T(""), cfg, _T(""), wxCONFIG_USE_LOCAL_FILE);
    wxString aux = _T("");
    cfgfile->Read(_T("FILES/COMPNAME"), &aux);

    if (wxFileExists(aux))
    {
      if (tbcomp.open(aux))
      {
	aux = _T("");
	cfgfile->Read(_T("FILES/REFNAME"), &aux);
	if (wxFileExists(aux))
	{
	  if (tbref.open(aux))
	  {
	    wxString refname = aux;
	    if (createscoretbl())
	    {
	      aux = _T("");
	      cfgfile->Read(_T("GENERAL/IXNAME"), &aux);
	      wxString ixname = aux;
	      aux = _T("");
	      cfgfile->Read(_T("GENERAL/IGNORE"), &aux);
	      ignmin = (aux == _T("Y"));
	      aux = _T("");
	      cfgfile->Read(_T("GENERAL/MINSCORE"), &aux);
	      aux.Replace(CVTFROM, CVTTO);
	      aux.ToDouble(&minscore);
	      long nlines = 0l;
	      cfgfile->Read(_T("BLOCK/NLINES"), &nlines);
	      noblks = (int) nlines;
	      blockopts = new reclink::blockcfg[nlines];
	      wxString tmp;
	      for (int i = 0; i < noblks; i++)
	      {
		tmp = _T("");
		aux.Printf(_T("BLOCK/COMP%d"), i);
		cfgfile->Read(aux, &tmp);
		blockopts[i].compfield = tmp;
		tmp = _T("");
		aux.Printf(_T("BLOCK/REF%d"), i);
		cfgfile->Read(aux, &tmp);
		blockopts[i].reffield = tmp;
	      }
	      if (checkmasterndx(refname, ixname))
	      {
		//aux.Printf(_T("%d"), first);
		//tbcomp.find(aux);
		tbcomp.go(first);
		retval = true;
		nlines = 0L;
		cfgfile->Read(_T("COMPARE/NLINES"), &nlines);
		nocps = (int) nlines;
		cpopts = new reclink::comparecfg[nocps];
		for (int i = 0; i < nocps; i++)
		{
		  tmp = _T("");
		  aux.Printf(_T("COMPARE/COMP%d"), i);
		  cfgfile->Read(aux, &tmp);
		  cpopts[i].compfield = tmp;
		  tmp = _T("");
		  aux.Printf(_T("COMPARE/PROC%d"), i);
		  cfgfile->Read(aux, &tmp);
		  if (tmp == _("EXATO"))
		    cpopts[i].comp = reclink::EXATO;
		  else if (tmp == _("CARACTERE"))
		    cpopts[i].comp = reclink::CARACTERE;
		  else if (tmp == _("DIFERENCA"))
		    cpopts[i].comp = reclink::DIFERENCA;
		  else if (tmp == _("APROX"))
		    cpopts[i].comp = reclink::APROX;
		  else
		    cpopts[i].comp = reclink::ERRADO;
		  tmp = _T("");
		  aux.Printf(_T("COMPARE/CORRECT%d"), i);
		  cfgfile->Read(aux, &tmp);
		  tmp.Replace(CVTFROM, CVTTO);
		  tmp.ToDouble(&(cpopts[i].correct));
		  cpopts[i].correct = cpopts[i].correct / 100.0;
		  tmp = _T("");
		  aux.Printf(_T("COMPARE/INCORRECT%d"), i);
		  cfgfile->Read(aux, &tmp);
		  tmp.Replace(CVTFROM, CVTTO);
		  tmp.ToDouble(&(cpopts[i].incorrect));
		  cpopts[i].incorrect = cpopts[i].incorrect / 100.0;
		  tmp = _T("");
		  aux.Printf(_T("COMPARE/THRESH%d"), i);
		  cfgfile->Read(aux, &tmp);
		  tmp.Replace(CVTFROM, CVTTO);
		  tmp.ToDouble(&(cpopts[i].lim));
		  tmp = _T("");
		  aux.Printf(_T("COMPARE/REF%d"), i);
		  cfgfile->Read(aux, &tmp);
		  cpopts[i].reffield = tmp;
		}
	      }
	    }
	  }
	}
      }
    }

    delete cfgfile;

    return retval;
  }

  bool _dolink::checkmasterndx(wxString fname, wxString ixname)
  {
    bool retval = false;

    wxFileName matchfile = wxFileName(fname);
    ntable t;
    wxString ixfile = matchfile.GetPath(wxPATH_GET_SEPARATOR) + ixname.Upper() + t.defixext();

    if (!wxFileExists(ixfile))
    {
      wxArrayString kyflds;
      for (int i = 0; i < noblks; i++)
	kyflds.Add(blockopts[i].reffield);
      progressdialog *dlg = new progressdialog(parent);
      dlg->Show();
      dlg->Update();
      if (parent)
	parent->Update();
      wxYieldIfNeeded();
      if (tbref.makeindex(ixfile, &kyflds))
	if (tbref.setindex(ixfile))
	  //retval = tbref.reindex();
	  retval = true;
      dlg->Close();
      delete dlg;
    }
    else
      retval = tbref.setindex(ixfile);

    return retval;
  }

  bool _dolink::findblockbeg(void)
  {
    bool retval = false;
    int recno = (int) tbcomp.getcurrentrec();

    while (!retval && !tbcomp.eof() && (recno <= last))
    {
      wxString key = _T("");
      for (int i = 0; i < noblks; i++)
	key += tbcomp.getstring(blockopts[i].compfield);
      //wxString key = tbref.makekey();
      retval = tbref.find(key);
#ifdef __DEBBUG__
      wxString dbg;
      if (retval)
	linkdebugmsg(key);
#endif
      if (!retval)
	tbcomp.next();
      recno = (int) tbcomp.getcurrentrec();	// KRCJ 20110208 otherwise the last test wouldn't be checked
    }

    return retval;
  }

  bool _dolink::checkblockvars(void)
  {
    bool retval = true;
    wxString cmp;

#ifdef __DEBUG__
    wxString msg = _T("");
#endif

    for (int i = 0; i < noblks; i++)
      
    {
      wxString compfld = blockopts[i].compfield;
      wxString reffld = blockopts[i].reffield;
      wxString compval = tbcomp.getstring(compfld);
      wxString refval = tbref.getstring(reffld);

#ifdef __DEBBUG__
      if (!msg.IsEmpty())
	msg = msg + _("; ") + compval + _T("/") + refval;
      else
	msg = compval + _T("/") + refval;
#endif
      if (compval != refval)
	
      {
	retval = false;
	break;
      }
    }

#ifdef __DEBBUG__
    if (retval)
    {
      tmp.Printf(_T(" (ref: %d/ comp: %d)"), tbref.getcurrentrec(), tbcomp.getcurrentrec());
      msg += tmp;
      linkdebugmsg(msg);
    }
#endif

    return retval;
  }

  long _dolink::therecno(void)
  {
    return tbcomp.getcurrentrec();
  }

  bool _dolink::isinblock(void)
  {
    int recno = (int) tbcomp.getcurrentrec();

    bool retval = !(tbcomp.eof() || tbref.eof() || (recno > last));

    if (retval)
    {
      if (!checkblockvars())
      {
	retval = false;
	tbcomp.next();
      }
    }
    if (tbref.eof())
      tbcomp.next();

    return retval;
  }

  void _dolink::docalc(void)
  {
    bool retval = !tbref.eof();
    if (retval)
    {
      double compresult = 0.0;
      bool cpmatch;

      wxString valref;
      wxString valcomp;

      for (int i = 0; i < nocps; i++)
      {
	valref = tbref.getstring(cpopts[i].reffield);
	valcomp = tbcomp.getstring(cpopts[i].compfield);;
	compresult = compresult + docompare(valref,
					    valcomp,
					    cpopts[i].comp,
					    cpopts[i].correct,
					    cpopts[i].incorrect, cpopts[i].lim, cpmatch);
      }

#ifdef __DEBUG__
      wxString msg;
      msg.Printf(_T("%g"), compresult);
      msg = valref + _T(" ? ") + valcomp + _T(" = ") + msg;
      linkdebugmsg(msg);
#endif

      if (!ignmin || (ignmin && compresult >= minscore))
      {
	wxString refno, compno, score;
	refno.Printf(_T("%d"), tbref.getcurrentrec());
	compno.Printf(_T("%d"), tbcomp.getcurrentrec());
	score.Printf(_T("%16.12f"), compresult);
	tbscore.setfield(compno, _T("COMPREC"));
	tbscore.setfield(refno, _T("REFREC"));
	//tbscore.setfield(compresult,_T("SCORE"));
	tbscore.setfield(score, _T("SCORE"));
	tbscore.setfield(_T("*"), _T("MATCH"));
	tbscore.appendrec();
      }
      //retval = checkblockvars();
    }
    tbref.next();

  }

  bool _dolink::createscoretbl(void)
  {
    bool retval = false;

    dbtable::fielddef stru[] =
    {
      {
      _T("COMPREC"), dbtable::CHAR, 12, 0},
      {
      _T("REFREC"), dbtable::CHAR, 12, 0},
      {
      _T("SCORE"), dbtable::CHAR, 15, 0},
      {
      _T("MATCH"), dbtable::CHAR, 1, 0}
    };

    wxArrayString ixflds;

    wxFileName matchfile = wxFileName(cfg);
    ntable t;
    matchfile.SetExt(t.defdbext().Right(3));
    wxString name = matchfile.GetName();
    name = name + _T("SCORE");
    matchfile.SetName(name);

    if (!wxFileExists(matchfile.GetFullPath()))
      tbscore.setstructure(stru, 4);

    retval = tbscore.open(matchfile.GetFullPath());

    /*
       if (retval)
       {
       ntable t;
       matchfile.SetExt(t.defixext().Right(3));
       name = matchfile.GetFullPath();
       if (!wxFileExists(name))
       {
       ixflds.Clear();
       ixflds.Add(_T("SCORE"));
       tbscore.makeindex(name, &ixflds);
       }
       tbscore.setindex(name);
       }
     */
    return retval;
  }

}
