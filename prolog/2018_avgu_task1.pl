betw(A,A,B) :- A=<B.
betw(X,A,B) :- A<B, A1 is A+1, betw(X,A1,B).

appnd([],B,B).
appnd([HA|A],B,[HA|L]) :- appnd(A,B,L).

gen(0).
gen(N) :- gen(M), N is M + 1.

par(A,B) :- gen(N),
    betw(A,0,N),
    B is N-A.

isPrime(X) :- X > 1,
    X1 is X - 1,
    not((betw(N, 2, X1), X mod N =:= 0)).

arePrimes([]).
arePrimes([H|T]) :- arePrimes(T), isPrime(H).

genks(1, S, [S]).
genks(K, S, [XI|R]) :- K>1,
    K1 is K - 1,
    betw(XI, 0, S),
    S1 is S - XI,
    genks(K1,S1,R).

areIncreasing([]).
areIncreasing([_]).
areIncreasing([H1,H2|T]) :- H1 < H2, 
    appnd([H2], T, T1), 
    areIncreasing(T1).

haveEqualDifferenceBetweenElements(_, []).
haveEqualDifferenceBetweenElements(_, [_]).
haveEqualDifferenceBetweenElements(N, [H1,H2|T]) :- N is H2 - H1, 
    appnd([H2], T, T1), 
    haveEqualDifferenceBetweenElements(N, T1).

haveEqualDifferenceBetweenElements([H1,H2|T]) :- N is H2 - H1,
    appnd([H1,H2], T, T1),
    haveEqualDifferenceBetweenElements(N, T1).

q(X) :- par(K,S),
    genks(K, S, X),
    areIncreasing(X),
    arePrimes(X),
    haveEqualDifferenceBetweenElements(X).
