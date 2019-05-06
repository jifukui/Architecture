#include <stdio.h>
#include "list.h"
List * ListInit(List * list)
{
    if(list)
    {
        printf("这个地址已经存在\n");
    }
    else
    {
        printf("开始分配地址\n");
        if(NULL==(list=(List*)malloc(sizeof(List))))
        {
            printf("分配地址空间失败\n");
        }
        printf("List 数据结构的大小%d\n",sizeof(List));
        printf("分配的地址为%u\n",list);
        list->last=0;
        list->size=MAX;
    }
    return list;
}
List * ListDestroy(List * list)
{
    if(list)
    {
        free(list);
        list=NULL;
        
    }
    return list;
    
}
int ListClear(List *list)
{
    if(list)
    {
        list->last=0;
        return LIST_OK;
    }
    else
    {
        return LIST_ERR;
    }
    
}
int ListLength(plist list)
{
    if(list)
    {
        return list->last;
    }
    else
    {
        return LIST_ERR;
    }
    
}
int ListEmpty(plist list)
{
    if(list)
    {
        return list->last;
    }
    else
    {
        return LIST_ERR;
    }
    
}
int GetElem(plist list,int index)
{
    if(list)
    {
        if(index>list->last-1||index<0)
        {
            return LIST_ERR;
        }
        else
        {
            return list->data[index];
        }
    }
    return LIST_ERR;
}
int LocateElem(plist list,int data)
{
    if(list)
    {
        int i=0;
        for(i=0;i<list->last;i++)
        {
            if(list->data[i]==data)
            {
                break;
            }
        }
        if(i==list->last)
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
int PreElem(plist list,int data)
{
    int index=LocateElem(list,data);
    if(index>0)
    {
        return list->data[index-1];
    }
    else
    {
        return LIST_OK;
    }
    
}
int SuccElem(plist list,int data)
{
    int index=LocateElem(list,data);
    if((list->last-1)>index)
    {
        return list->data[index+1];
    }
    else
    {
        return LIST_OK;
    }
}
int ListInsert(plist list,int index,int data)
{
    if(list->size>index)
    {
        if(list->last>=index&&index>=0)
        {
            int i;
            for(i=list->last;i<index;i--)
            {
                list->data[i+1]=list->data[i];
            }
            list->data[i]=data;
            list->last++;
            return LIST_OK;
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
int ListDel(plist list,int index)
{
    if(0==list->last)
    {
        return LIST_ERR;
    }
    else
    {
        if(index>list->last||index<0)
        {
            return LIST_ERR;
        }
        else
        {
            int i=0;
            for(i=index;i<list->last-1;i++)
            {
                list->data[i]=list->data[i+1];
            }
            list->last--;
            return LIST_OK;
        }
    }
}

void ListDisplay(plist list)
{
    if(list)
    {
        int i;
        for(i=0;i<list->last;i++)
        {
            printf("The %d is %d\n",i,list->data[i]);
        }
    }
}
