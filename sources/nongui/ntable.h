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

#ifndef ntable_h
#define ntable_h

#include "dbutils.h"
#include "dblowlevel.h"
#include "dbtable.h"
#include "findex.h"

typedef class _ntable:public
  dbtable::table
{
private:
  dbraw *
    dbf_file;
  dfield *
    dbfstru;
  ixfile
    dbf_ix;
  bool
    iseof;
  bool
    isbof;
  bool
    useix;
  bool
    openflag;
  wxString
    ixinuse;
  wxArrayString
    ixflds;
  void
  error(wxString errmsg);
  bool
    iserr;
  wxString
    errmsg;
  wxArrayString
    copyfrom;
  wxArrayInt
    copyto;
public:
  _ntable();
  ~
  _ntable();
  wxString
  getstring(wxString fldname);
  long
  getlong(wxString fldname);
  double
  getdouble(wxString fldname);
  dbtable::date
  getdate(wxString fldname);
  bool
  getbool(wxString fldname);
  int
  getnumfields(void);
  wxString
  getfieldname(int num);
  dbtable::ftype
  getfieldtype(wxString fldname);
  dbtable::ftype
  getfieldtype(int num);
  int
  getfieldlen(wxString fldname);
  int
  getfieldlen(int num);
  int
  getfielddec(wxString fldname);
  int
  getfielddec(int num);
  bool
  setfield(wxString value, wxString fldname);
  bool
  setfield(wxString value, int num);
  bool
  appendrec(void);
  bool
  replacerec(void);
  bool
  open(wxString Filename);
  bool
  close(void);
  bool
  isopen(void);
  bool
  eof(void);
  bool
  bof(void);
  bool
  first(void);
  bool
  next(void);
  bool
  prev(void);
  bool
  last(void);
  bool
  find(wxString key);
  bool
  find(long key);
  bool
  go(long recno);
  bool
  moveby(long step);
  long
  gettotalrecs(void);
  long
  getcurrentrec(void);
  bool
  makeindex(wxString name, wxArrayString * fields);
  bool
  setindex(wxString name);
  bool
  reindex(void);
  void
  setstructure(dbtable::fielddef * dbstruct, int nflds);
  dbtable::fielddef *
  getstructure(void);
  int
  getfieldnum(wxString fieldname);
  wxString
  getcurrentidx(void);
  void
  setstructure(wxString strstru);
  void
  setstructure(wxArrayString arrstru);
  bool
  iserror(void);
  void
  clearerror(void);
  bool
  copystru(dbtable::table * tbl);
  bool
  copyrec(dbtable::table * tbl);
  wxString
  getrecord(void);
  wxString
  getheader(void);
  bool
  str2rec(wxString recstr, wxString sep);
  wxString
  makekey(void);
  wxString
  defdbext(void);
  wxString
  defixext(void);
} ntable;

#endif
