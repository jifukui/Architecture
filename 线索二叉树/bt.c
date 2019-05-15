#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
#include "stack.h"
#include "istack.h"
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
        while (!StackEmpty(fstack))
        {
            node=Pop(fstack);
            while (node&&node->data!='@')
            { 
                if(!node->flag)
                {
                    Push(fstack,node);
                }
				else
				{
					break;
				}
                node=node->lchild;
            }
			if (!StackEmpty(fstack))
			{
				node = Pop(fstack);
				if (node->flag)
				{
					data = node->data;
					printf("The %d is %c\n", index, data);
					index++;	
				}
				else
				{
					node->flag = 1;
					Push(fstack, node);
				}	
				Push(fstack, node->rchild);
			}
        }
    }
}

int TreeDeep(sBinaryTree *bt)
{
    int maxdeep=0;
    if(bt)
    {
        int deep=1;
        isStack *dstack=NULL;
        sStack *fstack=NULL;
        fstack=StackInit();
        dstack=IStackInit();
        if(!fstack&&!dstack)
        {
            return maxdeep;
        }
        sBinaryTreeNode *node=NULL;
        int len=bt->length;
        node=bt->root;
        int index=0;
        int data;
        Push(fstack,node);
        IPush(dstack,deep);
        while (!StackEmpty(fstack))
        {
            node=Pop(fstack);
            deep=IPop(dstack);
            while (node&&node->data!='@')
            {
                Push(fstack,node);
                IPush(dstack,deep);
                deep++;
                node=node->lchild;
            }
            if(!StackEmpty(fstack))
            {
                node=Pop(fstack);
                deep=IPop(dstack);
                printf("当前的深度为%d\n",deep);
                printf("当前的最大深度为%d\n",maxdeep);
                if(deep>maxdeep)
                {
                    maxdeep=deep;
                }
                data=node->data;
                printf("The %d is %c\n",index,data);
                index++;
                Push(fstack,node->rchild);
                deep++;
                IPush(dstack,deep);
            }
            
        }
        
    }
    return maxdeep;
}

/**线索二叉树中序存储*/
scluetree *ClueTreeInit()
{
    scluetree *root=NULL;
    root=(scluetree *)malloc(sizeof(scluetree));
    return root;
}
scluetree * StoreClueTreeMid(sBinaryTree *bt)
{
    scluetree *root=NULL;
    root=ClueTreeInit();
    scluetreenode *cnode=NULL;
    scluetreenode *pcnode=NULL;
    int index=0;
    if(root&&bt)
    {
        sBinaryTreeNode *node=NULL;
        sStack *stack=NULL;
        stack=StackInit();
        node=bt->root;
        Push(stack,node);
        while (!StackEmpty(stack))
        {
            node=Pop(stack);
            while (node&&node->data!='@')
            {
                Push(stack,node);
                node=node->lchild;
            }
            if(!StackEmpty(stack))
            {
                node=Pop(stack);
                printf("The data  is %c\n",node->data);
                cnode=(scluetreenode *)malloc(sizeof(scluetreenode));
                cnode->data=node->data;
                cnode->lchild=NULL;
                cnode->ltag=0;
                cnode->rchild=NULL;
                cnode->rtag=0;
                if(!node->lchild||((sBinaryTreeNode *)(node->lchild))->data=='@')
                {
                    cnode->ltag=1;
                    cnode->lchild=pcnode;
                }
                if(!node->rchild||((sBinaryTreeNode *)(node->rchild))->data=='@')
                {
                    cnode->rtag=1;
                }
                if(pcnode&&pcnode->rtag==1)
                {
                    pcnode->rchild=cnode;
                }
                if(index==0)
                {
                    root->top=node;
                }
                pcnode=cnode;
                Push(stack,node->rchild);
                index++;
            }
        }
        return root;
    }
    else
    {
        printf("中序存储线索二叉树失败\n");
        return NULL;
    }
    
}

void DisplayStoreTree(scluetree *root)
{
    scluetreenode *cnode=NULL;
    cnode=root->top;
    if(cnode)
    {
        int i=0;
        while (cnode)
        {
            printf("The %d is %c\n",i,cnode->data);
            cnode->rchild;
            i++;
        }
    }
}