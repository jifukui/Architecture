CC=gcc
CFLAG=
heap:heap.o main.o stack.o
	$(CC) $(CFLAG) heap.o main.o -o heap
main.o:main.c heap.h
	$(CC) $(CFLAG) -c main.c -o main.o
heap.o:heap.h heap.c
	$(CC) $(CFLAG) -c heap.c -o heap.o
stack.o:stack.c stack.h
	$(CC) $(CFLAG) -c stack.c -o stack.o