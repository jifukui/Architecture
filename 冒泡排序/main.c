#include <stdio.h>
#include <sys/time.h>
int main
{
    int data[]={12,5,8,65,78,32,5,1,45,66,27,56,77,99};
    int i,n;
    int temp;
    for(i=0;i<((sizeof data)/(sizeof(int))-1;i++)
    {
        for(n=0;n<((sizeof data)/(sizeof(int))-1;n++)
        {
            if(data[n]>data[n+1])
            {
                temp=data[n];
                data[n]=data[n+1];
                data[n+1]=temp;
            }
        }
    }
    for(n=0;n<n<((sizeof data)/(sizeof(int));n++)
    {
        printf("The %d Is %d \n",n,data[n]);
    }
    return 0;
}