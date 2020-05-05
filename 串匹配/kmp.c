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
        //生成模式数组
        Getmode(str2,mode);
        printf("普通模式数组为:\n");
        for(i=0;i<strlen(str2);i++)
        {
            printf("The %d is %d\n",i,mode[i]);
        }
        i=0;
        j=0;
        while (i<strlen(str1)&&j<strlen(str2))
        {
            //对于没有匹配上调用设置模式数组的位置
            if(j==-1||str1[i]==str2[j])
            {
                i++;
                j++;
            }
            else
            {
                j=mode[j];
            }
            
        }
        printf("The j is %d\n",j);
        printf("The i is %d\n",i);
        if(j==strlen(str2))
        {
            return i-j;
        }    
    }
    return -1;
}
int GetSuperPostion(char *str1,char *str2)
{
    unsigned int mode[256];
    int i=0;
    int j=0;
    if(str1&&str2)
    {
        GetSupermode(str2,mode);
        printf("超级模式数组为:\n");
        for(i=0;i<strlen(str2);i++)
        {
            printf("The %d is %d\n",i,mode[i]);
        }
        i=0;
        j=0;
        while (i<strlen(str1)&&j<strlen(str2))
        {
            if(str1[i]!=str2[j])
            {
                j=mode[j];
            }
            j++;
            i++;
        }
        printf("The j is %d\n",j);
        printf("The i is %d\n",i);
        if(j==strlen(str2))
        {
            return i-j;
        }    
    }
    printf("This is Supper Position\n");
    return -1;
}
/**普通的方式产生next数组
 * str为输入的数组，mode数生成的next数组
 * i为next数组的指针，j为next数组中的值
*/
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
            index++;
        }
        
    }
    printf("普通算法使用的计算次数为%d\n",index);
}
void GetSupermode(char *str,unsigned int *mode)
{
    printf("This is Supper Position Get Mode \n");
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
            mode[i]=mode[i]==mode[j]?mode[j]:j;
        }
        else
        {
            j=mode[j];
            index++;
        }
        
    }
    printf("超级算法使用的计算次数为%d\n",index);
}