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
    status=ListInsert(list,1,55);
    status=ListInsert(list,2,66);
    status=ListInsert(list,3,77);
    status=ListInsert(list,4,88);
    if(!status)
    {
        printf("插入数据成功\n");
    }
    else
    {
        printf("插入数据失败\n");
    }
    ListDisplay(list);
    status=LocateElem(list,77);
    printf("The 77 is at %d\n",status);
    status=LocateElem(list,100);
    printf("The 100 is at %d\n",status);
    status=GetElem(list,2);
    printf("链表的第3个数据为%d\n",status);
    status=GetElem(list,8);
    printf("链表的第9个数据为%d\n",status);
    status=ListDel(list,-1);
    printf("链表的第-1个数据为%d\n",status);
    status=ListDel(list,0);
    if(!status)
    {
        printf("删除数据成功\n");
    }
    else
    {
        printf("删除数据失败\n");
    }
    status=PreElem(list,88);
    printf("数据88的前一个数据是%d\n",status);
    status=PreElem(list,45);
    printf("数据45的前一个数据是%d\n",status);
    status=SuccElem(list,88);
    printf("数据88的后一个数据是%d\n",status);
    status=SuccElem(list,45);
    printf("数据45的后一个数据是%d\n",status);
    status=ListEmpty(list);
    printf("链表是否为空的状态%d\n",status);
    ListDisplay(list);
    status=ListLength(list);
    printf("线性表的长度为%d\n",status);
    ListClear(list);
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
