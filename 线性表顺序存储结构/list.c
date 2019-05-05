#include <stdio.h>
#include "list.h"
int ListInit(plist list)
{
    if(list)
    {
        return LIST_ERR;
    }
    else
    {
        list=(plist)malloc(sizeof(List));
        list->last=-1;
        return LIST_OK;
    }
    
}
int ListDestroy(plist list)
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

void ListDisplay(plsit list)
{
    if(list)
    {
        int i;
        for(i=0;i<list.last;i++)
        {
            printf("The %d is %d\n",i,list.data[i]);
        }
    }
}