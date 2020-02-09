scanner.o
	gcc -Wall -o oproject4 oproject4.o scanner.o

scanner.o:	scanner.c scanner.h
	gcc -Wall -c scanner.c

text.o:	text.c scanner.h
	gcc -Wall -c oproject4.c

clean:	
	rm -f *.o oproject4
