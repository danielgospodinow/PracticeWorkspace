select NAME from MOVIEEXEC
where NETWORTH = (select MIN(NETWORTH) from MOVIEEXEC);
