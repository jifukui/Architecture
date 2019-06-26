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
        BlanceTreeMidDisplay(list);
        /* 
        node=BlanceTreeSearch(list,'C');
        if(node)
        {
            printf("have get value C\n");
        }
        else
        {
            printf("have not get value C\n");
        }
        node=BlanceTreeSearch(list,32);
        if(node)
        {
            printf("have get value Q\n");
        }
        else
        {
            printf("have not get value Q\n");
        }*/
        /* 
        BlanceTreeDelete(list,'C');
        BlanceTreeMidDisplay(list);
        BlanceTreeDelete(list,'Q');
        BlanceTreeMidDisplay(list);
        BlanceTreeDelete(list,"A");
        BlanceTreeMidDisplay(list);*/
    }
    return 0;
}