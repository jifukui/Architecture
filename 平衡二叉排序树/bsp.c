#include "bsp.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
BlanceTreeList *BlanceTreeInit()
{
    BlanceTreeList *list=NULL;
    list=(BlanceTreeList *)malloc(sizeof(BlanceTreeList));
    if(list)
    {
        list->length=0;
        list->value=NULL;
    }
    return list;
}
void BlanceTreeDestory(BlanceTreeList *list)
{
    if(list)
    {

    }
}
void BlanceTreeDisplay(BlanceTreeList *list)
{
    if(list)
    {
        sStack *stack=StackInit();
        int i=0;
        if(stack)
        {
            BlanceTreeNode *node=NULL;
            node=list->value;
            Push(stack,node);
            while(!StackEmpty(stack))
            {
                node=Pop(stack);
                while (node)
                {
                    printf("The %d is %d\n",i,(int)node->data);
                    i++;
                    if(node->Rchild)
                    {
                        Push(stack,node->Rchild);
                    }
                    node=node->Lchild;
                }    
            }
        }
    }
}
void BlanceTreeMidDisplay(BlanceTreeList *list)
{
    if(list)
    {
        sStack *stack=StackInit();
        int i=0;
        if(stack)
        {
            BlanceTreeNode *node=NULL;
            node=list->value;
            Push(stack,node);
            while(!StackEmpty(stack))
            {
                node=Pop(stack);
                while (node)
                {
                    Push(stack,node);
                    node=node->Lchild;
                }
                if(!StackEmpty(stack))
                {
                    node=Pop(stack);
                    printf("%d is %d \n",i,(int)node->data);
                    i++;
                    Push(stack,node->Rchild);
                }
            }
        }
    }
}
int BlanceTreeInsert(BlanceTreeList *list,char value)
{
    if(list)
    {
        BlanceTreeNode *Dnode=NULL;
        BlanceTreeNode *temp=NULL;//待插入节点的父节点
        BlanceTreeNode *pa=NULL;//待插入节点的爷爷节点
        BlanceTreeNode *ppa=NULL;
        Dnode=list->value;
        int flag=0;
        while (Dnode)
        {
            if(pa)
            {
                ppa=pa;
            }
            if(temp)
            {
                pa=temp;
            }
            temp=Dnode;
            if(Dnode->data>value)
            {
                Dnode=Dnode->Lchild;
                flag=0;
            }
            else if(Dnode->data<value)
            {
                Dnode=Dnode->Rchild;
                flag=1;
            }
            else
            {
                return 1;
            }    
        }
        BlanceTreeNode *node=NULL;//插入的节点
        node=(BlanceTreeNode *)malloc(sizeof(BlanceTreeNode));
        if(node)
        {
            node->Lchild=NULL;
            node->Rchild=NULL;
            node->data=value;
            node->BF=0;
            if(list->length==0)
            {
                list->value=node;
            }
            else
            {
                /* code */
                if(flag)
                {
                    temp->Rchild=node;
                    temp->BF--;
                    if(pa)
                    {
						if (pa->data > temp->data)
						{
							pa->BF++;
						}
						else
						{
							pa->BF--;
						}
                    }
                }
                else
                {
                    temp->Lchild=node;
                    temp->BF++;
                    if(pa)
                    {
						if (pa->data > temp->data)
						{
							pa->BF++;
						}
						else
						{
							pa->BF--;
						}
                    }
                }
            }
            list->length++;
        }
        if(pa&&(pa->BF>=2||pa->BF<=-2))
        {
            if(pa->BF==2)
            {
                if(temp->BF==1)
                {
                    Dnode=BlanceTreeLL(pa);
                }
                else if(temp->BF==-1)
                {
                    Dnode=BlanceTreeRL(pa);   
                }    
            }
            else
            {
                if(temp->BF==1)
                {
                    Dnode=BlanceTreeLR(pa);
                }
                else if(temp->BF==-1)
                {
                    Dnode=BlanceTreeRR(pa);
                }
                
            }
			if (ppa)
			{
				if (ppa->data>temp->data)
				{
					ppa->Lchild = Dnode;
				}
				else
				{
					ppa->Rchild = Dnode;
				}
			}
			else
			{
				list->value = Dnode;
			}
        } 
		return 0;
    }   
    return -1;  
}
int BlanceTreeDelete(BlanceTreeList *list,char value)
{
    if(list)
    {
        BlanceTreeNode *Dnode=NULL;
        BlanceTreeNode *temp=NULL;
        Dnode=list->value;
        //temp=list->value;
        while (Dnode)
        {
            if(Dnode->data>value)
            {
                temp=Dnode;
                Dnode=Dnode->Lchild;
            }
            else if(Dnode->data<value)
            {
                temp=Dnode;
                Dnode=Dnode->Rchild;
            }
            else
            {
                break;
            }    
        }
        if(Dnode)
        {
            /**有左子树 */
           if(Dnode->Lchild)
            {
                BlanceTreeNode *temp1=NULL;
                BlanceTreeNode *node=NULL;
                node=Dnode->Lchild;
                while (node->Rchild)
                {
                    temp1=node;
                    node=node->Rchild;
                }
                if(temp)
                {
                    temp->Lchild=node;   
                }
                else
                {
                    list->value=node;
                } 
                node->Rchild=Dnode->Rchild;
                if(temp1)
                {
                    temp1->Rchild=NULL;
                }      
            }
            /**无左子树 */
            else
            {
                if(temp)
                {
                    temp->Lchild=Dnode->Rchild;
                }
                else
                {
                    list->value=Dnode->Rchild;
                }
                
            }
        }
        else
        {
            printf("have not find data %d\n",value);
        }
              
    }
    return 1;
}
BlanceTreeNode *BlanceTreeSearch(BlanceTreeList *list,char value)
{
    BlanceTreeNode *Dnode=NULL;
    if(list)
    {
        
        Dnode=list->value;
        while (Dnode)
        {
            if(Dnode->data>value)
            {
                Dnode=Dnode->Lchild;
            }
            else if(Dnode->data<value)
            {
                Dnode=Dnode->Rchild;
            }
            else
            {
                break;
            }    
        }
    }
    return Dnode;
}
BlanceTreeNode *BlanceTreeLL(BlanceTreeNode *node)
{
    BlanceTreeNode *no=NULL;
    no=node->Lchild;
    no->Rchild=node;
    node->Lchild=NULL;
    no->BF=0;
    node->BF=0;
    return no;
}
BlanceTreeNode *BlanceTreeRR(BlanceTreeNode *node)
{
    BlanceTreeNode *no=NULL;
    no=node->Rchild;
    no->Lchild=node;
    node->Rchild=NULL;
    no->BF=0;
    node->BF=0;
    return no;
}
BlanceTreeNode *BlanceTreeLR(BlanceTreeNode *node)
{
    BlanceTreeNode *no=NULL;
    node->BF=0;
    no=node->Rchild;
    no->Lchild->Lchild=node;
	node->Rchild = NULL;
	no->BF = 2;
	no->Lchild->BF = 1;
	node->BF = 0;
    node=BlanceTreeLL(no);
    return node;
}
BlanceTreeNode *BlanceTreeRL(BlanceTreeNode *node)
{
    BlanceTreeNode *no=NULL;
    node->BF=0;
    no=node->Lchild;
    no->Rchild->Rchild=node;
	node->Lchild = NULL;
	no->BF = -2;
	no->Rchild->BF = -1;
	node->BF = 0;
    node=BlanceTreeRR(no);
    return node;
}