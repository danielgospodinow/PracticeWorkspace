#lang racket

; Task 1
(define (sum-numbers a b)

  (define (isGoodNum? num)
    (define (helper x lastDig)
      (if (= x 0)
          #t
          (if (<= lastDig (remainder x 10))
              (helper (quotient x 10) (remainder x 10))
              #f)))

    (helper (quotient num 10) (remainder num 10)))
    
  (if (> a b)
      0
      (if (isGoodNum? a)
          (+ a (sum-numbers (+ a 1) b))
          (sum-numbers (+ a 1) b))))

;(sum-numbers 219 225)


; Task 2
(define (num-bigger-elements lst)

  (define (getBigger el lst)
    (if (null? lst)
        0
        (if (> (car lst) el)
            (+ 1 (getBigger el (cdr lst)))
            (getBigger el (cdr lst)))))
  
  (define (helper lst finalLst origList)
    (if (null? lst)
        finalLst
        (helper (cdr lst) (cons (cons (car lst) (getBigger (car lst) origList)) finalLst) origList)))
  
  (reverse (helper lst '() lst)))

;(num-bigger-elements '(5 6 3 4))


; Task 3
(define (switchsum f g n)

  (define (helper i prev sum)
    (cond [(> i n) sum]
          [(even? i) (helper (+ i 1) (f prev) (+ sum (f prev)))]
          [else (helper (+ i 1) (g prev) (+ sum (g prev)))]))

  (λ (x) (helper 0 (f x) (f x))))


; Task 4
(define (repeater str)

  (define (appender glue n)
    (if (= n 0)
        glue
        (appender (string-append glue str) (- n 1))))

  (λ(x y)(appender x y)))

;((repeater "Gay") " " 5)


; Task 5
(define (sum-sum-digit a b k)

  (define (getDigSum a)
    (if (= a 0)
        0
        (+ (remainder a 10) (getDigSum (quotient a 10)))))
  
  (if (> a b)
      0
      (if (= 0 (remainder (getDigSum a) k))
          (+ a (sum-sum-digit (+ a 1) b k))
          (sum-sum-digit (+ a 1) b k))))

;(sum-sum-digit 5 20 5)


; Task 6
(define (max-ordered-sublist lst)

  (define (getLen lst)
    (if (null? lst)
        0
        (+ 1 (getLen (cdr lst)))))
  
  (define (helper2 lst last)
    (if (null? lst)
        '()
        (if (>= (car lst) last)
            (cons (car lst) (helper2 (cdr lst) (car lst)))
            '())))
  
  (define (helper1 lst finalLst)
    (if (null? lst)
        finalLst
        (helper1 (cdr lst) (cons (helper2 lst (car lst)) finalLst))))

  (define maxNum (apply max (map (λ(x) (getLen x)) (helper1 lst '()))))
  (car (filter (λ(x) (>= (getLen x) maxNum)) (helper1 lst '()))))


;(max-ordered-sublist '(1 5 2 4 6 8 3 4 1))


; Task 7
(define (pair-compose fs)

  (define (helper fs x)
    (if (and (not (null? fs)) (not (null? (cdr fs))))
        (+ ((car fs) ((car (cdr fs)) x)) (helper (cdr (cdr fs)) x))
        (if (not (null? fs))
            ((car fs) x)
            0)))

  (λ(x) (helper fs x)))

;(define g (pair-compose (list (λ(x)(+ x 1)) (λ(x)(+ x 2)))))
;(g 1)

      
; Task 8
(define (where elems predics)
  (if (null? predics)
      elems
      (where (filter (car predics) elems) (cdr predics))))

  
;(where '(3 4 5 6 7 8 9 10) (list even? (λ(x) (> x 5))))
;(where '(3 4 5 7) (list even? (λ(x) (> x 5))))









 