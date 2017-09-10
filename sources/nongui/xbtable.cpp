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
// Nome:        xbtable.cpp
// Propósito:   Classe wrapper para xbase (acesso a arquivos dbf)
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "xbtable.h"
#include "dbutils.h"

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
#define debugmsg(msg) (xmsgfile << __FILE__ << "line " << __LINE__ << ": " << msg.mb_str(wxConvUTF8) << std::endl)
  std::ofstream xmsgfile;
#else
#define debugmsg(msg) (msg)
#endif
  _xbtable::_xbtable()
{
  dbf_file = 0;
  ixinuse = _T("");
  dbfstru = 0;
  iseof = false;
  isbof = false;
  useix = false;
  openflag = false;
  iserr = false;
  errmsg = _T("");
  _currecno = 0l;
#ifdef __DEBUG__
  xmsgfile.open("xbtable.log");
#endif
}

_xbtable::~_xbtable()
{
  if (openflag)
    close();
#ifdef __DEBUG__
  xmsgfile.close();
#endif
}

wxString
_xbtable::getstring(wxString fldname)
{
  wxString retval = _T("");
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
    {
      char buff[256];		//
      xbShort br;		//specific
      try
      {
	br = dbf_file->GetField(fldno, buff);	//specific
      } catch( ...)
      {
	error(_("Erro ao acessar campo"));
      };
      if (br)
	retval = wxString(buff, wxConvUTF8).Trim();
    }
  }
  return retval;
}

long
_xbtable::getlong(wxString fldname)
{
  long retval = 0l;
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      try
    {
      retval = dbf_file->GetLongField(fldno);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao acessar campo"));
    };
  }
  return retval;
}

double
_xbtable::getdouble(wxString fldname)
{
  double retval = 0.0;
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      try
    {
      retval = dbf_file->GetFloatField(fldno);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao acessar campo"));
    };
  }
  return retval;
}

dbtable::date _xbtable::getdate(wxString fldname)
{
  dbtable::date retval =
  {
  0, 0, 0};
  if (dbf_file)
  {
    int
      fldno = getfieldnum(fldname);
    if (fldno != -1)
    {
      char
	buff[11];		//specific
      xbShort
	br;			//specific
      try
      {
	br = dbf_file->GetField(fldno, buff);	//specific
      } catch( ...)
      {
	error(_("Erro ao acessar campo"));
      };
      if (br > 9)
      {
	retval.day = atoi(buff + 8);
	buff[8] = '\0';
	retval.month = atoi(buff + 5);
	buff[5] = '\0';
	retval.year = atoi(buff);
      }
    }
  }
  return retval;
}

bool
_xbtable::getbool(wxString fldname)
{
  bool retval = false;
  if (dbf_file)
  {
    int fldno = getfieldnum(fldname);
    if (fldno != -1)
      try
    {
      retval = dbf_file->GetLogicalField(fldno);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao acessar campo"));
    };
  }
  return retval;
}

int
_xbtable::getnumfields(void)
{
  int numflds = 0;
  if (dbf_file)
    try
  {
    numflds = dbf_file->FieldCount();	//specific
  }
  catch( ...)
  {
    error(_("Erro ao computar número de campos"));
  };
  return numflds;
}

wxString
_xbtable::getfieldname(int num)
{
  wxString retval = _T("");
  if (dbf_file)
  {
    try
    {
      if ((num != -1) && num < dbf_file->FieldCount())	//specific
	retval = wxString(dbf_file->GetFieldName(num), wxConvUTF8);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao identificar nome de campo"));
    };
  }
  return retval;
}

int
_xbtable::getfieldnum(wxString fldname)
{
  int retval = -1;
  if (dbf_file)
  {
    char fname[256];		//specific
    strcpy(fname, fldname.mb_str(wxConvUTF8));	//specific
    try
    {
      retval = dbf_file->GetFieldNo(fname);	//specific
    } catch( ...)
    {
      error(_("Erro ao identificar número de campo"));
    };
  }
  return retval;
}

dbtable::ftype _xbtable::getfieldtype(wxString fldname)
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

