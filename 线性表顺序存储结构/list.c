#include <stdio.h>
#include "list.h"
int ListInit(List * list)
{
    if(list)
    {
        printf("这个地址已经存在\n");
        return LIST_ERR;
    }
    else
    {
        printf("开始分配地址\n");
        list=(List*)malloc(sizeof(List));
        printf("分配的地址为%u\n",list);
        list->last=-1;
        return LIST_OK;
    }
    
}
int ListDestroy(List * list)
{
    if(list)
    {
        free(list);
        list=NULL;
        return LIST_OK;
    }
    else
    {
        return LIST_ERR;
    }
    
}
int ListClear(List *list)
{
    if(list)
    {
        list->last=-1;
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
        if(index>list->last)
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
        if(i>list->last)
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

}
int SuccElem(plist list,int data)
{

}
int ListInsert(plist list,int index,int data)
{

}
int ListDel(plist list,int index)
{

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
