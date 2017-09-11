-- Este arquivo de comandos foi testado com PostgresSQL.
-- Pode ser necessário editá-lo para usar com outros SGBDs.
-- O comando abaixo faz um join lateral das duas
-- tabelas com o arquivo de pares, permitindo a
-- inspeção do relacionamento.
-- Todos os campos são mostrados.
SELECT 
	SeguroDefeso.SCORE,
	sdf1103pad.RECNO,
	sdf1103pad.PIS,
	sdf1103pad.RGP,
	sdf1103pad.FNOMEP,
	sdf1103pad.FNOMEU,
	sdf1103pad.FNOMEI,
	sdf1103pad.FNOMEA,
	sdf1103pad.PBLOCO,
	sdf1103pad.UBLOCO,
	sdf1103pad.UF,
	sdf1103pad.MUNICIPIO,
	sdf1703pad.RECNO,
	sdf1703pad.PIS,
	sdf1703pad.RGP,
	sdf1703pad.FNOMEP,
	sdf1703pad.FNOMEU,
	sdf1703pad.FNOMEI,
	sdf1703pad.FNOMEA,
	sdf1703pad.PBLOCO,
	sdf1703pad.UBLOCO,
	sdf1703pad.UF,
	sdf1703pad.MUNICIPIO
FROM SeguroDefeso, sdf1103pad, sdf1703pad
WHERE SeguroDefeso.COMPREC = sdf1103pad.RECNO AND SeguroDefeso.REFREC = sdf1703pad.RECNO
ORDER BY SeguroDefeso.SCORE DESC;