dbtable::ftype _xbtable::getfieldtype(int num)
{
  dbtable::ftype retval = dbtable::UNKNOWN;
  if (dbf_file)
  {
    try
    {
      if ((num != -1) && num < dbf_file->FieldCount())
	switch (dbf_file->GetFieldType(num))	//specific
	{
	case 'C':
	  retval = dbtable::CHAR;
	  break;
	case 'D':
	  retval = dbtable::DATE;
	  break;
	case 'L':
	  retval = dbtable::BOOLEAN;
	  break;
	case 'N':
	  if (dbf_file->GetFieldDecimal(num))
	    retval = dbtable::FLOAT;
	  else
	    retval = dbtable::INT;
	  break;
	case 'F':
	  retval = dbtable::FLOAT;
	  break;
	default:
	  break;
	}
    }
    catch( ...)
    {
      error(_("Erro ao identificar tipo de campo"));
    };
  }
  return retval;
}

int
_xbtable::getfieldlen(wxString fldname)
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
_xbtable::getfieldlen(int num)
{
  int retval = 0;
  if (dbf_file)
  {
    try
    {
      if ((num != -1) && num < dbf_file->FieldCount())	//specific
	retval = dbf_file->GetFieldLen(num);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao identificar tamanho de campo"));
    };
  }
  return retval;
}

int
_xbtable::getfielddec(wxString fldname)
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
_xbtable::getfielddec(int num)
{
  int retval = 0;
  if (dbf_file)
  {
    try
    {
      if ((num != -1) && num < dbf_file->FieldCount())
	retval = dbf_file->GetFieldDecimal(num);	//specific
    }
    catch( ...)
    {
      error(_("Erro ao identificar decimais de campo"));
    };
  }
  return retval;
}

bool
_xbtable::setfield(wxString value, wxString fldname)
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
_xbtable::setfield(wxString value, int num)
{
  bool retval = false;
  if (dbf_file)
  {
    try
    {
      if (num < getnumfields())
	if (dbf_file->PutField(num, value.mb_str(wxConvUTF8)) == XB_NO_ERROR)	//specific
	  retval = true;
    }
    catch( ...)
    {
      error(_("Erro ao atribuir valor a campo"));
    };
  }
  return retval;
}

bool
_xbtable::replacerec(void)
{
  bool retval = false;
  if (dbf_file)
  {
    long recno;
    try
    {
      recno = dbf_file->GetCurRecNo();	//specific
      if (dbf_file->PutRecord(recno) == XB_NO_ERROR)	//specific
	retval = true;
    }
    catch( ...)
    {
      error(_("Erro ao substituir registro"));
    };
  }
  return retval;
};

bool
_xbtable::appendrec(void)
{
  bool retval = false;
  if (dbf_file)
  {
    try
    {
      if (dbf_file->AppendRecord() == XB_NO_ERROR)	//specific
	retval = true;
    }
    catch( ...)
    {
      error(_("Erro ao acrescentar registro"));
    };
  }
  return retval;
}

bool
_xbtable::writeheader(wxString name)	//specific
{
  bool retval = false;
  try
  {
    struct headerbeg
    {
      unsigned char type;
      unsigned char date[3];
      char nrecs[4];
      short int hdrsiz;
      short int recsiz;
      char filler[20];
    };
    struct fldrec
    {
      char name[11];
      char type;
      unsigned char filler[4];
      unsigned char len;
      unsigned char dec;
      unsigned char filler2[14];
    };
    struct headerbeg hdbg;
    struct fldrec frec;
    memset(&hdbg, 0, 32);
    hdbg.type = 0x03;

    hdbg.date[0] = 0x70;
    hdbg.date[1] = 0x07;
    hdbg.date[2] = 0x12;

    short int nflds = 0;
    short int reclen = 0;
    int i = 0;
    while (dbfstru[i].FieldLen)
    {
      nflds++;
      reclen += dbfstru[i].FieldLen;
      i++;
    }
    nflds = nflds * 32 + 32 + 1;
    hdbg.hdrsiz = nflds;
    hdbg.recsiz = ++reclen;
    FILE *fp = fopen(name.mb_str(wxConvUTF8), "wb");

    if (!fp)
      throw;
    if (!dbfstru)
      throw;

    i = 0;
    fseek(fp, 0, SEEK_SET);

    fwrite(&hdbg, 32, 1, fp);

    while (dbfstru[i].FieldLen)
    {
      memset(&frec, 0, 32);
      strncpy(frec.name, dbfstru[i].FieldName, 10);
      frec.type = dbfstru[i].Type;
      frec.len = (unsigned char) dbfstru[i].FieldLen;
      frec.dec = (unsigned char) dbfstru[i].NoOfDecs;
      fwrite(&frec, 32, 1, fp);
      i++;
    }
    char mark = 0x0d;
    fwrite(&mark, 1, 1, fp);
    fclose(fp);
    retval = true;
  } catch( ...)
  {
    retval = false;
  };
  return retval;
}

