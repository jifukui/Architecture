#include <stdio.h>
#include "kmp.h"
void Getmode(char *str,unsigned int *mode);
void GetSupermode(char *str,unsigned int *mode);
int GetPostion(char *str1,char *str2)
{
    unsigned int mode[256];
    unsigned int super[256];
    int i=0;
    int j=0;
    if(str1&&str2)
    {
        Getmode(str1,mode);
        GetSupermode(str1,super);
        printf("普通模式数组为:\n");
        for(i=0;i<strlen(str2);i++)
        {
            printf("The %d is %d\n",i,mode[i]);
        }
        printf("超级模式数组为:\n");
        for(i=0;i<strlen(str2);i++)
        {
            printf("The %d is %d\n",i,super[i]);
        }
        i=0;
        j=0;
        while (i<strlen(str1)||i<strlen(str2))
        {
            if(str1[i]!=str2[j])
            {
                j=mode[i];
            }
            else
            {
                j++;
            }
            i++;
        }
        if(j==strlen)
        {
            return i-j;
        }
        
    }
    return -1;
}
void Getmode(char *str,unsigned int *mode)
{
    int i=0;
    int j=-1;
    mode[i]=-1;
    int index=0;
    int len;
    len=strlen(&str[0]);
    while (i<len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++;
            j++;
            mode[i]=j;
            
        }
        else
        {
            j=mode[j];
        }
        index++;
    }
    printf("普通算法使用的计算次数为%d\n",index);
}
void GetSupermode(char *str,unsigned int *mode)
{
    int i=0;
    int j=-1;
    mode[i]=-1;
    int index=0;
    while (i<strlen(str))
    {
        if(j==-1||str[i]==str[j])
        {
            i++;
            j++;
            if(mode[i]!=mode[j])
            {
                mode[i]=j;
            }
            else
            {
                mode[i]=mode[j];
            }         
        }
        else
        {
            j=mode[j];
        }
        index++;
    }
    printf("超级算法使用的计算次数为%d\n",index);
}