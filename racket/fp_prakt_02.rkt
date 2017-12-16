#lang racket

;=====================================Task-01=====================================

;Is Prime?
(define (isPrime n)
  (define (iter i)
    (cond
      [(> i (sqrt n)) #t]
      [else 
       (if (= (remainder n i) 0) #f (iter (+ i 1))) ]))

  (iter 2))



;Prime Summator
(define (primeSummator n k)
  (cond
    [(= n 0) 0]
    [else
     (if (isPrime (+ k 1)) (+ (+ k 1) (primeSummator (- n 1) (+ k 1))) (primeSummator n (+ k 1 )) )]))


;=====================================Task-02=====================================

;Power
(define (pow n m)
  (if (= m 0) 1 (* n (pow n (- m 1))) ))



;Get Num Len
(define (getNumLen n)
  (if (> n 0) (+ 1 (getNumLen (exact-floor (/ n 10)))) 0))



;Get reversed num
(define (getReversed n nlen)
  (if (<= nlen 1) n (+ (* (remainder n 10) (pow 10 (- nlen 1))) (getReversed (exact-floor(/ n 10)) (- nlen 1)) )))


  
;Is Palind?
(define (isPalind n)
  (= (getReversed n (getNumLen n)) n))


  
;Num of palindroms in [a, b]
(define (numOfPalinds a b)
  (cond
    [(> a b) 0]
    [else (if (isPalind a) (+ 1 (numOfPalinds (+ a 1) b)) (numOfPalinds (+ a 1) b))]))


;=====================================Task-03=====================================

;Total natural dividers
(define (totalNatDividers n)
  (define (iter i)
    (cond
      [(> i n 0) 0]
      [else (if (= (remainder n i) 0) (+ 1 (iter (+ i 1))) (iter (+ i 1)) )]))

  (iter 1))


;=====================================Task-04=====================================

;Biggest common divider

