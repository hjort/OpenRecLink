export PGPORT=5433 PGDATABASE=reclink

createuser -W reclink

createdb -O reclink reclink

psql -c 'CREATE EXTENSION fuzzystrmatch'

psql -f criar-tabelas.sql

