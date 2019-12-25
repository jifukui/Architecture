#include <stdio.h>
#include "heap.h"
int main()
{
    heap * test;
    test=init();
    int value;
    int status;
    int index;
    if(test)
    {
        printf("创建堆成功\n");
        add(test,15);
        add(test,6);
        add(test,56);
        add(test,47);
        add(test,40);
        add(test,30);
        add(test,19);
        printf("当前堆的长度:%d\n",getlength(test));
        status=get(test,0,&value);
        if(status==ERR)
        {
            printf("获取数据错误\n");
        }
        else
        {
            printf("获取数据成功%d\n",value);
        }
        display(test);
        status=find(test,6,&index);
        if(status==ERR)
        {
            printf("未查找到此数据\n");
        }
        else
        {
            printf("查找到此数据位置在%d\n",index);
        }
        status=find(test,12,&index);
        if(status==ERR)
        {
            printf("未查找到此数据\n");
        }
        else
        {
            printf("查找到此数据位置在%d\n",index);
        }
        status=find(test,19,&index);
        if(status==ERR)
        {
            printf("未查找到此数据\n");
        }
        else
        {
            printf("查找到此数据位置在%d\n",index);
        }
        status=remove(test,1);
        if(status==ERR)
        {
            printf("删除数据失败\n");
        }
        else
        {
            printf("删除数据成功\n");
        }
        printf("当前堆的长度:%d\n",getlength(test));
        display(test);
        status=remove(test,6);
        if(status==ERR)
        {
            printf("删除数据失败\n");
        }
        else
        {
            printf("删除数据成功\n");
        }
        printf("当前堆的长度:%d\n",getlength(test));
        display(test);
        destory(test);
    }
    else
    {
        printf("初始化堆失败\n");
    }
    return 0;
    
}