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
// Nome:        reclinktypes.h
// Propósito:   Definicao de tipos para as rotinas de padronizacao e linkagem
// Author:      Kenneth Camargo
// Modified by:
// Criado:      2009-02-12
// Copyright:   (c) Kenneth Camargo
// Licença:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef reclinktypes_h
#define reclinktypes_h

#include <wx/string.h>

namespace reclink
{

// Essa enumeracao contem os diferentes tipos de padronizacao
  typedef enum _convref
  {
    NADA,			// 0 Sem conversao
    NUMERO,			// 1 Converte numero -> caractere
    DATASC,			// 2 Converte formato data -> caractere
    CDATA0,			// 3 DD/MM/AA
    CDATA1,			// 4 DDMMAA
    CDATA2,			// 5 DD/MM/AAAA
    CDATA3,			// 6 DDMMAAAA
    CDATA4,			// 7 MM/DD/AA
    CDATA5,			// 8 MMDDAA
    CDATA6,			// 9 MM/DD/AAAA
    CDATA7,			// 10 MMDDAAAA
    CDATA8,			// 11 AA/MM/DD
    CDATA9,			// 12 AAMMDD
    CDATAA,			// 13 AAAA/MM/DD
    CNOMES,			// 14 Nomes
    CPONTO,			// 15 Pontuacao
    LOGICO,			// 16 Logico -> caractere
    FNOMEP,			// 17 primeiro nome
    FNOMEU,			// 18 último nome
    FNOMEI,			// 19 iniciais do nome
    FNOMEA,			// 20 apêndice do nome
    PBLOCO,			// 21 soundex primeiro nome para blocagem
    UBLOCO,			// 22 soundex último nome para blocagem
    SUBSTR,			// 23 substring
    EXPR,			// 24 expressao
    TROCA,			//  25 substitui valor
    ERRO			// 26 Erro - nao deve retornar esse valor (obvio)
  } convref;

// Essa estrutura e p/permitir a conversao da configuracao (texto) p/a
// representacao interna do programa dos tipos de padronizacao
  typedef struct _convtype
  {
    wxString label;
    convref ref;
  } convtype;

// Essa estrutura e p/conversao dos campos string
  typedef struct _opconv
  {
    convref ref;
    int beg;			// para substring
    int nchars;			// para substring
    wxString extra;		// para expressão, troca etc.
  } opconv;

// Essa estrutura e' a base p/as operacoes de padronizacao
  typedef struct _execstd
  {
    wxString infield;
    wxString outfield;
    opconv ref;
  } execstd;

// Enumeracao p/comparacoes
  typedef enum _compref
  {
    EXATO, CARACTERE, DIFERENCA, APROX, ERRADO
  } compref;

// Estrutura para definicao de campos de blocagem nos dois arquivos
  typedef struct _blockcfg
  {
    wxString reffield;
    wxString compfield;
  } blockcfg;

// Estrutura para a definicao das comparacoes
  typedef struct _comparecfg
  {
    wxString reffield;
    wxString compfield;
    compref comp;
    double correct;
     double incorrect;
     double lim;
   } comparecfg;
 }				// fim do namespace

#endif
