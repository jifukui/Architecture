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
        while (addr->data[temp]>addr->data[next]||next<0)
        {
            addr->data[temp]=addr->data[next];
            addr->date[next]=value;
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
int get(heap*,int *data)
{

}
void destory(heap *addr)
{
    if(addr)
    {
        free(addr)
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