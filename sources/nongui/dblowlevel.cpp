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
// Nome:        dblowlevel.cpp
// Propósito:   Classe para acesso a disco
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-02
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "dblowlevel.h"

#include "checksep.h"

#ifdef __DEBUG__
#include <iostream>
using namespace std;
#endif

_dbraw::_dbraw()
{
  isbof = false;
  iseof = false;
  openflag = false;
  fp = NULL;
  current = 0l;
  hdr.totalrecs = 0l;
  reclen = 0;
  dbstruct = 0;
};

_dbraw::~_dbraw()
{

};

bool
_dbraw::isopen(void)
{
  return openflag;
}

void
_dbraw::arraytobuffer(void)
{
  if (isopen())
    try
  {
    int offset = 0;
    while (fieldvals.Count() < hdr.nvars)
      fieldvals.Add(_T(""));
    for (int i = 0; i < hdr.nvars; i++)
    {
      if ((offset + dbstruct[i].len) <= MAXRECSIZE)
	strncpy(buffer + offset, (const char *) fieldvals[i].mb_str(wxConvUTF8), dbstruct[i].len);
      offset += dbstruct[i].len;
    }
  }
  catch( ...)
  {
  };
};

void
_dbraw::buffertoarray(void)
{
  if (isopen())
    try
  {
    while (fieldvals.Count() < hdr.nvars)
      fieldvals.Add(_T(""));
    int offset = 0;
    for (int i = 0; i < hdr.nvars; i++)
    {
      memset(varbuff, 0, MAXVARSIZE + 1);
      if ((offset + dbstruct[i].len) <= MAXRECSIZE)
	strncpy(varbuff, buffer + offset, dbstruct[i].len);
      offset += dbstruct[i].len;
      fieldvals[i] = wxString::FromUTF8(varbuff);
    }
  }
  catch( ...)
  {
  };
};

long
_dbraw::xlate(long recno)
{
  long pos = (--recno * reclen) + sizeof(dheader) + (hdr.nvars * sizeof(dfield));
  fseek(fp, pos, SEEK_SET);
  return pos;
}

bool
_dbraw::readrec(long recno)
{
  bool ok = false;
  if (isopen() && (recno > 0) && (recno <= hdr.totalrecs))
  {
    try
    {
      xlate(recno);
      memset(buffer, 0, (reclen + 1));
      int bytes = fread(buffer, reclen, 1, fp);
      ok = (bytes == 1);
      if (ok)
	buffertoarray();
    }
    catch( ...)
    {
    };
  }
  return ok;
};

bool
_dbraw::writerec(long recno)
{
  bool ok = false;
  if (isopen() && (recno > 0))
  {
    try
    {
      arraytobuffer();
      xlate(recno);
      int bytes = fwrite(buffer, reclen, 1, fp);
      ok = (bytes == 1);
    } catch( ...)
    {
    };
  }
  return ok;
};

wxString
_dbraw::getfield(int fldno)
{
  wxString retval = _T("{inv}");
  if (isopen() && (fldno >= 0) && (fldno < hdr.nvars) && (fldno < fieldvals.Count()))
    retval = fieldvals[fldno];
  return retval;
};

long
_dbraw::getlongfield(int fldno)
{
  long retval = 0l;

  wxString val = getfield(fldno);
  if (val != _T("{inv}"))
    try
  {
    if (!val.ToLong(&retval))
      retval = 0;
  }
  catch( ...)
  {
  };

  return retval;
};

double
_dbraw::getfloatfield(int fldno)
{
  double retval = 0.0;

  wxString val = getfield(fldno);
  if (val != _T("{inv}"))
    try
  {
    val.Replace(CVTFROM, CVTTO);
    if (!val.ToDouble(&retval))
      retval = 0.0;
  }
  catch( ...)
  {
  };

  return retval;
};

bool
_dbraw::getlogicalfield(int fldno)
{
  bool retval = false;

  wxString val = getfield(fldno);
  if (val != _T("{inv}"))
    retval = (val == _T("+"));

  return retval;
};

