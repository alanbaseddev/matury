SELECT d.dziedzina, COUNT(*) AS Liczba_zakupow
FROM zakupy z JOIN publikacje p
	on z.ID_publikacji = p.ID_publikacji
JOIN dziedziny d
	ON p.ID_dziedziny = d.ID_dziedziny
GROUP BY d.dziedzina
ORDER BY Liczba_zakupow DESC
LIMIT 1;