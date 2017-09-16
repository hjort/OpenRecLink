export PGPORT=5433 PGDATABASE=reclink

cat sdf1103.csv | psql reclink -c 'COPY sdf1103 FROM STDIN WITH CSV HEADER;'
cat sdf1703.csv | psql reclink -c 'COPY sdf1703 FROM STDIN WITH CSV HEADER;'

psql -c 'TRUNCATE sdf1103; TRUNCATE sdf1703;'
bzcat sdf1103c.csv.bz2 |\
  psql -c 'COPY sdf1103 FROM STDIN WITH CSV HEADER;'
bzcat sdf1703c.csv.bz2 |\
  psql -c 'COPY sdf1703 FROM STDIN WITH CSV HEADER;'

