-- the solution wanted: wtf?

-- the normal solution
select BATTLE from OUTCOMES
group by BATTLE
having COUNT(SHIP) = 1;