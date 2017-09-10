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
// Nome:        ntable_grid.cpp
// Propósito:   Classe adaptadora para wxGrid e ntable
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-02
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "ntable_grid.h"
  
#include <wx/tokenzr.h>
  _ngrid::_ngrid()
{
  rowmin = 0;
  rowmax = 0;
}

 _ngrid::~_ngrid()
{
}

 int
_ngrid::GetNumberRows()
{
  return nrows;
}

 int
_ngrid::GetNumberCols()
{
  return ncols;
}

 bool _ngrid::IsEmptyCell(int row, int col) 
{
  bool retval = false;
  try
  {
    wxString tmp = GetValue(row, col);
    retval = tmp.IsEmpty();
  } catch( ...)
  {
  };
   return retval;
}

 wxString _ngrid::GetColLabelValue(int col)
{
  wxString retval = _T("N/A");
   try
  {
    if (col >= 0 && col < collabels.GetCount())
      retval = collabels[col];
  }
  catch( ...)
  {
  };
   return retval;
}

 wxString _ngrid::GetRowLabelValue(int row)
{
  wxString retval;
  if (rowmin)
    retval.Printf(_T("%d"), row + rowmin);
  else
    retval.Printf(_T("%d"), row + 1);
  return retval;
}

 void
ngrid::SetValue(int row, int col, const wxString & value)
{
  
    //wxMessageBox(_("Não implementado ainda"), _("AVISO"), wxICON_WARNING);
}  wxString _ngrid::GetValue(int row, int col)
{
  wxString value = GetRowLabelValue(row);
  long
    recno;
  value.ToLong(&recno);	// this might be a PROBLEM
  value = _T("N/A");
  try
  {
    if (table->find(recno))
      value = table->getstring(GetColLabelValue(col));
  }
  catch( ...)
  {
  };
  return value;
}

 bool _ngrid::SetTable(ntable * tb)
{
  table = tb;
  bool retval = tb->isopen();
  try
  {
    if (retval)
      
    {
      collabels.Clear();
      ncols = table->getnumfields();
      for (int i = 0; i < ncols; i++)
	collabels.Add(table->getfieldname(i));
      long
	maxrecs = table->gettotalrecs();

      if (rowmin || rowmax)
	nrows = (int) (rowmax - rowmin + 1L);
      else
      {
	if (maxrecs <= LOTSA_RECS)
	  nrows = maxrecs;
	else
	  nrows = LOTSA_RECS;
      }
    }
  }
  catch( ...)
  {
    retval = false;
  }
  return retval;
}

 void
_ngrid::SetLimits(long begin, long end)
{
  if (rowmin < 1L)
    rowmin = 1L;
  rowmin = begin;
  if ((end - begin + 1) < LOTSA_RECS)
    rowmax = end;
  else
    rowmax = begin + LOTSA_RECS - 1;
}