long
_xbtable::check_file_size(const char *fname)
{
  FILE *fp = fopen(fname, "rb");

  if (!fp)
    throw;
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fclose(fp);
  return size;
}

bool
_xbtable::open(wxString Filename)
{
  bool retval = false;
  try
  {
    dbf_file = new xbDbf(&x);	//specific
  }
  catch( ...)
  {
    dbf_file = 0;
  };
  if (dbf_file)
  {
    //dbf_file->SetVersion(4);
    if (wxFileExists(Filename))	// se o arquivo existe, abre
    {
      if (dbfstru)
      {
	delete[]dbfstru;
	dbfstru = 0;
      }
      try
      {
	long filesize = check_file_size(Filename.mb_str(wxConvUTF8));
	if (dbf_file->OpenDatabase(Filename.mb_str(wxConvUTF8)) == XB_NO_ERROR)	//specific
	  retval = true;
	int nflds = getnumfields();
	int reclen = 0;
	for (int i = 0; i < nflds; i++)
	  reclen += getfieldlen(i);
	reclen++;
	int hdrsize = (nflds * 32) + 33;
	calcrecs = (filesize - hdrsize) / reclen;
      } catch( ...)
      {
	error(_("Erro ao abrir arquivo"));
      };
    }
    else			// senão, cria...
    {
      if (dbfstru)		// se não tiver criado a estrutura primeiro, não tem como criar
      {
	xbShort rslt;		//specific
	try
	{
	  if (writeheader(Filename))	//specific // BUG WORKAROUND!
	  {
	    delete[]dbfstru;
	    dbfstru = 0;

	    xbShort rslt = dbf_file->OpenDatabase(Filename.mb_str(wxConvUTF8));	//specific
	    if (rslt == XB_NO_ERROR)	//specific
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
	dbf_file->CloseDatabase(false);
      }
      catch( ...)
      {
      };
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
_xbtable::close(void)
{
  bool retval = false;
  if (dbf_file)
  {
    try
    {
      if (dbf_file->CloseDatabase(false) == XB_NO_ERROR)	//specific
	retval = true;
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
_xbtable::isopen(void)
{
  return openflag;
}

bool
_xbtable::eof(void)
{
  bool retval = false;
  if (dbf_file)
    retval = iseof;
  return retval;
}

bool
_xbtable::bof(void)
{
  bool retval = false;
  if (dbf_file)
    retval = isbof;
  return retval;
}

bool
_xbtable::first(void)
{
  bool retval = false;
  if (dbf_file)
  {
    iseof = false;
    isbof = true;
    if (useix)
    {
      xbShort result;		//specific
      try
      {
	long recno = dbf_ix.first();
	if (recno > -1)
	{
	  result = dbf_file->GetRecord(recno);	//specific
	  if (result == XB_NO_ERROR)	//specific
	    retval = true;
	}
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
    else
    {
      xbShort result;
      try
      {
	result = dbf_file->GetFirstRecord();	//specific
	if (result == XB_NO_ERROR)	//specific
	  retval = true;
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
_xbtable::next(void)
{
  bool retval = false;
  isbof = false;
  if (dbf_file)
  {
    if (useix)
    {
      xbShort result;
      try
      {
	long recno = dbf_ix.next();
	iseof = dbf_ix.iseof();
	if (!iseof && (recno > -1))
	{
	  result = dbf_file->GetRecord(recno);	//specific
	  if (result == XB_NO_ERROR)	//specific
	    retval = true;
	}
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
    else
    {
      xbShort result;
      try
      {
	result = dbf_file->GetNextRecord();	//specific
	if (result == XB_EOF)	//specific
	  iseof = true;
	
	else if (result == XB_NO_ERROR)	//specific
	  retval = true;
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
_xbtable::prev(void)
{
  bool retval = false;
  iseof = false;
  if (dbf_file)
  {
    if (useix)
    {
      xbShort result;		//specific
      try
      {
	long recno = dbf_ix.prev();
	isbof = dbf_ix.isbof();
	if (!isbof && (recno > -1))
	{
	  result = dbf_file->GetRecord(recno);	//specific
	  if (result == XB_NO_ERROR)	//specific
	    retval = true;
	}
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
    else
    {
      xbShort result;
      try
      {
	result = dbf_file->GetPrevRecord();	//specific
	if (result == XB_BOF)	//specific
	  isbof = true;
	
	else if (result == XB_NO_ERROR)	//specific
	  retval = true;
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
_xbtable::last(void)
{
  bool retval = false;
  if (dbf_file)
  {
    iseof = true;
    isbof = false;
    if (useix)
    {
      xbShort result;
      try
      {
	long recno = dbf_ix.last();
	result = dbf_file->GetRecord(recno);	//specific
	if (recno > -1)
	{
	  if (result == XB_NO_ERROR)	//specific
	    retval = true;
	}
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
    else
    {
      xbShort result;		//specific
      try
      {
	result = dbf_file->GetLastRecord();	//specific
	if (result == XB_EOF)	//specific
	  iseof = true;
	
	else if (result == XB_NO_ERROR)	//specific
	  retval = true;
      }
      catch( ...)
      {
	error(_("Erro ao acessar registro"));
      };
    }
  }
  return retval;
}

bool _xbtable::go(long recno)
{
  bool
    retval = false;
  if (recno && recno < dbf_file->NoOfRecords())	//specific
  {
    xbShort
      rslt;
    try
    {
      rslt = dbf_file->GetRecord(recno);	//specific
      if (rslt == XB_NO_ERROR)	//specific
      {
	retval = true;
	iseof = isbof = false;
      }
    }
    catch( ...)
    {
      error(_("Erro ao acessar registro"));
    };
  }
  return retval;
}

bool
_xbtable::find(long key)
{
  bool retval = false;
  if (dbf_file)
  {
    if (useix)
    {
      xbShort result;
      try
      {
	long recno = dbf_ix.xlate(--key);
	if (recno > -1l)
	{
	  result = dbf_file->GetRecord(recno);	//specific
	  if (result == XB_NO_ERROR)	//specific
	    retval = true;
	}
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
	xbShort rslt;
	try
	{
	  rslt = dbf_file->GetRecord(key);	//specific
	  if (rslt == XB_NO_ERROR)	//specific
	    retval = true;
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
_xbtable::find(wxString key)
{
  bool retval = false;
  if (dbf_file)
  {
    if (useix)
    {
      xbShort result;
      try
      {
	long recno = dbf_ix.find(key);
	if (recno > -1l)
	{
	  result = dbf_file->GetRecord(recno);	//specific
	  if (result == XB_NO_ERROR)	//specific
	    retval = true;
	}
      }
      catch( ...)
      {
	error(_("Erro ao procurar registro"));
      };
    }
    else
    {
      long recno;
      if (key.ToLong(&recno))
      {
	if (recno && (recno <= gettotalrecs()))
	{
	  xbShort rslt;		//specific
	  try
	  {
	    rslt = dbf_file->GetRecord(recno);	//specific
	    if (rslt == XB_NO_ERROR)	//specific
	      retval = true;
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
_xbtable::gettotalrecs(void)
{
  long retval = 0l;
  if (dbf_file)
    /*
       try {
       retval = dbf_file->NoOfRecords(); //specific
       } catch (...) {
       error(_("Erro ao computar total de registros"));
       };
     */
    retval = calcrecs;
  return retval;
}

long
_xbtable::getcurrentrec(void)
{
  long retval = 0l;
  if (dbf_file)
    try
  {
    retval = dbf_file->GetCurRecNo();	//specific
  }
  catch( ...)
  {
    error(_("Erro ao computar número de registro"));
  };
  return retval;
}

wxString
_xbtable::makekey(void)
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
_xbtable::makeindex(wxString name, wxArrayString * fields)
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
      long totalrecs = dbf_file->NoOfRecords();	//specific
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
_xbtable::reindex(void)
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
_xbtable::setindex(wxString name)
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
_xbtable::setstructure(wxString strstru)
{
  dbtable::fielddef * dbstruct = unpackstru(strstru);
  int nflds = 0;
  while (!dbstruct[nflds].fdname.IsEmpty())
    nflds++;
  setstructure(dbstruct, nflds);
}

void
_xbtable::setstructure(wxArrayString arrstru)
{
  dbtable::fielddef * dbstruct = array2stru(arrstru);
  int nflds = arrstru.Count();
  setstructure(dbstruct, nflds);
}

void
_xbtable::setstructure(dbtable::fielddef * dbstruct, int nflds)
{				//specific
  if (dbfstru)
    delete[]dbfstru;
  dbfstru = new xbSchema[nflds + 1];
  for (int i = 0; i < nflds; i++)
  {
    strcpy(dbfstru[i].FieldName, dbstruct[i].fdname.mb_str(wxConvUTF8));
    switch (dbstruct[i].fdtype)
    {
    case dbtable::CHAR:
      dbfstru[i].Type = XB_CHAR_FLD;
      break;
    case dbtable::INT:
      dbfstru[i].Type = XB_NUMERIC_FLD;
      break;
    case dbtable::FLOAT:
      dbfstru[i].Type = XB_FLOAT_FLD;
      break;
    case dbtable::BOOLEAN:
      dbfstru[i].Type = XB_LOGICAL_FLD;
      break;
    case dbtable::DATE:
      dbfstru[i].Type = XB_DATE_FLD;
      break;
    default:
      dbfstru[i].Type = XB_CHAR_FLD;
      break;
    }
    dbfstru[i].FieldLen = (unsigned char) dbstruct[i].len;
    dbfstru[i].NoOfDecs = (unsigned char) dbstruct[i].dec;
  }
  dbfstru[nflds].FieldName[0] = '\0';
  dbfstru[nflds].Type = 0;
  dbfstru[nflds].FieldLen = 0;
  dbfstru[nflds].NoOfDecs = 0;
}

dbtable::fielddef * _xbtable::getstructure(void)
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
_xbtable::copystru(dbtable::table * tbl)
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
_xbtable::copyrec(dbtable::table * tbl)
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
      int fldnum;
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
_xbtable::getrecord(void)
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
_xbtable::getheader(void)
{
  wxString retval = _T("");

  dbtable::fielddef * dbstruct = getstructure();

  if (dbstruct)
    retval = packstru(dbstruct);

  return retval;
};

bool
_xbtable::str2rec(wxString recstr, wxString sep)
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
_xbtable::getcurrentidx(void)
{
  return ixinuse;
};

 void
_xbtable::error(wxString errmsg)
{
  iserr = false;
  wxMessageBox(errmsg, _("ERRO"), wxICON_ERROR);
};

wxString
_xbtable::defdbext(void)
{
  return _T(".dbf");
};

wxString
_xbtable::defixext(void)
{
  return _T(".idx");
};

bool
_xbtable::moveby(long step)
{
  return false;
};

bool
_xbtable::iserror(void)
{
  return iserr;
};

void
_xbtable::clearerror(void)
{
  iserr = false;
};

bool
_xbtable::deleted(void)
{
  return false;
};
