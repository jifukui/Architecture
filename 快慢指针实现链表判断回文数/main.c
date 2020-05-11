#include <stdio.h>
struct linknode
{
    int data;
    struct linknode *next;
};

struct link
{
    struct linknode *head;
    int length;
};
struct link * link_init(void);
int link_insert(struct link *,int );
void link_display(struct link *);
int main()
{
    int value[12]={1,2,3,4,5,5,3,2,1,7,5,4};
    struct link *data=NULL;
    data=link_init();
    int i;
    int status;
    if(data)
    {
        printf("初始化链表成功\n");
        status=link_length(data);
        for(i=0;i<(sizeof(value)/sizeof(int));i++)
        {
            printf("准备插入数据%d\n",value[i]);
            status=link_insert(data,value[i]);
            if(status)
            {
                printf("插入数据正确\n");
            }
            else
            {
                printf("插入数据错误\n");
            }
            
        }
        link_display(data);
    }
    else
    {
        printf("初始化链表失败\n");
    }
    return 0;
    
}

int link_insert(struct link * node,int val)
{
    struct linknode *data=NULL;
    if(node)
    {
        if(data)
        {
            data->data=val;
            data->next=NULL;
            struct linknode *value=NULL;
            value=node->head;
            while (value->next)
            {
                value=value->next;
            }
            value->next=data;
            return 1;
        }
    }
    return 0;    
}

void link_display(struct link * node)
{
    if(node)
    {
        int i=0;
        struct linknode *val=node->head;
        printf("输出当前链表中的数据--------------------------------------------\n");
        while (val)
        {
            i++;
            printf("第%d个参数的值为:%d\n",i,val->data);
            val=val->next;
        }
        printf("输出链表数据结束-------------------------------------------------\n");
    }
}