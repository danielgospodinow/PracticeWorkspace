#lang racket

;Squarer
(define (squarer x) (* x x) )

















;Min of two nums
(define (min x y) (if (< x y) x y))











;Factorial
(define (fact num)
  (
   if (= num 0)
      1
      (* (fact(- num 1)) num)
  )
)
(fact 5)









;Average of two nums
(define (avg x y) (/ (+ x y) 2) )
(avg 7 5)












;Pow func
(define (pow x n) (if (= n 0) 1 (* x (pow x (- n 1))) ))
(pow 2 5)












;Fibonnaci (recursive)
(define (fib n)
  (if (>= n 2)
      (+ (fib (- n 1)) (fib (- n 2)))
      1
  )
)
(fib 20)











;Fibonnaci (iterative)
(define (fib-iter n)
  (define (helper n-2 n-1 i)
    (if (= i n)
        (+ n-1 n-2)
        (helper n-1 (+ n-1 n-2) (+ i 1))))
  (if (< n 2)
      1
      (helper 1 1 2)))

(fib-iter 20)













;
