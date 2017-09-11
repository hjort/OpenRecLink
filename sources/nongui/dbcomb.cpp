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
// Nome:        dbcomb.cpp
// Propósito:   Classe para combinação de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "dbcomb.h"
#include <wx/fileconf.h>
#include <wx/filename.h>
  _dbcomb::_dbcomb()
{
}

_dbcomb::~_dbcomb()
{
  ref.close();
  comp.close();
  score.close();
  comb.close();
  newref.close();
  newcomp.close();
}

int
_dbcomb::nrecs(void)
{
  int nrecs = 0;
  if (score.isopen())
    nrecs = score.gettotalrecs();
  return nrecs;
}

bool
_dbcomb::init(wxString ncfg, wxString ncomb, wxString new_ref, wxString new_comp)
{
  bool retval = true;

  wxFileConfig *cfgfile = new wxFileConfig(_T(""), _T(""), ncfg, _T(""), wxCONFIG_USE_LOCAL_FILE);
  wxFileName matchfile = wxFileName(ncfg);
  ntable t;
  matchfile.SetExt(t.defdbext().Right(3));
  wxString name = matchfile.GetName();
  name = name + _T("SCORE");
  matchfile.SetName(name);
  wxString aux = matchfile.GetFullPath();
  wxString dir = matchfile.GetPath(wxPATH_GET_SEPARATOR);

  if (wxFileExists(aux))
    retval &= score.open(aux);
  else
    retval = false;

  aux = _T("");
  cfgfile->Read(_T("FILES/COMPNAME"), &aux);
  if (wxFileExists(aux))
    retval &= comp.open(aux);
  else
    retval = false;

  aux = _T("");
  cfgfile->Read(_T("FILES/REFNAME"), &aux);
  if (wxFileExists(aux))
    retval &= ref.open(aux);
  else
    retval = false;

  delete cfgfile;

  if (retval)
  {
    if (!new_ref.IsEmpty())
    {
      if (wxFileExists(new_ref))
	wxRemoveFile(new_ref);
      copystructure(&ref, &newref);
      newref.open(new_ref);
      wxArrayString flds;
      flds.Add(_T("REFREC"));
      nrefix = dir + _T("refix") + t.defixext();
      score.makeindex(nrefix, &flds);
    }
    else
      nrefix = _T("");

    if (!new_comp.IsEmpty())
    {
      if (wxFileExists(new_comp))
	wxRemoveFile(new_comp);
      copystructure(&comp, &newcomp);
      newcomp.open(new_comp);
      wxArrayString flds;
      flds.Add(_T("COMPREC"));
      ncompix = dir + _T("compix") + t.defixext();
      score.makeindex(ncompix, &flds);
    }
    else
      ncompix = _T("");

    if (wxFileExists(ncomb))
      wxRemoveFile(ncomb);
    addstructures(&ref, &comp, &comb);
    retval &= comb.open(ncomb);
  }

  if (retval)
  {
    score.first();
    comp.first();
    ref.first();
  }

  return retval;
}

void
_dbcomb::copyfields(ntable * org, ntable * dest, wxString prefix)
{
  int nflds = org->getnumfields();
  wxString fname, val;
  for (int i = 0; i < nflds; i++)
  {
    fname = org->getfieldname(i);
    val = org->getstring(fname);
    dest->setfield(val, prefix + fname);
  }
}

void
_dbcomb::copystructure(ntable * original, ntable * copy)
{
  int nflds = original->getnumfields();
  dbtable::fielddef * dbstruct = new dbtable::fielddef[nflds];
  for (int i = 0; i < nflds; i++)
  {
    dbstruct[i].fdname = original->getfieldname(i);
    dbstruct[i].len = original->getfieldlen(i);
    dbstruct[i].fdtype = original->getfieldtype(i);
    dbstruct[i].dec = 0;
  }
  copy->setstructure(dbstruct, nflds);

  delete[]dbstruct;
}

