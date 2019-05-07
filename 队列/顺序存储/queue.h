#ifndef _QUEUE_H
#define _QUEUE_H
#define MAX 4
#define QUEUE_OK 0
#define QUEUE_ERR -1
#define TRUE 1
#define FALSE 0
typedef struct queue
{
    int data[MAX];
    unsigned int head;
    unsigned int tail;
}squeue,*psqueue;
squeue *QueueInit();
void QueueDestory(squeue *queue);
void QueueClear(squeue *queue);
int QueueLength(squeue *queue);
int QueueEmpty(squeue *queue);
int QueueFull(squeue *queue);
int EnQueue(squeue *queue,int value);
int DeQueue(squeue *queue);
int GetHeadQueue(squeue *queue);
void QueueDisplay(squeue*queue);
#endif