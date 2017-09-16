DROP TABLE IF EXISTS cruza1;

SELECT
  a.pis AS pis1, b.pis AS pis2,
  a.rgp AS rgp1, b.rgp AS rgp2,
  a.nome AS nome1, b.nome AS nome2,
  a.uf AS uf1, b.uf AS uf2,       
  a.municipio AS municipio1, b.municipio AS municipio2,
  a.pnome AS pnome1, b.pnome AS pnome2,
  a.unome AS unome1, b.unome AS unome2,
  a.spnome AS spnome1, b.spnome AS spnome2,
  a.sunome AS sunome1, b.sunome AS sunome2
INTO cruza1
FROM sdf1103p a
  JOIN sdf1703p b ON (b.uf = a.uf AND b.pnome = a.pnome)
--LIMIT 100
;

--------------------------------------------------

DROP TABLE IF EXISTS cruza2;

SELECT *,
  wpis + wrgp + wnome + wmun + wpnome + wunome AS score
INTO cruza2
FROM (
  SELECT *,
    CASE WHEN pis1 = pis2 THEN 1.585 ELSE -1.000 END AS wpis, -- 60x20
    CASE WHEN rgp1 = rgp2 THEN 1.874 ELSE -0.918 END AS wrgp, -- 55x15
    CASE WHEN nome1 = nome2 THEN 1.766 ELSE -2.322 END AS wnome, --85x25
    CASE WHEN municipio1 = municipio2 THEN 1.415 ELSE -1.807 END AS wmun, --80x30
    CASE WHEN spnome1 = spnome2 THEN 4.248 ELSE -4.248 END AS wpnome, --95x5
    CASE WHEN sunome1 = sunome2 THEN 3.248 ELSE -4.170 END AS wunome --95x10
  FROM cruza1
--  LIMIT 100
) a;

--------------------------------------------------

SELECT score, nome1, nome2
FROM cruza2
ORDER BY score DESC;

--------------------------------------------------

