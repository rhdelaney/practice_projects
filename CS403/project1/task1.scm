(define (main)
        (setPort (open (getElement ScamArgs 1) 'read))
        (println (apply zeno (readExpr)))
        )
(define (zeno d n c)
	(cond
		((= n 1) 
			(/ (real (^ c (/ (real (log d) ) (log 2.00) ) ) ) 12.00)
		)
		(else
			(+ (zeno (/ (real d) 2.00) (- n 1) c
				)
				(/ (real (^ c (/ (real (log (/ (real d) 2.00) ) ) (log 2.00) ) ) ) 12.00)
			)
		)
	)	
)