#include <stdio.h>
#include "bsp.h"
int main()
{
    BlanceTreeList* list=NULL;
    list=BlanceTreeInit();
    if(list)
    {
        int data;
        printf("输入数据\n");
        data=getchar();
        while (data!='!')
        {
            printf("输入数据是:%d\n",data);
            if(BlanceTreeInsert(list,data)<0)
            {
                break;
            }
            printf("输入数据\n");
            getchar();
            data=getchar();
        }
        BlanceTreeDisplay(list);
    }
}