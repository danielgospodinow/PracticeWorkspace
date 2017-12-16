#lang racket

; Map
(define (map proc lst)
  (if (null? lst)
      '()
      (cons (proc (car lst)) (map proc (cdr lst)))))
(map (λ(x) (* x x)) '(1 2 3 4))



; Foldl
(define (foldl oper nv lst)
  (if (null? lst)
      nv
      (oper (car lst) (foldl oper nv (cdr lst)))))
(foldl + 0 '(1 2 3))
(foldl (λ(x y) (or x y)) #f '(#f #f #f #t))



; Filter
(define (filter proc lst)
  (if (null? lst)
      '()
      (if (proc (car lst))
          (cons (car lst) (filter proc (cdr lst)))
          (filter proc (cdr lst)))))
(filter even? '(1 2 3 4 5 6))












  
