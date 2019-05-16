#ifndef _QUEUE_H
#define _QUEUE_H
#include "TreeNode.h"
#define QUEUE_OK 0
#define QUEUE_ERR -1
#define TRUE 1
#define FALSE 0
typedef struct queue
{
    struct sQueueNode* head;
    struct sQueueNode* tail;
    int length;
}squeue,*psqueue;
typedef struct queuenode
{
    cluetreenode *data;
    struct sQueueNode *next;  
}sQueueNode,*spQueueNode;
squeue *QueueInit();
void QueueDestory(squeue *queue);
void QueueClear(squeue *queue);
int QueueLength(squeue *queue);
int QueueEmpty(squeue *queue);
int QueueFull(squeue *queue);
int EnQueue(squeue *queue,cluetreenode *value);
cluetreenode *DeQueue(squeue *queue);
const cluetreenode *const GetHeadQueue(squeue *queue);
void QueueDisplay(squeue*queue);
#endif