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
// Nome:        dbutils.cpp
// Propósito:   Funções auxiliares para tabela
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "dbutils.h"

#include <wx/tokenzr.h>

wxString
packarray(wxArrayString dataarray, wxString sep)
{
  wxString retval = _T("");
  for (int i = 0; i < dataarray.GetCount(); i++)
  {
    if (i)
      retval = retval + sep + dataarray[i];
    else
      retval = dataarray[0];
  }
  return retval;
}

wxArrayString
unpackarray(wxString datastr, wxString sep)
{
  wxArrayString retval;

  if (!datastr.IsEmpty())
  {
    try
    {
      wxStringTokenizer tkz(datastr, sep);

      while (tkz.HasMoreTokens())
      {
	wxString token = tkz.GetNextToken();
	retval.Add(token);
      }
    }
    catch( ...)
    {
      retval.Clear();
    }
  }
  return retval;
}

wxString
packfield(dbtable::fielddef field)
{
  wxString retval = _T("");
  if (!field.fdname.IsEmpty())
  {
    retval = field.fdname + _T(",");
    switch (field.fdtype)
    {
    case dbtable::CHAR:
      retval += _T("C");
      break;
    case dbtable::INT:
      retval += _T("I");
      break;
    case dbtable::FLOAT:
      retval += _T("F");
      break;
    case dbtable::BOOLEAN:
      retval += _T("B");
      break;
    case dbtable::DATE:
      retval += _T("D");
      break;
    case dbtable::UNKNOWN:
    default:
      retval += _T("U");
      break;
    }

    retval += wxString::Format(_T(",%d,%d"), field.len, field.dec);
  }
  return retval;
}

dbtable::fielddef unpackfield(wxString fieldstring)
{
  dbtable::fielddef retval =
  {
  _T(""), dbtable::UNKNOWN, 0, 0};
  if (!fieldstring.IsEmpty())
  {
    wxArrayString tmp = unpackarray(fieldstring, _T(","));
    try
    {
      retval.fdname = tmp[0];
      wxString type = tmp[1].Upper();
      switch ((char) type[0])
      {
      case _T('C'):
	retval.fdtype = dbtable::CHAR;
	break;
      case _T('I'):
	retval.fdtype = dbtable::INT;
	break;
      case _T('F'):
	retval.fdtype = dbtable::FLOAT;
	break;
      case _T('B'):
	retval.fdtype = dbtable::BOOLEAN;
	break;
      case _T('D'):
	retval.fdtype = dbtable::DATE;
	break;
      case _T('U'):
      default:
	retval.fdtype = dbtable::UNKNOWN;
	break;
      }
      long tmpnum;
      if (tmp[2].ToLong(&tmpnum))
	retval.len = tmpnum;
      if (tmp[3].ToLong(&tmpnum))
	retval.dec = tmpnum;
    }
    catch( ...)
    {
      retval =
      {
      _T(""), dbtable::UNKNOWN, 0, 0};
    };
  }
  return retval;
}

wxString
packstru(dbtable::fielddef * structarray)
{
  int i = 0;
  wxString retval = _T("");

  while (!structarray[i].fdname.IsEmpty())
  {
    if (i)
      retval = retval + _T("|") + packfield(structarray[i]);
    else
      retval = packfield(structarray[i]);
    i++;
  }

  return retval;
}

wxArrayString
stru2array(dbtable::fielddef * structarray)
{
  wxArrayString retval;

  int i = 0;
  while (!structarray[i].fdname.IsEmpty())
    retval.Add(packfield(structarray[i++]));

  return retval;
}

dbtable::fielddef * unpackstru(wxString structstring)
{
  wxArrayString tmp = unpackarray(structstring, _T("|"));
  int nflds = tmp.GetCount();
  dbtable::fielddef * retval = new dbtable::fielddef[nflds + 1];
  dbtable::fielddef fld;
  for (int i = 0; i < nflds; i++)
  {
    fld = unpackfield(tmp[i]);
    retval[i].fdname = fld.fdname;
    retval[i].fdtype = fld.fdtype;
    retval[i].len = fld.len;
    retval[i].dec = fld.dec;
  }
  retval[nflds].fdname = _T("");
  retval[nflds].fdtype = dbtable::UNKNOWN;
  retval[nflds].len = 0;
  retval[nflds].dec = 0;
  return retval;
}

dbtable::fielddef * array2stru(wxArrayString structarray)
{
  int nflds = structarray.GetCount();
  dbtable::fielddef * retval = new dbtable::fielddef[nflds + 1];
  dbtable::fielddef fld;
  for (int i = 0; i < nflds; i++)
  {
    fld = unpackfield(structarray[i]);
    retval[i].fdname = fld.fdname;
    retval[i].fdtype = fld.fdtype;
    retval[i].len = fld.len;
    retval[i].dec = fld.dec;
  }
  retval[nflds].fdname = _T("");
  retval[nflds].fdtype = dbtable::UNKNOWN;
  retval[nflds].len = 0;
  retval[nflds].dec = 0;
  return retval;
}
