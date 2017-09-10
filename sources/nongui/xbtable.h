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
// Nome:        xbtable.h
// Propósito:   Classe wrapper para xbase (acesso a arquivos dbf)
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef xbtable_h
#define xbtable_h

#include "dbtable.h"
#include "findex.h"
//#include <xbase64/xbase64.h>
#include <xbase/xbase.h>

typedef class _xbtable:public
  dbtable::table
{
private:
  xbXBase
    x;				//specific
  xbDbf *
    dbf_file;			//specific
  ixfile
    dbf_ix;
  xbSchema *
    dbfstru;			// specific
  bool
    iseof;
  bool
    isbof;
  bool
    useix;
  bool
    openflag;
  long
    _currecno;
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
  bool
  writeheader(wxString name);	//specific
  long
  check_file_size(const char *fname);	// friggin' thing won't work
  long
    calcrecs;
  wxArrayString
    copyfrom;
  wxArrayInt
    copyto;
public:
  _xbtable();
  ~
  _xbtable();
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
  moveby(long step);
  bool
  find(wxString key);
  bool
  find(long key);
  bool
  go(long recno);
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
  bool
  deleted(void);
} xbtable;

#endif
