#ifndef _STACK_H
#define _STACK_H
#include "TreeNode.h"
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
    sBinaryTreeNode* data;
    struct sStackNode *pre;
}sStackNode,psStackNode;
sStack * StackInit();
void StackDestory(sStack *stack);
void StackClear(sStack *stack);
int  StackLength(sStack *stack);
bool StackEmpty(sStack *stack);
bool StackFull(sStack *stack);
bool Push(sStack *stack,sBinaryTreeNode* value);
sBinaryTreeNode*  Pop(sStack *stack);
const sBinaryTreeNode*const  GetTop(sStack *stack);
void StackDisplay(sStack *stack);
#endif