#include <stdio.h>
int main(int argc,char **argv)
{
    int data[]={1,2,3,4,5,6,7,9,12,15,17,19,20,21,23,29,30,42,45,46,47,58,59,62,64,67,68};
    if(argc==2)
    {
        int i,val,j=5;
        int key[10];
        int index=0;
        int n;
        int max;
        val=atoi(argv[1]);
        printf("输入的要查找的数为%d\n",val);
        for(i=0;i<((sizeof(data)/sizeof(int)));i+=j)
        {
            index++;
            for(n=0;n<j;n++)
            {
                if(n==0)
                {
                    max=data[i+n];
                }
                else
                {
                    if(max<data[i+n])
                    {
                        max=data[i+n];
                    }
                }     
            }
            key[index++]=max;
        }
        for(i=0;i<index;i++)
        {
            printf("The %d key is %d\n",i,key[i]);
        }
        for(i=0;i<index;i++)
        {
            if(val<key[i])
            {
                
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