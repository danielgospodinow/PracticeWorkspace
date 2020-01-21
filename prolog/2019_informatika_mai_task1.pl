betw(A,A,B) :- A=<B.
betw(X,A,B) :- A<B, 
    A1 is A+1, 
    betw(X,A1,B).

gen(0).
gen(N) :- gen(M), N is M+1.

par(A,B) :- gen(N),
    betw(A,0,N),
    B is N-A.

getGoodWidthAndHeight(N, A, B) :-
    between(1,N,A),
    0=:=N mod A,
    B is N div A,
    B>0.

q(N,[AX,AY],[BX,BY],[CX,CY],[DX,DY]) :- par(AX,AY),
    getGoodWidthAndHeight(N, W, H),
    BX is AX + W,
    BY is AY,
    CX is AX,
    CY is AY - H,
    DX is AX + W,
    DY is AY - H.