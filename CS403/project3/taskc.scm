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
  (println "...)")
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

(define (pair stream)
  (if (= (- (scar (scdr stream)) (scar stream)) 2)
    (cons-stream
      (list (scar stream) (scar (scdr stream)))
      (pair (scdr stream))
      )
    (pair (scdr stream))
    )
  )

(define twinPrimes (pair primes))
(define (main)
  ; (stream-display countingNums 3)
  ; (stream-display primes 7)
  (println "first seven twin primes?")
  (stream-display 7 twinPrimes)
  )