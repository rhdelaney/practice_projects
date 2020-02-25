OBJS = scanner.o sll.o dll.o stack.o queue.o integer.o comparator.o sqsort.o readin.o real.o string.o
OBJS1 = scanner.o sll.o queue.o integer.o comparator.o real.o string.o bst.o vbst.o parser.o rbt.o bstrees.o
OOPTS = -Wall -Wextra -g -c -std=c99
LOPTS = -Wall -Wextra -g -std=c99

all : bstrees

bstrees : $(OBJS1)
	gcc $(LOPTS) -o bstrees $(OBJS1)

sqsort : $(OBJS)
	gcc $(LOPTS) -o sqsort $(OBJS)

scanner.o : scanner.c scanner.h
	gcc $(OOPTS) scanner.c

sll.o : sll.c sll.h
	gcc $(OOPTS) sll.c

dll.o : dll.c dll.h
	gcc $(OOPTS) dll.c

stack.o : stack.c stack.h
	gcc $(OOPTS) stack.c

comparator.o : comparator.c comparator.h
	gcc $(OOPTS) comparator.c

queue.o : queue.c queue.h
	gcc $(OOPTS) queue.c

integer.o : integer.c integer.h
	gcc $(OOPTS) integer.c

real.o : real.c real.h
	gcc $(OOPTS) real.c

string.o : string.c string.h
	gcc $(OOPTS) string.c

readin.o : readin.c readin.h
	gcc $(OOPTS) readin.c

bst.o : bst.c bst.h
	gcc $(OOPTS) bst.c

rbt.o : rbt.c rbt.h bst.h
	gcc $(OOPTS) rbt.c

vbst.o : vbst.c vbst.h bst.h
	gcc $(OOPTS) vbst.c

parser.o : parser.c parser.h string.h scanner.h
	gcc $(OOPTS) parser.c

sqsort.o : sqsort.c integer.h sll.h dll.h stack.h queue.h comparator.h scanner.h readin.h real.h string.h
	gcc $(OOPTS) sqsort.c

bstrees.o : bstrees.c integer.h sll.h queue.h comparator.h scanner.h real.h string.h bst.h vbst.h parser.h rbt.h
	gcc $(OOPTS) bstrees.c

test : bstrees
	
clean   :
	rm -f *.o bstrees