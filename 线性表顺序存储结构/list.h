#ifndef _LIST_H
#define _LIST_H
#define MAX 256
#define LIST_ERR -1
#define LIST_OK 0
typedef struct{
    int data[MAX];
    int last;
    int size;
}List,*plist;
/**初始化线性表*/
List * ListInit();
/**销毁线性表*/
int ListDestroy(List *list);
/**设置线性表为空*/
int ListClear(List *list);
/**获取线性表的长度*/
int ListLength(plist list);
/**判断线性表是否为空*/
int ListEmpty(plist list);
/**获取线性表的对应位置的值*/
int GetElem(plist list,int index);
/**获取此线性表中是否存在此数据，存在返回此数据在线性表中的位置*/
int LocateElem(plist list,int data);
/**判断此数据是线性表中若不是线性表首数据返回前驱值，如果是返回空*/
int PreElem(plist list,int data);
/**判断此数据是线性表中若不是线性表尾数据返回后继值，如果是返回空*/
int SuccElem(plist list,int data);
/**在线性表的指定位置插入数据*/
int ListInsert(plist list,int index,int data);
/**在线性表的制定位置删除数据*/
int ListDel(plist list,int index);
/**输出线性表的数据*/
void ListDisplay(plist list);
#endif
