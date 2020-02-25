(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
    (define op (readExpr))
    (define ugh (readExpr))
    (n-loop (eval op this) ugh)
)
;change recursive range to iterate through for more control
;okay you have to do this
;iterate through and make the return into a list
;cons said list (somehow?)
(define (n-loop procedure f)
	(define (range start stop step)
  		(define (help c)
    		(cond
      			((or
       			 (and (> step 0) (< c stop))
       			 (and (< step 0) (> c stop)))
      	 		 	(procedure c) ;can't cons here
          			(help (+ step c))
       		 	)
      			(else nil)
      		)
    	)
  		(help start)
	)
	(define (helpf f)
  		(cond
    		((null? f) nil)
    		;((null? (car (car f))) (range (car f) (cadr f) 1))
    		(else ;(begin
      			(range (car (car f)) (cadr (car f)) 1) ;prints out first val-> basically n-loop each and all right?
      			;(range (car (cadr f)) (cadr (cadr f)) 1)
      			;(range (car f) (cdr f) 1)
      			(helpf (cdr f))
      			;)
    		)
   		)
   	)
   	(helpf f)
)