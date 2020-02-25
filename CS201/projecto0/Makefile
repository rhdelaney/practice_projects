OBJSA = sll.o dll.o stack.o queue.o integer.o test-all.o
OBJS = integer.o sll.o test-sll.o
OBJS2 = integer.o dll.o test-dll.o
OBJS3 = integer.o dll.o stack.o test-stack.o
OBJS4 = integer.o sll.o queue.o test-queue.o

OOPTS = -Wall -Wextra -g -c -std=c99
LOPTS = -Wall -Wextra -g -std=c99

all : test-sll test-dll test-stack test-queue test-all

test-all : $(OBJSA)
	gcc $(LOPTS) -o test-all $(OBJSA)

test-sll : $(OBJS)
	gcc $(LOPTS) -o test-sll $(OBJS)

sll.o : sll.c sll.h
	gcc $(OOPTS) sll.c

test-sll.o : test-sll.c integer.h sll.h
	gcc $(OOPTS) test-sll.c

test-dll : $(OBJS2)
	gcc $(LOPTS) -o test-dll $(OBJS2)

dll.o : dll.c dll.h
	gcc $(OOPTS) dll.c

test-dll.o : test-dll.c integer.h dll.h
	gcc $(OOPTS) test-dll.c

test-stack : $(OBJS3)
	gcc $(LOPTS) -o test-stack $(OBJS3)

stack.o : stack.c stack.h
	gcc $(OOPTS) stack.c

test-stack.o : test-stack.c integer.h stack.h 
	gcc $(OOPTS) test-stack.c

test-queue : $(OBJS4)
	gcc $(LOPTS) -o test-queue $(OBJS4)

queue.o : queue.c queue.h
	gcc $(OOPTS) queue.c

test-queue.o : test-queue.c integer.h queue.h
	gcc $(OOPTS) test-queue.c

integer.o : integer.c integer.h
	gcc $(OOPTS) integer.c

test-all.o : test-all.c integer.h sll.h dll.h stack.h queue.h
	gcc $(OOPTS) -c test-all.c

test : test-all
	./test-all

clean   :
	rm -f *.o test-sll test-dll test-stack test-queue test-all