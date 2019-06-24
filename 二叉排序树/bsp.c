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
                    printf("The %d is %d\n",i,(char)node->data);
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
int BlanceTreeInsert(BlanceTreeList *list,char value)
{
    if(list)
    {
        BlanceTreeNode *Dnode=NULL;
        BlanceTreeNode *temp=NULL;
        Dnode=list->value;
        int flag=0;
        while (Dnode)
        {
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
        BlanceTreeNode *node=NULL;
        node=(BlanceTreeNode *)malloc(sizeof(BlanceTreeNode));
        if(node)
        {
            node->Lchild=NULL;
            node->Rchild=NULL;
            node->data=value;
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
                }
                else
                {
                    temp->Lchild=node;
                }
                
            }
            
            return 0;
        }
        
    }   
    return -1;  
}
int BlanceTreeDelete(BlanceTreeList *list,char value)
{
    
}
BlanceTreeNode *BlanceTreeSearch(BlanceTreeList *list,char value)
{
    if(list)
    {
        BlanceTreeNode *Dnode;

    }
}