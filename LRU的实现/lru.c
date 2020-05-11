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
    if(status)
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
    val=(struct link *)malloc(sizeof(struct link));
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
        if(data==node->head)
        {
            return 1;
        }
        else
        {
            data->pre->next=data->next;
            if(data->next)
            {
                data->next->pre=data->pre;
            }
        }
    }
    else
    {
        printf("插入的数据不在链表中\n");
        data=(struct linknode *)malloc(sizeof(struct linknode));
        data->data=val;  
        if(len==MAX)
        {
            link_removed(node);
        }
        node->length++;
    }
    data->pre=NULL;
    data->next=node->head;
    if(node->head)
    {
        node->head->pre=data;
    }
    node->head=data;
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
        printf("输出当前链表中的数据--------------------------------------------\n");
        while (val&&(i<len))
        {
            i++;
            printf("第%d个参数的值为:%d\n",i,val->data);
            val=val->next;
        }
        printf("输出链表数据错误-------------------------------------------------\n");
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
        while (val->next)
        {
            val=val->next;
        }
        val->pre->next=NULL;
        free(val);
        flag=1;
        node->length--;
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