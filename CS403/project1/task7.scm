(define (main)
        (setPort (open (getElement ScamArgs 1) 'read))
        (println (apply zarp (readExpr)))
)
(define (zarp i)
  ; if i < 3 just return i
  (if (< i 3) i
    ; otherwise, for 3 or more, we need to zarp UP to i
    (begin
      ; first, define an iterator function
      (define (iter n prev1 prev2 prev3)
        ; if we've not yet found zarp(i)
        (if (<= n i)
          (iter                             ; find zarp(n+1), and:
            (+ 1 n)                         ; increment the counter
            (- (+ prev1 (* 2 prev2)) prev3) ; calculate zarp(n)
            prev1                           ; zarp(n-1) was previously known
            prev2                           ; zarp(n-2) was also known
            ; prev3                         ; zarp(n-3) no longer needed
            )
          ; otherwise, when we're past the number of zarps we need to count
          ; up to, (so i + 1), just return the last zarp we calucated
          prev1
          )
        )
      ; we know that for 3, zarp(i-1) = 2, zarp(i-2) = 1, and zarp(i-3) = 0
      ; so call iter starting at 3 with these as prev1, prev2, and prev3
      (iter 3 2 1 0)
      ) ; end else block
    ) ; end if statement; (define (zarp i)
)