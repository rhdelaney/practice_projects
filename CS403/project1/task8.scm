(define (main)
(setPort (open (getElement ScamArgs 1) 'read))
(define args (readExpr))
(println "half of " (car args) " is " (halve (car args)))
(println "half of " (cadr args) " is " (halve (cadr args)))
(println (car args) " squared is " (square (car args)))
(println (cadr args) " squared is " (square (cadr args)))
(println (apply babyl args))
)
(define (babyl a b)
	(halve (- (square (+ a b) ) (square a ) ( square b ) ) )
)
(define (square i)
	(define (siter count acc) 
		(if(= count 1) 
			acc
			(siter (- count 1) (- (+ acc (+ count count) ) 1) )
		)
	)
	(siter i 1)
)
(define (halve n)
  (define (hitter acc twos prev n)
  	(cond
  	;powers
  		((< (+ twos twos) n) (hitter acc (+ twos twos) twos n))
  		((>= (- n prev) 1) (hitter (+ acc prev) 1 1 (- n twos) ) )
  		(else acc)
  	)
  )
  (hitter 0 1 1 n)
)