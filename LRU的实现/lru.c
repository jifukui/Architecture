#include <stdio.h>
#define MAX 3
struct linknode
{
    int data;
    linknode *next;
};

struct link
{
    linknode *head;
    linknode *pre;
    int length;
};

int link_init(link *);
int link_insert(link *,int );
int link_removed(link *);
int link_length(link *);
void link_display(link *);

int main()
{
    int vlaue[12]={1,2,3,4,5,5,3,2,1,7,5,4};
    link *data=null;
    int status;
    status=link_init(data);
    if(status)
    {
        printf("初始化链表失败\n");
    }
    else
    {
        printf("初始化链表成功\n");
    }
    return 0;
    
}
int link_init(link * val)
{
    int flag=0;
    val=(link *)malloc(sizeof(link));
    if(val)
    {
        val->head=null;
        val->pre=null;
        link->length=0;
        flag=1;
    }
    return flag;
}