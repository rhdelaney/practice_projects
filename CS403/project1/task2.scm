(define (main)
        (setPort (open (getElement ScamArgs 1) 'read))
        (println (apply minMaxSum (readExpr)))
)
(define (minMaxSum a b c)
	; (define (min x y)
 ;    	(if (< x y) x y)
 ;    )
 ;    (define (max x y)
 ;    	(if (< x y) y x)
 ;    )
 ;    (+ (min ; 2
 ;       (min a b)
 ;       c
 ;    )
 ;    (max ; 5
 ;      (max a b) ; 6
 ;      c
 ;      )
 ;    )
	(if(< a b) ; 
		(if(< b c) ; b > a
			(+ a c) ;c>b > a
			(if(< a c) ; a<b b>c so if a<c<b
				(+ a b) ;a
				(+ c b) ;
			)
		)
		(if(< a c) ;a>b
			(+ b c) ;c>a>b
			(if(< b c) ; a>b a>c
				(+ a b) ; b<c<a
				(+ a c) ; c<b<a
			)
		)
	)
)
;use difference of c-a b-a and the larger number -> biggest number -> - means a is less than
