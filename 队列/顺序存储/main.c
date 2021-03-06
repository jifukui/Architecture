#include <stdio.h>
#include "queue.h"
int main()
{
    squeue *queue=NULL;
    queue=QueueInit();
    int status=0;
    if(!queue)
    {
        printf("初始化队列失败\n");
        return 0;
    }
    printf("初始化队列成功\n");
    status=QueueEmpty(queue);
    if(status)
    {
        printf("队列为空\n");
    }   
    else
    {
        printf("队列不为空\n");
    }
    if(EnQueue(queue,11))
    {
        printf("插入队列成功\n");
    }
    else
    {
        printf("插入队列失败\n");
    }
    status=QueueEmpty(queue);
    if(status)
    {
        printf("队列为空\n");
    }   
    else
    {
        printf("队列不为空\n");
    }
    printf("队列头 %d\n",queue->head);
    printf("队列尾 %d\n",queue->tail);
    if(EnQueue(queue,22))
    {
        printf("插入队列成功\n");
    }
    else
    {
        printf("插入队列失败\n");
    }
    printf("获取队列头元素%d\n",GetHeadQueue(queue));
    printf("队列长度为%d\n",QueueLength(queue));
    if(EnQueue(queue,33))
    {
        printf("插入队列成功\n");
    }
    else
    {
        printf("插入队列失败\n");
    }
    if(QueueFull(queue))
    {
        printf("队列满\n");
    }
    else
    {
        printf("队列不为满\n");
    }
    printf("队列长度为%d\n",QueueLength(queue));
    QueueDisplay(queue);
    printf("De获取队列头元素%d\n",DeQueue(queue));
    if(EnQueue(queue,44))
    {
        printf("插入队列成功\n");
    }
    else
    {
        printf("插入队列失败\n");
    }
    if(QueueFull(queue))
    {
        printf("队列满\n");
    }
    else
    {
        printf("队列不为满\n");
    }
    printf("队列长度为%d\n",QueueLength(queue));
    QueueDisplay(queue);
    printf("De获取队列头元素%d\n",DeQueue(queue));
    printf("队列长度为%d\n",QueueLength(queue));
    QueueDisplay(queue);
    if(EnQueue(queue,55))
    {
        printf("插入队列成功\n");
    }
    else
    {
        printf("插入队列失败\n");
    }
    if(QueueFull(queue))
    {
        printf("队列满\n");
    }
    else
    {
        printf("队列不为满\n");
    }
    printf("队列头 %d\n",queue->head);
    printf("队列尾 %d\n",queue->tail);
    printf("队列长度为%d\n",QueueLength(queue));
    QueueDisplay(queue);
    QueueClear(queue);
    status=QueueEmpty(queue);
    if(status)
    {
        printf("队列为空\n");
    }   
    else
    {
        printf("队列不为空\n");
    }
    printf("队列长度为%d\n",QueueLength(queue));
    QueueDestory(queue);
    return 0;
}