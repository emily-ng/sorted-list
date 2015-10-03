CC = gcc
CFLAGS  = -Wall -ansi -pedantic -g
COMPILE = $(CC) $(CFLAGS)

all: libsl.a sl

libsl.a: sorted-list.o
	ar -rv libsl.a sorted-list.o

sl: main.o sorted-list.o
	$(COMPILE) -o sl main.o sorted-list.o

main.o: main.c sorted-list.c sorted-list.h
	$(COMPILE) -c main.c sorted-list.c

sorted-list.o: sorted-list.c sorted-list.h
	$(COMPILE) -c sorted-list.c

clean:
	rm -rf *.o sl main.o