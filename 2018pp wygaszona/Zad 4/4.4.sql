SELECT DISTINCT h.Druzyna
FROM harcerze h
WHERE h.Druzyna NOT IN (
    SELECT h2.Druzyna
    FROM dzialania d
    JOIN harcerze h2 ON d.Id_harcerza = h2.Id_harcerza
    JOIN sprawnosc s ON d.Id_sprawnosci = s.Id_sprawnosci
    WHERE s.Nazwa_sprawnosci = 'ratownik'
);
