#lang racket

;Is perfect num?
(define (isPerfectNum n)
  (define (iter i)
    (if (= i n) 
        0
        (if (= 0 (remainder n i))
            (+ i (iter (+ i 1)))
            (iter (+ i 1)))))

  (= (iter 1) n)
  )

;(isPerfectNum 496)


;Has inc digits?
(define (incDigits n)

  (define (digDiv n ld)
    (if (and (<= n 9) (>= n 0)) 
        (>= ld n)
        (if (>= (remainder n 10) (remainder (quotient n 10) 10)) (digDiv (quotient n 10) (remainder n 10) ) #f)))

  (digDiv n (remainder n 10)))

;(incDigits 123734)


;Is n automorphic?
(define (isAutomorphic n)
  
  (define (sravnenie n m)
    (if (= n 0) #t
        (if (= (remainder n 10) (remainder m 10)) (sravnenie (quotient n 10) (quotient m 10)) #f)))
  
  (sravnenie n (* n n)))

;(isAutomorphic 25)


;Sum of x^0 + x^1 + ... + x^n
(define (eps x n)

  (define (pow x n)
    (if (= n 0) 1 (* x (pow x (- n 1)))))

  (if (< n 0) 0 (+ (pow x n) (eps x (- n 1)))))

;(eps 2 3)