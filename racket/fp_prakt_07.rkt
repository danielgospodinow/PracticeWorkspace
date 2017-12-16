#lang racket

; Task 1
; '(1 (2 3) (4 ((5) 6))) -> (1 2 3 4 5 6)
(define (flatten l)
  
  (define (atom? x)
    (and
     (not (null? x))
     (not (pair? x))))

  (cond
    ((null? l) l)
    ((atom? l) (list l))
    (else
     (append
      (flatten (car l))
      (flatten (cdr l))))))
  

(flatten '(1 (2 3) (4 (5 6))))


; Task 2
(define (diag-product matrix)
  
  (define (getMainDiag matrix diagLst)
    (if (null? matrix)
        diagLst
        (getMainDiag (cdr (map cdr matrix)) (cons (car (car matrix)) diagLst))))

  (apply + (map * (getMainDiag matrix '()) (getMainDiag (map reverse matrix) '()))))

;(diag-product '((1 2 3) (4 5 6) (7 8 9)))


; Task 3
(define (transponMatrix matrix)
  (if (null? (car matrix))
      '()
      (cons (map car matrix) (transponMatrix (map cdr matrix)))))

;(transponMatrix '((1 2 3) (4 5 6) (7 8 9)))










  