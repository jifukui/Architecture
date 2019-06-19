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
/**存储线索二叉树 */
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
/**前序存储 */
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
                    while (node&&node->data!='@')
                    {
                        if(node->rtag==0)
                        {
                            Push(stack,node->rchild);
                        }
						if (pre&&pre->rtag == 1)
						{
							pre->rchild = node;
						}
                        pre=node;
                        node=node->lchild;
                    }
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
/**前序显示 */
void FrontDisPlay(cluetreelist *bl)
{
    cluetreenode *node=NULL;
    node=bl->top;
    int index=0;
    while (node)
    {
        printf("The %d is %c \n",index,node->data);
        if(node->ltag)
        {
            node=node->rchild;
        }
        else
        {
            node=node->lchild;
        }
		index++;
    }
}
cluetreenode *FrontGetNode(cluetreelist *bl,int value)
{
    if(bl)
    {
        cluetreenode *node=NULL;
        node=bl->top;
        int index=0;
        while (node)
        {
            if(node->data==value)
            {
                return node;
            }
            if(node->ltag)
            {
                node=node->rchild;
            }
            else
            {
                node=node->lchild;
            }
		    index++;
        }
    }
}
void FrontInsert(cluetreenode *Bp,int value)
{
    if(Bp)
    {
        cluetreenode *node=NULL;
        node=(cluetreenode *)malloc(sizeof(cluetreenode));
        if(node)
        {
            node->data=value;
            node->rtag=Bp->rtag;
            if(Bp->rtag)
            {
                
                Bp->rtag=0;
               
            }
            node->rchild=Bp->rchild;
            ((cluetreenode *)Bp->rchild)->lchild=node;
            Bp->rchild=node;
            node->lchild=Bp;
        }
        else
        {
            printf("申请空间失败\r\n");
        }
    }
    else
    {
        printf("错误的数据\r\n");
    }
}
void FrontDel(cluetreelist *bl,int value)
{
    if(bl)
    {

    }
}