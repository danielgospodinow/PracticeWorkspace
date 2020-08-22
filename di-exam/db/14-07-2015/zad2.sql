-- Б)
SELECT name, YEAR(birthdate), COUNT(DISTINCT studioName) FROM MOVIESTAR
LEFT OUTER JOIN STARSIN ON name = starname
LEFT JOIN MOVIE ON movieTitle = title AND movieYear = year
GROUP BY name
HAVING COUNT(title) <= 5;