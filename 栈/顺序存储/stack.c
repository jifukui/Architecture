#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
sStack * StackInit()
{
    sStack *stack=NULL;
    stack=(psStack)malloc(sizeof(sStack));
    if(stack)
    {
        printf("栈创建成功\n");
        stack->top=-1;
    }
    return stack;
}
void StackDestory(sStack *stack)
{
    if(stack)
    {
        free(stack);
        stack=NULL;
        printf("释放栈成功\n");
    }
}
void StackClear(sStack *stack)
{
    if(stack)
    {
        stack->top=-1;
    }
}
int  StackLength(sStack *stack)
{
    if(stack)
    {
        return stack->top+1;
    }
    return STACK_ERR;
}
bool StackEmpty(sStack *stack)
{
    if(stack&&stack->top==-1)
    {
        return TRUE;
    }
    return FALSE;
    
}
bool StackFull(sStack *stack)
{
    if(stack&&stack->top==(MAX-1))
    {
        return TRUE;
    }
    return FALSE;
}
bool Push(sStack *stack,int value)
{
    if(stack)
    {
        stack->data[++stack->top]=value;
        return TRUE;
    }
    return FALSE;
}
int  Pop(sStack *stack)
{
    if(stack&&stack->top>=0)
    {
        return stack->data[stack->top--];
    }
    return STACK_ERR;
}
int GetTop(sStack *stack)
{
    if(stack&&stack->top>=0)
    {
        return stack->data[stack->top];
    }
    return STACK_ERR;
}
void StackDisplay(sStack *stack)
{
    if(stack&&stack->top>=0)
    {
        int i;
        for(i=0;i<=stack->top;i++)
        {
            printf("The %d is %d\n",i,stack->data[i]);
        }
    }
}