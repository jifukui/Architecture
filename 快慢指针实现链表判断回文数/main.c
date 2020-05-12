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
int  PalindromeNumber(struct link *);

int main()
{
    int value[7]={1,2,3,4,3,2,1};
    struct link *data=NULL;
    data=link_init();
    int i;
    int status=0;
    if(data)
    {
        printf("初始化链表成功\n");
        for(i=0;i<(sizeof(value)/sizeof(int));i++)
        {
            printf("准备插入数据%d\n",value[i]);
            link_insert(data,value[i]);
        }
        link_display(data);
        status=PalindromeNumber(data);
        if(status)
        {
            printf("回文数\n");
        }
        else
        {
            printf("不是回文数\n");
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
    struct linknode *data=NULL;
    if(node)
    {
        data=(struct linknode *)malloc(sizeof(struct linknode));
        if(data)
        {
            data->data=val;
            data->next=NULL;
            struct linknode *value=NULL;
            value=node->head;
            if(!value)
            {
                node->head=data;
                return 1;
            }
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
            printf("第%d个参数的值为:%d地址为%u\n",i,val->data,val);
            val=val->next;
        }
        printf("输出链表数据结束-------------------------------------------------\n");
    }
}

int  PalindromeNumber(struct link *node)
{
    struct linknode * slow=NULL;
    struct linknode * fast=NULL;
    struct linknode * next=NULL;
    struct linknode * pre=NULL;
    int flag=1;
    int i=0;
    int first=0;
    if(node)
    {
        fast=node->head;
        next=node->head;
        while (fast->next)
        {
            fast=fast->next;
            if(fast->next)
            {
                fast=fast->next;
                slow=next;
                next=next->next;
                printf("first address is %u,the second address is %u\n",slow,next);
                slow->next=pre;
                pre=slow;
                
                //next=next->next;
                
                if(!first)
                {
                    slow=next;
                    next=next->next;
                    slow->next=pre;
                    first=1;

                }
                printf("first address is %u,the second address is %u,the third address is %u\n",slow,next,pre);
            }
            else
            {
                break;
            }
        }
        if(!slow)
        {
            return 1;
        }
        else
        {
            while (next&&pre)
            {
                i++;
                printf("当前比较第%d次,前指针的值为%d,后指针的值为%d\n",i,pre->data,next->data);
                if(pre->data!=next->data)
                {
                    return 0;
                }
                pre=pre->next;
                next=next->next;
            }
            
        }
        
    }
    else
    {
        flag=1;
    }
    return flag;
}