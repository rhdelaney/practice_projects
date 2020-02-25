OBJS = scanner.o dll.o db.o main.o

OOPTS = -Wall -Wextra -g -c -std=c99
LOPTS = -Wall -Wextra -g -std=c99

all : final

final : $(OBJS)
	gcc $(LOPTS) -o final $(OBJS)

scanner.o : scanner.c scanner.h
	gcc $(OOPTS) scanner.c

dll.o : dll.c dll.h
	gcc $(OOPTS) dll.c

db.o : db.c db.h
	gcc $(OOPTS) db.c

main.o : main.c dll.h scanner.h db.h
	gcc $(OOPTS) -c main.c

test : final

clean   :
	rm -f *.o final