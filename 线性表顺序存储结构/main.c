#include <stdio.h>
#include "list.h"
int main(void)
{
    List * list=NULL;
    int status=-1;
    status=ListInit(list);
    if(status)
    {
        printf("初始化失败\n");
    }
    else
    {
        printf("初始化成功\n");
        printf("list的内存地址为 %u\n",&list);
    }
    status=ListLength(list);
    printf("线性表的长度为%d\n",status);
    status=ListDestroy(list);
    if(status)
    {
        printf("释放失败\n");
        printf("失败状态值为%d\n",status);
    }
    else
    {
        printf("释放成功\n");
    }
    return 0;
}
