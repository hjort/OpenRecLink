--------------------------------------------------

DROP TABLE IF EXISTS sdf1103p;

SELECT *,
  substring(pnome FROM 1 FOR 1)::char AS ipnome,
  substring(unome FROM 1 FOR 1)::char AS iunome,
  soundex(pnome)::char(4) AS spnome,
  soundex(unome)::char(4) AS sunome
INTO sdf1103p
FROM (
  SELECT pis, substring(rgp FROM 4) AS rgp,
    nome, uf, municipio,
    anome[1]::varchar(10) AS pnome,
    anome[array_upper(anome, 1)]::varchar(10) AS unome
  FROM (
    SELECT *, string_to_array(nome, ' ') AS anome
    FROM sdf1103
    WHERE pis < '10999999999' 
--    LIMIT 10
  ) a
) b;

--------------------------------------------------

DROP TABLE IF EXISTS sdf1703p;

SELECT *,
  substring(pnome FROM 1 FOR 1)::char AS ipnome,
  substring(unome FROM 1 FOR 1)::char AS iunome,
  soundex(pnome)::char(4) AS spnome,
  soundex(unome)::char(4) AS sunome
INTO sdf1703p
FROM (
  SELECT pis, substring(rgp FROM 4) AS rgp,
    nome, uf, municipio,
    anome[1]::varchar(10) AS pnome,
    anome[array_upper(anome, 1)]::varchar(10) AS unome
  FROM (
    SELECT *, string_to_array(nome, ' ') AS anome
    FROM sdf1703
    WHERE pis < '10999999999'
--    LIMIT 10
  ) a
) b;

--------------------------------------------------

CREATE INDEX ON sdf1703p (pnome, uf);

--------------------------------------------------

/*
SELECT min(pis), max(pis), count(1)
FROM sdf1103;

SELECT count(1)
FROM sdf1103
WHERE pis < '10999999999';

SELECT min(pis), max(pis), count(1)
FROM sdf1703;

SELECT count(1)
FROM sdf1703
WHERE pis < '10999999999';
*/

--------------------------------------------------

