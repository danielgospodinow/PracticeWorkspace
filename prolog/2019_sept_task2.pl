appnd([],B,B).
appnd([HA|A], B, [HA|C]) :- appnd(A,B,C).

multi(1, L1, L1).
multi(K, L, R) :- K > 0,
    K1 is K - 1, 
    multi(K1, L, R1), 
    appnd(R1, L, R).

listEq([],[]).
listEq([H|L1], [H|L2]) :- listEq(L1, L2).

membr(E, L) :- appnd(_, [E|_], L).

gen(0).
gen(N) :- gen(M), N is M + 1.

% Not correct, see exact implementation
subs(0, [], _).
subs(N, S, L) :- N1 is N - 1, 
    subs(N1, S1, L), 
    membr(M, L), 
    appnd([M], S1, S).
subs(S, L) :- gen(N), 
    subs(N, S, L).

% To be continued...
isCyclic(L) :- genList(U),
    genNum(N),
    genList(V),
    genList(W),
    multi(U, N, UR),
    appnd(V, W, V1),
    appnd(UR, V1, L).

copy([], []).
copy([H|T], [H|R]) :- copy(T,R).

% Not sure
cycl(A, L) :- subs(S, A), 
    isCyclic(S),
    copy(L, L1),
    appnd(L1, S, L).
