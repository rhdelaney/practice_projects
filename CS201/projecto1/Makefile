OBJS = scanner.o sll.o dll.o stack.o queue.o integer.o comparator.o sqsort.o readin.o real.o string.o

OOPTS = -Wall -Wextra -g -c -std=c99
LOPTS = -Wall -Wextra -g -std=c99

all : sqsort

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

sqsort.o : sqsort.c integer.h sll.h dll.h stack.h queue.h comparator.h scanner.h readin.h real.h string.h
	gcc $(OOPTS) -c sqsort.c

test : sqsort

clean   :
	rm -f *.o sqsort