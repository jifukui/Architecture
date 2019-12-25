#include "heap.h"
heap *init()
{
    heap *data=NULL;
    data=(heap *)malloc(sizeof(heap));
    if(data)
    {
        data->current=0;
    }
    return data;
}
int add(heap* addr,int data)
{    
    if(addr)
    {
        int temp=addr->current;
        int next=(temp%2)?(temp-1)/2:temp/2-1;
        int value=data;
        addr->data[addr->current++]=data;
        while (addr->data[temp]>addr->data[next]&&temp>0)
        {
            #ifdef DEBUG
            printf("The last is %d the new %d the temp %d the next %d\n",addr->data[temp],addr->data[next],temp,next);
            #endif
            addr->data[temp]=addr->data[next];
            addr->data[next]=value;
            temp=next;
            next=(temp%2)?(temp-1)/2:temp/2-1;
        }
        return SUCCESS;
    }
    else
    {
        return ERR;
    }
    
}
int find(heap *addr,int data,int *index)
{
    if(addr)
    {
        
    }
    else
    {
        return ERR;
    }
    
}
int get(heap* addr,int index,int *data)
{
    if(index>=0&&addr)
    {
        if(index<addr->current)
        {
            *data=addr->data[index];
            return SUCCESS;
        }

    }
    return ERR;
}
void destory(heap *addr)
{
    if(addr)
    {
        free(addr);
    }
}
void display(heap *addr)
{
    int i=0;
    for(i=0;i<addr->current;i++)
    {
        printf("The %d  is %d\n",i,addr->data[i]);
    }
}
int getlength(heap* addr)
{
    return addr->current;
}