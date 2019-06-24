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
        scanf("%d",&data);
        while (data!=0)
        {
            printf("输入数据是:%d\n",data);
            if(BlanceTreeInsert(list,data)<0)
            {
                break;
            }
            printf("输入数据\n");
            scanf("%d",&data);
        }
        BlanceTreeDisplay(list);
        BlanceTreeMidDisplay(list);
    }
}