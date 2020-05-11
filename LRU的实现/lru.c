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
        for(i=0;i<(sizeof(value)/sizeof(int));i++)
        {

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