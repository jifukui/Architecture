#include <stdio.h>
#include "bt.h"
int main()
{
    int data;
    sBinaryTree *bt;
    bt=StoreTreeInit();
    if(bt)
    {
        printf("初始华顺序二叉树成功\n");
        printf("输入数据\n");
        data=getchar();
        while (data!='#')
        {
            printf("输入数据是:%c\n",data);
            if(!StoreTree(bt,data))
            {
                break;
            }
            printf("输入数据\n");
            getchar();
            data=getchar();
        }
        //DisplayStoreTree(bt);
        TreeFrontErgodic(bt);
        StoreTreeDestory(bt);
    }
    else
    {
        printf("初始华顺序二叉树失败\n");
    }
    return 0;
}