#include <stdio.h>
#define MAX 3
struct linknode
{
    int data;
    struct linknode *next;
};

struct link
{
    struct linknode *head;
    struct linknode *pre;
    int length;
};

int link_init(struct link *);
int link_insert(struct link *,int );
int link_removed(struct link *);
int link_length(struct link *);
void link_display(struct link *);

int main()
{
    int value[12]={1,2,3,4,5,5,3,2,1,7,5,4};
    struct link *data=NULL;
    int status;
    status=link_init(data);
    int i;
    if(status)
    {
        printf("初始化链表成功\n");
        printf("数组的大小为%d\n",sizeof(value));
        status=link_length(value);
        printf("获取链表的长度为%d\n",status);
        for(i=0;i<(sizeof(value)/sizeof(int));i++)
        {
            /*status=link_insert(value[i]);
            if(status)
            {
                printf("插入数据正确\n");
            }
            else
            {
                printf("插入数据错误\n");
            }*/
            
        }
    }
    else
    {
        printf("初始化链表失败\n");
    }
    return 0;
    
}

int link_init(struct link * val)
{
    int flag=0;
    val=(struct link *)malloc(sizeof(struct link));
    printf("malloc status is %x\n",val);
    if(val)
    {
        val->head=NULL;
        val->pre=NULL;
        val->length=0;
        flag=1;
    }
    return flag;
}

int link_insert(struct link *,int )
{
    int len=link_length();
    if(len==MAX)
    {

    }
    else
    {
        
    }
    
}

int link_length(struct link * val)
{
    if(val)
    {
        return val->length;
    }
}