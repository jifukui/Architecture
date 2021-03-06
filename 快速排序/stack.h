#ifndef _STACK_H
#define _STACK_H
#define MAX 4
#define STACK_OK 0
#define STACK_ERR -1
#define TRUE 1
#define FALSE 0
typedef int bool;
typedef struct stack
{
    struct sStackNode *top;
    int len;
}sStack,*psStack;
typedef struct stacknode
{
    void *data;
    struct sStackNode *pre;
}sStackNode,psStackNode;
sStack * StackInit();
void StackDestory(sStack *stack);
void StackClear(sStack *stack);
int  StackLength(sStack *stack);
bool StackEmpty(sStack *stack);
bool StackFull(sStack *stack);
bool Push(sStack *stack,void * value);
void *  Pop(sStack *stack);
void * GetTop(sStack *stack);
void StackDisplay(sStack *stack);
#endif