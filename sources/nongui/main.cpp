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
#include <iostream>
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/filename.h>

#include "ntable.h"
#include "xbtable.h"


using namespace std;

void
import_dbf(wxString name)
{
  xbtable xtbl;
  ntable htbl;
  xtbl.open(name);
  cout << name.mb_str(wxConvUTF8) << endl << endl;
  wxFileName fname(name);
  fname.SetExt(htbl.defdbext().Right(3));
  name = fname.GetFullPath();
  if (wxFileExists(name))
    wxRemoveFile(name);
  htbl.copystru(&xtbl);
  htbl.open(name);
  xtbl.first();
  long copied = 0l;
  htbl.copyrec(0);		// initialize
  int ticker = 0;
  long totalrecs = xtbl.gettotalrecs();
  while (!xtbl.eof() && (copied < totalrecs))
  {
    if (htbl.copyrec(&xtbl))
    {
      copied++;
      ticker++;
      if (ticker > 99)
      {
	ticker = 0;
	cout << copied << '\r';
      }
    }
    xtbl.next();
  }
  xtbl.close();
  htbl.close();
  cout << endl << name.mb_str(wxConvUTF8) << ": " << copied << endl;
}

int
main(int argc, char *argv[])
{
  for (int i = 0; i < argc; i++)
  {
    wxString name = wxString(argv[i], wxConvUTF8);
    if (wxFileExists(name))
    {
      wxFileName fname(name);
      wxString ext = fname.GetExt();
      if (!ext.IsEmpty() && (ext.Lower() == _T("dbf")))
	import_dbf(name);
    }
  }
  return 0;
}
