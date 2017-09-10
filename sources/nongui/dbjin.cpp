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
// Nome:        dbjin.cpp
// Propósito:   Classe para associação (join) de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "dbjin.h"
#include "progressdialog.h"

#include <wx/window.h>
#include <wx/fileconf.h>
#include <wx/filename.h>

_dbjin::_dbjin(wxWindow * w)
{
  masterkey = _T("");
  updatekey = _T("");
  mastercheck = 0;
  updatecheck = 0;
  mastersel = 0;
  updatesel = 0;
  mastername = _T("");
  parent = w;
}

_dbjin::~_dbjin()
{
  if (mastercheck)
    delete[]mastercheck;
  if (updatecheck)
    delete[]updatecheck;
  joined.close();
}

bool
_dbjin::init(wxString cfgname, wxString outname)
{
  bool retval = false;

  loadcfg(cfgname);
  if (master.isopen() && update.isopen())
  {
    if (!masterkey.IsEmpty() && !updatekey.IsEmpty() && mastersel && updatesel)
    {
      addstructures(&master, &update, &joined);
      if (joined.open(outname))
      {
	if (masterkey != _T("@RECNO"))
	{
	  wxFileName outfile = wxFileName(mastername);
	  ntable t;
	  wxString ixfile =
	    outfile.GetPath(wxPATH_GET_SEPARATOR) + outfile.GetName() + masterkey + t.defixext();

	  if (!wxFileExists(ixfile))
	  {
	    wxArrayString kyflds;
	    kyflds.Add(masterkey);
	    progressdialog *dlg = new progressdialog(parent);
	    dlg->Show();
	    dlg->Update();
	    if (parent)
	      parent->Update();
	    wxYieldIfNeeded();
	    if (master.makeindex(ixfile, &kyflds))
	      if (master.setindex(ixfile))
		//retval = master.reindex();
		retval = true;
	    dlg->Close();
	    delete dlg;
	  }
	  else
	    retval = master.setindex(ixfile);
	}
	else
	  retval = true;
	if (retval)
	{
	  master.first();
	  update.first();
	}
      }
    }
  }

  return retval;
}

long
_dbjin::norecs(void)
{
  return update.gettotalrecs();
}

bool
_dbjin::exec(void)
{
  //bool retval = !update.eof();
  //if (retval)
  //{
  bool retval;

  wxString ref;

  if (updatekey != _T("@RECNO"))
    ref = update.getstring(updatekey);
  else
    ref.Printf(_T("%d"), update.getcurrentrec());

  clearfields(&joined);

  if (master.find(ref))
    copyfields(&master, mastercheck, &joined, _T("M_"));

  copyfields(&update, updatecheck, &joined, _T("U_"));
  joined.appendrec();

  /*
     if (master.find(ref))
     {
     copyfields(&master, mastercheck, &joined, _T("M_"));
     copyfields(&update, updatecheck, &joined, _T("U_"));
     joined.appendrec();
     }
   */

  update.next();
  retval = !update.eof();
  //}

  return retval;
}

void
_dbjin::addstructures(ntable * _master, ntable * _update, ntable * newtable)
{
  int masterflds = _master->getnumfields();
  int updateflds = _update->getnumfields();
  int nflds = mastersel + updatesel;
  dbtable::fielddef * dbstruct = new dbtable::fielddef[nflds];

  int nfld = 0;
  for (int i = 0; i < masterflds; i++)
  {
    if (mastercheck[i])
    {
      dbstruct[nfld].fdname = _T("M_") + _master->getfieldname(i);
      dbstruct[nfld].len = _master->getfieldlen(i);
      dbstruct[nfld].fdtype = _master->getfieldtype(i);
      dbstruct[nfld++].dec = 0;
    }
  }
  for (int i = 0; i < updateflds; i++)
  {
    if (updatecheck[i])
    {
      dbstruct[nfld].fdname = _T("U_") + _update->getfieldname(i);
      dbstruct[nfld].len = _update->getfieldlen(i);
      dbstruct[nfld].fdtype = _update->getfieldtype(i);
      dbstruct[nfld++].dec = 0;
    }
  }
  newtable->setstructure(dbstruct, nflds);

  delete[]dbstruct;
}

void
_dbjin::loadcfg(wxString cfgname)
{
  wxFileConfig *cfgfile =
    new wxFileConfig(_T(""), _T(""), cfgname, _T(""), wxCONFIG_USE_LOCAL_FILE);

  mastername = _T("");
  cfgfile->Read(_T("FILES/MASTER"), &mastername);
  if (!mastername.IsEmpty())
    master.open(mastername);
  wxString aux = _T("");
  cfgfile->Read(_T("FILES/UPDATE"), &aux);
  if (!aux.IsEmpty())
    update.open(aux);
  long nitems = 0l;
  cfgfile->Read(_T("KEYS/MASTERSEL"), &nitems);
  if (mastercheck)
    delete[]mastercheck;
  mastercheck = new bool[master.getnumfields()];
  if ((int) nitems < master.getnumfields() && (nitems >= 0L))
    masterkey = master.getfieldname((int) nitems);
  else
    masterkey = _T("@RECNO");
  if (updatecheck)
    delete[]updatecheck;
  updatecheck = new bool[update.getnumfields()];
  cfgfile->Read(_T("KEYS/UPDATESEL"), &nitems);
  if ((int) nitems < update.getnumfields() && (nitems >= 0L))
    updatekey = update.getfieldname((int) nitems);
  else
    updatekey = _T("@RECNO");

  int items = master.getnumfields();
  wxString tmp;
  mastersel = 0;
  for (int i = 0; i < items; i++)
  {
    tmp = _T("");
    aux.Printf(_T("FIELDS/MASTER%d"), i);
    cfgfile->Read(aux, &tmp);
    mastercheck[i] = (tmp == _T("Y"));
    if (mastercheck[i])
      mastersel++;
  }
  items = update.getnumfields();
  updatesel = 0;
  for (int i = 0; i < items; i++)
  {
    tmp = _T("");
    aux.Printf(_T("FIELDS/UPDATE%d"), i);
    cfgfile->Read(aux, &tmp);
    updatecheck[i] = (tmp == _T("Y"));
    if (updatecheck[i])
      updatesel++;
  }

  delete cfgfile;
}

void
_dbjin::copyfields(ntable * org, bool * permits, ntable * dest, wxString prefix)
{
  int nflds = org->getnumfields();
  wxString fname, val;
  for (int i = 0; i < nflds; i++)
  {
    if (permits[i])
    {
      fname = org->getfieldname(i);
      val = org->getstring(fname);
      dest->setfield(val, prefix + fname);
    }
  }
}

void
_dbjin::clearfields(ntable * tbl)
{
  int n = tbl->getnumfields();
  for (int i = 0; i < n; i++)
    tbl->setfield(_T(""), i);
}
