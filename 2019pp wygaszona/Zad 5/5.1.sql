SELECT Tytul, Cena from publikacje
WHERE
	(ID_publikacji LIKE 'a%' AND Cena > 45)
	OR
	(ID_publikacji LIKE 'e%' AND Cena > 120)
ORDER BY Cena DESC;