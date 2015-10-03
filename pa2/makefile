CC = gcc
CFLAGS  = -Wall -ansi -pedantic -g
COMPILE = $(CC) $(CFLAGS)

all: libsl.a sl

libsl.a: main.o
	ar -rv libsl.a main.o

sl: main.c sorted-list.c sorted-list.h
	$(COMPILE) -o sl main.c sorted-list.c sorted-list.h 

clean:
	rm -rf *.o sl main.o