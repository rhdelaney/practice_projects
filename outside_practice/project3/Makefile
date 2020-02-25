scanner.o
	gcc -Wall -o main main.o scanner.o

scanner.o:	scanner.c scanner.h
	gcc -Wall -c scanner.c

main.o:	main.c scanner.h
	gcc -Wall -c main.c

clean:	
	rm -f *.o main
