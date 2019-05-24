#include <stdio.h>
#include "stack.h"
typedef struct 
{
    int low;
    int height;
}Qk;

int qkpass(int *data,int low,int height);
void qksort(int *data,int len);
int main()
{
    int data[]={12,5,8,65,78,32,15,1,45,66,27,56,77,99};
    int i,n;
    int temp;
    int num=(sizeof data)/sizeof(int);
    qksort(data,num);
    for(n=0;n<num;n++)
    {
        printf("The %d Is %d \n",n,data[n]);
    }
    return 0;
}
int qkpass(int *data,int low,int height)
{
    int i=low,j=height;
    int temp=data[low];
    while (i<j)
    {
        while (i<j&&temp<=data[j])
        {
            j--;
        }
        if(i<j)
        {
            data[i]=data[j];
        }
        while (i<j&&temp>=data[i])
        {
            i++;
        }
        if(i<j)
        {
            data[j]=data[i];
        }
    }
    data[i]=temp;
    return i;
    
}
void qksort(int *data,int len)
{
    int i,low,height;
    Qk qk;
    sStack * stack;
    stack=StackInit();
    if(stack)
    {
        printf("初始化栈成功\n");
        qk.low=0;
        qk.height=len;
        Push(stack,&qk);
        while (!StackEmpty(stack))
        {
            qk=(Qk) *Pop(stack);
            low=qk.low;
            height=qk.height;
            while (low<height)
            {
                i=qkpass(data,low,height);
                if(i<height)
                {
                    qk.low=i+1;
                    qk.height=height;
                    Push(stack,&qk);
                }
                height=i-1;
            }
            
        }
        
    }
    else
    {
        printf("初始化栈失败\n");
    }
    
}