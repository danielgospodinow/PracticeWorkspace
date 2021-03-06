betw(A,A,B) :- A=<B.
betw(X,A,B) :- A<B, 
    A1 is A+1, 
    betw(X,A1,B).

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

rng(A,B,[]) :- A > B.
rng(A,B,[A|R]) :- A =< B,
    A1 is A+1,
    rng(A1,B,R).

toSet([], []).
toSet([HL|L],[HL|S]) :- not(membr(HL, L)), toSet(L,S).
toSet([HL|L],S) :- membr(HL, L), toSet(L,S).

select(X,L,L1) :- appnd(A,[X|B],L),
    appnd(A,B,L1).

perm([],[]).
perm(L,[HR|TR]) :- select(HR,L,L1),
    perm(L1,TR).