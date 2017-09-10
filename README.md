# OpenRecLink
OpenRecLink - Probabilistic Record Linkage Software

========================================================================
OPENRECLINK:
(English instructions are further down)
========================================================================

Esta é uma versão experimental, sem nenhuma garantia de funcionamento, distribuída sob a licença GPL versão 3 (http://www.gnu.org/licenses/gpl-3.0.txt).

Para executar os binários desta distribuição é necessário Windows (TM) de 32 ou 64 bits com suporte a Unicode ou Ubuntu Linux versão 12.04 64 bits. A versão Windows 32 bits deste arquivo depende de bibliotecas dinâmicas que são instaladas automaticamente.

INSTALAÇÃO:

Executar o programa openreclink-2.8-inst32.exe (32 bits) ou openreclink-2.8-inst.exe 

Linux:
O pacote openreclink-2.8-amd64.deb contém o executável do programa. Para instalá-lo e executar a versão precompilada é necessário a versão 12.4 (Precise Pangolin) ou superior, 64 bits do Ubuntu Linux.

Notas:
1 - O programa impdbf (impdbf.exe sob windows) permite a importação de um ou mais arquivos dbf para o formato usado pelo programa; impdbf <arq>.dbf importa um único arquivo com o nome <arq>; impdbf *.dbf importa todos os arquivos dbf no diretório corrente;
2 - Os arquivos de dados usados pelo programa tem nomes diferentes dependendo da versão (32 ou 64 bits). Em 64 bits, o arquivo de dados tem a extensão .dat e o de índice .idx; em 32 bits as extensões são, respectivamente, d32 e i32.

COMPILAÇÃO:

Os fontes do programa estão no arquivo openreclink-2.8-src.zip, que deve ser descompactado. Um arquivo make (makefile) está incluído, mas para utilizá-lo é necessário instalar as bibliotecas adicionais descritas abaixo. O arquivo deve ser editado para ajustar os diretórios utilizados e selecionar a versão para compilação.

Windows:
Deve-se compilar as bibliotecas Xbase (fontes em http://linux.techass.com/projects/xdb/), wxWidgets (fontes em http://www.wxwidgets.org), compilar-se todos os fontes sob os diretórios "gui" e "nongui" e linká-los com as bibliotecas.

Para utilizar o makefile é necessário usar as ferramentas GNU: MingW (toolchain) e MSys (simula o ambiente Unix), mais o utilitário wx-config.exe (http://sites.google.com/site/wxconfig/). Ver a documentação deste último sobre as variáveis de sistema que devem ser criadas para utilizá-lo.

Linux:
Para compilação sob Linux, são necessários pacotes adicionais:
wxWidgets:
- wx2.8-headers
- libwxgtk2.8-dev
- libwxgtk2.8-dbg 
- libwxbase2.8-dev
- libwxbase2.8-dbg
- libxbase2.0-dev

========================================================================
This is an experimental version, with no warranties that it will work. It is distributed under the GPL version 3 license (http://www.gnu.org/licenses/gpl-3.0.txt).

In order to run the precompiled binaries, either Ubuntu Linux version 12.4 (Precise) or higher, 64 bits or Windows (TM) 32 or 64 bits with Unicode support is required. The windows version requires dynamic libraries that are automatically.

INSTALL:

Windows: Run the program openreclink-2.8-inst32.exe (32 bits) or openreclink-2.8-inst.exe (64 bits).

Linux:
The package openreclink-2.8-amd64.deb contains the executable. In order to install and run the program, version 12.4 (Precise Pangolin) or higher of Ubuntu Linux is necessary.

Notes:
1 - The program impdbf (impdbf.exe under windows) allows importing one or more dbf files to the format used by the program; impdbf <arq>.dbf imports a single file named <arq>.dbf; impdbf *.dbf imports all dbf files in hte current directory;
2 - The data files used by the program have different names depending on the version (32 or 64 bits). With 64 bits, the data file has the extenson .dat and the index file .idx; with 32 bits the extensions are, respectively, d32 and i32.
 
COMPILING:

The sources of the program are in the file openreclink-2.8-src.zip, that has to be unpacked. The file includes a makefile to build the program, but it depends on the installation of the libraries described below. The makefile has to be edited in order to adjust the directories used and select the version for compiling.

Windows:
The following libraries should be built: Xbase (sources are at http://linux.techass.com/projects/xdb/), and wxWidgets (sources at http://wxwidgets.org), all the sources under the directories "gui" and "nongui" should be compiled and linked against the libraries.

In order to use the makefile it is necessary to have the GNU toolchain (MingW) and MSys (which simulates an Unix environment), plus the wx-config.exe utility (http://sites.google.com/site/wxconfig/). See its documentation about system variables that must be created to use it.

Linux:
To build under Linux, additional libraries are necessary:
wxWidgets:
- wx2.8-headers
- libwxgtk2.8-dev
- libwxgtk2.8-dbg
- libwxbase2.8-dev
- libwxbase2.8-dbg
- libxbase2.0-dev

For both Windows(TM) and Linux the file "openreclink.po" should be compiled to a .mo file and placed on a directory called "en" under the same directory of the program executable (openreclink.exe or openreclink). The compilation can be made uing poedit, available for Windows or Linux (www.poedit.net)
========================================================================
GPL v3 NOTICE: 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
