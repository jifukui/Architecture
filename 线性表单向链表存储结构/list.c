#include <stdio.h>
#include "list.h"
static ListNode *Getindex(pList list,int index);
List * ListInit()
{
    List *list=NULL;
    printf("开始分配地址\n");
    if(NULL==(list=(ListNode *)malloc(sizeof(List))))
    {
        printf("分配地址空间失败\n");
        return LIST_ERR;
    }
    printf("分配的地址为%u\n",list);
    list->head=NULL;
    list->length=0;
    return list;
}
int ListDestroy(List * list)
{
    int status;
    status=ListClear(list);
    if(status)
    {
        printf("释放空间失败\n");
    }
    else
    {
        printf("释放空间成功\n");
        free(list);
    }
    return status;
}
int ListClear(List *list)
{
    if(list)
    {
        plistnode current,next;
        unsigned len;
        current=list->head;
        len=list->length;
        while(len--)
        {
            next=current->next;
            free(current);
            current=next;
        }
        list->head=NULL;
        list->length=0;
        return LIST_OK;
    }
    else
    {
        return LIST_ERR;
    }
    
}
int ListLength(pList list)
{
    if(list)
    {
        return list->length;
    }
    else
    {
        return LIST_ERR;
    }
    
}
int ListEmpty(pList list)
{
    if(list)
    {
        return list->length;
    }
    else
    {
        return LIST_ERR;
    }
    
}
int GetElem(pList list,int index)
{
    if(list)
    {
        if(index>list->length-1||index<0)
        {
            return LIST_ERR;
        }
        else
        {
            int i=0;
            plistnode node;
            node=Getindex(list,index);
            if(!node)
            {
                return LIST_ERR;
            }
            return node->data;
        }
    }
    return LIST_ERR;
}
int LocateElem(pList list,int data)
{
    if(list)
    {
        int i=0;
        plistnode node;
        for(i=0;i<list->length;i++)
        {
            if(!node)
            {
                return LIST_ERR;
            }
            if(node->data==data)
            {
                break;
            }
        }
        if(i==list->length)
        {
            return LIST_ERR;
        }
        else
        {
            return i;
        }
    }
    else
    {
        return LIST_ERR;
    }
    
}
int PreElem(pList list,int data)
{
    int index=LocateElem(list,data);
    if(index>0)
    {
        return GetElem(list,index-1);
    }
    else
    {
        return LIST_OK;
    }
    
}
int SuccElem(pList list,int data)
{
    int index=LocateElem(list,data);
    if((list->length-1)>index)
    {
        return GetElem(list,index+1);
    }
    else
    {
        return LIST_OK;
    }
}
int ListInsert(pList list,int index,int data)
{
    if(list)
    {
        if(list->length>=index&&index>=0)
        {
            ListNode *node=NULL;
            ListNode *current=NULL;
            if(NULL==(node=(plistnode)malloc(sizeof(ListNode))))
            {
                node->data=data;
                node->next=NULL;
                if(index==0)
                {
                    node->next=list->head;
                    list->head=node;
                }
                else
                {
                    current=Getindex(list,index-1);
                    if(!current&&(index!=list->length))
                    {
                        return LIST_ERR;
                    }
                    node->next=current->next;
                    current->next=node;
                }
                list->length++;
            }
            else
            {
                return LIST_ERR;
            }
            
        }
        else
        {
            return LIST_ERR;
        }    
    }
    else
    {
        return LIST_ERR;
    }
    
}

int ListDel(pList list,int index)
{
    if(0==list->length)
    {
        return LIST_ERR;
    }
    else
    {
        if(index>list->length||index<0)
        {
            return LIST_ERR;
        }
        else
        {
            ListNode *current=NULL;
            ListNode *before=NULL;
            before=Getindex(list,index-1);
            if(!before)
            {
                return LIST_ERR;
            }
            current=before->next;
            if(!current&&(index!=list->length))
            {
                return LIST_ERR;
            }
            before->next=current->next;
            free(current);
            list->length--;
            return LIST_OK;
        }
    }
}

void ListDisplay(pList list)
{
    if(list)
    {
        unsigned int len;
        ListNode *node;
        node=list->head;
        unsigned int i=0;
        while((len--)&&node)
        {
            printf("The %d is %d\n",i,node->data);
            i++;
        }
    }
   
}
ListNode *Getindex(pList list,int index)
{
    if(list&&list->length>index)
    {
        ListNode *node=NULL;
        int i;
        node=list->head;
        for(i=0;i<index&&node;i++)
        {
            node=node->next;
        }
        return node;
    }
    else
    {
        return NULL;
    }
    
}