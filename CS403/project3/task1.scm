(define (main)
    (setPort (open (getElement ScamArgs 1) 'read))
    (eval (readExpr) this)
    (eval (readExpr) this)
    ;(eval (readExpr) this)
)


(define (staticScope count env)

    (define (findVars levnum names values ev)

        (define (findLocal vars vals)
            (cond
                ((eq? 'nil (car vars)) 0)
                ((eq? (car vars) 'this)
                    (getVars (cdr vars) (cdr vals))
                )
                (else
                    (findLocal (cdr vars) (cdr vals))
                )
            )
        )
        (define (getVars sym l)

            (if (local? (car sym) ev)
                (begin
                    (print "    ")
                    (print (car sym))
                    (print " : ")
                    (if (not(defined? (car sym) env))
                        (print "UNINITIALIZED")
                        (if (closure? (car l))
                            (begin
                                (print "#[user defined function ")
                                (print (cons (get 'name (car l)) (get 'parameters (car l))))
                                (print "]")
                            )
                            (print (car l))
                        )
                    )
                    (println)
                )
            )

            (if (not(eq? 'nil (cdr sym)))
                (getVars (cdr sym) (cdr l))
            )
        )

        (print "#[environment L")
        (print levnum)
        (print "]")
        (println)

        (findLocal names values)
    )



    (define (scope-iter current i myenv)
        (cond
            ((= i 0)
                ;(inspect (get '__level myenv))
                (define max (get '__level myenv))
                (scope-iter 0 max myenv)
            )
            ((= current (- i 1))
                (findVars current (cadr myenv) (caddr myenv) myenv)
            )
            ((< current i)
                (begin
                    (findVars current (cadr myenv) (caddr myenv) myenv)
                    (scope-iter (+ 1 current) i (myenv'__context))
                    ;(scope-iter (+ 1 current) i (cadr (caddr myenv)))
                )
            )
            (else
                (println "ERROR, LEVEL" i "IS OUT OF SCOPE")
            )
        )
    )


    (scope-iter 0 count env)
)
