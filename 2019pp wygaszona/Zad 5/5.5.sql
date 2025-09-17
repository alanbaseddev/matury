SELECT * FROM (
    SELECT Nick_clienta, printf('%.2f zł', SUM(Cena)) AS Kwota
    FROM zakupy z
    JOIN publikacje p ON z.ID_publikacji = p.ID_publikacji
    GROUP BY Nick_clienta
    ORDER BY SUM(Cena) DESC
    LIMIT 1
)
UNION ALL
SELECT * FROM (
    SELECT Nick_clienta, printf('%.2f zł', SUM(Cena)) AS Kwota
    FROM zakupy z
    JOIN publikacje p ON z.ID_publikacji = p.ID_publikacji
    GROUP BY Nick_clienta
    ORDER BY SUM(Cena) ASC
    LIMIT 1
);
