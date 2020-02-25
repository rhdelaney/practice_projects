(define (main)
	(inspect (iterate i (list 5 2 4) (inspect i)))
	(inspect (iterate i (list 4 8 1) (inspect i) (inspect (+ i i))))
	(inspect (iterate i (list 5 7 1) (inspect i) (inspect (* i i))))
)
(define (iterate # $i lst $)
	(define l 
	  (cons
	    'lambda
	      (cons 
		'(i)
	        $ 
	    )
	  )
	)
	(define ll (eval l this))
	(define (it scope $i lst lam)
	  (cond ((=(length lst) 1)   
		(define $i (car lst))
		(eval (ll $i) scope)
	  )
		(else 	(define $i (car lst))
			(eval (ll $i) scope)
			(it scope $i (cdr lst) lam)))
)
	(define $i (car lst))
	(it # $i lst ll)
)