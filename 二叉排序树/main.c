#include <stdio.h>
#include "bsp.h"
int main()
{
    BlanceTreeList* list=NULL;
    BlanceTreeNode *node=NULL;
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
        node=BlanceTreeSearch(list,12);
        if(node)
        {
            printf("have get value 12\n");
        }
        else
        {
            printf("have not get value 12\n");
        }
        node=BlanceTreeSearch(list,32);
        if(node)
        {
            printf("have get value 32\n");
        }
        else
        {
            printf("have not get value 32\n");
        }
        BlanceTreeDelete(list,12);
        BlanceTreeMidDisplay(list);
        BlanceTreeDelete(list,32);
        BlanceTreeMidDisplay(list);
    }
    return 0;
}