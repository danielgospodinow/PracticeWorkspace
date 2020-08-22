select NAME, SUM(LENGTH) from MOVIEEXEC
join MOVIE M on MOVIEEXEC.CERT = M.PRODUCERC
where CERT in (select distinct PRODUCERC from MOVIE where YEAR < 1980) and LENGTH is not null
group by NAME;
