#lang racket

; Task1- Convert K to N number system
(define (convert x k n)

  (define (convKtoDec k x step)
    (if (= x 0)
        0
        (+ (* (remainder x 10) (expt k step)) (convKtoDec k (quotient x 10) (+ step 1)))))

  (define (convDectoN n x step)
    (if (= x 0)
        0
        (+ (* (remainder x n) (expt 10 step)) (convDectoN n (quotient x n) (+ 1 step)))))
  
  
  (convDectoN n (convKtoDec k x 0) 0))

;(convert 123 10 2) ;-> 1111011
;(convert 173 8 10) ;-> 123


; Task2- Sum numbers in shit string
(define (sum-numbers str)

  (define (getNumLists listOfChars finalList currentNumList)
    (if (null? listOfChars)
        finalList
        (if (and (>= (char->integer (car listOfChars)) (char->integer #\0)) (<= (char->integer (car listOfChars)) (char->integer #\9)))
            (getNumLists (cdr listOfChars) finalList (cons (- (char->integer (car listOfChars)) (char->integer #\0)) currentNumList))
            (if (null? currentNumList)
                (getNumLists (cdr listOfChars) finalList '())
                (getNumLists (cdr listOfChars) (cons currentNumList finalList) '())))))

  (define (listToInt list i)
    (if (null? list)
        0
        (+ (* (car list) (expt 10 i)) (listToInt (cdr list) (+ i 1)))))
  
  (apply + (map (λ (x) (listToInt x 0)) (getNumLists (append (string->list str) (list (integer->char 65))) '() '()))))


;(sum-numbers "a123b2c56")
;(sum-numbers "a1b2c3")


; Task3- RLE
(define (encode lst)

  (define (rleHelp lst finalList currListLen last)
    (if (null? lst)
        (cons (cons last (list currListLen)) finalList)
        (if (eq? (car lst) last)
            (rleHelp (cdr lst) finalList (+ 1 currListLen) last)
            (rleHelp (cdr lst) (cons (cons last (list currListLen)) finalList) 1 (car lst)))))

  (reverse (rleHelp lst '() 0 (car lst))))

;(encode '(a a a a b c c a a d e e e e))
;(encode  '(m i s s i s s i p p i))


;Task4- Get the best return value of all functions
(define (maximize funcLst)

  (define (getMaxVal fL x maxX)
    (if (null? fL)
        maxX
        (if  (> (abs ((car fL) x)) (abs maxX))
             (getMaxVal (cdr fL) x ((car fL) x)) 
             (getMaxVal (cdr fL) x maxX))))

  (λ (x) (getMaxVal funcLst x ((car funcLst) x))))

;((maximize (list (λ(x) (- x 10)) (λ(x) (- x 5)))) 5)
;((maximize (list (λ(x) (- x 10)) (λ(x) (- x 5)))) 9)


;Task4- Second solution
;(define (maximize1 fL)

  ;(λ(x) (map (λ(y) (y x)) fL)))


;((maximize1 (list (λ(x) (- x 10)) (λ(x) (- x 5)))) 5)
;((maximize1 (list (λ(x) (- x 10)) (λ(x) (- x 5)))) 9)





(define (maxy fncLst)

  (define (getMaxAbsVal lst currMax)
    (if (null? lst)
        currMax
        (if (< (abs currMax) (abs (car lst)))
            (getMaxAbsVal (cdr lst) (car lst))
            (getMaxAbsVal (cdr lst) currMax))))

  (λ(x) (getMaxAbsVal (map (λ(y) (y x)) fncLst) ((car fncLst) x))))

((maxy (list (λ(x) (- x 10)) (λ(x) (- x 5)))) 5)
((maxy (list (λ(x) (- x 10)) (λ(x) (- x 5)))) 9)


