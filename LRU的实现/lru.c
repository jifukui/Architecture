#include <stdio.h>
#define MAX 3
struct linknode
{
    int data;
    struct linknode *next;
    struct linknode *pre;
};

struct link
{
    struct linknode *head;
    int length;
};

struct link * link_init(void);
int link_insert(struct link *,int );
int link_removed(struct link *);
int link_length(struct link *);
struct linknode* link_find(struct link*,int);
void link_display(struct link *);

int main()
{
    int value[12]={1,2,3,4,5,5,3,2,1,7,5,4};
    struct link *data=NULL;
    int status;
    data=link_init();
    int i;
    printf("数据data的地址为%x\n",data);
    if(status)
    {
        printf("初始化链表成功\n");
        printf("数组的大小为%d\n",sizeof(value));
        status=link_length(data);
        printf("获取链表的长度为%d\n",status);
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
            link_display(data);
        }
    }
    else
    {
        printf("初始化链表失败\n");
    }
    return 0;
    
}

struct link * link_init(void)
{
    int flag=0;
    struct link * val=NULL;
    printf("数据的地址为%x\n",val);
    val=(struct link *)malloc(sizeof(struct link));
    printf("malloc status is %x\n",val);
    if(val)
    {
        val->head=NULL;
        val->length=0;
        flag=1;
    }
    return val;
}

int link_insert(struct link * node,int val)
{
    int len=link_length(node);
    struct linknode *data=NULL;
    data=link_find(node,val);
    if(data)
    {
        printf("插入的数据在链表中\n");
        data->next=node->head;
        data->pre=NULL;
        node->head=data;
    }
    else
    {
        printf("插入的数据不在链表中\n");
        data=(struct linknode *)malloc(sizeof(struct linknode));
        data->data=val;
        data->pre=NULL;
        data->next=NULL;
        if( len>0 )
        {
            data->next=node->head;
            printf("更新链表的连接1\n");
            data->next->pre=data;
            printf("更新链表的连接2\n");
        }
        
        if(len==MAX)
        {
            link_removed(node);
        }
        node->head=data;
        node->length++;
    }
    return 1;    
}

int link_length(struct link * val)
{
    if(val)
    {
        return val->length;
    }
    return -1;
}

void link_display(struct link * node)
{
    if(node)
    {
        int len=link_length(node);
        int i=0;
        struct linknode *val=node->head;
        while (val)
        {
            i++;
            printf("第%d个参数的值为:%d\n",i,val->data);
            val=val->next;
        }
    }
}
int link_removed(struct link *node)
{
    int flag=0;
    printf("链表已经满了需要删除尾部的数据\n");
    if(node)
    {
        struct linknode *val=NULL;
        val=node->head;
        /**找到最后一个节点*/
        while (val->next)
        {
            val=val->next;
        }
        free(val);
        flag=1;
        node->length++;
    }
    return flag;
}

struct linknode* link_find(struct link* node,int val)
{
    struct linknode *data=NULL;
    if(node)
    {
        data=node->head;
        while (data)
        {
            if(data->data==val)
            {
                printf("查找到了数据\n");
                return data;
            }
            data=data->next;
        }
    }
    printf("没有查找到数据\n");
    return NULL;
}