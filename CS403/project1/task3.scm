(define (main)
      (setPort (open (getElement ScamArgs 1) 'read))
        (define (print-together x y t)
        (define r-val (resistance x y t))
        	(print r-val " ")
        	(print (mred r-val t) " ")
        	(print (mgreen r-val t) " ")
        	(print (mblue r-val t) "\n")
        )
    (apply print-together (readExpr))
)
(define (resistance x y t)
	(define (iter r s i)
		(cond
			((= i t) t)
			((> (+ (* r r) (* s s)) 4) i)
			(else (iter (+ (- (* r r) (* s s)) x) (+ (* 2 r s) y) (+ i 1) ) )
		)
	)
	(iter 0 0 0)
)
(define (mred i t)
	;(cond
	(if (= i t) 
		0
		(integer (+ 
			(* 255 
				(cos 
					(* 
						(/ 3.14159265358979323846 
							(* 2.0 
								(- t 1) 
							) 
						) 
					i ) 
				) 
			)
		0.5 )
		)
	)	
)
(define (mgreen i t)

	(if (= i t) 
		0
		;(integer (+ (* 255 (sin (* (/ 3.14159265358979323846 (* 2.0 (- t 1) ) ) i) ) ) 0.5) )
		(integer (+ (* 255 (sin (* (/ 3.14159265358979323846 (- t 1) ) i) ) ) 0.5) )
	)
)

(define (mblue i t)
	;(cond
	(if (= i t) 
		0
		(integer (+ (* 255 (sin (* (/ 3.14159265358979323846 (* 2.0 (- t 1) ) ) i) ) ) 0.5) )

	)
)