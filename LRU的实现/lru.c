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

int link_init(struct link *);
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
    status=link_init(data);
    int i;
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

int link_init(struct link * val)
{
    int flag=0;
    val=(struct link *)malloc(sizeof(struct link));
    printf("malloc status is %x\n",val);
    if(val)
    {
        val->head=NULL;
        val->length=0;
        flag=1;
    }
    return flag;
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
        printf("插入的数据不再链表中\n");
        data=(struct linknode *)malloc(sizeof(struct linknode));
        printf("初始化数据data的状态%d\n",data);
        data->data=val;
        printf("更新数据成功\n");
        data->pre=NULL;
        printf("设置前向指针成功\n");
        data->next=NULL;
        printf("初始化后向指针成功\n");
        data->next=node->head->next;
        printf("设置后向指针成功\n");
        if(len==MAX)
        {
            link_removed(node);
        }
        node->head=data;
        printf("更新头指针数据成功\n");
        node->length++;
        printf("更新数据长度成功\n");
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
        int i;
        struct linknode *val=node->head;
        for(i;i<len;i++)
        {
            printf("第%d个参数的值为:%d\n",(i+1),val->data);
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