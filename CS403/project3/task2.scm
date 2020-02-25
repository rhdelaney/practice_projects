(include "pretty.lib")

;(define (denv f) (get'__context f))

(define (included2? x L)
    (if (null? L)
        #f
        (begin
            (if (== (car L) x)
                #t
                (included2? x (cdr L))
            )
        )
    )
)

(define (compile f)
    ; capture the local variables (parameters)
    (define local-ids (get 'parameters f))
    (define body (get 'code f)) ;please google this shit
    (define env (get '__context f))
    ; iterate through the code
    (define (iter expr)
        (cond
            ; if the expr is a pair, and the car is define
            ; add the defined id to the local-ids list
            ; and iterate through the cddr to keep going
            ((pair? expr)
                (if (eq? (car expr) 'quote) 
                    (cons (iter (car expr)) (cdr expr))
                    (cons (iter (car expr)) (iter (cdr expr)))
                )
            )
            ((member? expr local-ids) expr)
            ((eq? expr 'begin) expr)
            ((symbol? expr)
                (begin 
                    (define someVar (catch (eval expr env)))
                    (cond
                        ((error? someVar) expr)
                        ((closure? someVar) (compile someVar) someVar)
                        (else
                            someVar
                        )
                    )
                )
            )
            (else
                nil
            )
        )
    )
    (define new (iter body))
    (set-car! body (car new))
    (set-cdr! body (cdr new))
)
;                 (if (eq? (car expr) 'define)
;                     (begin
;                         (if (pair? (cadr expr))
;                             (set! local-ids (append (cadr expr) local-ids))
;                             (set! local-ids (cons (cadr expr) local-ids))
;                         )
;                         ;(inspect local-ids)
;                         (cons 'define (cons (cadr expr) (iter (cddr expr))))
;                     )
;                     (cons (iter (car expr)) (iter (cdr expr)))
;                 )
;             )
;             ((included2? expr local-ids) expr)
;             ;((error? expr) expr)
;             ;((closure? expr) (compile expr))
;             (else (eval expr (denv f)))
;         )
;     )
;     ;(set* f'code (cons 'begin (cdr (iter (get 'code f)))))

; )

(define (main)
    (setPort (open (getElement ScamArgs 1) 'read))
    (define f (readExpr))
    ;(pretty (compile (eval f this)) )
    (compile (eval f this) )
    (pretty f)
)
