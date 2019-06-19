#include <stdio.h>
#include "ClueTree.h"
int main()
{
    cluetreelist *bl=NULL;
    cluetreenode *node;
    bl=ClueTreeInit();
    int data;
    if(bl)
    {
        printf("初始华顺序二叉树成功\n");
        printf("输入数据\n");
        data=getchar();
        while (data!='#')
        {
            printf("输入数据是:%c\n",data);
            if(ClueTreeStror(bl,data))
            {
                break;
            }
            printf("输入数据\n");
            getchar();
            data=getchar();
        }
        printf("前序线索二叉树\n");
        Front(bl);
        FrontDisPlay(bl);
        node=FrontGetNode(bl,'C');
        FrontInsert(node,'J');
        FrontDisPlay(bl);
    }
    return 0;
}