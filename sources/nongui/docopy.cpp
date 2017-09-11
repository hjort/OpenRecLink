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
// Nome:        docopy.cpp
// Propósito:   Classe para cópia seletiva de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "docopy.h"

#include "checksep.h"

#include <wx/string.h>
#include <wx/fileconf.h>

namespace dbcopy
{

  _docopy::_docopy(wxString cfgfile, wxString nameout)
  {
    //ctor
    out = nameout;
    cfg = cfgfile;
  }

  _docopy::~_docopy()
  {
    //
    if (tbin.isopen())
      tbin.close();
    if (tbout.isopen())
      tbout.close();
  }

  bool _docopy::createout(void)
  {
    bool retval = false;

    nrecs = tbin.gettotalrecs();
    tbin.first();
    int nflds = outfields.Count();

    dbtable::fielddef * dbstruct = new dbtable::fielddef[nflds];

    int fldno;
    for (int i = 0; i < nflds; i++)
    {
      fldno = tbin.getfieldnum(outfields[i]);
      dbstruct[i].fdname = outfields[i];
      dbstruct[i].fdtype = tbin.getfieldtype(fldno);
      dbstruct[i].len = tbin.getfieldlen(fldno);
      dbstruct[i].dec = tbin.getfielddec(fldno);
    }

    try
    {
      tbout.setstructure(dbstruct, nflds);
      retval = tbout.open(out);
      if (retval)
	tbout.copyrec(0);
    }
    catch( ...)
    {
      tbin.close();
      tbout.close();
    }

    return retval;
  }

  bool _docopy::init(void)
  {
    bool retval = false;

    if (wxFileExists(cfg))
    {
      try
      {
	wxFileConfig *cfgfile =
	  new wxFileConfig(_T(""), _T(""), cfg, _T(""), wxCONFIG_USE_LOCAL_FILE);
	in = _T("");
	cfgfile->Read(_T("GENERAL/FILENAME"), &in);
	if (!in.IsEmpty() && wxFileExists(in))
	{
	  tbin.open(in);
	  long nitems = tbin.getnumfields();
	  wxString aux, tmp;
	  int n;
	  for (int i = 0; i < nitems; i++)
	  {
	    aux.Printf(_T("FIELDS/STATE%d"), i);
	    tmp = cfgfile->Read(aux, _T(""));
	    if (tmp == _T("Y"))
	      outfields.Add(tbin.getfieldname(i));
	  }
	  int s;
	  aux = _T("SELECTIONS/FIELD1");
	  s = cfgfile->Read(aux, -1);
	  if (s > -1)
	    selflds.Add(tbin.getfieldname(s));
	  else
	    selflds.Add(_T(""));
	  aux = _T("SELECTIONS/OP1");
	  s = cfgfile->Read(aux, -1);
	  selops.Add(s);
	  aux = _T("SELECTIONS/VALUE1");
	  tmp = cfgfile->Read(aux, _T(""));
	  selvals.Add(tmp);
	  aux = _T("SELECTIONS/CONNECT1");
	  s = cfgfile->Read(aux, -1);
	  sellnks.Add(s);
	  aux = _T("SELECTIONS/FIELD2");
	  s = cfgfile->Read(aux, -1);
	  if (s > -1)
	    selflds.Add(tbin.getfieldname(s));
	  else
	    selflds.Add(_T(""));
	  aux = _T("SELECTIONS/OP2");
	  s = cfgfile->Read(aux, -1);
	  selops.Add(s);
	  aux = _T("SELECTIONS/VALUE2");
	  tmp = cfgfile->Read(aux, _T(""));
	  selvals.Add(tmp);
	  aux = _T("SELECTIONS/CONNECT2");
	  s = cfgfile->Read(aux, -1);
	  sellnks.Add(s);
	  aux = _T("SELECTIONS/FIELD3");
	  s = cfgfile->Read(aux, -1);
	  if (s > -1)
	    selflds.Add(tbin.getfieldname(s));
	  else
	    selflds.Add(_T(""));
	  aux = _T("SELECTIONS/OP3");
	  s = cfgfile->Read(aux, -1);
	  selops.Add(s);
	  aux = _T("SELECTIONS/VALUE3");
	  tmp = cfgfile->Read(aux, _T(""));
	  selvals.Add(tmp);
	  aux = _T("SELECTIONS/CONNECT3");
	  s = cfgfile->Read(aux, -1);
	  sellnks.Add(s);
	  aux = _T("SELECTIONS/FIELD4");
	  s = cfgfile->Read(aux, -1);
	  if (s > -1)
	    selflds.Add(tbin.getfieldname(s));
	  else
	    selflds.Add(_T(""));
	  aux = _T("SELECTIONS/OP4");
	  s = cfgfile->Read(aux, -1);
	  selops.Add(s);
	  aux = _T("SELECTIONS/VALUE4");
	  tmp = cfgfile->Read(aux, _T(""));
	  selvals.Add(tmp);
	  aux = _T("SELECTIONS/CONNECT4");
	  s = cfgfile->Read(aux, -1);
	  sellnks.Add(s);
	  aux = _T("SELECTIONS/FIELD5");
	  s = cfgfile->Read(aux, -1);
	  if (s > -1)
	    selflds.Add(tbin.getfieldname(s));
	  else
	    selflds.Add(_T(""));
	  aux = _T("SELECTIONS/OP5");
	  s = cfgfile->Read(aux, -1);
	  selops.Add(s);
	  aux = _T("SELECTIONS/VALUE5");
	  tmp = cfgfile->Read(aux, _T(""));
	  selvals.Add(tmp);
	}
	delete cfgfile;
	retval = createout();
      }
      catch( ...)
      {
      };
    }
    return retval;
  }

