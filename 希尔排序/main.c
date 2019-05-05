#include <stdio.h>
#include <sys/time.h>
int main()
{
    int data[]={12,5,8,65,78,32,15,1,45,66,27,56,77,99};
    int i,n;
    int temp;
    int len;
    len=14/2;
    while(len>=1)
    {
        for(i=len+1;i<14;i=i++)
        {
            if(data[i]>data[i+len])
            {

            }
        }
        len=(len+1)/2;
    }
    for(n=0;n<14;n++)
    {
        printf("The %d Is %d \n",n,data[n]);
    }
    return 0;
}