int
_dbraw::fieldcount(void)
{
  return hdr.nvars;
};

wxString
_dbraw::getfieldname(int num)
{
  wxString retval = _T("{inv}");
  if (isopen() && (num >= 0) && (num < hdr.nvars))
    retval = wxString::FromUTF8(dbstruct[num].fdname);
  return retval;
};

dbtable::ftype _dbraw::getfieldtype(int num)
{
  dbtable::ftype retval = dbtable::UNKNOWN;
  if (isopen() && (num >= 0) && (num < hdr.nvars))
    retval = dbstruct[num].fdtype;
  return retval;
};

int
_dbraw::getfieldlen(int num)
{
  int retval = 0;
  if (isopen() && (num >= 0) && (num < hdr.nvars))
    retval = dbstruct[num].len;
  return retval;
};

int
_dbraw::getfielddecimal(int num)
{
  int retval = 0;
  if (isopen() && (num >= 0) && (num < hdr.nvars))
    retval = dbstruct[num].dec;
  return retval;
};

int
_dbraw::getfieldno(wxString fname)
{
  int retval = -1;
  int i;
  bool found = false;
  for (i = 0; i < hdr.nvars; i++)
    if (fname == wxString::FromUTF8(dbstruct[i].fdname))
    {
      found = true;
      break;
    };
  if (found)
    retval = i;
  return retval;
};

int
_dbraw::putfield(int num, wxString value)
{
  int retval = 0;
  if (isopen() && (num >= 0) && (num < hdr.nvars))
  {
    while (fieldvals.Count() < hdr.nvars)
      fieldvals.Add(_T("{inv}"));
    fieldvals[num] = value;
    retval = -1;
  }
  return retval;
};

long
_dbraw::getcurrecno(void)
{
  return current;
};

bool
_dbraw::putrecord(long recno)
{
  bool retval = false;
  if (isopen())
    try
  {
    if (writerec(recno))
    {
      current = recno;
      retval = true;
    }
  }
  catch( ...)
  {
  };
  return retval;
};

bool
_dbraw::appendrecord(void)
{
  bool retval = false;
  long recno = hdr.totalrecs + 1l;
  if (putrecord(recno))
  {
    current = recno;
    hdr.totalrecs++;
    iseof = true;
    isbof = false;
    retval = true;
  }
  return retval;
};

bool
_dbraw::opendatabase(wxString filename, dfield * dbst)
{
  bool retval = false;
  if (isopen())
    closedatabase();

  fieldvals.Clear();

  if (wxFileExists(filename))
  {
    fp = fopen(filename.mb_str(wxConvUTF8), "r+b");
    fseek(fp, 0, SEEK_END);
    long maxrecs = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int bytes = fread(&hdr, sizeof(dheader), 1, fp);
    maxrecs = (maxrecs - sizeof(dheader)) / (sizeof(dfield) * hdr.nvars);
    if (bytes == 1)
    {
      if (!memcmp(hdr.brandname, dtbrand, DBRANDSIZE))
      {
	if (maxrecs != hdr.totalrecs)
	{
	  hdr.totalrecs = maxrecs;
	  fseek(fp, 0, SEEK_SET);
	  fwrite(&hdr, sizeof(dheader), 1, fp);
	  fflush(fp);
	  fseek(fp, 0, SEEK_SET);
	  fread(&hdr, sizeof(dheader), 1, fp);
	}
	dbstruct = new dfield[hdr.nvars];
	retval = true;
	for (int i = 0; i < hdr.nvars; i++)
	  if (fread(&dbstruct[i], sizeof(dfield), 1, fp) != 1)
	    if (retval)
	      retval = false;
      }
    }
    iseof = true;
    isbof = false;
  }
  else if (dbst)
  {
    hdr.nvars = 0;
    while (dbst[hdr.nvars].len)
      hdr.nvars++;
    memcpy(hdr.brandname, dtbrand, DBRANDSIZE);
    hdr.totalrecs = 0L;
    fp = fopen(filename.mb_str(wxConvUTF8), "w+b");
    fseek(fp, 0, SEEK_SET);
    if (fwrite(&hdr, sizeof(dheader), 1, fp) == 1)
    {
      dbstruct = new dfield[hdr.nvars];
      retval = true;
      for (int i = 0; i < hdr.nvars; i++)
	if (fwrite(&dbst[i], sizeof(dfield), 1, fp) != 1)
	{
	  if (retval)
	    retval = false;
	}
	else
	{
	  strncpy(dbstruct[i].fdname, dbst[i].fdname, 15);
	  dbstruct[i].fdtype = dbst[i].fdtype;
	  dbstruct[i].len = dbst[i].len;
	  dbstruct[i].dec = dbst[i].dec;
	}
      iseof = isbof = true;
      fflush(fp);
    }
  }

  if (retval)
  {
    openflag = true;
    for (int i = 0; i < hdr.nvars; i++)
    {
      reclen += dbstruct[i].len;
      fieldvals.Add(_T(""));
    }
    if (reclen > MAXRECSIZE)
      reclen = MAXRECSIZE;
    long bookmark = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    long nrecs = (fsize - (sizeof(dheader) + (hdr.nvars * sizeof(dfield)))) / reclen;
    if (nrecs != hdr.totalrecs)
    {
      fseek(fp, 0, SEEK_SET);
      hdr.totalrecs = nrecs;
      retval = (fwrite(&hdr, sizeof(dheader), 1, fp) == 1);
    }
    fseek(fp, bookmark, SEEK_SET);
  }

  return retval;
};

