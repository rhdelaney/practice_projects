(define (scoping symbol object)
	(cond
		((local? symbol object) 'bound)
		(else
			(define (scope_iter sym env)
				(cond
					((null? env) 'undefined)
					((local? sym env) 'free)
					(else
						(scope_iter sym (env'__context))
						)
					)
				)
			(scope_iter symbol (object'__context))
			)
		)
	)
(define (main)
	
)