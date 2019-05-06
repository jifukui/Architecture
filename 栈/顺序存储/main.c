#include <stdio.h>
#include "stack.h"
int main()
{
    sStack *stack=NULL;
    int status=0;
    stack=StackInit();
    if(!stack)
    {
        printf("初始化栈失败\n");
    }
    StackDestory(stack);
    return 0;
}