  bool _docopy::exec(void)	// executa 1 registro por vez
  {
    bool retval = false;
    try
    {
      retval = checksel();
      if (retval)
	tbout.copyrec(&tbin);
      tbin.next();
    }
    catch( ...)
    {
    }
    return retval;
  }

  bool _docopy::isfinished(void)
  {
    bool retval = tbin.eof();
    return retval;
  }

  long _docopy::numberofrecs(void)
  {
    long retval = nrecs;
    return retval;
  }

  bool _docopy::evals(int num)
  {
    bool retval = true;
    wxString vtbl = tbin.getstring(selflds[num]);
    wxString vref = selvals[num];
    switch (selops[num])
    {
    case 0:
      retval = (vtbl > vref);
      break;
    case 1:
      retval = (vtbl >= vref);
      break;
    case 2:
      retval = (vtbl == vref);
      break;
    case 3:
      retval = (vtbl <= vref);
      break;
    case 4:
      retval = (vtbl < vref);
      break;
    case 5:
      retval = (vtbl != vref);
      break;
    default:
      retval = true;
      break;
    }
    return retval;
  }

  bool _docopy::evalf(int num)
  {
    bool retval = true;
    double vtbl = tbin.getdouble(selflds[num]);
    wxString tmp = selvals[num].Trim(false);
    tmp.Replace(CVTFROM, CVTTO);
    double vref;
    if (tmp.ToDouble(&vref))
      switch (selops[num])
      {
      case 0:
	retval = (vtbl > vref);
	break;
      case 1:
	retval = (vtbl >= vref);
	break;
      case 2:
	retval = (vtbl == vref);
	break;
      case 3:
	retval = (vtbl <= vref);
	break;
      case 4:
	retval = (vtbl < vref);
	break;
      case 5:
	retval = (vtbl != vref);
	break;
      default:
	retval = true;
	break;
      }
    return retval;
  }

  bool _docopy::evali(int num)
  {
    bool retval = true;
    long vtbl = tbin.getlong(selflds[num]);
    wxString tmp = selvals[num].Trim(false);
    long vref;
    if (tmp.ToLong(&vref))
      switch (selops[num])
      {
      case 0:
	retval = (vtbl > vref);
	break;
      case 1:
	retval = (vtbl >= vref);
	break;
      case 2:
	retval = (vtbl == vref);
	break;
      case 3:
	retval = (vtbl <= vref);
	break;
      case 4:
	retval = (vtbl < vref);
	break;
      case 5:
	retval = (vtbl != vref);
	break;
      default:
	retval = true;
	break;
      }
    return retval;
  }

  bool _docopy::evalb(int num)
  {
    bool retval = true;
    bool vtbl = tbin.getbool(selflds[num]);
    bool vref = (selvals[num] == _T("+"));
    switch (selops[num])
    {
    case 2:
      retval = (vtbl == vref);
      break;
    default:
      retval = (vtbl != vref);
      break;
    }
    return retval;
  }

  bool _docopy::eval(int num)
  {
    bool retval = true;
    int n = -1;
    if (!selflds[num].IsEmpty())
      n = tbin.getfieldnum(selflds[num]);
    if (n > -1)
      switch (tbin.getfieldtype(n))
      {
      case dbtable::INT:
	retval = evali(num);
	break;
      case dbtable::FLOAT:
	retval = evalf(num);
	break;
      case dbtable::CHAR:
      case dbtable::DATE:
	retval = evals(num);
	break;
      case dbtable::BOOLEAN:
	retval = evalb(num);
	break;
      default:
	retval = true;
	break;
      }
    return retval;
  }

  bool _docopy::checksel(void)
  {
    bool retval;
    if (sellnks[0] != 2)
    {
      if (sellnks[1] != 2)
      {
	if (sellnks[2] != 2)
	{
	  if (sellnks[3] != 2)
	  {
	    switch (sellnks[3])
	    {
	    case 0:
	      retval = eval(4) && eval(3);
	      break;
	    case 1:
	      retval = eval(4) || eval(3);
	      break;
	    }
	  }
	  else
	    retval = eval(3);
	  switch (sellnks[2])
	  {
	  case 0:
	    retval = retval && eval(2);
	    break;
	  case 1:
	    retval = retval || eval(2);
	    break;
	  }
	}
	else
	  retval = eval(2);
	switch (sellnks[1])
	{
	case 0:
	  retval = retval && eval(1);
	  break;
	case 1:
	  retval = retval || eval(1);
	  break;
	}
      }
      else
	retval = eval(1);
      switch (sellnks[0])
      {
      case 0:
	retval = retval && eval(0);
	break;
      case 1:
	retval = retval || eval(0);
	break;
      }
    }
    else
      retval = eval(0);

    return retval;
  }

};
