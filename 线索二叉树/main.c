#include <stdio.h>
#include "ClueTree.h"
int main()
{
    cluetreelist *bl=NULL;
    cluetreelist=ClueTreeInit();
    if(cluetreelist)
    {
        printf("初始华顺序二叉树成功\n");
        printf("输入数据\n");
        data=getchar();
        while (data!='#')
        {
            printf("输入数据是:%c\n",data);
            if(!ClueTreeStror(bt,data))
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
    }
    return 0;
}