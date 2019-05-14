#include <stdio.h>
#include <stdlib.h>
#include "istack.h"
static const  int IStackMask=MAX;
isStack * IStackInit()
{
    isStack *stack=NULL;
    stack=(ipsStack)malloc(sizeof(isStack));
    if(stack)
    {
        printf("栈创建成功\n");
        stack->top=NULL;
        stack->len=0;
    }
    return stack;
}
void IStackDestory(isStack *stack)
{
    if(stack)
    {
        IStackClear(stack);
        free(stack);
        stack=NULL;
        printf("释放栈成功\n");
    }
}
void IStackClear(isStack *stack)
{
    if(stack)
    {
        int len;
        isStackNode *current,*pre;
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
int  IStackLength(isStack *stack)
{
    if(stack)
    {
        return stack->len;
    }
    return STACK_ERR;
}
bool IStackEmpty(sStack *istack)
{
    if(stack&&(!stack->len))
    {
        return TRUE;
    }
    return FALSE;
    
}
bool IStackFull(isStack *stack)
{
    if(stack&&(stack->len==StackMask))
    {
        return TRUE;
    }
    return FALSE;
}
bool IPush(isStack *stack,int value)
{
    if(stack&&stack->len<StackMask)
    {
        isStackNode *node=NULL;
        node =(isStackNode*)malloc(sizeof(isStackNode));
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
int  IPop(isStack *stack)
{
    if(stack&&stack->top>0)
    {
        int data;
        isStackNode *current;
        current=stack->top;
        stack->len--;
        data=current->data;
        stack->top=current->pre;
        free(current);
        return data;
    }
    return STACK_ERR;
}
int IGetTop(isStack *stack)
{
    if(stack&&stack->top>0)
    {
        return ((isStackNode *)(stack->top))->data;
    }
    return STACK_ERR;
}
void IStackDisplay(isStack *stack)
{
    if(stack&&stack->top>0)
    {
        isStackNode *node=stack->top;
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