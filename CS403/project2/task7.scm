(define (main)
    (setPort (open (getElement ScamArgs 1) 'read))
    (println (apply queens (readExpr)))
)

(define (queens rows cols lowToHigh)

    (define (safe? newQueen queenlist)
        (cond
            ((null? queenlist)
                #t
            )
            ((or (= (car newQueen) (caar queenlist)) (= (cadr newQueen) (cadr (car queenlist)))
            (= 1 (abs (/ (real (- (car newQueen)(caar queenlist))) (- (cadr newQueen) (cadr (car queenlist)))))))
                #f
            )
            (else
                (safe? newQueen (cdr queenlist))
            )
        )
    )

    (define (rowIter i queenlist)
        (define (colIter j)
            (cond
                ((= i rows)
                    queenlist
                )
                ((= j cols)
                    nil
                )
                (else
                    (if (and (safe? (list i j) queenlist) (not (null? (rowIter (+ i 1) (cons (list i j) queenlist)))))
                        (rowIter (+ i 1) (cons (list i j) queenlist))
                        (colIter (+ 1 j))
                    )
                )
            )
        )
        (colIter 0)
    )

    (define (semetrisize input output)
        (if (null? input)
            output
            (semetrisize (cdr input) (append output (list (list (caar input) (- (- cols 1) (cadr (car input)))))))
        )
    )

    (if lowToHigh
        (rowIter 0 '())
        (semetrisize (rowIter 0 '()) '())
    )
)