bool
_dbraw::closedatabase(void)
{
  if (fp != NULL)
  {
    fseek(fp, 0, SEEK_SET);
    fwrite(&hdr, sizeof(dheader), 1, fp);
    fflush(fp);
    fclose(fp);
  }
  if (dbstruct)
  {
    delete[]dbstruct;
    dbstruct = 0;
  }
  reclen = 0;

  isbof = false;
  iseof = false;
  openflag = false;
  fp = NULL;
  current = 0l;
  hdr.totalrecs = 0l;
  if (fieldvals.Count())
    fieldvals.Clear();
  return true;
};

bool
_dbraw::eof(void)
{
  return iseof;
}

bool
_dbraw::bof(void)
{
  return isbof;
}

bool
_dbraw::getrecord(long recno)
{
  bool retval = false;
  if (isopen())
    try
  {
    if ((recno > 0) && (recno <= hdr.totalrecs))
      if (readrec(recno))
      {
	iseof = isbof = false;
	current = recno;
	retval = true;
      }
  }
  catch( ...)
  {
  };
  return retval;
};

bool
_dbraw::getfirstrecord(void)
{
  bool retval = false;
  if (isopen())
    try
  {
    if (readrec(1L))
    {
      current = 1L;
      isbof = true;
      iseof = false;
      retval = true;
    }
  }
  catch( ...)
  {
  };
  return retval;
};

bool
_dbraw::getnextrecord(void)
{
  bool retval = false;
  if (isopen())
    try
  {
    if (current < hdr.totalrecs)
    {
      if (readrec(current + 1L))
      {
	current++;
	iseof = false;
	retval = true;
      }
    }
    else
      iseof = true;
  }
  catch( ...)
  {
  };
  return retval;
};

bool
_dbraw::getprevrecord(void)
{
  bool retval = false;
  if (isopen())
    try
  {
    if (current > 1L)
    {
      if (readrec(current - 1L))
      {
	current--;
	iseof = false;
	retval = true;
      }
    }
    else
      isbof = true;
  }
  catch( ...)
  {
  };
  return retval;
};

bool
_dbraw::getlastrecord(void)
{
  bool retval = false;
  if (isopen())
    try
  {
    if (readrec(hdr.totalrecs))
    {
      current = hdr.totalrecs;
      isbof = false;
      iseof = true;
      retval = true;
    }
  }
  catch( ...)
  {
  };
  return retval;
};

long
_dbraw::noofrecords(void)
{
  return hdr.totalrecs;
};
