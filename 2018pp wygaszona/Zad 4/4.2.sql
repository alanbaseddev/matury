SELECT * FROM (
    SELECT s.Nazwa_sprawnosci, SUM(d.L_punktow) AS Suma_punktow
    FROM dzialania d
    JOIN sprawnosc s ON d.Id_sprawnosci = s.Id_sprawnosci
    GROUP BY s.Nazwa_sprawnosci
    ORDER BY Suma_punktow DESC
    LIMIT 1
)
UNION ALL
SELECT * FROM (
    SELECT s.Nazwa_sprawnosci, SUM(d.L_punktow) AS Suma_punktow
    FROM dzialania d
    JOIN sprawnosc s ON d.Id_sprawnosci = s.Id_sprawnosci
    GROUP BY s.Nazwa_sprawnosci
    ORDER BY Suma_punktow ASC
    LIMIT 1
);
