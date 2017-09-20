--------------------------------------------------

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

ALTER TABLE cruza1 OWNER TO reclink;

--------------------------------------------------

DROP TABLE IF EXISTS cruza2;

SELECT *,
  wpis + wrgp + wnome + wmun + wpnome + wunome + wspnome + wsunome AS score
INTO cruza2
FROM (
  SELECT *,
    CASE WHEN pis1 = pis2 THEN 1.585 ELSE -1.000 END AS wpis, -- 60x20
    CASE WHEN rgp1 = rgp2 THEN 1.874 ELSE -0.918 END AS wrgp, -- 55x15
    CASE WHEN nome1 = nome2 THEN 1.766 ELSE -2.322 END AS wnome, --85x25
    CASE WHEN municipio1 = municipio2 THEN 1.415 * sk_municipio ELSE -1.807 END AS wmun, --80x30
    CASE WHEN pnome1 = pnome2 THEN 4.248 * sk_pnome ELSE -4.248 END AS wpnome, --95x5
    CASE WHEN unome1 = unome2 THEN 3.248 * sk_unome ELSE -4.170 END AS wunome, --95x10
    CASE WHEN spnome1 = spnome2 THEN 4.170 * sk_spnome ELSE -3.248 END AS wspnome, --90x5
    CASE WHEN sunome1 = sunome2 THEN 3.087 * sk_sunome ELSE -2.585 END AS wsunome --80x10
  FROM cruza1
  LEFT JOIN freq_pnome f1 ON (f1.pnome = pnome1)
  LEFT JOIN freq_unome f2 ON (f2.unome = unome1)
  LEFT JOIN freq_spnome f3 ON (f3.spnome = spnome1)
  LEFT JOIN freq_sunome f4 ON (f4.sunome = sunome1)
  LEFT JOIN freq_municipio f5 ON (f5.municipio = municipio1)
--  LIMIT 100
) a;

ALTER TABLE cruza2 OWNER TO reclink;

--------------------------------------------------

SELECT score, nome1, nome2
FROM cruza2
WHERE nome1 <> nome2
ORDER BY score DESC;

--------------------------------------------------

