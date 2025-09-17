SELECT 
    d.Dziedzina,
    printf('%.2f zł', AVG(p.Cena)) AS "Średnia cena"
FROM publikacje p
JOIN dziedziny d 
    ON p.ID_dziedziny = d.ID_dziedziny
GROUP BY d.Dziedzina
ORDER BY d.Dziedzina;
