export PGPORT=5433
#export PGHOST=localhost PGPORT=5433 PGUSER=reclink

cat sdf1103.csv | psql reclink -c 'COPY sdf1103 FROM STDIN WITH CSV HEADER;'

cat sdf1703.csv | psql reclink -c 'COPY sdf1703 FROM STDIN WITH CSV HEADER;'

