betw(A,A,B) :- A =< B.
betw(X,A,B) :- A < B, 
    A1 is A + 1, 
    betw(X, A1, B).

cover(H,V,N,K) :- betw(N1,0,N),
    betw(N2, 0, N),
