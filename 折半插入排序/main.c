#include<stdio.h>
int main()
{
    int data[]={12,5,8,65,78,32,15,1,45,66,27,56,77,99};
    int i,n;
    int temp;
    int low,hight,mid;
    for(i=1;i<14;i++)
    {
        low=0;
        hight=i;
        temp=data[i];
        while (low<=hight)
        {
            mid=(hight+low)/2;
            if(temp>=data[mid])
            {
                low=mid+1;
            }
            else
            {
                hight=mid-1;
            }
        }
        for(n=i-1;n>=low;n++)
        {
            data[n+1]=data[n];
        }
        data[n]=temp;
        
    }
    for(n=0;n<14;n++)
    {
        printf("The %d Is %d \n",n,data[n]);
    }
    return 0;
}