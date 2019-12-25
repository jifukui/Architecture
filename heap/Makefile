CC=gcc
CFLAG=
heap:heap.o main.o
	$(CC) -$(CFLAG) -o heap
main.o:main.c heap.h
	$(CC) -$(CFLAG) -o main.o
heap.o:heap.h heap.c
	$(CC) -$(CFLAG) -o heap.o