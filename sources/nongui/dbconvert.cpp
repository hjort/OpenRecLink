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
// Nome:        dbconvert.cpp
// Propósito:   Classe para padronização de arquivos
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "dbconvert.h"
#include <wx/string.h>
#include <wx/fileconf.h>
#include <wx/intl.h>
#include <wx/tokenzr.h>

namespace dbconv
{

  _doconv::_doconv(wxString cfgfile, wxString nameout)
  {
    out = nameout;
    cfg = cfgfile;
    procopts = 0;
    nopts = 0;
  }

  _doconv::~_doconv()
  {
    tbin.close();
    tbout.close();
    if (procopts)
      delete[]procopts;
  }

  bool _doconv::init(void)
  {
    bool result = false;
    reclink::convtype convtypes[] =
    {
      {
      wxTRANSLATE("NADA"), reclink::NADA}, 
      {
      wxTRANSLATE("NUMERO"), reclink::NUMERO}, 
      {
      wxTRANSLATE("DATASC"), reclink::DATASC}, 
      {
      wxTRANSLATE("CDATA0"), reclink::CDATA0}, 
      {
      wxTRANSLATE("CDATA1"), reclink::CDATA1}, 
      {
      wxTRANSLATE("CDATA2"), reclink::CDATA2}, 
      {
      wxTRANSLATE("CDATA3"), reclink::CDATA3}, 
      {
      wxTRANSLATE("CDATA4"), reclink::CDATA4}, 
      {
      wxTRANSLATE("CDATA5"), reclink::CDATA5}, 
      {
      wxTRANSLATE("CDATA6"), reclink::CDATA6}, 
      {
      wxTRANSLATE("CDATA7"), reclink::CDATA7}, 
      {
      wxTRANSLATE("CDATA8"), reclink::CDATA8}, 
      {
      wxTRANSLATE("CDATA9"), reclink::CDATA9}, 
      {
      wxTRANSLATE("CDATAA"), reclink::CDATAA}, 
      {
      wxTRANSLATE("CNOMES"), reclink::CNOMES}, 
      {
      wxTRANSLATE("CPONTO"), reclink::CPONTO}, 
      {
      wxTRANSLATE("LOGICO"), reclink::LOGICO}, 
      {
      wxTRANSLATE("FNOMEP"), reclink::FNOMEP}, 
      {
      wxTRANSLATE("FNOMEU"), reclink::FNOMEU}, 
      {
      wxTRANSLATE("FNOMEI"), reclink::FNOMEI}, 
      {
      wxTRANSLATE("FNOMEA"), reclink::FNOMEA}, 
      {
      wxTRANSLATE("PBLOCO"), reclink::PBLOCO}, 
      {
      wxTRANSLATE("UBLOCO"), reclink::UBLOCO},
      {
      wxTRANSLATE("SUBSTR"), reclink::SUBSTR},
      {
      wxTRANSLATE("EXPR"), reclink::EXPR},
      {
      wxTRANSLATE("TROCA"), reclink::TROCA},
      {
      _T(""), reclink::ERRO}
    };

    if (procopts)
      delete[]procopts;
    procopts = 0;
    nopts = 0;

    wxString aux;
    long nlines;
    if (wxFileExists(cfg))
    {
      try
      {
	wxFileConfig *cfgfile =
	  new wxFileConfig(_T(""), _T(""), cfg, _T(""), wxCONFIG_USE_LOCAL_FILE);
	in = _T("");
	cfgfile->Read(_T("GENERAL/FILENAME"), &in);
	excl = _T("");
	cfgfile->Read(_T("GENERAL/EXCL"), &excl);
	punct = _T("");
	cfgfile->Read(_T("GENERAL/PUNCT"), &punct);
	suffix = _T("");
	cfgfile->Read(_T("GENERAL/SUFFIX"), &suffix);
	nlines = 1;
	converter.initparms(excl, punct, suffix);

	cfgfile->Read(_T("OPTIONS/NLINES"), &nlines);
	nopts = (int) nlines;

	procopts = new reclink::execstd[(int) nlines];

	wxString tmp, prevvar = _T("");
	for (int i = 0; i < nopts; i++)
	{
	  aux.Printf(_T("OPTIONS/INVAR%d"), i);
	  cfgfile->Read(aux, &tmp);
	  procopts[i].infield = tmp;

	  aux.Printf(_T("OPTIONS/PROC%d"), i);
	  tmp = _T("");
	  cfgfile->Read(aux, &tmp);

	  if (!tmp.IsEmpty())
	  {
	    int j = 0;
	    do
	    {
	      if (tmp.StartsWith(wxGetTranslation(convtypes[j].label)))
		break;
	    }
	    while (!convtypes[j++].label.IsEmpty());
	    procopts[i].ref.ref = convtypes[j].ref;
	    if (convtypes[j].ref == reclink::SUBSTR)
	    {
	      wxString lb = wxGetTranslation(convtypes[j].label);
	      int len = lb.Length();
	      tmp.Remove(0, len + 1);
	      wxArrayString vals = wxStringTokenize(tmp, _T("-"));
	      int nv = vals.Count();
	      long num;
	      if (nv)
	      {
		if (vals[0].ToLong(&num))
		  procopts[i].ref.beg = (int) num;
	      }
	      else
		procopts[i].ref.beg = 0;
	      if (nv > 1)
	      {
		if (vals[1].ToLong(&num))
		  procopts[i].ref.nchars = int (num);
	      }
	      else
		procopts[i].ref.nchars = 1;

	    }
	    if ((convtypes[j].ref == reclink::EXPR) || (convtypes[j].ref == reclink::TROCA))
	    {
	      wxString lb = wxGetTranslation(convtypes[j].label);
	      int len = lb.Length();
	      tmp.Remove(0, len + 1);
	      procopts[i].ref.extra = tmp;
	    }
	    if (i && !prevvar.IsEmpty() && procopts[i].infield == prevvar)
	    {
	      if ((convtypes[j].ref == reclink::CNOMES) ||
		  (convtypes[j].ref == reclink::FNOMEP) ||
		  (convtypes[j].ref == reclink::FNOMEU) ||
		  (convtypes[j].ref == reclink::FNOMEI) ||
		  (convtypes[j].ref == reclink::FNOMEA) ||
		  (convtypes[j].ref == reclink::PBLOCO) ||
		  (convtypes[j].ref == reclink::CNOMES) || (convtypes[j].ref == reclink::UBLOCO))
	      {
		if ((procopts[i - 1].ref.ref == reclink::CNOMES) ||
		    (procopts[i - 1].ref.ref == reclink::FNOMEP) ||
		    (procopts[i - 1].ref.ref == reclink::FNOMEU) ||
		    (procopts[i - 1].ref.ref == reclink::FNOMEI) ||
		    (procopts[i - 1].ref.ref == reclink::FNOMEA) ||
		    (procopts[i - 1].ref.ref == reclink::PBLOCO) ||
		    (procopts[i - 1].ref.ref == reclink::CNOMES) ||
		    (procopts[i - 1].ref.ref == reclink::UBLOCO))
		  procopts[i].infield = _T("=");
	      }
	    }
	    prevvar = procopts[i].infield;
	  }
	  else
	    procopts[i].ref.ref = reclink::ERRO;

	  aux.Printf(_T("OPTIONS/OUTVAR%d"), i);
	  tmp = _T("");
	  cfgfile->Read(aux, &tmp);
	  procopts[i].outfield = tmp;
	}
	delete cfgfile;
	result = createout();
      }
      catch( ...)
      {
	if (procopts)
	  delete[]procopts;
	procopts = 0;
	nopts = 0;
      }
    }
    return result;
  }

