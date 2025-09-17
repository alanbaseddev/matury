SELECT Druzyna, COUNT(*) AS Liczba_harcerzy
FROM harcerze
GROUP BY Druzyna
ORDER BY Druzyna;