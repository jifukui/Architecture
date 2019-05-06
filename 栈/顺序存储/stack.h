#ifndef _STACK_H
#define _STACK_H
#define MAX 4
#define STACK_OK 0
#define STACK_ERR -1
#define TRUE 1
#define FALSE 0
typedef int bool;
const unsigned int Mask=MAX-1;
typedef struct stack
{
    int data[MAX];
    unsigned int top;
}sStack,*psStack;
sStack * StackInit();
void StackDestory(sStack *stack);
void StackClear(sStack *stack);
int  StackLength(sStack *stack);
bool StackEmpty(sStack *stack);
bool StackFull(sStack *stack);
bool Push(sStack *stack,int value);
int  Pop(sStack *stack);
int GetTop(sStack *stack);
void StackDisplay(sStack *stack);
#endif