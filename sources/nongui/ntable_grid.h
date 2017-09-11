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
// Nome:        ntable_grid.h
// Propósito:   Classe adaptadora para wxGrid e ntable
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2012-08-02
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef ntable_grid_h
#define ntable_grid_h
#include <wx/grid.h>
  
#include "ntable.h"
typedef class _ngrid:public wxGridTableBase 
{
public:
	/** Default constructor */ 
  _ngrid();
  
	/** Default destructor */ 
  ~_ngrid();
  int GetNumberRows();
   int GetNumberCols();
   bool IsEmptyCell(int row, int col);
   wxString GetColLabelValue(int col);
   wxString GetRowLabelValue(int row);
   void SetValue(int row, int col, const wxString & value);
   wxString GetValue(int row, int col);
   bool SetTable(_ntable * tb);
  void SetLimits(long begin, long end);
protected: private:
  long rowmin;
  long rowmax;
   int nrows;
   int ncols;
   wxArrayString collabels;
   ntable * table;
 } ngrid;
 
#endif	/*  */
