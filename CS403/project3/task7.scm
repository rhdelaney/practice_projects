(define scar stream-car)
(define scdr stream-cdr)
(define (stream-add s t)
  (cons-stream
    (+ (stream-car s) (stream-car t))
    (stream-add (stream-cdr s) (stream-cdr t))
    )
  )
(define (repeat x)
  (cons-stream x (repeat x))
  )
(define (stream-keep p? s)
  (if (p? (scar s))
    (cons-stream (scar s) (stream-keep p? (scdr s)))
    (stream-keep p? (scdr s))
    )
  )
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
  (print "...)")
)
(define countingNums
  (cons-stream 1 (stream-add (repeat 1) countingNums))
  )

(define (divisible? a b) (= (% a b) 0))

(define (sieve stream)
  (cons-stream
    (scar stream)
    (sieve 
      (stream-keep
        (lambda (x) (not (divisible? x (scar stream))))
        (scdr stream)
      )
    )
  )
)

(define primes (sieve (scdr countingNums)))
;(define primes2 (sieve (scdr primes)))

(define (pair stream1 stream2 num)
  (if (<= (- (scar (scdr stream2)) (scar stream1)) num )
    (cons-stream
      (list (scar stream1) (scar (scdr stream2)))
      (pair stream1 (scdr stream2) num)
    )
    (pair (scdr stream1) (scdr stream1) num)
  )
)

(define (twinPrimes num) (pair primes primes num))
  

(define (main)
  (setPort (open (getElement ScamArgs 1) 'read))
  (define f (readExpr))
  (define b (readExpr))
  ;(stream-display 3 countingNums)
  ;(stream-display 3 primes)
  (stream-display f (twinPrimes b))
  (println)
  )