void
_dbcomb::addstructures(ntable * _ref, ntable * _comp, ntable * newtable)
{
  int refflds = _ref->getnumfields();
  int compflds = _comp->getnumfields();
  int nflds = refflds + compflds + 3;
  dbtable::fielddef * dbstruct = new dbtable::fielddef[nflds];

  dbstruct[0].fdname = _T("COMPREC");
  dbstruct[0].len = 12;
  dbstruct[0].fdtype = dbtable::CHAR;
  dbstruct[0].dec = 0;
  dbstruct[1].fdname = _T("REFREC");
  dbstruct[1].len = 12;
  dbstruct[1].fdtype = dbtable::CHAR;
  dbstruct[1].dec = 0;
  dbstruct[2].fdname = _T("SCORE");
  dbstruct[2].len = 15;
  dbstruct[2].fdtype = dbtable::CHAR;
  dbstruct[2].dec = 0;
  for (int i = 0; i < refflds; i++)
  {
    dbstruct[i + 3].fdname = _T("R_") + _ref->getfieldname(i);
    dbstruct[i + 3].len = _ref->getfieldlen(i);
    dbstruct[i + 3].fdtype = _ref->getfieldtype(i);
    dbstruct[i + 3].dec = 0;
  }
  for (int i = 0; i < compflds; i++)
  {
    dbstruct[i + 3 + refflds].fdname = _T("C_") + _comp->getfieldname(i);
    dbstruct[i + 3 + refflds].len = _comp->getfieldlen(i);
    dbstruct[i + 3 + refflds].fdtype = _comp->getfieldtype(i);
    dbstruct[i + 3 + refflds].dec = 0;
  }
  newtable->setstructure(dbstruct, nflds);

  delete[]dbstruct;
}

bool
_dbcomb::process(void)
{
  bool retval;

  bool status;
  wxString aux = score.getstring(_T("MATCH"));
  status = (aux == _T("+"));
  wxString pr, pc;

  if (status)
  {
    pc = score.getstring(_T("COMPREC"));
    pr = score.getstring(_T("REFREC"));
    if (!pr.IsEmpty() && !pc.IsEmpty() && ref.find(pr) && comp.find(pc))
    {
      copyfields(&ref, &comb, _T("R_"));
      copyfields(&comp, &comb, _T("C_"));
      comb.setfield(score.getstring(_T("COMPREC")), _T("COMPREC"));
      comb.setfield(score.getstring(_T("REFREC")), _T("REFREC"));
      comb.setfield(score.getstring(_T("SCORE")), _T("SCORE"));
      comb.appendrec();
    }
  }
  /*
     else
     {
     if (newref.isopen())
     {
     copyfields(&ref, &newref, _T(""));
     newref.appendrec();
     }
     if (newcomp.isopen())
     {
     copyfields(&ref, &newcomp, _T(""));
     newcomp.appendrec();
     }
     }
   */
  score.next();
  retval = !score.eof();
  return retval;
}

bool
_dbcomb::purge(void)
{
  bool retval = true;
  if (newref.isopen())
    retval = purge_file(_T('R'));
  if (newcomp.isopen())
    retval = purge_file(_T('C'));
  return retval;
}

bool
_dbcomb::purge_file(wxChar which)
{
  bool retval = true;
  ntable *in, *out;
  wxString frecno, fldname;
  try
  {
    if (which == _T('R'))
    {
      in = &ref;
      out = &newref;
      score.setindex(nrefix);
      fldname = _T("REFREC");
    }
    else
    {
      in = &comp;
      out = &newcomp;
      score.setindex(ncompix);
      fldname = _T("COMPREC");
    }
    in->first();

    while (!in->eof())
    {
      frecno.Printf(_T("%d"), in->getcurrentrec());
      score.first();
      if (!score.find(frecno))
      {
	copyfields(in, out, _T(""));
	out->appendrec();
      }
      else
      {
	bool hasmatch = false;
	while ((score.getstring(fldname) == frecno) && !score.eof())
	{
	  if (score.getstring(_T("MATCH")) == _T("+"))
	  {
	    hasmatch = true;
	    break;
	  }
	  score.next();
	}
	if (!hasmatch)
	{
	  copyfields(in, out, _T(""));
	  out->appendrec();
	}
      }
      in->next();
    }
  }
  catch( ...)
  {
    retval = false;
  }
  return retval;
}
