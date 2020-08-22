select name
from BATTLES
where (select count(*)
       from OUTCOMES o
                join SHIPS s on o.ship = s.name
                join CLASSES c on c.class = s.class
       where o.battle = BATTLES.name and type = 'bb')
          >
      (select count(*)
       from OUTCOMES o
                join SHIPS s on o.ship = s.name
                join CLASSES c on c.class = s.class
       where o.battle = BATTLES.name and type = 'bc');
