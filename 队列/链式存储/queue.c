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
        queue->head=queue->tail=NULL;
        queue->length=0;
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
    int len;
    sQueueNode *node=queue->head;
    sQueueNode *current;
    len=queue->length;
    while ((len--)&&node)
    {
        current=node->next;
        free(node);
        node=current;
    }
    queue->length=0;
}
int QueueLength(squeue *queue)
{
    if(queue)
    {
        return queue->length;
    }
    return QUEUE_ERR;
}
int QueueEmpty(squeue *queue)
{
    if(queue)
    {
        if(0==queue->length)
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
        if(MAX==queue->length)
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
        sQueueNode *node=NULL;
        sQueueNode *current=NULL;
        node=(sQueueNode*)malloc(sizeof(sQueueNode));
        if(node)
        {
            node->data=value;
            node->next=NULL;
            current=queue->tail;
            current->next=node;
            queue->tail=node
            //((sQueueNode *)(queue->tail))->next=node;
            queue->length++;
            return TRUE;
        }
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
            sQueueNode *node=NULL;
            node=queue->head;
            queue->head=node->next;
            free(node);
            queue->length--;
        }
        return value;
    }
    return FALSE;
}
int GetHeadQueue(squeue *queue)
{
    if(queue&&(!QueueEmpty(queue)))
    {
        return ((sQueueNode *)(queue->head))->data;
    }
    return FALSE;
}
void QueueDisplay(squeue*queue)
{
    if(queue)
    {
        int i=0;
        int index;
        index=queue->length;
        sQueueNode *node=NULL;
        while((index--)&&node)
        {
            printf("The %d is %d\n",i,node->data);
            node=node->next;
        }
    }
}