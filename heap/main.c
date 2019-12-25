#include <stdio.h>
#include "heap.h"
int main()
{
    heap * test;
    test=init();
    if(test)
    {
        printf("创建堆成功\n");
    }
    else
    {
        printf("初始化堆失败\n");
    }
    return 0;
    
}