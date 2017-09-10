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
// Nome:        findex.h
// Propósito:   Classe para indice simples
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef FINDEX_H
#define FINDEX_H
//#include <wx/file.h>
#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/filefn.h>
#include <wx/msgdlg.h>

#include <stdio.h>

#define MAXEXPRLEN 160

#ifdef __x86_64__
#ifndef __LP64__
#define __LP64__
#endif
#endif

#ifdef __WXMSW__
static const char *ixbrand = "IXWFILE";
#else
static const char *ixbrand = "IDXFILE";
#endif

#define XBRANDSIZE 7

typedef struct _ixhdr
{
  char brandname[XBRANDSIZE];
  char ixexpr[MAXEXPRLEN + 1];
  int sz;
  long totalrecs;
} ixhdr;

typedef class _keyrec
{
public:
  _keyrec(int size);
   ~_keyrec();
  int len(void);
  long recpos;
  char *key;
  int klen;
} keyrec;

typedef class _ixfile
{
private:
  //wxFile diskfile;
  FILE * fp;
  ixhdr hdr;
  void disk_sort(long left, long right);
  void getkeyrec(keyrec * kr, long recpos);
  void setkeyrec(keyrec * kr, long recpos);
  void swaprec(long i, long j);
  long currec;
  bool eof;
  bool bof;
  wxString errmsg;
public:
    _ixfile();
   ~_ixfile();
  bool open(wxString Filename);
  void init(wxString expr, int keysize);
  void close(void);
  void add_rec(wxString key, long recpos);
  long find(wxString key);
  long moveby(long step);
  long xlate(long pos);
  long first(void);
  long last(void);
  long prev(void);
  long next(void);
  bool iseof(void);
  bool isbof(void);
  bool sort_file(void);
  long gettotalrecs(void);
  void error(wxString errmsg);
  bool isopen(void);
  wxString getkey(void);
  wxString getexpr(void);
} ixfile;
#endif