  int _doconv::calcsize(wxString spec)
  {
    int size = 0;
    wxArrayString vals = wxStringTokenize(spec, _T("^"));
    int pos;
    for (int i = 0; i < vals.Count(); i++)
    {
      pos = vals[i].Find(_T('|'));
      if (pos != wxNOT_FOUND)
      {
	pos = vals[i].Len() - pos - 1;
	if (pos > size)
	  size = pos;
      }
    }
    return size;
  }

  bool _doconv::createout(void)
  {
    bool result = tbin.open(in);
    nrecs = tbin.gettotalrecs();
    tbin.first();

    if (result)
    {
      dbtable::fielddef * dbstruct = new dbtable::fielddef[nopts];

      for (int i = 0; i < nopts; i++)
      {
	dbstruct[i].fdname = procopts[i].outfield;
	dbstruct[i].fdtype = dbtable::CHAR;
	int fsize = 10;
	int decs = 0;

	switch (procopts[i].ref.ref)
	{
	case reclink::NADA:	// Duh.
	case reclink::NUMERO:
	  fsize = tbin.getfieldlen(procopts[i].infield);
	  decs = tbin.getfielddec(procopts[i].infield);
	  break;
	case reclink::LOGICO:
	  fsize = 1;
	  break;
	case reclink::DATASC:
	case reclink::CDATA0:	// DD/MM/AA
	case reclink::CDATA1:	// DDMMAA
	case reclink::CDATA2:	// DD/MM/AAAA
	case reclink::CDATA3:	// DDMMAAAA
	case reclink::CDATA4:	// MM/DD/AA
	case reclink::CDATA5:	// MMDDAA
	case reclink::CDATA6:	// MM/DD/AAAA
	case reclink::CDATA7:	// MMDDAAAA
	case reclink::CDATA8:	// AA/MM/DD
	case reclink::CDATA9:	// AAMMDD
	case reclink::CDATAA:	// AAAA/MM/DD
	  fsize = 8;
	  break;
	case reclink::CNOMES:	// Names
	case reclink::CPONTO:	// Punctuation
	  fsize = tbin.getfieldlen(procopts[i].infield);
	  break;
	case reclink::TROCA:
	  fsize = calcsize(procopts[i].ref.extra);
	  fsize =
	    (fsize >
	     tbin.getfieldlen(procopts[i].infield)) ? fsize : tbin.getfieldlen(procopts[i].infield);
	  break;
	case reclink::FNOMEP:	//1st name
	case reclink::FNOMEU:	//Last name
	  fsize = 30;
	  break;
	case reclink::FNOMEI:	//Initials
	case reclink::FNOMEA:	//Appendix
	  fsize = 10;
	  break;
	case reclink::PBLOCO:
	case reclink::UBLOCO:
	  fsize = 4;
	  break;
	case reclink::SUBSTR:	// Substring
	  fsize = procopts[i].ref.nchars;
	  break;
	case reclink::EXPR:
	  break;
	case reclink::ERRO:
	default:
	  break;
	}
	dbstruct[i].len = fsize;
	dbstruct[i].dec = decs;
      }
      try
      {
	tbout.setstructure(dbstruct, nopts);
	result = tbout.open(out);
      }
      catch( ...)
      {
	tbin.close();
	tbout.close();
	result = false;
      }
    }

    return result;
  }

