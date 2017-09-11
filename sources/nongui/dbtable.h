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
// Nome:        dbtable.h
// Propósito:   Classe generica para tabela
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef dbtable_h
#define dbtable_h

#include <wx/string.h>
#include <wx/datetime.h>
#include <wx/arrstr.h>

#include "dbtypes.h"

namespace dbtable
{

  typedef class _table
  {
  public:
    virtual wxString getstring(wxString fldname) = 0;
    virtual long getlong(wxString fldname) = 0;
    virtual double getdouble(wxString fldname) = 0;
    virtual date getdate(wxString fldname) = 0;
    virtual bool getbool(wxString fldname) = 0;
    virtual int getnumfields(void) = 0;
    virtual wxString getfieldname(int num) = 0;
    virtual ftype getfieldtype(wxString fldname) = 0;
    virtual ftype getfieldtype(int num) = 0;
    virtual int getfieldlen(wxString fldname) = 0;
    virtual int getfieldlen(int num) = 0;
    virtual int getfielddec(wxString fldname) = 0;
    virtual int getfielddec(int num) = 0;
    virtual bool setfield(wxString value, wxString fldname) = 0;
    virtual bool setfield(wxString value, int num) = 0;
    virtual bool appendrec(void) = 0;
    virtual bool replacerec(void) = 0;
    virtual bool open(wxString Filename) = 0;
    virtual bool close(void) = 0;
    virtual bool isopen(void) = 0;
    virtual bool eof(void) = 0;
    virtual bool bof(void) = 0;
    virtual bool first(void) = 0;
    virtual bool next(void) = 0;
    virtual bool prev(void) = 0;
    virtual bool last(void) = 0;
    virtual bool find(long key) = 0;
    virtual bool find(wxString key) = 0;
    virtual bool go(long recno) = 0;
    virtual bool moveby(long step) = 0;
    virtual long gettotalrecs(void) = 0;
    virtual long getcurrentrec(void) = 0;
    virtual bool makeindex(wxString name, wxArrayString * fields) = 0;
    virtual bool setindex(wxString name) = 0;
    virtual bool reindex(void) = 0;
    virtual void setstructure(fielddef * dbstruct, int nflds) = 0;
    virtual int getfieldnum(wxString fieldname) = 0;
    virtual wxString getcurrentidx(void) = 0;
    virtual void setstructure(wxString strstru) = 0;
    virtual void setstructure(wxArrayString arrstru) = 0;
    virtual bool iserror(void) = 0;
    virtual void clearerror(void) = 0;
    virtual bool copystru(class _table * tbl) = 0;
    virtual bool copyrec(class _table * tbl) = 0;
    virtual wxString getrecord(void) = 0;
    virtual wxString getheader(void) = 0;
    virtual bool str2rec(wxString recstr, wxString sep) = 0;
    virtual wxString makekey(void) = 0;
    virtual wxString defdbext(void) = 0;
    virtual wxString defixext(void) = 0;
    //virtual bool       deleted(void) = 0;
  } table;

}
#endif
