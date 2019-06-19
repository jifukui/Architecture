#include <stdio.h>
void Adjust(int *data,int s,int n);
int main()
{
    int data[]={12,5,8,65,78,32,15,1,45,66,27,56,77,99};
    int i;
    int temp;
    int  num=(sizeof data)/sizeof(int);
    
    for(i=0;i<num;i++)
    {
        printf("The %d Is %d \n",i,data[i]);
    }
    return 0;
}
void Adjust(int *data,int s,int n)
{
    
}