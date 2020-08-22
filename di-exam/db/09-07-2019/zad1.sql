-- A) or C), both work and look okay but I'll personally rely more on C)

select STUDIO.NAME, COUNT(M.TITLE) as COUNT from STUDIO
join MOVIE M on STUDIO.NAME = M.STUDIONAME
group by STUDIO.NAME
having COUNT(M.TITLE) < 2;
