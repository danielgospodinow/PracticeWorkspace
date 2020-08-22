-- the solution wanted
SELECT BATTLE FROM OUTCOMES o1
WHERE not exists(SELECT *
                 FROM OUTCOMES o2
                 WHERE o1.battle = o2.battle and o1.ship != o2.ship);

-- the normal solution
select BATTLE from OUTCOMES
group by BATTLE
having COUNT(SHIP) = 1;