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
        return stack->len;
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
bool Push(sStack *stack,cluetreenodec * value)
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
cluetreenode *  Pop(sStack *stack)
{
    if(stack&&stack->top>0)
    {
        int data;
        sStackNode *current;
        current=stack->top;
        stack->len--;
        data=current->data;
        stack->top=current->pre;
        free(current);
        return data;
    }
    return STACK_ERR;
}
const cluetreenode * const GetTop(sStack *stack)
{
    if(stack&&stack->top>0)
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