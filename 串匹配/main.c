#include <stdio.h>
#include "kmp.h"
int main(int argc,char **argv)
{
    if(argc==3)
    {
        int pos=-1;
        printf("父字符串是:%s\n",argv[1]);
        printf("模式串是%s\n",argv[2]);
        if(strlen(argv[1])<strlen(argv[2]))
        {
            printf("错误的匹配串\n");
            return 0;
        }
        pos=GetPostion(argv[1],argv[2]);
        printf("postion is %d\n",pos);
    }
    return 0;
}