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
// Nome:        ntable.cpp
// Propósito:   Classe wrapper para record manager
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-02
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "ntable.h"

#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/filefn.h>
#include <wx/msgdlg.h>
#include <stdio.h>
#ifdef __DEBUG__
#include <iostream>
#include <fstream>
#ifdef  debugmsg
#undef  debugmsg
#endif
#define debugmsg(msg) (cracamsgfile << __FILE__ << "line " << __LINE__ << ": " << msg.mb_str(wxConvUTF8) << std::endl)
  std::ofstream cracamsgfile;
#else
#define debugmsg(msg) (msg)
#endif
  _ntable::_ntable()
{
  dbf_file = 0;
  dbfstru = 0;
  ixinuse = _T("");
  iseof = false;
  isbof = false;
  useix = false;
  openflag = false;
  iserr = false;
  errmsg = _T("");
#ifdef __DEBUG__
  cracamsgfile.open("ntable.log");
#endif
}

_ntable::~_ntable()
{
#ifdef __DEBUG__
  cracamsgfile.close();
#endif
}

wxString
_ntable::getstring(wxString fldname)
{
  wxString retval = _T("");
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
    {
      try
      {
	retval = dbf_file->getfield(fldno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao acessar campo"));
      };
    }
  }
  return retval;
}

long
_ntable::getlong(wxString fldname)
{
  long retval = 0l;
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      try
    {
      retval = dbf_file->getlongfield(fldno);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao acessar campo"));
    };
  }
  return retval;
}

double
_ntable::getdouble(wxString fldname)
{
  double retval = 0.0;
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      try
    {
      retval = dbf_file->getfloatfield(fldno);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao acessar campo"));
    };
  }
  return retval;
}

dbtable::date _ntable::getdate(wxString fldname)
{
  dbtable::date retval =
  {
  0, 0, 0};
  if (dbf_file)
  {
    int
      fldno = getfieldnum(fldname);
    wxString
      buff;
    if (fldno != -1)
    {
      try
      {
	buff = dbf_file->getfield(fldno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao acessar campo"));
      };
      wxString
	tmp = buff.Mid(6, 2);
      long
	num;
      if (tmp.ToLong(&num))
	retval.day = num;
      else
	retval.day = 0;
      tmp = buff.Mid(4, 2);
      if (tmp.ToLong(&num))
	retval.month = num;
      else
	retval.month = 0;
      tmp = buff.Mid(0, 4);
      if (tmp.ToLong(&num))
	retval.year = num;
      else
	retval.year = 0;
    }
  }
  return retval;
}

bool
_ntable::getbool(wxString fldname)
{
  bool retval = false;
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      try
    {
      retval = dbf_file->getlogicalfield(fldno);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao acessar campo"));
    };
  }
  return retval;
}

int
_ntable::getnumfields(void)
{
  int numflds = 0;
  if (dbf_file)
    try
  {
    numflds = dbf_file->fieldcount();	//specific
  }
  catch( ...)
  {
    error(_("Erro ao computar número de campos"));
  };
  return numflds;
}

wxString
_ntable::getfieldname(int num)
{
  wxString retval = _T("");
  if (dbf_file)
  {
    try
    {
      if ((num != -1) && num < dbf_file->fieldcount())	//specific
	retval = dbf_file->getfieldname(num);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao identificar nome de campo"));
    };
  }
  return retval;
}

int
_ntable::getfieldnum(wxString fldname)
{
  int retval = -1;
  if (dbf_file)
  {
    try
    {
      retval = dbf_file->getfieldno(fldname);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao identificar número de campo"));
    };
  }
  return retval;
}

dbtable::ftype _ntable::getfieldtype(wxString fldname)
{
  dbtable::ftype retval = dbtable::UNKNOWN;
  if (dbf_file)
  {
    int
      fldno = getfieldnum(fldname);
    if (fldno != -1)
      retval = getfieldtype(fldno);
  }
  return retval;
}

dbtable::ftype _ntable::getfieldtype(int num)
{
  dbtable::ftype retval = dbtable::UNKNOWN;
  if (dbf_file)
  {
    try
    {
      retval = dbf_file->getfieldtype(num);
    }
    catch( ...)
    {
      error(_("Erro ao identificar tipo de campo"));
    };
  }
  return retval;
}

int
_ntable::getfieldlen(wxString fldname)
{
  int retval = 0;
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      retval = getfieldlen(fldno);
  }
  return retval;
}

