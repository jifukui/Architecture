#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
static const  int StackMask=MAX;
sStack * StackInit()
{
    sStack *stack=NULL;
    stack=(psStack)malloc(sizeof(sStack));
    if(stack)
    {
        printf("栈创建成功\n");
        stack->top=NULL;
        stack->len=0;
    }
    return stack;
}
void StackDestory(sStack *stack)
{
    if(stack)
    {
        StackClear(stack);
        free(stack);
        stack=NULL;
        printf("释放栈成功\n");
    }
}
void StackClear(sStack *stack)
{
    if(stack)
    {
        int len;
        sStackNode *current,*pre;
        current=stack->top;
        len=stack->len;
        while ((len--)&&current)
        {
            pre=current->pre;
            free(current);
            current=pre;
        }
        stack->len=0;
    }
}
int  StackLength(sStack *stack)
{
    if(stack)
    {
        return stack->len+1;
    }
    return STACK_ERR;
}
bool StackEmpty(sStack *stack)
{
    if(stack&&(!stack->len))
    {
        return TRUE;
    }
    return FALSE;
    
}
bool StackFull(sStack *stack)
{
    if(stack&&(stack->len==StackMask))
    {
        return TRUE;
    }
    return FALSE;
}
bool Push(sStack *stack,int value)
{
    if(stack&&stack->len<StackMask)
    {
        sStackNode *node=NULL;
        node =(sStackNode*)malloc(sizeof(sStackNode));
        if(NULL==node)
        {
            return FALSE;
        }
        node->data=value;
        node->pre=stack->top;
        stack->top=node;
        stack->len++;
        return TRUE;
    }
    return FALSE;
}
int  Pop(sStack *stack)
{
    if(stack&&stack->top>0)
    {
        sStackNode *current;
        current=stack->top;
        stack->len--;
        return current->data;
    }
    return STACK_ERR;
}
int GetTop(sStack *stack)
{
    if(stack&&stack->top>=0)
    {
        return ((sStackNode *)(stack->top))->data;
    }
    return STACK_ERR;
}
void StackDisplay(sStack *stack)
{
    if(stack&&stack->top>0)
    {
        sStackNode *node=stack->top;
        int len=stack->len;
        int i=0;
        while (len--&&node)
        {
            printf("The %d is %d\n",i,node->data);
            node=node->pre;
            i++;
        }
        
    }
}