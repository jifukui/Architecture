#ifndef _ISTACK_H
#define _ISTACK_H
#include "queue.h"
#define STACK_OK 0
#define STACK_ERR -1
#define TRUE 1
#define FALSE 0
typedef int bool;
typedef struct istack
{
    struct isStackNode *top;
    int len;
}isStack,*ipsStack;
typedef struct istacknode
{
    int data;
    struct isStackNode *pre;
}isStackNode,ipsStackNode;
isStack * IStackInit();
void IStackDestory(isStack *stack);
void IStackClear(isStack *stack);
int  IStackLength(isStack *stack);
bool IStackEmpty(isStack *stack);
bool IStackFull(isStack *stack);
bool IPush(isStack *stack,int value);
int  IPop(isStack *stack);
int IGetTop(isStack *stack);
void IStackDisplay(isStack *stack);
#endif