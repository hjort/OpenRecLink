--------------------------------------------------

DROP TABLE IF EXISTS freq;

SELECT *,
  sqrt(tk_pnome / qk_pnome) AS ak_pnome,
  sqrt(tk_unome / qk_unome) AS ak_unome
INTO freq
FROM (
  SELECT
    count(1) AS total,
    count(pnome) AS tk_pnome,
    count(unome) AS tk_unome,
    count(DISTINCT pnome) AS qk_pnome,
    count(DISTINCT unome) AS qk_unome
  FROM (
    SELECT pnome, unome
    FROM sdf1103p
    UNION ALL
    SELECT pnome, unome
    FROM sdf1703p
  ) x
) y;

SELECT *
FROM freq;

--------------------------------------------------

DROP TABLE IF EXISTS freq_pnome;

SELECT pnome, ik_pnome,
  sqrt(ak_pnome / ik_pnome) AS sk_pnome
INTO freq_pnome
FROM (
  SELECT
    pnome,
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

--------------------------------------------------

DROP TABLE IF EXISTS freq_unome;

SELECT unome, ik_unome,
  sqrt(ak_unome / ik_unome) AS sk_unome
INTO freq_unome
FROM (
  SELECT
    unome,
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

--------------------------------------------------

