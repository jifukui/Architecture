#include <stdio.h>
int main(int argc,char **argv)
{
    int data[]={1,2,3,4,5,6,7,9,12,15,17,19,20,21,23,29,30,42,45,46,47,58,59,62,64,67,68};
    if(argc==2)
    {
        int i,val;
        val=atoi(argv[1]);
        printf("输入的要查找的数为%d\n",val);
        for(i=0;i<((sizeof(data)/sizeof(int)));i++)
        {
            if(data[i]==val)
            {
                break;
            }
        }
        if(i==(sizeof(data)/sizeof(int)))
        {
            printf("没有找到参数\n");
        }
        else
        {
            printf("找到参数在%d\n",i);
        }
        
    }
    return 0;
}