  long _doconv::numberofrecs(void)
  {
    return nrecs;
  }

  bool _doconv::isfinished(void)
  {
    return tbin.eof();
  }

  bool _doconv::exec(void)
  {
    bool result = false;
    wxString val_in, val_out, aux;
    long lnum;
    double dnum;
    int fwidth, ndecs;
    dbtable::date idate;
    try
    {
      for (int i = 0; i < nopts; i++)
      {
	switch (procopts[i].ref.ref)
	{
	case reclink::NADA:	// Duh.
	  val_in = tbin.getstring(procopts[i].infield);
	  val_out = val_in;
	  break;
	case reclink::NUMERO:
	  if (tbin.getfieldtype(procopts[i].infield) == dbtable::INT)
	  {
	    lnum = tbin.getlong(procopts[i].infield);
	    fwidth = tbin.getfieldlen(procopts[i].infield);
	    aux.Printf(_T("%%%dd"), fwidth);
	    val_out.Printf(aux, lnum);
	  }
	  else
	  {
	    dnum = tbin.getdouble(procopts[i].infield);
	    fwidth = tbin.getfieldlen(procopts[i].infield);
	    ndecs = tbin.getfielddec(procopts[i].infield);
	    aux.Printf(_T("%%%d.%df"), fwidth, ndecs);
	    val_out.Printf(aux, dnum);
	  }
	  break;
	case reclink::LOGICO:
	  if (tbin.getbool(procopts[i].infield))
	    val_out = _("S");
	  else
	    val_out = _("N");
	  break;
	case reclink::DATASC:
	  idate = tbin.getdate(procopts[i].infield);
	  if (idate.year && idate.month && idate.day)
	    val_out.Printf(_T("%4d%02d%02d"), idate.year, idate.month, idate.day);
	  else
	    val_out = _T("");
	  break;
	case reclink::CNOMES:	// Names
	case reclink::FNOMEP:	//1st name
	case reclink::FNOMEU:	//Last name
	case reclink::FNOMEI:	//Initials
	case reclink::FNOMEA:	//Appendix
	case reclink::PBLOCO:
	case reclink::UBLOCO:
	  val_in = procopts[i].infield;
	  if (val_in != _T("="))
	    val_in = tbin.getstring(val_in);
	  val_out = converter.convstring(val_in, procopts[i].ref);
	  break;
	case reclink::CPONTO:	// Punctuation
	case reclink::CDATA0:	// DD/MM/AA
	case reclink::CDATA1:	// DDMMAA
	case reclink::CDATA2:	// DD/MM/AAAA
	case reclink::CDATA3:	// DDMMAAAA
	case reclink::CDATA4:	// MM/DD/AA
	case reclink::CDATA5:	// MMDDAA
	case reclink::CDATA6:	// MM/DD/AAAA
	case reclink::CDATA7:	// MMDDAAAA
	case reclink::CDATA8:	// AA/MM/DD
	case reclink::CDATA9:	// AAMMDD
	case reclink::CDATAA:	// AAAA/MM/DD
	case reclink::SUBSTR:	// Substring
	case reclink::TROCA:
	  val_in = tbin.getstring(procopts[i].infield);
	  val_out = converter.convstring(val_in, procopts[i].ref);
	  break;
	case reclink::EXPR:	// não implementado ainda, deixa igual
	  val_in = tbin.getstring(procopts[i].infield);
	  val_out = val_in;
	  break;
	case reclink::ERRO:
	default:
	  val_out = _T("");
	  break;
	}
	tbout.setfield(val_out, procopts[i].outfield);
      }
      result = tbout.appendrec();
    }
    catch( ...)
    {
      tbin.close();
      tbout.close();
    }
    tbin.next();
    return result;
  }

}
