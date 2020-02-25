(define (exprTest # $expr target)
   (define result (catch (eval $expr #)))
   (if (error? result)
      (println $expr " is EXCEPTION: "(result'value)
         " (it should be " target ")")
      (println $expr " is " result
         " (it should be " target ")")
      )
   )
   
(define (iterator # $x items $)
   (define lamList (eval (lambda ($x) $) #))
   (map lamList items)
   )

(define (peval f @)
   ; if 'MISSING is not in @ 
   ; then return lambda function
   ; else use lambda to collect another list of variables
   ; then replace each 'MISSING with corresponding var from new list
   ; and generate a lambda
   ; and finally evaluate the generated lambda function
   (define p @)
   (lambda (@)
      (define lst (cons nil nil))
   ; old version
;      (while (and (valid? p) (valid? @))
;         (if (eq? (car p) 'MISSING)
;            ; add car of @ to lst
;            (define lst (append lst (cons (car @) nil)))
;            ; else add car of p to lst
;            (define lst (append lst (cons (car p) nil)))
;            )
;         (define p (cdr p))
;         (define @ (cdr @))
;         )
   ; new version
      (define (constLst p @ ls)
;         (print lst)
;         (pause)
         (if (eq? (car p) 'MISSING)
            ; add car of @ to lst
            (define ls (append ls (cons (car @) nil)))
            ; else add car of p to lst
            (define ls (append ls (cons (car p) nil)))
            )
         (if (and (valid? (cdr p)) (valid? (cdr @))) 
            (constLst (cdr p) (cdr @))
            lst
            )
         )
   ; old version
;      (while (valid? p)
;         (define lst (append lst (cons (car p) nil)))
;         (define p (cdr p))
;         )
   ; new version
      (define (finishLst p ls)
         (define ls (append ls (cons (car p) nil)))
         (if (valid? (cdr p)) 
            (finishList (cdr p)))
            lst
         )
;      (print p)
;      (print @)
;      (print lst)
;      (pause)
      (define lst (constLst p @ lst))
;      (print lst)
;      (print p)
;      (print @)
      (define lst (finishLst p lst))
      (define lst (cdr lst))
      (apply f lst)
      )
   )

(define (main)
    (define (f x y) (+ x y))
    (define x 1)
    (define y 2)
    (define . 'MISSING)
    (exprTest ((peval f 1 2)) 3)
    (exprTest ((peval f 0 2) 1) 3)
    (exprTest ((peval f 0) 1 2) 3)
    )