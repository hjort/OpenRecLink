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
  
{
  rowmin = 0;
  rowmax = 0;



{



_ngrid::GetNumberRows()
{
  



_ngrid::GetNumberCols()
{
  



{
  
  
  {
    
    
  
  {
  
  



{
  
  
  {
    
      
  
  catch( ...)
  {
  
  



{
  
  if (rowmin)
    retval.Printf(_T("%d"), row + rowmin);
  else
    
  



ngrid::SetValue(int row, int col, const wxString & value)
{
  
    //wxMessageBox(_("Não implementado ainda"), _("AVISO"), wxICON_WARNING);
} 
{
  
  
    recno;
  
  value = _T("N/A");
  try
  {
    
      
  }
  catch( ...)
  {
  
  



{
  
  
  
  {
    
      
    {
      
      
      
	
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
    
  
  
  {
    
  
  



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

