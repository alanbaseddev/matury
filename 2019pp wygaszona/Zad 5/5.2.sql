SELECT p.Autor, p.Tytul FROM publikacje p
JOIN dziedziny d ON p.ID_dziedziny = d.ID_dziedziny
JOIN zakupy z ON p.ID_publikacji = z.ID_publikacji
WHERE
	z.Nick_clienta = 'flipher'
	AND p."Rok wydania" = 2014
	AND d.dziedzina IN ('informatyka', 'ekonomia');