main:	main.o scanner.o ppm.o
	gcc -Wall -g -o main main.o scanner.o ppm.o

scanner.o:	scanner.c scanner.h
	gcc -Wall -g -c scanner.c

main.o:	main.c scanner.h ppm.h
	gcc -Wall -g -c main.c

ppm.o:	ppm.c ppm.h
	gcc -Wall -g -c ppm.c

clean:	
	rm -f *.o ppm
