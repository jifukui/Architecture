#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
static const unsigned int QueueMask=MAX-1;
squeue *QueueInit()
{
    squeue *queue=NULL;
    queue=(squeue *)malloc(sizeof(squeue));
    if(queue)
    {
        queue->head=queue->tail=0;
    }
    return queue;
}
void QueueDestory(squeue *queue)
{
    if(queue)
    {
        free(queue);
        queue=NULL;
    }
}
void QueueClear(squeue *queue)
{
    queue->head=queue->tail=0;
}
int QueueLength(squeue *queue)
{
    if(queue)
    {
        return (QueueMask+queue->tail-queue->head+1)&QueueMask;
    }
    return QUEUE_ERR;
}
int QueueEmpty(squeue *queue)
{
    if(queue)
    {
        if(queue->tail==queue->head)
        {
            return TRUE;
        }
    }
    return FALSE;
}
int QueueFull(squeue *queue)
{
    if(queue)
    {
        if(((queue->tail+1)&QueueMask)==queue->head)
        {
            return TRUE;
        }
    }
    return FALSE;
}
int EnQueue(squeue *queue,int value)
{
    if(queue&&!QueueFull(queue))
    {
        queue->data[queue->tail++]=value;
        queue->tail&=QueueMask;
        return TRUE;
    }
    return FALSE;
}
int DeQueue(squeue *queue)
{
    if(queue)
    {
        int value;
        value=GetHeadQueue(queue);
        if(value)
        {
            queue->head=(queue->head+1)&QueueMask;
        }
        return value;
    }
    return FALSE;
}
int GetHeadQueue(squeue *queue)
{
    if(queue&&(!QueueEmpty(queue)))
    {
        return queue->data[queue->head];
    }
    return FALSE;
}
void QueueDisplay(squeue*queue)
{
    if(queue)
    {
        int i=0;
        int index;
        index=queue->head;
        while((queue->tail<index))
        {
            printf("The %d is %d\n",i,queue->data[index++]);
            index=index&QueueMask;
            i++;
        }
    }
}