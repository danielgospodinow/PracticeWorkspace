-- Б) уж, но пак не е коректна

SELECT c.country , COUNT(o.result) FROM CLASSES c
JOIN SHIPS s ON c.class=s.class
JOIN OUTCOMES o ON s.name=o.ship
WHERE result='sunk'
GROUP BY c.country;

-- по-скоро май трябва да изглежда така:

SELECT c.country , COUNT(o.result) FROM CLASSES c
JOIN SHIPS s ON c.class=s.class
JOIN OUTCOMES o ON s.name=o.ship
WHERE result='sunk' and c.country in (select distinct country from CLASSES
    join SHIPS S2 on CLASSES.CLASS = S2.CLASS
    join OUTCOMES O2 on S2.NAME = O2.SHIP
    where O2.RESULT is not null)
GROUP BY c.country;
