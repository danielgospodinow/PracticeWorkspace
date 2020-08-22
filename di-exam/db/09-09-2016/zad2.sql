-- A) и В), но В) е по-оптимално

-- A)
SELECT DISTINCT BATTLE FROM OUTCOMES o1
WHERE (SELECT COUNT(DISTINCT country) FROM OUTCOMES o,SHIPS s,CLASSES c WHERE o.ship=s.name AND s.class=c.class AND battle=o1.battle) >
      (SELECT count(DISTINCT country) FROM OUTCOMES o,SHIPS s,CLASSES c WHERE o.ship=s.name AND s.class=c.class AND battle='Coral Sea')

-- В)
SELECT DISTINCT battle FROM OUTCOMES o, SHIPS s, CLASSES c
WHERE o.ship=s.name AND s.class=c.class
GROUP BY battle
HAVING COUNT(DISTINCT country) >
       (SELECT COUNT(country) FROM OUTCOMES o, CLASSES c, SHIPS s WHERE ship=name AND s.class=c.class   AND battle='Coral Sea');
