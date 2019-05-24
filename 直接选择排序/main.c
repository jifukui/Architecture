#include <stdio.h>
int main()
{
    int data[]={12,5,8,65,78,32,15,1,45,66,27,56,77,99};
    int i,j,k;
    int temp;
    int  num=(sizeof data)/sizeof(int);
    for(i=0;i<num;i++)
    {
        j=i;
        for(k=i;k<num;k++)
        {
            if(data[k]<data[j])
            {
                j=k;
            }
        }
        if(j!=k)
        {
            temp=data[j];
            data[j]=data[i];
            data[i]=temp;
        }
    }
    for(i=0;i<num;n++)
    {
        printf("The %d Is %d \n",i,data[i]);
    }
    return 0;
}
