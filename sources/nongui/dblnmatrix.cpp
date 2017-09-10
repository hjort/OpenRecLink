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
// Nome:        dblnmatrix.cpp
// Propósito:   Classe para geração de matrizes para cálculo de parâmetros de relacionamento
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "dblnmatrix.h"
#include "progressdialog.h"

#include "checksep.h"

//#include <wx/msgdlg.h>

#include <wx/filename.h>
#include <wx/fileconf.h>

namespace dblnmatrix
{

  _domatrix::_domatrix(wxString cfgfile)
  {
    cfg = cfgfile;
    blockopts = 0;
    cpopts = 0;
    refrecs = 0L;
    comprecs = 0L;
    freqmatch = 0;
  }

  long _domatrix::getrefrecs(void)
  {
    return refrecs;
  }

  long _domatrix::getcomprecs(void)
  {
    return comprecs;
  }

  _domatrix::~_domatrix()
  {
    if (blockopts)
      delete[]blockopts;
    if (cpopts)
      delete[]cpopts;
    if (freqmatch)
      delete[]freqmatch;

    tbcomp.close();
    tbref.close();
  }

  bool _domatrix::init(wxWindow * w)
  {
    bool retval = false;
    fullrun = false;

    parent = w;

    wxFileConfig *cfgfile = new wxFileConfig(_T(""), _T(""), cfg, _T(""), wxCONFIG_USE_LOCAL_FILE);
    wxString aux = _T("");
    cfgfile->Read(_T("FILES/COMPNAME"), &aux);

    if (wxFileExists(aux))
    {
      if (tbcomp.open(aux))
      {
	comprecs = tbcomp.gettotalrecs();	//wxMessageBox(wxString::Format(_T("%d"),comprecs),_T("DUUUH"));
	aux = _T("");
	cfgfile->Read(_T("FILES/REFNAME"), &aux);
	if (wxFileExists(aux))
	{
	  if (tbref.open(aux))
	  {
	    refrecs = tbref.gettotalrecs();	//wxMessageBox(wxString::Format(_T("%d"),refrecs),_T("DUUUH"));
	    wxString refname = aux;
	    aux = _T("");
	    cfgfile->Read(_T("GENERAL/IXNAME"), &aux);
	    wxString ixname = aux;
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
	      tbcomp.first();	//if (tbcomp.eof()) wxMessageBox(_T("SCREWED UP"),_T("DUUUH"));
	      retval = true;
	      nlines = 0L;
	      cfgfile->Read(_T("COMPARE/NLINES"), &nlines);
	      nocps = (int) nlines;
	      cpopts = new reclink::comparecfg[nocps];
	      freqmatch = new double[nocps];
	      for (int i = 0; i < nocps; i++)
	      {
		freqmatch[i] = 0.0;
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

    delete cfgfile;

    return retval;
  }

  bool _domatrix::checkmasterndx(wxString fname, wxString ixname)
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

  void _domatrix::reset(void)
  {
    tbcomp.first();
    tbref.first();
  }

  bool _domatrix::checkmatches(long linecount)
  {
    bool retval = true;

    for (int i = 0; i < nocps; i++)
    {
      freqmatch[i] = (freqmatch[i] * 100.0) / (double) linecount;
      if (!freqmatch[i])
      {
	retval = false;
	break;
      }
    }

    return retval;
  }



  bool _domatrix::findblockbeg(void)
  {
    bool retval = false;

    while (!retval && !tbcomp.eof())
    {
      wxString key = _T("");
      //wxMessageBox(wxString::Format(_T("%d"),noblks),_T("DUUUH"));
      for (int i = 0; i < noblks; i++)
	key += tbcomp.getstring(blockopts[i].compfield);
      //wxString key = tbref.makekey();
      //wxMessageBox(key,_T("DUUUH"));
      retval = tbref.find(key);
      if (!retval)
	tbcomp.next();
    }
    if (tbcomp.eof())
      fullrun = true;		// wxMessageBox(_("At end"),_T("NOTE"));

    return retval;
  }

  long domatrix::therecno(void)
  {
    return tbcomp.getcurrentrec();
  }

  bool domatrix::reachedend(void)
  {
    return fullrun;
  }

  bool _domatrix::checkblockvars(void)
  {
    bool retval = true;

    for (int i = 0; i < noblks; i++)
      
    {
      wxString compfld = blockopts[i].compfield;
      wxString reffld = blockopts[i].reffield;
      wxString compval = tbcomp.getstring(compfld);
      wxString refval = tbref.getstring(reffld);
      if (compval != refval)
	
      {
	retval = false;
	break;
      }
    }

    return retval;
  }

  bool _domatrix::isinblock(void)
  {
    bool retval = !(tbcomp.eof() || tbref.eof());

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

  void _domatrix::domatrix_nb(wxArrayString * matches, long refno, long compno)
  {
    double compresult = 0.0;
    bool cpmatch;

    if (matches)
      matches->Clear();

    wxString valref;
    wxString valcomp;

    tbref.go(refno);
    tbcomp.go(compno);

    for (int i = 0; i < nocps; i++)
    {
      valref = tbref.getstring(cpopts[i].reffield);
      valcomp = tbcomp.getstring(cpopts[i].compfield);;
      compresult = compresult + docompare(valref,
					  valcomp,
					  cpopts[i].comp,
					  cpopts[i].correct,
					  cpopts[i].incorrect, cpopts[i].lim, cpmatch);
      if (matches)
      {
	if (cpmatch)
	{
	  matches->Add(_T("1 "));
	  freqmatch[i] += 1.0;
	}
	else
	  matches->Add(_T("0 "));
      }

    }
  }

  void _domatrix::domatrix(wxArrayString * matches)
  {
    bool retval = !tbref.eof();
    if (retval)
    {
      double compresult = 0.0;
      bool cpmatch;

      if (matches)
	matches->Clear();

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
	if (matches)
	{
	  if (cpmatch)
	    matches->Add(_T("1 "));
	  else
	    matches->Add(_T("0 "));
	}

      }

    }
    tbref.next();
  }

}