int
_ntable::getfieldlen(int num)
{
  int retval = 0;
  if (dbf_file)
  {
    try
    {
      if ((num != -1) && num < dbf_file->fieldcount())	//specific
	retval = dbf_file->getfieldlen(num);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao identificar tamanho de campo"));
    };
  }
  return retval;
}

int
_ntable::getfielddec(wxString fldname)
{
  int retval = 0;
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      retval = getfielddec(fldno);
  }
  return retval;
}

int
_ntable::getfielddec(int num)
{
  int retval = 0;
  if (dbf_file)
  {
    try
    {
      if ((num != -1) && num < dbf_file->fieldcount())
	retval = dbf_file->getfielddecimal(num);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao identificar decimais de campo"));
    };
  }
  return retval;
}

bool
_ntable::setfield(wxString value, wxString fldname)
{
  bool retval = false;

  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      retval = setfield(value, fldno);
  }
  return retval;
}

bool
_ntable::setfield(wxString value, int num)
{
  bool retval = false;
  if (dbf_file)
  {
    try
    {
      if (num < getnumfields())
	retval = dbf_file->putfield(num, value);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao atribuir valor a campo"));
    };
  }
  return retval;
}

bool
_ntable::replacerec(void)
{
  bool retval = false;
  if (dbf_file)
  {
    long recno;
    try
    {
      recno = dbf_file->getcurrecno();	//specific
      retval = dbf_file->putrecord(recno);
    } catch( ...)
    {
      error(_("Erro ao substituir registro"));
    };
  }
  return retval;
};

bool
_ntable::appendrec(void)
{
  bool retval = false;
  if (dbf_file)
  {
    try
    {
      retval = dbf_file->appendrecord();
    }
    catch( ...)
    {
      error(_("Erro ao acrescentar registro"));
    };
  }
  return retval;
}


bool
_ntable::open(wxString Filename)
{
  bool retval = false;
  try
  {
    dbf_file = new dbraw();	//specific
  }
  catch( ...)
  {
    dbf_file = 0;
  };
  if (dbf_file)
  {
    if (wxFileExists(Filename))	// se o arquivo existe, abre
    {
      if (dbfstru)
      {
	delete[]dbfstru;
	dbfstru = 0;
      }
      try
      {
	if (dbf_file->opendatabase(Filename))	//specific
	  retval = true;
      }
      catch( ...)
      {
	error(_("Erro ao abrir arquivo"));
      };
    }
    else			// senão, cria...
    {
      if (dbfstru)		// se não tiver criado a estrutura primeiro, não tem como criar
      {
	try
	{
	  if (dbf_file->opendatabase(Filename, dbfstru))	//specific // BUG WORKAROUND!
	  {
	    delete[]dbfstru;
	    dbfstru = 0;
	    retval = true;
	  }
	}
	catch( ...)
	{
	  error(_("Erro ao criar arquivo"));
	};
      }
    }
  }
  if (!retval)
  {
    if (dbf_file)
    {
      try
      {
	dbf_file->closedatabase();
      }
      catch( ...)
      {
      };
      if (dbfstru)
      {
	delete[]dbfstru;
	dbfstru = 0;
      }
      if (useix)
      {
	useix = false;
	ixinuse = _T("");
	dbf_ix.close();
      }
    }
  }
  openflag = retval;
  return retval;
}

bool
_ntable::close(void)
{
  bool retval = false;
  if (dbf_file)
  {
    try
    {
      retval = dbf_file->closedatabase();	//specific
      if (useix)
	dbf_ix.close();
      dbf_file = 0;
    }
    catch( ...)
    {
    };
  }
  openflag = false;
  isbof = false;
  iseof = false;
  useix = false;
  ixinuse = _T("");
  return retval;
}

bool
_ntable::isopen(void)
{
  return openflag;
}

bool
_ntable::eof(void)
{
  bool retval = false;
  if (dbf_file)
    retval = iseof;
  return retval;
}

bool
_ntable::bof(void)
{
  bool retval = false;
  if (dbf_file)
    retval = isbof;
  return retval;
}

