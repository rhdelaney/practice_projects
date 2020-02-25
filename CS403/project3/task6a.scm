(define (stream-for-each proc s times)
    (if (eq? times 0)
        'done
        (begin (proc (stream-car s))
            (stream-for-each proc (stream-cdr s) (- times 1)))))

(define (stream-display n s)
  (define (helper t c)
    (if (= c 0)
      'OK
      (begin
        (print (stream-car t) " ")
        (helper (stream-cdr t) (- c 1))
        )
      )
    )
  (print "(")
  (helper s n)
  (println "...)")
)

(define (display-line x)
    (print x)
    (print " ")
    )

(define (stream-filter pred stream)
    (cond ((stream-null? stream) the-empty-steam)
        ((pred (stream-car stream))
            (cons-stream (stream-car stream)
                (stream-filter pred (stream-cdr stream))))
        (else
            (stream-filter pred (stream-cdr stream)))))

(define (big-gulp? n)
    (define factors (pfactors n))
    (define (iter f)
        (cond
            ((null? f) #t)
            ( (eq? (car f) n) #f)
            (else
                (iter (cdr f))
            )
        )
    )
    (iter factors)
)

(define (pfactors n)
    (define (helper n m)
        (cond
            ((eq? n 1) '())
            ((eq? (% n m) 0) (cons m (helper (/ n m) 2)))
            (else
                (inspect m)
                (helper n (+ 1 m))
            )
        )
    )
    (helper n 2)
)

(define (integers-starting-from n)
    (cons-stream n (integers-starting-from (+ n 1)))
    )

(define (big-gulp n)
    (cons-stream n (stream-filter big-gulp? (integers-starting-from n)))
    )

(define (main)
    (setPort (open (getElement ScamArgs 1) 'read))
    (define f (readExpr))
    (define n (readExpr))
    (define pfs (big-gulp n))
    (stream-display f pfs)
)