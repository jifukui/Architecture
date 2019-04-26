#include <stdio.h>
#include <sys/time.h>
int main()
{
    int data[]={12,5,8,65,78,32,15,1,45,66,27,56,77,99};
    int i,n;
    int temp;
    for(i=1;i<14;i++)
    {
        temp=data[i];
		//printf("The %i is %d\n",i,temp);
       	n=i-1;
		//注意除了需要小于当前边界的值还需要注意范围
        while(temp<data[n]&&(n>-1))
        {
            data[n+1]=data[n];
            n--;
        }
        data[n+1]=temp;
    }
    for(n=0;n<14;n++)
    {
        printf("The %d Is %d \n",n,data[n]);
    }
    return 0;
}
