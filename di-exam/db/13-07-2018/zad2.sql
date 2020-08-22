select NAME, COUNT(distinct S.MOVIETITLE) as TOTAL_FILMS from MOVIESTAR
join STARSIN S on MOVIESTAR.NAME = S.STARNAME
where GENDER = 'F'
group by NAME
order by COUNT(distinct S.MOVIETITLE) DESC
limit 1;
