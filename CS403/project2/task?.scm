(define (main)
        (setPort (open (getElement ScamArgs 1) 'read))
        (define first (readExpr))
    	(define second (readExpr))
        (println (if2cond(readExpr)))
        (println (cond2if(readExpr)))
)
(define (if2cond )
	;all if s have both a true expression and a false expression
)
(define (cond2if )
	; all conds have an else

)