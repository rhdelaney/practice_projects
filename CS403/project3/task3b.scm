(define debug #f)

(define (Queue)
		(define front (list 'head))
		(define back nil)

		(define (this msg . args)
		    (cond
		        ((eq? msg 'enqueue) (apply enqueue args))
		        ((eq? msg 'dequeue) (apply dequeue args))
		        ((eq? msg 'empty?) (apply empty? args))
		        (else (error "queue message not understood: " msg))
		        )
		    )
		(define (enqueue x) ; add to the back
		    (set-cdr! back (list x))
		    (set! back (cdr back))
		    )
		(define (dequeue) ; remove from the front
		    ; user is responsible ensuring queue is non empty
		    (define tmp (cadr front))
		    (set-cdr! front (cddr front))
		    (if (null? (cdr front))
		        (set! back front)
		        )
		    tmp
		    )
		(define (empty?)
		    (eq? (cdr front) nil)
		    )

		(set! back front)
		this
		)


(define (bst comp)
	(define count 0)
	(define base (cons nil (list nil nil)))
	(define (size+) (set! count (+ count 1)))
	(define (size-) (set! count (- count 1)))
	(define queue (Queue))

	(define (leftChild node)
		(cadr node)
		)

	(define (rightChild node)
		(cadr (cdr node))
		)

	(define (size)
		count
		)

	(define (root)
		(car base)
		)

	(define (find val)
		(define (find-helper node)
			(cond
				((null? node)
					#f)
				((= val (caar node))
					(cadr (car node))
					)
				((comp val (caar node))
					(find-helper (leftChild node))
					)
				(else
					(find-helper (rightChild node))
					)
				)
			)
		(find-helper base)
		)

	(define (insert @)
		(for-each insert-helper @)
		)

	(define (insert-helper x)
		(if debug (newline))
		(if debug (println "Current tree: " base))
		(if debug (println "Attempting to insert " x "..."))

		(define (insertWalker node)
			(if debug (println "Node: " node))
			(cond
				((comp (car x) (caar node))
					(if debug (println x " was smaller than " (car node) ". Checking left child..."))
					(cond
						((null? (leftChild node))
							(if debug (println "left child was null. inserting."))
							(set-car! (cdr node) (cons x (list nil nil)))
							(size+)
							)
						(else
							(if debug (println "left child was not null. recurring..."))
							(insertWalker (leftChild node))
							)
						)
					)
				(else
					(if debug (println x " was bigger than " (car node) ". Checking right child..."))
					(cond
						((null? (rightChild node))
							(if debug (println "right child was null. inserting."))
							(set-car! (cddr node) (cons x (list nil nil)))
							(size+)
							)
						(else
							(if debug (println "right child was not null. recurring..."))
							(insertWalker (rightChild node))
							)
						)
					)
				)
			)

		(cond
			((null? (root))
				(if debug (println "root was null. inserting."))
				(set-car! base x)
				(size+)
				)
			(else
				(insertWalker base)
				)
			)
		)

	(define (predecessor node)
		(define (p-helper node)
			(cond
				((null? (rightChild node))
					node
					)
				(else
					(p-helper (rightChild node))
					)
				)
			)
		(p-helper (leftChild node))
		)

	(define (successor node)
		(define (p-helper node)
			(cond
				((null? (leftChild node))
					node
					)
				(else
					(p-helper (leftChild node))
					)
				)
			)
		(p-helper (rightChild node))
		)

	(define (delete val)
		(define (parent node)
			(define (tracer curr)
				(cond
					((or (eq? (leftChild curr) node) (eq? (rightChild curr) node))
						curr
						)
					(else
						(if (comp (car curr) (car node))
							(tracer (leftChild curr))
							(tracer (rightChild curr))
							)
						)
					)
				)
			(tracer base)
			)

		(define (delete-helper node)
			(if debug (inspect (car node)))
			(if debug (inspect val))
			(define (!comp)
				(if (eq? comp <)
					>
					<
					)
				)
			(cond
				((null? node) nil)
				((comp (car val) (caar node))
					(if debug (println val " is less than " (car node) ". recurring left."))
					(delete-helper (leftChild node))
					)
				(((!comp) (car val) (caar node))
					(if debug (println val " is more than " (car node) ". recurring right."))
					(delete-helper (rightChild node))
					)
				(else
					(if debug (println val " is " (car node) ". beginning delete."))
					(cond
						((and (null? (rightChild node)) (null? (leftChild node)))
							(if debug (println "Both children are null. Deleting..."))
							(if (eq? (rightChild (parent node)) node)
								(set-car! (cddr (parent node)) nil)
								(set-car! (cdr (parent node)) nil)
								)
							(size-)
							)
						((null? (rightChild node))
							(if debug (println "Right child is null.  Replacing node with " (leftChild node)))
							(set-car! node (car (leftChild node)))
							(set-cdr! node (cdr (leftChild node)))
							(size-)
							)
						((null? (leftChild node))
							(if debug (println "Left child is null.  Replacing node with "  (rightChild node)))
							(set-car! node (car (rightChild node)))
							(set-cdr! node (cdr (rightChild node)))
							(size-)
							)
						(else
							; Call the node to be deleted N.
							; Do not delete N.
							; Instead, choose either its in-order successor node or its in-order predecessor node, R.
							; Replace the value of N with the value of R, then delete R.
							(if debug (println "Complicated one. This probably fails..."))
							(define tmp (car (predecessor node)))
							(delete (car (predecessor node)))
							(set-car! node tmp)
							)
						)
					)
				)
			)
		(delete-helper base)
		)

	(define (walk)
		(define (preorder node)
			(cond
				((null? node) nil)
				(else
					(preorder (leftChild node))
					((queue 'enqueue) (car node))
					(preorder (rightChild node))
					)
				)
			)
		(preorder base)
		(cadr ((queue 'dequeue)))
		)

	(define (next)
		(cond
			(((queue 'empty?)) nil)
			(else (cadr ((queue 'dequeue))))
			)
		)

	(define (printTree)
		(println base)
		)

	this
)


(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	; (define tree (bst <))
	; (tree 'base)
	; (apply (tree 'insert) (readExpr))
	; (define (next-iter)
	;  	(define val ((tree 'next)))
	; 	(if (null? val)
	; 		nil
	; 		(begin
	; 			(println val)
	; 			(next-iter)
	; 			)
	; 		)
	; 	)
	; (println "First walk:")
	; (println ((tree 'walk)))
	; (next-iter)
	; (println "Second walk:")
	; (define root ((tree 'root)))
	; ((tree 'delete) root)
	; (println ((tree 'walk)))
	; (next-iter)
)
