--------------------------------------------------

DROP TABLE IF EXISTS freq;

SELECT *,
  sqrt(tk_pnome / qk_pnome) AS ak_pnome,
  sqrt(tk_unome / qk_unome) AS ak_unome,
  sqrt(tk_spnome / qk_spnome) AS ak_spnome,
  sqrt(tk_sunome / qk_sunome) AS ak_sunome,
  sqrt(tk_municipio / qk_municipio) AS ak_municipio
INTO freq
FROM (
  SELECT
    count(1) AS total,
    count(pnome) AS tk_pnome,
    count(DISTINCT pnome) AS qk_pnome,
    count(unome) AS tk_unome,
    count(DISTINCT unome) AS qk_unome,
    count(spnome) AS tk_spnome,
    count(DISTINCT spnome) AS qk_spnome,
    count(sunome) AS tk_sunome,
    count(DISTINCT sunome) AS qk_sunome,
    count(municipio) AS tk_municipio,
    count(DISTINCT municipio) AS qk_municipio
  FROM (
    SELECT pnome, unome, spnome, sunome, municipio
    FROM sdf1103p
    UNION ALL
    SELECT pnome, unome, spnome, sunome, municipio
    FROM sdf1703p
  ) x
) y;

ALTER TABLE freq OWNER TO reclink;

SELECT * FROM freq;

--------------------------------------------------

DROP TABLE IF EXISTS freq_pnome;

SELECT pnome, qk_pnome, ik_pnome,
  sqrt(ak_pnome / ik_pnome) AS sk_pnome
INTO freq_pnome
FROM (
  SELECT
    pnome,
    count(1) AS qk_pnome,
    min(freq.ak_pnome) AS ak_pnome,
    count(1)::numeric / min(freq.tk_pnome) AS ik_pnome
  FROM (
    SELECT pnome
    FROM sdf1103p
    UNION ALL
    SELECT pnome
    FROM sdf1703p
  ) x, freq
  GROUP BY pnome
) y
ORDER BY pnome;

ALTER TABLE freq_pnome ADD PRIMARY KEY (pnome);

ALTER TABLE freq_pnome OWNER TO reclink;

SELECT * FROM freq_pnome LIMIT 10;

--------------------------------------------------

DROP TABLE IF EXISTS freq_unome;

SELECT unome, qk_unome, ik_unome,
  sqrt(ak_unome / ik_unome) AS sk_unome
INTO freq_unome
FROM (
  SELECT
    unome,
    count(1) AS qk_unome,
    min(freq.ak_unome) AS ak_unome,
    count(1)::numeric / min(freq.tk_unome) AS ik_unome
  FROM (
    SELECT unome
    FROM sdf1103p
    UNION ALL
    SELECT unome
    FROM sdf1703p
  ) x, freq
  GROUP BY unome
) y
ORDER BY unome;

ALTER TABLE freq_unome ADD PRIMARY KEY (unome);

ALTER TABLE freq_unome OWNER TO reclink;

SELECT * FROM freq_unome LIMIT 10;

--------------------------------------------------

DROP TABLE IF EXISTS freq_spnome;

SELECT spnome, qk_spnome, ik_spnome,
  sqrt(ak_spnome / ik_spnome) AS sk_spnome
INTO freq_spnome
FROM (
  SELECT
    spnome,
    count(1) AS qk_spnome,
    min(freq.ak_spnome) AS ak_spnome,
    count(1)::numeric / min(freq.tk_spnome) AS ik_spnome
  FROM (
    SELECT spnome
    FROM sdf1103p
    UNION ALL
    SELECT spnome
    FROM sdf1703p
  ) x, freq
  GROUP BY spnome
) y
ORDER BY spnome;

ALTER TABLE freq_spnome ADD PRIMARY KEY (spnome);

ALTER TABLE freq_spnome OWNER TO reclink;

SELECT * FROM freq_spnome LIMIT 10;

--------------------------------------------------

DROP TABLE IF EXISTS freq_sunome;

SELECT sunome, qk_sunome, ik_sunome,
  sqrt(ak_sunome / ik_sunome) AS sk_sunome
INTO freq_sunome
FROM (
  SELECT
    sunome,
    count(1) AS qk_sunome,
    min(freq.ak_sunome) AS ak_sunome,
    count(1)::numeric / min(freq.tk_sunome) AS ik_sunome
  FROM (
    SELECT sunome
    FROM sdf1103p
    UNION ALL
    SELECT sunome
    FROM sdf1703p
  ) x, freq
  GROUP BY sunome
) y
ORDER BY sunome;

ALTER TABLE freq_sunome ADD PRIMARY KEY (sunome);

ALTER TABLE freq_sunome OWNER TO reclink;

SELECT * FROM freq_sunome LIMIT 10;

--------------------------------------------------

DROP TABLE IF EXISTS freq_municipio;

SELECT municipio, qk_municipio, ik_municipio,
  sqrt(ak_municipio / ik_municipio) AS sk_municipio
INTO freq_municipio
FROM (
  SELECT
    municipio,
    count(1) AS qk_municipio,
    min(freq.ak_municipio) AS ak_municipio,
    count(1)::numeric / min(freq.tk_municipio) AS ik_municipio
  FROM (
    SELECT municipio
    FROM sdf1103p
    UNION ALL
    SELECT municipio
    FROM sdf1703p
  ) x, freq
  GROUP BY municipio
) y
ORDER BY municipio;

ALTER TABLE freq_municipio ADD PRIMARY KEY (municipio);

ALTER TABLE freq_municipio OWNER TO reclink;

SELECT * FROM freq_municipio LIMIT 10;

--------------------------------------------------
