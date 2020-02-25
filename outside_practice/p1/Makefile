OBJS = scanner.o sll.o dll.o stack.o queue.o integer.o comparator.o project1a.o readin.o real.o string.o people.o

OOPTS = -Wall -Wextra -g -c -std=c99
LOPTS = -Wall -Wextra -g -std=c99

all : project1

project1 : $(OBJS)
	gcc $(LOPTS) -o project1 $(OBJS) -lpthread

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

people.o : people.c people.h
	gcc $(OOPTS) people.c

string.o : string.c string.h
	gcc $(OOPTS) string.c

readin.o : readin.c readin.h
	gcc $(OOPTS) readin.c

project1a.o : project1a.c integer.h sll.h dll.h stack.h queue.h comparator.h scanner.h readin.h real.h string.h people.h
	gcc $(OOPTS) -c project1a.c

test : project1

clean   :
	rm -f *.o project1