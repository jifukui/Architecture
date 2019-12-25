CC=gcc
CFLAG=
heap:heap.o main.o
	$(CC) $(CFLAG) heap.o main.o -o heap
main.o:main.c heap.h
	$(CC) $(CFLAG) -c main.c -o main.o
heap.o:heap.h heap.c
	$(CC) $(CFLAG) -c heap.c -o heap.o