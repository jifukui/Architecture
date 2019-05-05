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
		//注意这里为什么是-1而不是i
        hight=i-1;
        temp=data[i];
        while (low<=hight)
        {
            mid=low+((hight+low) >> 1);
            if(temp>=data[mid])
            {
                low=mid+1;
            }
            else
            {
                hight=mid-1;
            }
        }
        for(n=i-1;n>=low;n--)
        {
            data[n+1]=data[n];
        }
        data[low]=temp;
        
    }
    for(n=0;n<14;n++)
    {
        printf("The %d Is %d \n",n,data[n]);
    }
    return 0;
}
