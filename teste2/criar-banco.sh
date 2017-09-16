export PGPORT=5433

createuser -W reclink

createdb -O reclink reclink

psql reclink -f criar-tabelas.sql

