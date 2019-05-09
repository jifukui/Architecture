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
            if('@'==value)
            {
                node=NULL;
            }
            else
            {
                node->data=value;
                node->lchild=node->rchild=NULL;
            }
            if(EnQueue(bt->queue,node))
            {
                if(!bt->length)
                {
                    bt->root=node;
                }
                else
                {
                    pnode=GetHeadQueue(bt->queue);
                    if(node&&pnode)
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
                    if((bt->length%2)==0)
                    {
                        DeQueue(bt->queue);
                    }
                }
                bt->length++;
                return BT_OK;   
            }
        }
    }
    return BT_ERR;
}
/**前序遍历树*/
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
            while (node)
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