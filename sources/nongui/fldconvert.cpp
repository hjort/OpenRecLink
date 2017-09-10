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
// Nome:        fldconvert.cpp
// Propósito:   Classe para conversão de campos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "fldconvert.h"

#include <wx/msgdlg.h>

namespace fldcvt
{

  _fldcv::_fldcv()
  {
    //excllist = NULL;
    initvars();
  }

  _fldcv::~_fldcv()
  {
  }

  void _fldcv::initvars(void)
  {
    stdval = _T("");
    stdfirst = _T("");
    stdlast = _T("");
    stdinit = _T("");
    stdapp = _T("");
  }

  wxString _fldcv::convstring(wxString src, reclink::opconv convtype)
  {
    wxString retval = _T("");
    int punclen;
    int srclen;
    switch (convtype.ref)
    {
    case reclink::NADA:	// Duh.
      retval = src;
      break;
    case reclink::CDATA0:	// DD/MM/AA
      retval = _T("19") + src.Mid(6, 2) + src.Mid(3, 2) + src.Mid(0, 2);
      break;
    case reclink::CDATA1:	// DDMMAA
      retval = _T("19") + src.Mid(4, 2) + src.Mid(2, 2) + src.Mid(0, 2);
      break;
    case reclink::CDATA2:	// DD/MM/AAAA
      retval = src.Mid(6, 4) + src.Mid(3, 2) + src.Mid(0, 2);
      break;
    case reclink::CDATA3:	// DDMMAAAA
      retval = src.Mid(4, 4) + src.Mid(2, 2) + src.Mid(0, 2);
      break;
    case reclink::CDATA4:	// MM/DD/AA
      retval = _T("19") + src.Mid(6, 2) + src.Mid(0, 2) + src.Mid(3, 2);
      break;
    case reclink::CDATA5:	// MMDDAA
      retval = _T("19") + src.Mid(4, 2) + src.Mid(0, 2) + src.Mid(2, 2);
      break;
    case reclink::CDATA6:	// MM/DD/AAAA
      retval = src.Mid(6, 4) + src.Mid(0, 2) + src.Mid(3, 2);
      break;
    case reclink::CDATA7:	// MMDDAAAA
      retval = src.Mid(4, 4) + src.Mid(0, 2) + src.Mid(2, 2);
      break;
    case reclink::CDATA8:	// AA/MM/DD
      retval = _T("19") + src.Mid(0, 2) + src.Mid(3, 2) + src.Mid(6, 2);
      break;
    case reclink::CDATA9:	// AAMMDD
      retval = _T("19") + src;
      break;
    case reclink::CDATAA:	// AAAA/MM/DD
      retval = src.Mid(0, 4) + src.Mid(5, 2) + src.Mid(8, 2);
      break;
    case reclink::CNOMES:	// Names
    case reclink::FNOMEP:	//1st name
    case reclink::FNOMEU:	//Last name
    case reclink::FNOMEI:	//Initials
    case reclink::FNOMEA:	//Appendix
    case reclink::PBLOCO:
    case reclink::UBLOCO:
      retval = procname(src, convtype.ref);
      break;
    case reclink::CPONTO:	// Punctuation
      retval = src;
      punclen = punctuation.Length();
      srclen = src.Length();
      for (int j = srclen - 1; j > -1; j--)
      {
	for (int i = 0; i < punclen; i++)
	  if (punctuation[i] == retval[j])
	    try
	  {
	    retval.Remove(j, 1);
	    break;
	  }
	catch( ...)
	{
	};
      }
      break;
    case reclink::SUBSTR:	// Substring
      try
      {
	retval = src.Mid(convtype.beg, convtype.nchars);
      }
      catch( ...)
      {
	retval = _T("*");	// error
      };
      break;
    case reclink::TROCA:
      retval = xchange(src, convtype.extra);
      break;
    case reclink::NUMERO:
    case reclink::DATASC:
    case reclink::LOGICO:
    case reclink::EXPR:
    case reclink::ERRO:
    default:
      break;
    }
    return retval;
  }

  wxString _fldcv::xchange(wxString var, wxString rules)
  {
    wxString retval;
    wxString aux;

    aux = var;
    aux.Trim().Trim(false);

    if (aux.IsEmpty())
      aux = _T("^.|");
    else
      aux = _T("^") + aux + _T("|");
    int pos = rules.Find(aux);
    if (pos == -1)
    {
      aux = _T("^*|");
      pos = rules.Find(aux);
    }
    if (pos != -1)
    {
      pos += aux.Length();
      wxChar buff[100];
      int i = 0, lim = rules.Length();
      while ((i < lim) && (i < 100) && (rules[pos + i] != _T('^')))
      {
	wxChar c = rules[pos + i];
	buff[i] = c;
	i++;
      }

      buff[i] = _T('\0');
      retval = buff;
    }
    else
      retval = var;
    return retval;
  }

