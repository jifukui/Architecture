#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
#include "stack.h"
#include "queue.h"
const int BTMask=MAX;
sBinaryTree* StoreTreeInit()
{
    sBinaryTree * bt=NULL;
    bt=(sBinaryTree*)malloc(sizeof(sBinaryTree));
    bt->length=0;
    if(bt)
    {
        bt->queue=NULL;
        bt->queue=QueueInit();
        if(bt->queue)
        {
            return bt;
        }
    }
    return NULL;
}
void StoreTreeDestory(sBinaryTree *bt)
{
    if(bt)
    {
        free(bt);
        bt=NULL;
    }
}
int StoreTree(sBinaryTree *bt,int value)
{
    if(bt)
    {
        sBinaryTreeNode *node=NULL;
        sBinaryTreeNode *pnode=NULL;
        node=(sBinaryTreeNode *)malloc(sizeof(sBinaryTreeNode));
        if(bt->length<BTMask&&node)
        { 
            node->data=value;
            node->flag=0;
            node->lchild=node->rchild=NULL;
			if(EnQueue(bt->queue,node))
            {
                if(!bt->length)
                {
                    bt->root=node;
                }
                else
                {
                    pnode=GetHeadQueue(bt->queue);
                    if(node->data!='@'&&pnode->data!='@')
                    {
                        if(bt->length%2)
                        {
                            pnode->lchild=node;
                        }
                        else
                        {
                            pnode->rchild=node;
                        }   
                    }
                    
                }
            }
			if ((bt->length % 2) == 0&&bt->length!=0)
			{
				DeQueue(bt->queue);
			}
			bt->length++;
			return BT_OK;
        }
    }
    printf("store Tree Error %c\n",value);
    return BT_ERR;
}
void TreeFrontErgodic(sBinaryTree *bt)
{
    if(bt)
    {
        sStack *fstack=NULL;
        fstack=StackInit();
        if(!fstack)
        {
            return NULL;
        }
        sBinaryTreeNode *node=NULL;
        int len=bt->length;
        node=bt->root;
        int index=0;
        int data;
        Push(fstack,node);
        while (!StackEmpty(fstack))
        {
            node=Pop(fstack);
            while (node&&node->data!='@')
            {
                data=node->data;
                printf("The %d is %c\n",index,data);
                index++;
                if(node->rchild)
                {
                    Push(fstack,node->rchild);
                }
                node=node->lchild;
            }
            
        }
        
    }
    return NULL;
}
void TreeMidErgodic(sBinaryTree *bt)
{
    if(bt)
    {
        sStack *fstack=NULL;
        fstack=StackInit();
        if(!fstack)
        {
            return NULL;
        }
        sBinaryTreeNode *node=NULL;
        int len=bt->length;
        node=bt->root;
        int index=0;
        int data;
        Push(fstack,node);
        while (!StackEmpty(fstack))
        {
            node=Pop(fstack);
            while (node&&node->data!='@')
            {
                Push(fstack,node);
                node=node->lchild;
            }
            if(!StackEmpty(fstack))
            {
                node=Pop(fstack);
                data=node->data;
                printf("The %d is %c\n",index,data);
                index++;
                Push(fstack,node->rchild);
            }
            
        }
        
    }
    return NULL;
}
void TreeEedErgodic(sBinaryTree *bt)
{
    if(bt)
    {
        sStack *fstack=NULL;
        fstack=StackInit();
        if(!fstack)
        {
            return NULL;
        }
        sBinaryTreeNode *node=NULL;
        int len=bt->length;
        node=bt->root;
        int index=0;
        int data;
        Push(fstack,node);
        while (!StackEmpty(bt))
        {
            node=Pop(fstack);
            while (node&&node->data!='@')
            { 
                Push(fstack,node);
                node=node->lchild;
            }
            node=Pop(fstack);
            if(node->flag)
            {

            }   
            else
            {
                node->flag=1;
                data=node->data;
                printf("The %d is %c\n",index,data);
                index++;
                Push(fstack,node);
            }         
            Push(fstack,node->rchild);
            node=node->rchild;
        }
        
    }
}
void DisplayStoreTree(sBinaryTree *bt)
{
    if(bt)
    {
        int i,index=0;
        i=bt->length;
        while (i--)
        {
            //printf("The %d is %c \n",index,bt->data[index]);
            index++;
        }
    }
}