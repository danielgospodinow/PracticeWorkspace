select name, country from SHIPS
left join OUTCOMES O on SHIPS.NAME = O.SHIP
join CLASSES C on SHIPS.CLASS = C.CLASS
where O.BATTLE is null;