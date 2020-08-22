select studioname, title, year
from MOVIE m
where year = (select MAX(YEAR) from MOVIE where m.STUDIONAME = STUDIONAME);
