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
        printf("前序遍历树为：\n");
        TreeFrontErgodic(bt);
        printf("中续遍历树为:\n");
        TreeMidErgodic(bt);
        printf("后续遍历为:\n");
        TreeEedErgodic(bt);
        data=TreeDeep(bt);
        printf("二叉树的深度为%d\n",data);
        printf("线索二叉树中序\n");
        scluetree *root=NULL;
        root=StoreClueTreeMid(bt);
        if(root)
        {
            MidDisplayStoreTree(root);
        }
        StoreTreeDestory(bt);
    }
    else
    {
        printf("初始华顺序二叉树失败\n");
    }
    return 0;
}