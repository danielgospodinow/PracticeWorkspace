-- A)
SELECT t.name, title FROM MOVIE m
JOIN (SELECT name, cert FROM MOVIEEXEC WHERE cert IN (SELECT producerc FROM MOVIE WHERE title='Pretty Woman')) t ON m.producerc=t.cert

-- My solution
select NAME, TITLE from MOVIE
join MOVIEEXEC M on MOVIE.PRODUCERC = M.CERT
where CERT = (select PRODUCERC from MOVIE where TITLE = 'Pretty Woman');
