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
// Nome:        findex.cpp
// Propósito:   Classe para indice simples
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "findex.h"

#include <wx/msgdlg.h>
#ifdef __DEBUG__
#include <iostream>
#include <fstream>
#ifdef  debugmsg
#undef  debugmsg
#endif
#define debugmsg(msg) (ixmsgfile << __FILE__ << " line " << __LINE__ << ": " << msg.mb_str(wxConvUTF8) << std::endl)
//std::ofstream ixmsgfile;
#else
#define debugmsg(msg) (msg)
#endif

_keyrec::_keyrec(int size)
{
  if (size <= 0)
    size = 21;
  key = new char[size + 1];
  klen = size;
};

_keyrec::~_keyrec()
{
  delete[]key;
};

int
_keyrec::len(void)
{
  return (sizeof(long) + (klen * sizeof(char)));
};

_ixfile::_ixfile()
{
  bof = false;
  eof = false;
  fp = NULL;
  currec = 0l;
  hdr.totalrecs = 0l;
  memset(hdr.ixexpr, 0, MAXEXPRLEN + 1);
#ifdef __DEBUG__
//    if (!ixmsgfile.is_open())
//        ixmsgfile.open("indexdebug.log");
#endif
};

_ixfile::~_ixfile()
{
  //close();
#ifdef __DEBUG__
  //if (ixmsgfile.is_open())
  //ixmsgfile.close();
#endif
};

void
_ixfile::init(wxString expr, int keysize)
{
  memcpy(hdr.brandname, ixbrand, XBRANDSIZE);
  memset(hdr.ixexpr, 0, MAXEXPRLEN + 1);
  hdr.sz = keysize;
  strncpy(hdr.ixexpr, (const char *) expr.mb_str(wxConvUTF8), MAXEXPRLEN);
  //fseek(fp, 0, SEEK_SET);
  //fwrite(&hdr, sizeof(ixhdr), 1, fp);
};

wxString
_ixfile::getexpr(void)
{
  wxString retval = wxString::FromUTF8(hdr.ixexpr);
  return retval;
}

bool
_ixfile::open(wxString Filename)
{
  bool retval;
  if (wxFileExists(Filename))
  {
    fp = fopen(Filename.mb_str(wxConvUTF8), "r+b");
    fseek(fp, 0, SEEK_SET);
    int bytes = fread(&hdr, sizeof(ixhdr), 1, fp);
    if (bytes == 1)
      retval = (!memcmp(hdr.brandname, ixbrand, XBRANDSIZE));
  }
  else
  {
    fp = fopen(Filename.mb_str(wxConvUTF8), "w+b");
    fseek(fp, 0, SEEK_SET);
    int bytes = fwrite(&hdr, sizeof(ixhdr), 1, fp);
    fflush(fp);
    retval = (bytes == 1);
  }
  long bookmark = ftell(fp);
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  long nrecs = ((fsize - sizeof(ixhdr)) / (hdr.sz + sizeof(long)));
  if (nrecs != hdr.totalrecs)
  {
    fseek(fp, 0, SEEK_SET);
    hdr.totalrecs = nrecs;
    retval = (fwrite(&hdr, sizeof(ixhdr), 1, fp) == 1);
  }
  fseek(fp, bookmark, SEEK_SET);
  return retval;
};

void
_ixfile::close(void)
{
  if (fp != NULL)
  {
    fseek(fp, 0, SEEK_SET);
    fwrite(&hdr, sizeof(ixhdr), 1, fp);
    fflush(fp);
    fclose(fp);
    fp = NULL;
  }
}

bool
_ixfile::isopen(void)
{
  bool retval = (fp != NULL);
  return retval;
}

void
_ixfile::add_rec(wxString key, long recpos)
{
  if (isopen())
  {
    try
    {
      keyrec kr(hdr.sz);

      int len = key.length();
      memset(kr.key, 0, (hdr.sz + 1));
      if (len)
      {
	if (len > hdr.sz)
	  len = hdr.sz;
	strncpy(kr.key, (const char *) key.mb_str(wxConvUTF8), len);
      };
      kr.recpos = recpos;

      setkeyrec(&kr, hdr.totalrecs++);
    } catch( ...)
    {
      error(_("Erro ao gravar indice"));
    };
  }
  else
    error(_("Impossível gravar em arq. fechado"));
};

long
_ixfile::xlate(long pos)
{
  long retval = -1;
  keyrec kr(hdr.sz);
  if ((pos > -1) && (pos < gettotalrecs()))
  {
    getkeyrec(&kr, pos);
    retval = kr.recpos;
    currec = pos;
  }
  return retval;
}

long
_ixfile::moveby(long step)
{
  long retval = -1l;

  if (isopen())
  {
    try
    {
      long last = gettotalrecs() - 1L;
      long whereto = currec + step;
      if (whereto < 0L)
	whereto = 0L;
      if (whereto > last)
	whereto = last;
      keyrec kr(hdr.sz);
      getkeyrec(&kr, whereto);
      retval = kr.recpos;
      currec = whereto;
      bof = eof = false;
    }
    catch( ...)
    {
      error(_("Erro ao buscar indice"));
    };
  }
  return retval;
}

