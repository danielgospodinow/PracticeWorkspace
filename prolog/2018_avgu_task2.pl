appnd([],B,B).
appnd([HA|A],B,[HA|L]) :- appnd(A,B,L).

membr(X,L) :- appnd(_,[X|_],L).

p1(X) :- membr([], X).

p2(X) :- membr(Y, X), 
    membr(Z, X), 
    member(M,Y), 
    not((member(M, Z))).

p3(X) :- membr(Y,X),
    not((membr(Z,X), member(Z1, Z), not((membr(Z1, Y))))).

p4(X) :- not((membr(Y,X), not((membr(Z,X), membr(Z1, Z), not((membr(Z1, Y))))))).
