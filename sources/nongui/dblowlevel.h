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
// Nome:        dblowlevel.h
// Propósito:   Classe para acesso a disco
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-02
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef DBLOWLEVEL_H
#define DBLOWLEVEL_H

#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/filefn.h>
#include <wx/msgdlg.h>

#include <stdio.h>

#include "dbtypes.h"

#define MAXVARSIZE 1024
#define MAXRECSIZE 32 * 1024

#ifdef __x86_64__
#ifndef __LP64__
#define __LP64__
#endif
#endif

#ifdef __WXMSW__
static const char *dtbrand = "DTWFILE";
#else
static const char *dtbrand = "DATFILE";
#endif

#define DBRANDSIZE 7

typedef struct _dheader
{
  char brandname[DBRANDSIZE];
  int nvars;
  long totalrecs;
} dheader;

typedef struct _dfield
{
  char fdname[16];
    dbtable::ftype fdtype;
  int len;
  int dec;
} dfield;

typedef class _dbraw
{
private:
  FILE * fp;
  dheader hdr;
  dfield *dbstruct;
  bool iseof;
  bool isbof;
  bool openflag;
  wxString errmsg;
  wxArrayString fieldvals;
  char buffer[MAXRECSIZE];
  char varbuff[MAXVARSIZE + 1];
  int reclen;
  void arraytobuffer(void);
  void buffertoarray(void);
  bool readrec(long recno);
  bool writerec(long recno);
  long xlate(long recno);
  long current;
public:
    _dbraw();
   ~_dbraw();
  wxString getfield(int fldno);
  long getlongfield(int fldno);
  double getfloatfield(int fldno);
  bool getlogicalfield(int fldno);
  int fieldcount(void);
  int getfieldno(wxString fname);
  wxString getfieldname(int num);
    dbtable::ftype getfieldtype(int num);
  int getfieldlen(int num);
  int getfielddecimal(int num);
  int putfield(int num, wxString value);
  long getcurrecno(void);
  bool putrecord(long recno);
  bool appendrecord(void);
  bool opendatabase(wxString filename, dfield * dbst = 0);
  bool closedatabase(void);
  bool getrecord(long recno);
  bool getfirstrecord(void);
  bool getnextrecord(void);
  bool getprevrecord(void);
  bool getlastrecord(void);
  long noofrecords(void);
  bool eof(void);
  bool bof(void);
  bool isopen(void);
} dbraw;

#endif // DBLOWLEVEL_H
