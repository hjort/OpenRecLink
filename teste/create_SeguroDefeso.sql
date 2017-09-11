-- Este arquivo de comandos foi testado com PostgresSQL.
-- Pode ser necessário editá-lo para usar com outros SGBDs.

-- O campo MATCH da tabela de pares segue o seguinte padrão:
-- + é par
-- ? é dúvida
-- - é não par
-- * é ignorado

-- Tabela de pares
CREATE TABLE SeguroDefeso(
	RECNO char(8) PRIMARY KEY NOT NULL,
	COMPREC char(8),
	REFREC char(8),
	SCORE double precision,
	MATCH char(1)
);

COPY SeguroDefeso FROM '/home/rodrigo/Projetos/reclink/teste/SeguroDefesoSCORE.csv' WITH CSV HEADER;

-- Cria índice
CREATE INDEX SeguroDefeso_scores on SeguroDefeso (SCORE DESC);

-- Tabela de comparação
CREATE TABLE sdf1103pad(
	RECNO char(8) PRIMARY KEY NOT NULL,
	PIS char(11),
	RGP char(10),
	FNOMEP char(30),
	FNOMEU char(30),
	FNOMEI char(10),
	FNOMEA char(10),
	PBLOCO char(4),
	UBLOCO char(4),
	UF char(2),
	MUNICIPIO char(6)
);

COPY sdf1103pad FROM '/home/rodrigo/Projetos/reclink/teste/sdf1103pad.csv' WITH CSV HEADER;

-- Tabela de referência
CREATE TABLE sdf1703pad(
	RECNO char(8) PRIMARY KEY NOT NULL,
	PIS char(11),
	RGP char(10),
	FNOMEP char(30),
	FNOMEU char(30),
	FNOMEI char(10),
	FNOMEA char(10),
	PBLOCO char(4),
	UBLOCO char(4),
	UF char(2),
	MUNICIPIO char(6)
);

COPY sdf1703pad FROM '/home/rodrigo/Projetos/reclink/teste/sdf1703pad.csv' WITH CSV HEADER;
