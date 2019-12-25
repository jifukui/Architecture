#include <stdio.h>
#include "heap.h"
int main()
{
    heap * test;
    test=init();
    if(test)
    {
        printf("创建堆成功\n");
        add(test,15);
        add(test,6);
        add(test,56);
        display(test);
        destory(test);

    }
    else
    {
        printf("初始化堆失败\n");
    }
    return 0;
    
}