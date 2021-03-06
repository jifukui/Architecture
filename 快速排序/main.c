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
    //int data[]={50,36,66,76,36,12,25,95};
    int i,n;
    int temp;
    int  num=(sizeof data)/sizeof(int);
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
    //printf("The low is %d The height is %d\n",low,height);
    //printf("The temp is %d\n",temp);
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
    /*printf("The i is %d The j is %d\n",i,j);
    for(j=0;j<8;j++)
    {
        printf("The %d Is %d \n",j,data[j]);
    }*/
    
    return i;
    
}
void qksort(int *data,int len)
{
    int i,low,height;
    Qk *qk=NULL,*qk1;
    Qk *qk2=NULL;
    qk1=(Qk *)malloc(sizeof(Qk));
    sStack * stack;
    stack=StackInit();
    if(stack)
    {
        printf("初始化栈成功\n");
        qk1->low=0;
        qk1->height=len-1;
        //printf("The data length is %d\n",qk1->height);
        Push(stack,qk1);
        while (!StackEmpty(stack))
        {
            qk=Pop(stack);
            low=qk->low;
            height=qk->height;
            while (low<height)
            {
                i=qkpass(data,low,height);
                if(i+1<height)
                {
                    qk2=(Qk *)malloc(sizeof(Qk));
                    if(qk2)
                    {
                        printf("分配空间成功\n");
                        qk2->low=i+1;
                        qk2->height=height;
                        Push(stack,qk2);
                    }
                    else
                    {
                        printf("分配空间失败\n");
                    } 
                }
                height=i-1;
            }
            
        }
        
    }
    else
    {
        printf("初始化栈失败\n");
    }
    if(qk1)
    {
        free(qk1);
        qk1=NULL;
    }
    if(qk2)
    {
        free(qk2);
        qk2=NULL;
    }
    StackDestory(stack);
}