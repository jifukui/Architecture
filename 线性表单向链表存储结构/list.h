#ifndef _LIST_H
#define _LIST_H
#define LIST_ERR -1
#define LIST_OK 0
typedef struct{
    int data;
    ListNode * next;
}ListNode,*plistnode;
typedef struct{
    plistnode head;
    unsigned int length;
}List,*pList;
/**初始化线性表*/
ListNode * ListInit();
/**销毁线性表*/
int ListDestroy(ListNode *list);
/**设置线性表为空*/
int ListClear(List *list);
/**获取线性表的长度*/
int ListLength(pList list);
/**判断线性表是否为空*/
int ListEmpty(pList list);
/**获取线性表的对应位置的值*/
int GetElem(pList list,int index);
/**获取此线性表中是否存在此数据，存在返回此数据在线性表中的位置*/
int LocateElem(pList list,int data);
/**判断此数据是线性表中若不是线性表首数据返回前驱值，如果是返回空*/
int PreElem(pList list,int data);
/**判断此数据是线性表中若不是线性表尾数据返回后继值，如果是返回空*/
int SuccElem(pList list,int data);
/**在线性表的指定位置插入数据*/
int ListInsert(pList list,int index,int data);
/**在线性表的制定位置删除数据*/
int ListDel(pList list,int index);
/**输出线性表的数据*/
void ListDisplay(pList list);
#endif