bool
_ntable::first(void)
{
  bool retval = false;
  if (dbf_file)
  {
    iseof = false;
    isbof = true;
    if (useix)
    {
      try
      {
	long recno = dbf_ix.first();
	if (recno > -1)
	  retval = dbf_file->getrecord(recno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
    else
    {
      try
      {
	retval = dbf_file->getfirstrecord();	//specific
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
  }
  return retval;
}

bool
_ntable::next(void)
{
  bool retval = false;
  isbof = false;
  if (dbf_file)
  {
    if (useix)
    {
      try
      {
	long recno = dbf_ix.next();
	iseof = dbf_ix.iseof();
	if (!iseof && (recno > -1))
	  retval = dbf_file->getrecord(recno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
    else
    {
      try
      {
	retval = dbf_file->getnextrecord();	//specific
	iseof = dbf_file->eof();
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
  }
  return retval;
}

bool
_ntable::prev(void)
{
  bool retval = false;
  iseof = false;
  if (dbf_file)
  {
    if (useix)
    {
      try
      {
	long recno = dbf_ix.prev();
	isbof = dbf_ix.isbof();
	if (!isbof && (recno > -1))
	  retval = dbf_file->getrecord(recno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
    else
    {
      try
      {
	retval = dbf_file->getprevrecord();	//specific
	isbof = dbf_file->bof();
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
  }
  return retval;
}

bool
_ntable::last(void)
{
  bool retval = false;
  if (dbf_file)
  {
    iseof = true;
    isbof = false;
    if (useix)
    {
      try
      {
	long recno = dbf_ix.last();
	if (recno > -1)
	  retval = dbf_file->getrecord(recno);
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
    else
    {
      try
      {
	retval = dbf_file->getlastrecord();	//specific
	iseof = dbf_file->eof();
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
  }
  return retval;
}

bool _ntable::go(long recno)
{
  bool
    retval = false;
  if (recno && recno <= dbf_file->noofrecords())	//specific
  {
    try
    {
      retval = dbf_file->getrecord(recno);	//specific
      if (retval)		//specific
	iseof = isbof = false;
    }
    catch( ...)
    {
      error(_("Erro ao acessar registro"));
    };
  }
  return retval;
}

bool
_ntable::find(long key)
{
  bool retval = false;
  if (dbf_file)
  {
    if (useix)
    {
      try
      {
	long recno = dbf_ix.xlate(--key);
	if (recno > -1l)
	  retval = dbf_file->getrecord(recno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao procurar registro"));
      };
    }
    else
    {
      if ((key) && key <= gettotalrecs())
      {
	try
	{
	  retval = dbf_file->getrecord(key);	//specific
	}
	catch( ...)
	{
	  error(_("Erro ao procurar registro"));
	};
      }
    }
  }
  if (retval)
    iseof = isbof = false;
  return retval;
}

bool
_ntable::moveby(long step)
{
  bool retval = false;
  if (dbf_file)
  {
    if (useix)
    {
      try
      {
	long recno = dbf_ix.moveby(step);
	if (recno > -1l)
	  retval = dbf_file->getrecord(recno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao procurar registro"));
      };
    }
    else
    {
      long recno = dbf_file->getcurrecno();
      long maxval = dbf_file->noofrecords();
      recno = recno + step;
      if (recno < 1l)
	recno = 1L;
      if (recno > maxval)
	recno = maxval;
      try
      {
	retval = dbf_file->getrecord(recno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao procurar registro"));
      };
    }
  }
  iseof = isbof = false;
  return retval;
}


bool
_ntable::find(wxString key)
{
  bool retval = false;
  if (dbf_file)
  {
    if (useix)
    {
      try
      {
	long recno = dbf_ix.find(key);
	if (recno > -1l)
	  retval = dbf_file->getrecord(recno);	//specific
      }
      catch( ...)
      {
	error(_("Erro ao procurar registro"));
      };
    }
    else
    {
      long recno;		// this might be a PROBLEM
      if (key.ToLong(&recno))
      {
	if (recno && (recno <= gettotalrecs()))
	{
	  try
	  {
	    retval = dbf_file->getrecord(recno);	//specific
	  }
	  catch( ...)
	  {
	    error(_("Erro ao procurar registro"));
	  };
	}
      }
    }
  }
  if (retval)
    iseof = isbof = false;
  return retval;
}

long
_ntable::gettotalrecs(void)
{
  long retval = 0l;
  if (dbf_file)
    try
  {
    retval = dbf_file->noofrecords();	//specific
  }
  catch( ...)
  {
    error(_("Erro ao computar total de registros"));
  };
  return retval;
}

long
_ntable::getcurrentrec(void)
{
  long retval = 0l;
  if (dbf_file)
    try
  {
    retval = dbf_file->getcurrecno();	//specific
  }
  catch( ...)
  {
    error(_("Erro ao computar número de registro"));
  };
  return retval;
}

wxString
_ntable::makekey(void)
{
  wxString ixexpr, tmp;

  int nitems = ixflds.Count();
  ixexpr = _T("");
  try
  {
    for (int i = 0; i < nitems; i++)
    {
      tmp = ixflds[i];
      tmp = getstring(tmp);
      if (i)
	ixexpr += tmp;
      else
	ixexpr = tmp;
    }
  }
  catch( ...)
  {
  };

  return ixexpr;
};

bool
_ntable::makeindex(wxString name, wxArrayString * fields)
{
  bool retval = false;
  useix = false;
  ixinuse = _T("");

  if (dbf_file)
  {
    try
    {
      if (dbf_ix.isopen())
	dbf_ix.close();
      if (wxFileExists(name))
	wxRemoveFile(name);
      int nitems = fields->GetCount();
      int keylen = 0;
      wxString ixexpr, tmp;
      for (int i = 0; i < nitems; i++)
      {
	tmp = fields->Item(i);
	if (i)
	  ixexpr = ixexpr + _T(",") + tmp;
	else
	  ixexpr = tmp;
	keylen += getfieldlen(tmp);
      }
      dbf_ix.init(ixexpr, keylen);
      dbf_ix.open(name);

      ixexpr = _T("");
      long totalrecs = dbf_file->noofrecords();	//specific
      if (!totalrecs)
	iseof = true;
      else
	first();
      long read = 0;
      int click = 0;
      while (!iseof)
      {
	for (int i = 0; i < nitems; i++)
	{
	  tmp = fields->Item(i);
	  tmp = getstring(tmp);
	  if (i)
	    ixexpr += tmp;
	  else
	    ixexpr = tmp;
	}
	long recpos = getcurrentrec();
	dbf_ix.add_rec(ixexpr, recpos);
	read++;
	next();
	click++;
	if (click > 99)
	{
	  wxYieldIfNeeded();
	  click = 0;
	}
      }
      // ATTENTION!!!!
      retval = ((read == gettotalrecs()) && dbf_ix.sort_file());
      dbf_ix.close();
      first();
    }
    catch( ...)
    {
      error(_("Erro ao criar índice"));
    };
  }
  return retval;
}

bool
_ntable::reindex(void)
{
  bool retval = false;

  if (dbf_file)
    if (useix)
    {
      wxString expr = dbf_ix.getexpr();
      wxArrayString tmp = unpackarray(expr, _T(","));
      dbf_ix.close();
      makeindex(ixinuse, &tmp);
      setindex(ixinuse);
    }
  return retval;
}

bool
_ntable::setindex(wxString name)
{
  bool retval = false;

  if (dbf_file)
  {
    try
    {
      if (useix)
      {
	dbf_ix.close();
	useix = false;
	ixinuse = _T("");
	ixflds.Clear();
      }
      if (!name.IsEmpty() && wxFileExists(name))
      {
	dbf_ix.open(name);
	wxString expr = dbf_ix.getexpr();
	ixflds = unpackarray(expr, _T(","));
	if (dbf_ix.gettotalrecs() != gettotalrecs())
	  retval = false;
	else
	  retval = true;
	useix = true;
	ixinuse = name;
      }
      else
	retval = name.IsEmpty();
    }
    catch( ...)
    {
      error(_("Erro ao abrir índice"));
    };
  }
  return retval;
}

void
_ntable::setstructure(wxString strstru)
{
  dbtable::fielddef * dbstruct = unpackstru(strstru);
  int nflds = 0;
  while (!dbstruct[nflds].fdname.IsEmpty())
    nflds++;
  setstructure(dbstruct, nflds);
}

void
_ntable::setstructure(wxArrayString arrstru)
{
  dbtable::fielddef * dbstruct = array2stru(arrstru);
  int nflds = arrstru.Count();
  setstructure(dbstruct, nflds);
}

void
_ntable::setstructure(dbtable::fielddef * dbstruct, int nflds)
{				//specific
  if (dbfstru)
    delete[]dbfstru;
  dbfstru = new dfield[nflds + 1];
  for (int i = 0; i < nflds; i++)
  {
    strncpy(dbfstru[i].fdname, (const char *) dbstruct[i].fdname.mb_str(wxConvUTF8), 15);
    dbfstru[i].fdtype = dbstruct[i].fdtype;
    dbfstru[i].len = dbstruct[i].len;
    dbfstru[i].dec = dbstruct[i].dec;
  }
  dbfstru[nflds].fdname[0] = '\0';
  dbfstru[nflds].fdtype = dbtable::UNKNOWN;
  dbfstru[nflds].len = 0;
  dbfstru[nflds].dec = 0;
}

dbtable::fielddef * _ntable::getstructure(void)
{
  dbtable::fielddef * retval = 0;

  if (openflag)
  {
    int
      nflds = getnumfields();
    retval = new dbtable::fielddef[nflds + 1];
    try
    {
      for (int i = 0; i < nflds; i++)
      {
	retval[i].fdname = getfieldname(i);
	retval[i].fdtype = getfieldtype(i);
	retval[i].len = getfieldlen(i);
	retval[i].dec = getfielddec(i);
      }
      retval[nflds].fdname = _T("");
      retval[nflds].fdtype = dbtable::UNKNOWN;
      retval[nflds].len = 0;
      retval[nflds].dec = 0;
    } catch( ...)
    {
      iserr = true;
      delete[]retval;
      retval = 0;
    };
  }
  return retval;
}

bool
_ntable::copystru(dbtable::table * tbl)
{
  bool retval = false;

  if (openflag)
    close();

  int nflds = tbl->getnumfields();
  wxArrayString tmp;
  dbtable::fielddef tmpfld;

  try
  {
    for (int i = 0; i < nflds; i++)
    {
      tmpfld.fdname = tbl->getfieldname(i);
      tmpfld.fdtype = tbl->getfieldtype(i);
      tmpfld.len = tbl->getfieldlen(i);
      tmpfld.dec = tbl->getfielddec(i);
      tmp.Add(packfield(tmpfld));
    }
    setstructure(tmp);
    retval = true;
  } catch( ...)
  {
    iserr = true;
  };

  return retval;
};

bool
_ntable::copyrec(dbtable::table * tbl)
{
  bool retval = false;

  if (!tbl)
  {
    if (copyfrom.Count())
      copyfrom.Clear();
    if (copyto.Count())
      copyto.Clear();
  }
  if (openflag && tbl)
  {
    int nflds = tbl->getnumfields();
    if (!copyfrom.Count())
    {
      wxString fldname;
      int fldnum;
      for (int i = 0; i < nflds; i++)
      {
	fldname = tbl->getfieldname(i);
	fldnum = getfieldnum(fldname);
	if (fldnum != -1)
	  if (tbl->getfieldtype(i) == getfieldtype(fldnum))
	  {
	    copyfrom.Add(fldname);
	    copyto.Add(fldnum);
	  }
      }
    }
    try
    {
      wxString fldname;
      for (int i = 0; i < copyfrom.Count(); i++)
	if (i < copyto.Count())
	  setfield(tbl->getstring(copyfrom[i]), copyto[i]);
      retval = appendrec();
    }
    catch( ...)
    {
      iserr = true;
    };
  }
  return retval;
};

wxString
_ntable::getrecord(void)
{
  wxString retval = _T("");
  if (openflag)
  {
    wxArrayString tmp;
    int nflds = getnumfields();
    try
    {
      for (int i = 0; i < nflds; i++)
	tmp.Add(getstring(getfieldname(i)));
      retval = packarray(tmp, _T("|"));
    } catch( ...)
    {
      iserr = true;
    };
  }
  return retval;
};

wxString
_ntable::getheader(void)
{
  wxString retval = _T("");

  dbtable::fielddef * dbstruct = getstructure();

  if (dbstruct)
    retval = packstru(dbstruct);

  return retval;
};

bool
_ntable::str2rec(wxString recstr, wxString sep)
{
  bool retval = false;
  if (openflag)
  {
    wxArrayString tmp = unpackarray(recstr, sep);
    int arrflds = tmp.GetCount();
    int nflds = getnumfields();
    int i;
    for (i = 0; (i < arrflds) && (i < nflds); i++)
      setfield(tmp[i], i);
    for (; i < nflds; i++)
      setfield(_T(""), i);
    retval = appendrec();
  }
  return retval;
};

wxString
_ntable::getcurrentidx(void)
{
  return ixinuse;
};

 void
_ntable::error(wxString errmsg)
{
  iserr = false;
  wxMessageBox(errmsg, _("ERRO"), wxICON_ERROR);
};

wxString
_ntable::defdbext(void)
{
  char buff[5];
  buff[0] = '.';
  memcpy(buff + 1, dtbrand, 3);
  buff[4] = '\0';
  wxString retval = wxString::FromUTF8(buff);
  retval = retval.Lower();
  return retval;
  //return _T(".dat");
};

wxString
_ntable::defixext(void)
{
  char buff[5];
  buff[0] = '.';
  memcpy(buff + 1, ixbrand, 3);
  buff[4] = '\0';
  wxString retval = wxString::FromUTF8(buff);
  retval = retval.Lower();
  return retval;
  //return _T(".idx");
};

bool
_ntable::iserror(void)
{
  return iserr;
};

void
_ntable::clearerror(void)
{
  iserr = false;
};
