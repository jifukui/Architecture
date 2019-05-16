#include <stdio.h>
#include <stdlib.h>
#include "ClueTree.h"
#include "stack.h"
#include "istack.h"
#include "queue.h"
cluetreelist* ClueTreeInit()
{
    cluetreelist* nodelist=NULL;
    nodelist=(cluetreelist*)malloc(sizeof(cluetreelist));
    if(nodelist)
    {
        nodelist->length=0;
        nodelist->queue=NULL;
        nodelist->queue=QueueInit();
    }
    return nodelist;
}
int ClueTreeStror(cluetreelist *bl,int value)
{
    if(bl)
    {
        cluetreenode *node=NULL;
        cluetreenode *current=NULL;
        node=(cluetreenode *)malloc(sizeof(cluetreenode));
        if(node)
        {
            node->data=value;
            node->lchild=NULL;
            node->ltag=1;
            node->rchild=NULL;
            node->rtag=1;
            if(EnQueue(bl->queue,node))
            {
                if(bl->length==0)
                {
                    bl->top=node;
                }
                else
                {
                    current=GetHeadQueue(bl->queue);
                    if(node->data!='@'&&current->data!='@')
                    {
                        if(bl->length%2)
                        {
                            current->lchild=node;
                            current->ltag=0;
                        }
                        else
                        {
                            current->rchild=node;
                            current->rtag=0;
                        }   
                    }
                }
                if ((bl->length % 2) == 0&&bl->length!=0)
			    {
				    DeQueue(bl->queue);
			    }
			    bl->length++;
			    return CLUETREE_OK;    
            }
        }

    }
    return CLUETREE_ERR;
}
int Mid(cluetreelist *bl)
{

}
int Front(cluetreelist *bl)
{
    if(bl)
    {
        cluetreenode *node=bl->top;
        cluetreenode *pre=NULL;
        sStack *stack=NULL;
        stack=StackInit();
        if(stack)
        {
            if(node)
            {
                Push(stack,node);
                while (!StackEmpty(stack))
                {
                    node=Pop(stack);
                    while (node&&!node->ltag)
                    {
                        if(node->rtag==0)
                        {
                            Push(stack,node->rchild);
                        }
                        pre=node;
                        node=node->lchild;
                    }
                    pre=node;
                    node=Pop(stack);
                    pre->rchild=node;
                    Push(stack,node);
                }
            }
            return CLUETREE_OK;
        }
    }
    return CLUETREE_ERR;
}
int End(cluetreelist *bl)
{

}

void FrontDisPlay(cluetreelist *bl)
{
    cluetreenode *node=NULL;
    node=bl->top;
    int index=0;
    while (node)
    {
        printf("The %d is %d \n",index,node->data);
        if(node->ltag)
        {
            node=node->rchild;
        }
        else
        {
            node=node->lchild;
        }
    }
    
}