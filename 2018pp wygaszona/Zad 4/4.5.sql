SELECT 
    h.Imie,
    h.Nazwisko,
    s.Nazwa_sprawnosci,
    SUM(julianday(d.Koniec_dzial) - julianday(d.Poczatek_dzial) + 1) AS Liczba_dni
FROM dzialania d
JOIN harcerze h ON d.Id_harcerza = h.Id_harcerza
JOIN sprawnosc s ON d.Id_sprawnosci = s.Id_sprawnosci
GROUP BY d.Id_harcerza, d.Id_sprawnosci
ORDER BY Liczba_dni DESC
LIMIT 1;
