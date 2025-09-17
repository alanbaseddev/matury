SELECT
    H.Imie,
    H.Nazwisko,
    GROUP_CONCAT(DISTINCT S.Nazwa_sprawnosci) AS Sprawnosci
FROM
    harcerze H
JOIN
    dzialania D ON H.Id_harcerza = D.Id_harcerza
JOIN
    sprawnosc S ON D.Id_sprawnosci = S.Id_sprawnosci
WHERE
    D.Id_harcerza IN (
        SELECT
            Id_harcerza
        FROM
            dzialania
        GROUP BY
            Id_harcerza
        HAVING
            COUNT(DISTINCT Id_sprawnosci) = (
                SELECT
                    MAX(liczba)
                FROM
                    (
                        SELECT
                            COUNT(DISTINCT Id_sprawnosci) AS liczba
                        FROM
                            dzialania
                        GROUP BY
                            Id_harcerza
                    )
            )
    )
GROUP BY
    H.Id_harcerza, H.Imie, H.Nazwisko;