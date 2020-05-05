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
/**节点的插入算法
 * node1为主要操作的节点
 * node2为当前主要操作的节点的父节点
 * node3为第一个平衡系数不为0的节点
 * node4位当前不平衡的节点的父节点
 * **/
int BlanceTreeInsert(BlanceTreeList *list,int value)
{
	if (list)
	{
		BlanceTreeNode *node1=NULL, *node2=NULL, *node3=NULL, *node4=NULL, *node = NULL;
		/**分配节点空间*/
		node = (BlanceTreeNode *)malloc(sizeof(BlanceTreeNode));
		if (node)
		{
			node->data = value;
			node->BF = 0;
			node->Lchild = NULL;
			node->Rchild = NULL;
			node1 = node3 = list->value;
			/*对于是空的处理 */
			if (!node1)
			{
				list->value = node;
				return 1;
			}
			/**遍历找到插入节点*/
			while (node1)
			{
				/**对于这个值存在的处理*/
				if (node1->data == value)
				{
					return 0;
				}
				/**对于node1的平衡系数不会0的处理*/
				if (node1->BF != 0)
				{
					node3 = node1;
					node4 = node2;
				}
				/***/
				node2 = node1;
				/**判断是放在左子树上还是放在右子树上*/
				if (node1->data > value)
				{
					node1 = node1->Lchild;
				}
				else
				{
					node1 = node1->Rchild;
				}
			}
			/**设置插入位置*/
			if (value<node2->data)
			{
				node2->Lchild = node;
			}
			else
			{
				node2->Rchild = node;
			}
			/**修改node1为第一个平衡系数不为1的节点的对应位置的子节点
			 * 并且修改此节点的平衡系数
			*/
			if (node->data < node3->data)
			{
				node1 = node3->Lchild;
				node2 = node1;
				node3->BF += 1;
			}
			else
			{
				node1 = node3->Rchild;
				node2 = node1;
				node3->BF -= 1;
			}
			/**修改从不平衡的节点到插入节点的平衡系数*/
			while (node1!=node)
			{
				if (node->data < node1->data)
				{
					node1->BF = 1;
					node1 = node1->Lchild;
				}
				else
				{
					node1->BF = -1;
					node1 = node1->Rchild;
				}
			}
			/**根据第一个不平衡的节点的平衡系数极性调整*/
			switch (node3->BF)
			{
			case 2:
				switch (node2->BF)
				{
				case 1:
					node1 = BlanceTreeLL(node3);
					break;
				case -1:
					node1 = BlanceTreeLR(node3);
					break;
				}
				if (!node4)
				{
					list->value = node1;
				}
				else
				{
					if (node4->Lchild == node3)
					{
						node4->Lchild = node1;
					}
					else
					{
						node4->Rchild = node1;
					}
				}
				break;
			case -2:
				switch (node2->BF)
				{
				case -1:
					node1 = BlanceTreeRR(node3);
					break;
				case 1:
					node1 = BlanceTreeRL(node3);
					break;
				}
				if (!node4)
				{
					list->value = node1;
				}
				else
				{
					if (node4->Lchild == node3)
					{
						node4->Lchild = node1;
					}
					else
					{
						node4->Rchild = node1;
					}
				}
				break;
			}
			return 1;
		}
	}
	return -1;
        
}
int BlanceTreeDelete(BlanceTreeList *list,int value)
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
BlanceTreeNode *BlanceTreeSearch(BlanceTreeList *list,int value)
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
/***
 * 只是顺时针旋转
 * node为不平衡的节点
 *     				node(36)
 *                  .
 *                .
 * 				no(23)
 *              .
 *            .
*/
BlanceTreeNode *BlanceTreeLL(BlanceTreeNode *node)
{
    BlanceTreeNode *no=NULL;
    no=node->Lchild;
    node->Lchild=no->Rchild;
	no->Rchild = node;
	no->BF = 0;
	node->BF = 0;
    return no;
}
/**
 * 只是逆时针的旋转
 * node 为不平衡的节点
 *      node(13)
 * 				.
 * 				  .
 * 				  no(23)
 * 					 .
 *    				   .
 * 						36
*/
BlanceTreeNode *BlanceTreeRR(BlanceTreeNode *node)
{
    BlanceTreeNode *no=NULL;
    no=node->Rchild;
    node->Rchild=no->Lchild;
	no->Lchild = node;
    no->BF=0;
    node->BF=0;
    return no;
}
/**
 * 先顺时针后逆时针旋转
*/
BlanceTreeNode *BlanceTreeLR(BlanceTreeNode *node)
{
	BlanceTreeNode *nod1, *nod2;
	nod1 = node->Lchild;
	nod2 = nod1->Rchild;
	node->Rchild = nod2->Lchild;
	nod1->Lchild = nod2->Rchild;
	nod2->Rchild = node;
	nod2->Lchild = nod1;
	switch (nod2->BF)
	{
	case 1:
	{
		node->BF = 0;
		nod1->BF = -1;
		break;
	}
	case -1:
	{
		node->BF = -1;
		nod1->BF = 0;
		break;
	}
	case 0:
	{
		node->BF = 0;
		nod1->BF = 0;
		break;
	}
	}
	nod2->BF = 0;
	return nod2;
}
/***
 * 
*/
BlanceTreeNode *BlanceTreeRL(BlanceTreeNode *node)
{
    BlanceTreeNode *nod1,*nod2;
	nod1 = node->Rchild;
	nod2 = nod1->Lchild;
	node->Rchild = nod2->Lchild;
	nod1->Lchild = nod2->Rchild;
	nod2->Lchild = node;
	nod2->Rchild = nod1;
	switch (nod2->BF)
	{
	case 1:
		node->BF = 0;
		nod1->BF = -1;
		break;
	case -1:
		node->BF = -1;
		nod1->BF = 0;
		break;
	case 0:
		node->BF = 0;
		nod1->BF = 0;
		break;
	}
	nod2->BF = 0;
    return nod2;
}