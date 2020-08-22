-- В)

select M.NAME, MOVIE.TITLE, MOVIE.YEAR from MOVIE
join MOVIEEXEC M on MOVIE.PRODUCERC = M.CERT
where M.CERT = ANY (select PRODUCERC from MOVIE where TITLE = 'Pretty Woman');
