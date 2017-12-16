#lang racket

(cons 1 2)
(cons 1 '())
(cons 1 (cons 2 '()))
(cons (cons 2 4) 1)
(define randList '(1 2 3 4 5 (1 2 3) 4 5))

(car randList)
(cdr randList)

(null? '() )

;01
(define (listLen list)
  (if (null? list)
      0
      (+ 1 (listLen (cdr list)))))

;(listLen (list 1 2 3 4 5 6 7))

;02
(define (revList list)

  (define (helper list revList)
    (if (null? list)
        revList
        (helper (cdr list) (cons )
  
  
        
  