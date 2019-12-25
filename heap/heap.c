#include "heap.h"
#include "stack.h"
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
        int value;
        int status;
        int pos=0;
        sStack *stack=NULL;
        stack=StackInit();
        Push(stack,pos);
        do{
            pos=Pop(stack);
            status=get(addr,pos,&value);
            if(status)
            {
                #ifdef DEBUG
                    printf("the pos is %d\n",pos);
                #endif
                //return ERR;
            }
            else
            {
                if(value==data)
                {
                    *index=pos;
                    return SUCCESS;
                }
                else if(value>data)
                {
                    if(pos*2<addr->current)
                    {
                        Push(stack,pos*2+2);
                        Push(stack,pos*2+1);
                    }
                }
            }
        }while(!StackEmpty(stack));
    }
    #ifdef DEBUG
        printf("No find\n");
    #endif
    return ERR;
    
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
int JIremove(heap *addr,int index)
{
    if(addr&&index>=0&&index<addr->current)
    { 
        int last=addr->current;
        addr->current-=1;
        int next=index;
        addr->data[index]=addr->data[addr->current];
        int value=addr->data[index];
        next=next*2+1;
        int temp;
        while (next<last)
        {    
            #ifdef DEBUG
            printf("the next is %d\n",next);
            #endif
            if(value<addr->data[next]||value<addr->data[++next])
            {
                addr->data[index]=addr->data[next];
                addr->data[next]=value;
            }
            index=next;
            next=next*2+1;
        }
        return SUCCESS;
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