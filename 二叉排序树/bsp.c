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
            list->length++;
            return 0;
        }
        
    }   
    return -1;  
}
int BlanceTreeDelete(BlanceTreeList *list,char value)
{
    if(list)
    {
        /**Dnode为删除节点，temp为删除节点的父节点 */
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
            /**删除节点有左子树 */
           if(Dnode->Lchild)
            {
                /**删除节点左子树的最大值的父节点 */
                //BlanceTreeNode *temp1=NULL;
                /**删除节点左子树的最大值 */
                BlanceTreeNode *node=NULL;
                node=Dnode->Lchild;
                while (node->Rchild)
                {
                    //temp1=node;
                    node=node->Rchild;
                }
                /**删除节点是否为根节点 */
                if(temp)
                {
                    if(temp->data<Dnode->data)
                    {
                        temp->Rchild=Dnode->Rchild;
                    }
                    else
                    {
                        temp->Lchild=Dnode->Rchild;
                    }   
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
                /**删除的节点是否为根节点对于不是根节点的处理 */
                if(temp)
                {
                    if(temp->data<Dnode->data)
                    {
                        temp->Rchild=Dnode->Rchild;
                    }
                    else
                    {
                        temp->Lchild=Dnode->Rchild;
                    }
                    
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