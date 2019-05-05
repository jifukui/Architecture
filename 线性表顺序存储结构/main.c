#include <stdio.h>
#include "list.h"
int main(void)
{
    List * list=NULL;
    int status=-1;
    list=ListInit(list);
    if(!list)
    {
        printf("初始化失败\n");
    }
    else
    {
        printf("初始化成功\n");
        printf("list的内存地址为 %u\n",list);
    }
    status=ListInsert(list,0,45);
    if(!status)
    {
        printf("插入数据成功\n");
    }
    else
    {
        printf("插入数据失败\n");
    }
    ListDisplay(list);
    status=ListInsert(list,0);
    if(!status)
    {
        printf("删除数据成功\n");
    }
    else
    {
        printf("删除数据失败\n");
    }
    ListDisplay(list);
    status=ListLength(list);
    printf("线性表的长度为%d\n",status);
    list=ListDestroy(list);
    if(list)
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
