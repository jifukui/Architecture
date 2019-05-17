#include <stdio.h>
int main(int argc,char **argv)
{
    int data[]={1,2,3,4,5,6,7,9,12,15,17,19,20,21,23,29,30,42,45,46,47,58,59,62,64,67,68};
    if(argc==2)
    {
        int i,val;
        val=atoi(argv[1]);
        printf("输入的要查找的数为%d\n",val);
        int low=0;
        int height=(sizeof(data))/(sizeof(int));
        int mid;
        while (low<=height)
        {
            mid=(low+height)/2;
            if(data[mid]>val)
            {
                height=mid-1;
            }
            else if(data[mid]<val)
            {
                low=mid+1;
            }
            else
            {
                printf("找到查找的参数在%d\n",mid);
                break;
            }
        }
        if(low>height)
        {
            printf("没有找到需要查找的参数\n");
        } 
    }
    return 0;
}