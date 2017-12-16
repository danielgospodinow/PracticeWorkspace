#lang racket

;01
(define (ex x n)

  (define (fact n)
    (if (= n 0) 1 (* n (fact (- n 1)))))

  (define (pow x n)
    (if (= n 0) 1 (* x (pow x (- n 1)))))

  (if (= n 0) 1 (+ (/ (pow x n) (fact n)) (ex x (- n 1)))))

;(ex 6 10)

;02
(define (include? a b)

  (define (checker a b)
    (cond
      [(= a 0) #t]
      [(= b 0) #f]
      [else (if (= (remainder a 10) (remainder b 10)) (checker (quotient a 10) (quotient b 10)) #f )]))

  (if (= b 0)
      #f 
      (cond
        [(= (remainder a 10) (remainder b 10)) (if (checker a b) #t (include? a (quotient b 10)) ) ]
        [else (include? a (quotient b 10)) ])))


;(include? 123 1234444443121312342)

;03
(define (difference F a b)
  (- (F a) (F b)))

;(difference (lambda (x) (* x x)) 7 3)

;04
(define f (lambda (x) (* 2 x)))

;05
(define (composition f g)
  (lambda (x) (f (g x))))

;((composition (lambda (x) (* x x)) (lambda (x) (+ x 1))) 5)

;06
(define (derive f eps)
  (lambda (x) (/ (- (f (+ x eps)) (f x)) eps )))

;(define f_ (derive (lambda (x) (* 2 x)) 1))
;(f_ 2)

;((derive (lambda (x) (* 2 x)) 1) 2)

;07
(define (secondDerive f eps)
  (derive (derive f eps) eps))

;((secondDerive (lambda (x) (* 2 x x)) 1) 2)

;08
(define (nDeritive)