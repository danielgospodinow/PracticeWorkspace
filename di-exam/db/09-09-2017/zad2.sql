select NAME, DISPLACEMENT, NUMGUNS from CLASSES C
join SHIPS S on C.CLASS = S.CLASS
where DISPLACEMENT = (select MIN(DISPLACEMENT) from CLASSES)
  and NUMGUNS = (select MAX(NUMGUNS) from CLASSES where DISPLACEMENT = C.DISPLACEMENT);
