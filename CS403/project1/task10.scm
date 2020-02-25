(define (main)
        (setPort (open (getElement ScamArgs 1) 'read))
        (define args (readExpr))
        (println "ramanujan returns " (ramanujan (car args)))
        (println "iramanujan returns " (iramanujan (car args)))
		(println "$3$")
)
(define (ramanujan a)
	;	(^ (* (ramanujan (- a 1) ) (+ 1 (+ a 1) ) ) (/ 1 2.00))
	;)
  (define (h x) 
    (if (<= (- x 1) a)                        ; x times
        (sqrt                     ; the square root of 
          (+ 1 
          	(* x              ; (x) plus
            	(h (+ x 1))           ; the recursion, with (x+1)
            )
          )
        )
      	1                            ; add zero when we hit max depth
      )
    )
    (if(= a 0)
      0.0
  	 (h 2)
    )
  )
(define (iramanujan a)
  (define (iter store src)                 ; define an iterator function
    (if (> src 1)                          ; we're working from the depth, up
      (iter                                ; iterate, and: 
        (sqrt (+ 1 (* src store))) ;   calculate new store w/ old store
        (- src 1)                          ;   decrease the depth by 1
        )
      store                                ; once we hit min depth, return store
      )
    )
    (if(= a 0)
      0.0
  	 (iter 1 (+ 1 a))
    ) ; call iterator with (depth + 1)     
)