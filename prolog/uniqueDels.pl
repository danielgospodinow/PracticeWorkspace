% Да се напише дефиниция на ПРОЛОГ на предикат p(X,Y,N), 
% който по дадени естествени числа X,Y връща в N броят на числата, 
% които делят X, но не делят Y

getDels(X,DS) :- range(2,X-1, XS),
    filterDels(X,XS,DS).

range(A,B,[]) :- A>B.
range(A,B,[A|R]) :- A=<B,
    A1 is A+1,
    range(A1,B,R).

filterDels(_,[],[]).
filterDels(X,[N|NS],[N|DS]) :- X mod N =:= 0,
    filterDels(X,NS,DS).
filterDels(X,[N|NS],DS) :- not(X mod N =:= 0),
    filterDels(X,NS,DS).

getUniquesFromFirst([],_,[]).
getUniquesFromFirst([XH|XT],Y,R) :- member(XH, Y),
    getUniquesFromFirst(XT,Y,R).
getUniquesFromFirst([XH|XT],Y,[XH|RT]) :- not(member(XH, Y)),
    getUniquesFromFirst(XT,Y,RT).

size([],0).
size([_|T],N) :- size(T,N1), 
    N is N1 + 1.

p(X,Y,N) :- getDels(X,XD),
    getDels(Y,YD),
    getUniquesFromFirst(XD,YD,US),
    size(US,N).