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
// Nome:        wxwinartprovider
// Propósito:   Classe para criar um artprovider para windoze
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2010-01-23
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef WXWINARTPROVIDER_H
#define WXWINARTPROVIDER_H

#include <wx/artprov.h>
 class wxWinArtProvider:public wxArtProvider 
{
public:
	/** Default constructor */ 
    wxWinArtProvider();
protected:
  virtual wxBitmap CreateBitmap(const wxArtID & id,
				const wxArtClient & client, const wxSize & size);
private:};


#endif // WXWINARTPROVIDER_H
