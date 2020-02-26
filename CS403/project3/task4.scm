(define false #f)
(define true #t)
(define (memq item x)
  (cond ((null? x) false)
        ((eq? item (car x)) x)
        (else (memq item (cdr x))))
)
(define (error @)
    (println)
    (apply println @)
    )

(define (for-each-except exception procedure list)
    (define (loop items)
        (if (null? items)
            'done
            (if (eq? (car items) exception)
                (loop (cdr items))
                (begin
                    (procedure (car items))
                    (loop (cdr items))
                )
            )

        )
    )
    (loop list)
)

(define (has-value? connector)
    (connector 'has-value?)
)

(define (get-value connector)
    (connector 'value)
)

(define (set-value! connector new-value informant)
    ((connector 'set-value!) new-value informant)
)

(define (forget-value! connector retractor)
    ((connector 'forget) retractor)
)

(define (connect connector new-constraint)
    ((connector 'connect) new-constraint)
)

(define (inform-about-value constraint)
    (constraint 'I-have-a-value)
)

(define (inform-about-no-value constraint)
    (constraint 'I-lost-my-value)
)

(define (make-connector)
    (let ((value false) (informant nil) (constraints '()))
        (define (set-my-value newval setter)
          (cond ((not (has-value? me))
                 (set! value newval)
                 (set! informant setter)
                 (for-each-except setter
                                  inform-about-value
                                  constraints))
                ((not (= value newval))
                 (error "Contradiction" (list value newval)))
                (else 'ignored)))
        (define (forget-my-value retractor)
          (if (eq? retractor informant)
              (begin (set! informant nil)
                     (for-each-except retractor
                                      inform-about-no-value
                                      constraints))
              'ignored))
        (define (connect new-constraint)
          (if (not (memq new-constraint constraints))
              (set! constraints
                    (cons new-constraint constraints)))
          (if (has-value? me)
              (inform-about-value new-constraint))
          'done)
        (define (me request)
          (cond (
                (eq? request 'has-value?)
                (if (valid? informant) true false))
                ((eq? request 'value) value)
                ((eq? request 'set-value!) set-my-value)
                ((eq? request 'forget) forget-my-value)
                ((eq? request 'connect) connect)
                (else (error "Unknown operation -- CONNECTOR"
                             request)
                )
            )
        )
    me)
)

(define (constant value connector)
    (define (me request)
        (error "Unknown request -- CONSTANT" request))
    (connect connector me)
    (set-value! connector value me)
    me
)

(define (multiplier m1 m2 product)
    (define (process-new-value)
        (cond 
            ((or (and (has-value? m1) (= (get-value m1) 0))
                (and (has-value? m2) (= (get-value m2) 0)))
                    (set-value! product 0 me)
            )
            ((and (has-value? m1) (has-value? m2))
                (set-value! product
                    (* (get-value m1) (get-value m2))
                me)
            )
            ((and (has-value? product) (has-value? m1))
                (set-value! m2
                    (/ (get-value product) (get-value m1))
                me)
            )
            ((and (has-value? product) (has-value? m2))
                (set-value! m1
                    (/ (get-value product) (get-value m2))
                me)
            )
        )
    )
    (define (process-forget-value)
        (forget-value! product me)
        (forget-value! m1 me)
        (forget-value! m2 me)
        (process-new-value)
    )
    (define (me request)
        (cond
            ((eq? request 'I-have-a-value)
                (process-new-value))
            ((eq? request 'I-lost-my-value)
                (process-forget-value))
            (else
                (error "Unknown request -- MULTIPLIER" request)
            )
        )
    )
    (connect m1 me)
    (connect m2 me)
    (connect product me)
    me
)
(define (adder m1 m2 sum)
    (define (process-new-value)
        (cond 
            ((or (and (has-value? m1) (= (get-value m1) 0))
                (and (has-value? m2) (= (get-value m2) 0)))
                    (set-value! sum 0 me)
            )
            ((and (has-value? m1) (has-value? m2))
                (set-value! sum
                    (+ (get-value m1) (get-value m2))
                me)
            )
            ((and (has-value? sum) (has-value? m1))
                (set-value! m2
                    (- (get-value sum) (get-value m1))
                me)
            )
            ((and (has-value? sum) (has-value? m2))
                (set-value! m1
                    (- (get-value sum) (get-value m2))
                me)
            )
        )
    )
    (define (process-forget-value)
        (forget-value! sum me)
        (forget-value! m1 me)
        (forget-value! m2 me)
        (process-new-value)
    )
    (define (me request)
        (cond
            ((eq? request 'I-have-a-value)
                (process-new-value))
            ((eq? request 'I-lost-my-value)
                (process-forget-value))
            (else
                (error "Unknown request -- MULTIPLIER" request)
            )
        )
    )
    (connect m1 me)
    (connect m2 me)
    (connect sum me)
    me
)
(define (cosine norm anti)
    (define (process-new-value)
        (if (has-value? norm)
            (set-value! anti (cos (get-value norm)) me)
            (if (has-value? anti)
                (set-value! norm (atan 1 (/ (get-value anti) (sqrt (- 1 (^ (get-value anti) 2))))) me)
            )
        )
    )
    (define (process-forget-value)
        (forget-value! norm me)
        (forget-value! anti me)
        (process-new-value)
    )
    (define (me request)
        (if (eq? request 'I-have-a-value)
            (process-new-value)
            (if (eq? request 'I-lost-my-value)
                (process-forget-value)
                (error "Unknown request -- MULTIPLIER" request)
            )
        )
    )
    (connect norm me)
    (connect anti me)
    me
)
(define (divider d1 d2 product)
    (define (process-new-value)
        (cond ((and (has-value? d1) (= (get-value d1) 0))
                (set-value! product 0 me))
            ((and (has-value? d2) (= (get-value d2) 0))
                (error "Divide by zero error -- DIVIDER" request))
            ((and (has-value? d1) (has-value? d2))
                (set-value! product
                            (/ (get-value d1) (get-value d2))
                            me))
            ((and (has-value? product) (has-value? d1))
                (set-value! d2
                            (* (get-value product) (get-value m1))
                me))
            ((and (has-value? product) (has-value? d2))
                (set-value! d1
                    (* (get-value product) (get-value d2))
                    me))))
    (define (process-forget-value)
        (forget-value! product me)
        (forget-value! d1 me)
        (forget-value! d2 me)
        (process-new-value))
    (define (me request)
        (cond
            ((eq? request 'I-have-a-value)
                (process-new-value))
            ((eq? request 'I-lost-my-value)
                (process-forget-value))
            (else
                (error "Unknown request -- DIVIDER" request))))
    (connect d1 me)
    (connect d2 me)
    (connect product me)
    me
)
(define (sq-sqrt d1 d2)
    (define (process-new-value)
        (if (has-value? d1)
            (set-value! d2 (* (get-value d1) (get-value d1) ) me)
            (if (has-value? d2)
                (set-value! d1 (sqrt (get-value d2)) me)
            )
        )
    )
    (define (process-forget-value)
        (forget-value! d1 me)
        (forget-value! d2 me)
        (process-new-value)
    )
    (define (me request)
        (cond
            ((eq? request 'I-have-a-value)
                (process-new-value))
            ((eq? request 'I-lost-my-value)
                (process-forget-value))
            (else
                (error "Unknown request -- RAISER" request)
            )
        )
    )
    (connect d1 me)
    (connect d2 me)
    me
)

(define (fftms-conv d1 d2)
 (define conv 6012.88475304223335719399)
 (define (process-new-value)
        (if (has-value? d1)
            (set-value! d2 (/ (get-value d1) conv ) me)
            (if (has-value? d2)
                (set-value! d1 (* (get-value d2) conv) me)
            )
        )
    )
    (define (process-forget-value)
        (forget-value! d1 me)
        (forget-value! d2 me)
        (process-new-value)
    )
    (define (me request)
        (cond
            ((eq? request 'I-have-a-value)
                (process-new-value))
            ((eq? request 'I-lost-my-value)
                (process-forget-value))
            (else
                (error "Unknown request -- RAISER" request)
            )
        )
    )
    (connect d1 me)
    (connect d2 me)
    me
)

(define (mtf-conv d1 d2)
    (define conv 3.28083989501312335958)
    (define (process-new-value)
        (if (has-value? d1)
            (set-value! d2 (/ (get-value d1) conv ) me)
            (if (has-value? d2)
                (set-value! d1 (* (get-value d2) conv) me)
            )
        )
    )
    (define (process-forget-value)
        (forget-value! d1 me)
        (forget-value! d2 me)
        (process-new-value)
    )
    (define (me request)
        (cond
            ((eq? request 'I-have-a-value)
                (process-new-value))
            ((eq? request 'I-lost-my-value)
                (process-forget-value))
            (else
                (error "Unknown request -- RAISER" request)
            )
        )
    )
    (connect d1 me)
    (connect d2 me)
    me
)

(define (speed velocity latitude height)
    (let (
        (a (make-connector))
        (b (make-connector))
        (c (make-connector))
        (d (make-connector))
        (e (make-connector))
        (f (make-connector))
        (g (make-connector))
        (h (make-connector))
        (i (make-connector))
        (j (make-connector))
    )
;converters->convert units meters to feet feet to meters based on way you are going
;constants->exact/given numerals in equation
;just use add and multipler to reduce code useage (rather than divider or subtractor)
; (b=a/c) can be rewritten a=b*c
        (multiplier latitude a b)
        (cosine b c)
        (multiplier c d e)
        (adder e g f)
        ;converter
        (mtf-conv height h)
        (multiplier h g i)
        (sq-sqrt j i)
        ;converter?
        (fftms-conv velocity j)
        ;more multipliers
        (constant (/ 3.14159265358979323846 90) a)
        (constant 19.612 f)
        (constant 0.052 d)
        'ok
    )
)

; (define (gravity lat)
;     (- 9.806 (* 0.5 (- 9.832 9.780) (cos (* 2 lat (/ pi 180)))))
; )

(define (main)
    (setPort (open (getElement ScamArgs 1) 'read))
    (define arg1 (readExpr))
    (define arg2 (readExpr))

    (define ve (make-connector))
    (define la (make-connector))
    (define he (make-connector))
    (speed ve la he)

    (set-value! ve arg1 'user)
    (set-value! la arg2 'user)

    (define height (get-value he))

    ; TEST BELOW
    ; (inspect (get-value height))
    ; (inspect (get-value velocity))
    ; (inspect (get-value latitude))

    ; (println (height 'value))
    (println "the drop height should be around " (fmt "%.12f" height) " feet")

    ; (inspect (get-value height))
    ; (inspect (get-value velocity))
    ; (inspect (get-value latitude))

    ; (forget-value! velocity 'user)
    ; (forget-value! latitude 'user)

    ; (inspect (get-value height))
    ; (inspect (get-value velocity))
    ; (inspect (get-value latitude))

    ; (set-value! height 0.115521290132 'user)
    ; (set-value! latitude arg2 'user)

    ; (inspect (get-value height))
    ; (inspect (get-value velocity))
    ; (inspect (get-value latitude))

    ;(println "the velocity should be around " (fmt "%.12f" (velocity 'value)) " meters/second")

    ; (inspect (get-value height))
    ; (inspect (get-value velocity))
    ; (inspect (get-value latitude))

    ; (forget-value! height 'user)
    ; (forget-value! latitude 'user)

    ; (inspect (get-value height))
    ; (inspect (get-value velocity))
    ; (inspect (get-value latitude))

    ; (set-value! velocity arg1 'user)
    ; (set-value! height 0.115521290132 'user)

    ; (inspect (get-value height))
    ; (inspect (get-value velocity))
    ; (inspect (get-value latitude))

    ;(println "the latitude should be around " (fmt "%.12f" (latitude 'value)) " degrees")
)