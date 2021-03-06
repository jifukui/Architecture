#ifndef _QUEUE_H
#define _QUEUE_H
#define MAX 16
#define QUEUE_OK 0
#define QUEUE_ERR -1
#define TRUE 1
#define FALSE 0
typedef struct BinaryTreeNode
{
    int data;
    struct sBinaryTreeNode *lchild;
    struct sBinaryTreeNode *rchild;
}sBinaryTreeNode,*spBinaryTreeNode;
typedef struct queue
{
    struct sQueueNode* head;
    struct sQueueNode* tail;
    int length;
}squeue,*psqueue;
typedef struct queuenode
{
    sBinaryTreeNode *data;
    struct sQueueNode *next;  
}sQueueNode,*spQueueNode;
squeue *QueueInit();
void QueueDestory(squeue *queue);
void QueueClear(squeue *queue);
int QueueLength(squeue *queue);
int QueueEmpty(squeue *queue);
int QueueFull(squeue *queue);
int EnQueue(squeue *queue,sBinaryTreeNode *value);
sBinaryTreeNode *DeQueue(squeue *queue);
const sBinaryTreeNode *const GetHeadQueue(squeue *queue);
void QueueDisplay(squeue*queue);
#endif