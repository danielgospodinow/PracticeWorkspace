betw(A,A,B) :- A=<B.
betw(X,A,B) :- A<B, A1 is A+1, betw(X,A1,B).

gen(0).
gen(N) :- gen(M), N is M+1.

par(A,B) :- gen(N),
    betw(A,0,N),
    B is N-A.

getById(H,0,[H|_]).
getById(X,I,[_|T]) :- I1 is I-1, getById(X,I1,T).

appnd([],B,B).
appnd([HA|A],B,[HA|L]) :- appnd(A,B,L).

membr(X,[X|_]).
membr(X,[_|T]) :- membr(X,T).

membr2(X,L) :- appnd(_,[X|_],L).

rev([],[]).
rev([H|T],R) :- rev(T,TR), append(TR,[H],R).

sums(0,[]).
sums(N,[H|T]) :- betw(H,1,N), O is N-H, sums(O,T).

listN(L) :- par(A,B), listN(A,B,L).
listN(N,M,[H|L]) :- N>0,
    betw(H,0,M),
    N1 is N - 1,
    listN(N1, M, L).

genListWithMembersOfA([], _).
genListWithMembersOfA([H|S], A) :- genListWithMembersOfA(S,A), 
    membr(H,A).

genks(1, S, [S]).
genks(K, S, [XI|R]) :- K>1,
    K1 is K - 1,
    betw(XI, 0, S),
    S1 is S - XI,
    genks(K1,S1,R).
