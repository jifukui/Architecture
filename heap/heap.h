#ifndef _HEAP__H__
#define _HEAP__H__
#include <stdlib.h>
#define HEADSIZE 256
#define ERR 1
#define SUCCESS 0
struct typdef{
    int data[HEADSIZE];
    int current;
}heap;
heap *init();
int add(heap*,int data);
int get(heap*,int *data);
void destory(heap *);
void display(heap *);
int getlength(heap*);
#endif /**_HEAP__H__*/