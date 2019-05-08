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
        data=getchar();
        while (data!='#')
        {
            if(!StoreTree(bt,data))
            {
                break;
            }
            data=getchar();
        }
        StoreTreeEnd(bt);
    }
    else
    {
        printf("初始华顺序二叉树失败\n");
    }
    
    
}