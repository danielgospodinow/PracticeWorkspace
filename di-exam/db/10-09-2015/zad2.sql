-- Г)
SELECT name, address, AVG(length) AS avgLength FROM STUDIO
LEFT JOIN MOVIE ON name = studioName
WHERE NAME NOT IN (SELECT studioName FROM MOVIE WHERE inColor = 'n' GROUP BY studioName HAVING COUNT(*) > 3)
GROUP BY name, address;