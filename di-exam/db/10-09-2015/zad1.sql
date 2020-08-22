-- Б)
SELECT * FROM (SELECT name, address FROM MOVIESTAR WHERE gender = 'F' UNION SELECT name, address FROM STUDIO) T
WHERE T.address LIKE '%Sofia%'
ORDER BY T.address
