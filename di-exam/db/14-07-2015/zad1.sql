-- Г) which doesn't work for the MySQL dialect
SELECT starName FROM STARSIN JOIN MOVIE ON movieTitle = title AND movieYear = year
WHERE starName NOT LIKE '%a' AND inColor = 'y'
INTERSECT
SELECT starName FROM STARSIN
JOIN MOVIE ON movieTitle = title AND movieYear = year
WHERE inColor = 'n';

-- My solution
SELECT DISTINCT starName FROM STARSIN
INNER JOIN MOVIE ON movieTitle = title AND movieYear = year
WHERE starName NOT LIKE '%a'
  AND inColor = 'y'
  AND starName in (SELECT distinct starName FROM STARSIN, MOVIE WHERE STARSIN.MOVIETITLE = MOVIE.TITLE and inColor = 'n');