#lang racket

;Range
(define (range a b)
  (if (>= a b)
      (cons b '())
      (cons a (range (+ a 1)  b))))

;(range 1 6)

;Odd summer
(define (sum-odd list)
  (if (null? list)
      0
      (if (= 1 (remainder (car list) 2))
          (+ (car list) (sum-odd (cdr list)))
          (sum-odd (cdr list)))))

;(sum-odd '(1 2 3 4 5 6 7))

;Filter odd numbers
(define (filter-even list)
  (if (null? list)
      '()
      (if (= 0 (remainder (car list) 2))
          (cons (car list) (filter-even (cdr list)))
          (filter-even (cdr list)))))

;(filter-even '(1 2 3 4 5 6 7 8))

;Intersection of two sets
(define (intersect set1 set2)
  (if (null? set1)
      '()
      (if (member (car set1) set2)
          (cons (car set1) (intersect (cdr set1) set2))
          (intersect (cdr set1) set2))))

;(intersect '(15 7 1 16 3 2) '(1 2 3 7 4 5 6))

;List reverse
(define (revListMincho list)
  (cond
    ((null? (cdr list)) (car list))
    (else
      (cons (revListMincho (cdr list)) (car list)))))
      

(define (revList list)

  (define (revListHelp list rev)
    (if (null? list)
        rev
        (revListHelp (cdr list) (cons (car list) rev))))

  (revListHelp list '()))

;(revList '(1 2 3 4 5))

;List append
(define (listAppend list01 list02)

  (define (listAppHelp revList list)
    (if (null? revList)
        list
        (listAppHelp (cdr revList) (cons (car revList) list))))

  (listAppHelp (revList list01) list02))

;(listAppend '(1 2 3) '(3 2 1))

;Remove dublicats
(define (removeDubs list)

  (define (removeDubsHelp list retList)
    (if (null? list)
        retList
        (if (not (member (car list) retList))
            (removeDubsHelp (cdr list) (cons (car list) retList))
            (removeDubsHelp (cdr list) retList))))

  (removeDubsHelp (revList list) '()))

;(removeDubs '(1 1 1 2 1 3 4 4 7 6 7 6 6 6 7 7 7))

(define (getDigits n)

  (define (getDigitsHelp n list)
    (if (<= n 0)
        list
        (getDigitsHelp (quotient n 10) (cons (remainder n 10) list))))

  (getDigitsHelp n '()))

;(getDigits 123456123456)