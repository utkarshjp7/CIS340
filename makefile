
CC = gcc
CFLAGS = -std=gnu99 -Wall -g -I.
DEPS = minix.h
OBJ = main.c minix.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run:
	./main

.PHONY: clean
clean:
	rm -f *.o *~ main
