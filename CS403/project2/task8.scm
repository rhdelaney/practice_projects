(define (extract instructions target)
  (define (distill str li)
    (cond 
      ((null? str) li)
      ((equal? "h" (car str))             ; h = take the car target
        (distill (cdr str) (car li))) ; and advance instruction string
      ((equal? "t" (car str))
        (distill (cdr str) (cdr li))) ; t = take the cdr of target
      )
    )
  (distill (string instructions) target)
  )
(define (main)
  (setPort (open (getElement ScamArgs 1) 'read))
  (define inst (readExpr))
  (define targ (readExpr))
  (println (extract inst targ) )
)