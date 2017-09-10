#!/usr/bin/env python

import dbf

#sdf1103 = dbf.from_csv(csvfile='201103_SeguroDefeso.csv', filename='sdf1103',
#sdf1103 = dbf.from_csv(csvfile='head100.csv', filename='sdf1103',
#        field_names='zero datref numreq datreq pis cpf rgp pescador uf codmunic nommunic portdefeso datinicio datfim datemissao numparc datsaque vlrparcela datrest vlrrest codsit dessit codfun codsub codpro codacao'.split())

sdf1103 = dbf.from_csv(csvfile='head1000.csv', filename='sdf1103')

sdf1703 = dbf.from_csv(csvfile='head1000.csv', filename='sdf1703')

