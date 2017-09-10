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
// Nome:        wxwinartprovider.cpp
// Propósito:   Classe para criar um artprovider para windoze
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2010-01-23
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "wxwinartprovider.h"

#include "arrow_down.xpm"
#include "arrow_left.xpm"
#include "arrow_right.xpm"
#include "arrow_undo.xpm"
#include "arrow_up.xpm"
#include "cancel.xpm"
#include "cog.xpm"
#include "cross.xpm"
#include "disk.xpm"
#include "folder_page.xpm"
#include "tick.xpm"
 wxWinArtProvider::wxWinArtProvider() 
{
  
    //ctor
}

wxBitmap wxWinArtProvider::CreateBitmap(const wxArtID & id,
					 const wxArtClient & client, const wxSize & size)
{
  if (id == wxART_FILE_OPEN)
    return wxBitmap(disk_xpm);
  else if (id == wxART_FILE_SAVE)
    return wxBitmap(folder_page_xpm);
  else if (id == wxART_EXECUTABLE_FILE)
    return wxBitmap(cog_xpm);
  else if (id == wxART_UNDO)
    return wxBitmap(arrow_undo_xpm);
  else if (id == wxART_ERROR)
    return wxBitmap(cancel_xpm);
  else if (id == wxART_GO_UP)
    return wxBitmap(arrow_up_xpm);
  else if (id == wxART_GO_DOWN)
    return wxBitmap(arrow_down_xpm);
  else if (id == wxART_TICK_MARK)
    return wxBitmap(tick_xpm);
  else if (id == wxART_CROSS_MARK)	//Cancel
    return wxBitmap(cross_xpm);
  else if (id == wxART_GO_BACK)
    return wxBitmap(arrow_left_xpm);
  else if (id == wxART_GO_FORWARD)
    return wxBitmap(arrow_right_xpm);
  else
    return wxNullBitmap;
}