long
_ixfile::find(wxString key)
{
  long retval = -1l;

  if (isopen())
  {
    try
    {
      long first = 0;
      long last = gettotalrecs() - 1l;
      long mid;
      keyrec kr(hdr.sz);
      wxString cmp;

      while (first <= last)
      {
	mid = (first + last) / 2;	// compute mid point.

	getkeyrec(&kr, mid);
	cmp = wxString::FromUTF8(kr.key);
	if (key > cmp)
	  first = mid + 1;	// repeat search in top half.
	else if (key < cmp)
	  last = mid - 1;	// repeat search in bottom half.
	else
	{
	  retval = mid;
	  break;
	}
      }
      if (retval > -1)
      {
	do
	{
	  getkeyrec(&kr, --retval);
	  cmp = wxString::FromUTF8(kr.key);
	}
	while ((cmp == key) && (retval > -1l));
	currec = ++retval;
	getkeyrec(&kr, currec);
	retval = kr.recpos;
	bof = eof = false;
      }
    }
    catch( ...)
    {
      error(_("Erro ao buscar indice"));
    };
  }
  return retval;
};

long
_ixfile::gettotalrecs(void)
{
  return hdr.totalrecs;
};

bool
_ixfile::sort_file(void)
{
  bool retval = false;
  if (isopen())
  {
    try
    {
      long totalrecs = gettotalrecs();
      fseek(fp, 0, SEEK_SET);
      fwrite(&hdr, sizeof(ixhdr), 1, fp);
      disk_sort(0, --totalrecs);
      fflush(fp);
      retval = true;
    }
    catch( ...)
    {
      error(_("Erro ao ordenar índice"));
    };
  }
  return retval;
};

void
_ixfile::disk_sort(long left, long right)
{
  keyrec kr(hdr.sz);
  wxString aux, cmp, dbg;
  long i, j;
  i = left;
  j = right;

  getkeyrec(&kr, (i + j) / 2l);
  aux = wxString::FromUTF8(kr.key);

  do
  {
    getkeyrec(&kr, i);
    cmp = wxString::FromUTF8(kr.key);
    while ((cmp < aux) && (i < right))
    {
      getkeyrec(&kr, ++i);
      cmp = wxString::FromUTF8(kr.key);
    }
    getkeyrec(&kr, j);
    cmp = wxString::FromUTF8(kr.key);
    while ((cmp > aux) && (j > left))
    {
      getkeyrec(&kr, --j);
      cmp = wxString::FromUTF8(kr.key);
    }
    if (i <= j)
    {
      swaprec(i, j);
      i++;
      j--;
    }
  }
  while (i <= j);
  if (left < j)
    disk_sort(left, j);
  if (i < right)
    disk_sort(i, right);
};

void
_ixfile::setkeyrec(keyrec * kr, long recpos)
{
  if (isopen() && (recpos > -1l))
  {
    try
    {
      long where;
      where = (recpos * (hdr.sz + sizeof(long)) + sizeof(ixhdr));
      fseek(fp, where, SEEK_SET);
      long bytes = fwrite(&kr->recpos, sizeof(long), 1, fp);
      bool ok = (bytes == 1);
      bytes = fwrite(kr->key, hdr.sz, 1, fp);
      ok &= (bytes == 1);
      if (!ok)
	throw;
    }
    catch( ...)
    {
      error(_("Erro ao gravar chave"));
    };
  }
};

void
_ixfile::getkeyrec(keyrec * kr, long recpos)
{
  if (isopen() && (recpos > -1l))
  {
    try
    {
      long where;
      where = (recpos * (hdr.sz + sizeof(long)) + sizeof(ixhdr));
      fseek(fp, where, SEEK_SET);
      memset(kr->key, 0, (hdr.sz + 1));
      long bytes = fread(&kr->recpos, sizeof(long), 1, fp);
      bool ok = (bytes == 1);
      bytes = fread(kr->key, hdr.sz, 1, fp);
      ok &= (bytes == 1);
      if (!ok)
	throw;
    }
    catch( ...)
    {
      error(_("Erro ao ler chave"));
    };
  }
};

void
_ixfile::swaprec(long i, long j)
{
  keyrec kr1(hdr.sz), kr2(hdr.sz);
  getkeyrec(&kr1, i);
  getkeyrec(&kr2, j);
  setkeyrec(&kr1, j);
  setkeyrec(&kr2, i);
};

long
_ixfile::first(void)
{
  long retval = -1;
  if (isopen())
  {
    currec = 0l;
    bof = true;
    eof = false;
    keyrec kr(hdr.sz);
    getkeyrec(&kr, currec);
    retval = kr.recpos;
  }
  return retval;
};

long
_ixfile::last(void)
{
  long retval = -1l;
  if (isopen())
  {
    currec = gettotalrecs() - 1l;
    bof = false;
    eof = true;
    keyrec kr(hdr.sz);
    getkeyrec(&kr, currec);
    retval = kr.recpos;
  }
  return retval;
};

long
_ixfile::prev(void)
{
  long retval = -1;
  if (isopen())
  {
    currec--;
    if (currec < 0l)
    {
      currec = 0l;
      bof = true;
    }
    else
      bof = false;
    eof = false;
    keyrec kr(hdr.sz);
    getkeyrec(&kr, currec);
    retval = kr.recpos;
  }
  return retval;
};

long
_ixfile::next(void)
{
  long retval = -1;
  if (isopen())
  {
    currec++;
    if (currec > (gettotalrecs() - 1l))
    {
      currec = gettotalrecs() - 1l;
      eof = true;
    }
    else
      eof = false;
    bof = false;
    keyrec kr(hdr.sz);
    getkeyrec(&kr, currec);
    retval = kr.recpos;
  }
  return retval;
};

bool
_ixfile::iseof(void)
{
  return eof;
};

bool
_ixfile::isbof(void)
{
  return bof;
};

void
_ixfile::error(wxString errmsg)
{
  wxMessageBox(errmsg, _("ERRO"), wxICON_ERROR);
};

wxString
_ixfile::getkey(void)
{
  keyrec kr(hdr.sz);
  getkeyrec(&kr, currec);
  wxString retval = wxString::FromUTF8(kr.key);
  return retval;
};