  void _fldcv::initparms(wxString excl, wxString punct, wxString suffs)
  {
    punctuation = punct;
    suffixes = suffs;
    excllist = wxStringTokenize(excl, _T(","));
  }

  wxString _fldcv::procname(wxString name, reclink::convref convtype)
  {
    wxString retval = _T("");
    if (name != _T("="))
      parsename(name);
    switch (convtype)
    {
    case reclink::CNOMES:
      retval = stdval;
      break;
    case reclink::FNOMEP:	//1st name
      retval = stdfirst;
      break;
    case reclink::FNOMEU:	//Last name
      retval = stdlast;
      break;
    case reclink::FNOMEI:	//Initials
      retval = stdinit;
      break;
    case reclink::FNOMEA:	//Appendix
      retval = stdapp;
      break;
    case reclink::PBLOCO:
      retval = blockvar(stdfirst);
      break;
    case reclink::UBLOCO:
      retval = blockvar(stdlast);
      break;
    }
    return retval;
  }

  void _fldcv::parsename(wxString name)
  {
    initvars();
    wxString src = wxString(_T(" ")) + name.Upper() + wxString(_T(" "));
    int srclen = src.Length();

    if (!src.IsEmpty())
    {
      for (int i = 0; i < srclen; i++)
	try
      {
	switch ((unsigned char) src[i])
	{
	case _T('Á'):
	case _T('À'):
	case _T('Â'):
	case _T('Ã'):
	  src[i] = _T('A');
	  break;
	case _T('É'):
	case _T('Ê'):
	  src[i] = _T('E');
	  break;
	case _T('Í'):
	  src[i] = _T('I');
	  break;
	case _T('Ó'):
	case _T('Ò'):
	case _T('Ô'):
	case _T('Õ'):
	  src[i] = _T('O');
	  break;
	case _T('Ú'):
	case _T('Ü'):
	  src[i] = _T('U');
	  break;
	case _T('Ç'):
	  src[i] = _T('C');
	  break;
	}
      }
      catch( ...)
      {
	// error
      };
      wxString aux = punctuation + wxString(_T("0123456789"));
      int auxlen = aux.Length();	// Replaces punctuation and digits with spaces
      for (int i = 0; i < srclen; i++)
	for (int j = 0; j < auxlen; j++)
	  if (src[i] == aux[j])
	  {
	    src[i] = ' ';
	    break;
	  }
      int beg, len;
      while ((beg = src.Find(_T("  "))) != wxNOT_FOUND)	// Zaps double spaces
	try
      {
	src.Remove(beg, 1);
      }
      catch( ...)
      {
	// error
      };
      srclen = src.Length();
      for (int i = 0; i < excllist.Count(); i++)
      {
	wxString excl = wxString(_T(" ")) + excllist[i] + wxString(_T(" "));
	try
	{
	  len = excl.Length();
	  while ((beg = src.Find(excl)) != wxNOT_FOUND)
	    src.Remove(beg, len - 1);
	}
	catch( ...)
	{
	  // error
	};
      }
      src = src.Trim().Trim(false);

      if ((src.Length() > 3) && (src.Mid(0, 3) == _T("MA ")))
	src = src.insert(2, _T("RIA"));

      stdval = src;

      if (src.Length())
      {
	wxArrayString names = wxStringTokenize(src, _T(" "));
	int totalnames = names.Count();
	if (totalnames)
	{
	  stdfirst = names[0];

	  if (totalnames > 1)
	  {
	    if (suffixes.Find(names[totalnames - 1]) != wxNOT_FOUND)
	    {
	      if (totalnames > 2)
		stdlast = names[totalnames - 2];
	      stdapp = names[totalnames - 1];
	      totalnames--;
	    }
	    else
	      stdlast = names[totalnames - 1];
	  }
	  if (totalnames > 2)
	  {
	    for (int i = 1; i < (totalnames - 1); i++)
	      stdinit += wxString(names[i][0]);
	  }
	  else
	    stdinit = _T("*");
	}
      }
    }
  }

  wxString _fldcv::blockvar(wxString var)
  {
    if (var.Length() >= 2)
    {
      switch ((char) var[1])
      {
      case 'W':
	if (var[2] == 'A')
	  var[1] = 'V';
	break;
      case 'H':
	var.Remove(1, 1);
	break;
      case 'K':
	if ((var[2] == 'A') || (var[2] == 'O') || (var[2] == 'U'))
	  var[1] = 'C';
	break;
      case 'Y':
	var[1] = 'I';
	break;
      case 'C':
	if ((var[2] == 'E') || (var[2] == 'I'))
	  var[1] = 'S';
	break;
      case 'G':
	if ((var[2] == 'E') || (var[2] == 'I'))
	  var[1] = 'J';
	break;
      }
    }
    return soundex(var);
  }

}
