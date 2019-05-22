#include <stdio.h>
int main()
{
    int data[]={12,5,8,65,78,32,15,1,45,66,27,56,77,99};
    int i,n,j;
    int temp;
    int len;
    int num;
    num=(sizeof data)/sizeof(int);
    len=num/2;
    while(len>=1)
    {
        for(i=len+1;i<14;i++)
        {
            temp=data[i];
            j=i-len;
            while (j>=0&&temp<data[j])
            {
                data[j+len]=data[j];
                j=j-len;
            }
            data[j+len]=temp;
        }
        len=len/2;
    }
    for(n=0;n<14;n++)
    {
        printf("The %d Is %d \n",n,data[n]);
    }
    return 0;
}
