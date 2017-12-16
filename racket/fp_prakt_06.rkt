#lang racket

; Replacer
; (1 2 3 4) , (1. 7) (4.9) -> (7 2 3 9)
(define (replace list dict)

  (define (change x dict)
    (cond [(null? dict) x]
          [(equal? x (caar dict)) (cdar dict)]
          [else (change x (cdr dict))]))

  (map (lambda (x) (change x dict)) list))

;(replace '(1 2 3 4 5) '( (1 . 7) (4 . 9) ))

; Permutations
(define (permutations list)

  (define (insert-at pos x list)
    (cond [(null? list) (list x)]
          [(= pos 0) (cons x list)]
          [else (cons (car list) (insert-at (- pos 1)
                                            x
                                            (cdr list)))]))
  
  (define (in-all-positions x list)
    (map (lambda  (pos) (insert-at pos pos x list)) (range (+ 1 (length list)))))
  
  (define (helper res kst)
    (if (null? kst)
        res
        (helper (apply append (map (lambda (zst) (in-all-positions (car kst) zst)))
                       res)
                (cdr kst))))
    
  (helper '(()) list))

;(permutations '(1 2 3))

; Get the max ordered sublist
(define (max-ordered-sublist lst)

  (define (ordered-prefix lst)
    (define (helper prev kst)
      (if (or (null? kst) (> prev (car kst)))
          '()
          (cons (car kst) (helper (car kst) (cdr kst)))))
    (if (null? lst)
        '()
        (cons (car lst) (helper (car lst) (cdr lst)))))
  
  (define (helper kst max)
    (cond [(null? kst) max]
          [(< (length max) (length (ordered-prefix kst)))
           (helper (cdr kst) (ordered-prefix kst))]
          [else (helper (cdr kst) max)]))

  (helper lst '()))


;(max-ordered-sublist '(1 5 2 4 6 8 3 4 1))

(define (triangular?  mat)
  ;(map car mat) -> shte wyrne pyrwata kolona
  ;(map cdr mat) -> wsichki koloni bez pyrwata

  (define (isOkay? n mat)
    (if (= n 0)
        #t
        (if (= (car mat) 0)
            (isOkay? (- n 1) (cdr mat))
            #f)))
  
  (define (helper n all mat)
    (if (null? mat)
        #t
        (and (isOkay? (- all n) (car mat)) (helper (- n 1) all (cdr mat)))))

  (helper (length mat) (length mat) mat))

;(triangular? '((1 2 3) (0 5 6) (0 0 9)))
;(triangular? '((0 2 3) (0 0 6) (1 0 0)))

(define (pair-compose fs)
  (if (null? (cdr fs))
      (car fs)
      (λ (y) (((λ (x) ((car fs) ((cdr fs) x))) y) + ((pair-compose (cdr (cdr fs))) y)))))

((pair-compose '((λ (x) (*x x)) (λ (y) (+ y 1)))) 5)