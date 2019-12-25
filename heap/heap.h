#ifndef _HEAP__H__
#define _HEAP__H__
#include <stdlib.h>
#define HEADSIZE 256
#define ERR (!0)
#define SUCCESS 0
#define DEBUG
typedef struct {
    int data[HEADSIZE];
    int current;
}heap;
/**堆的初始化*/
heap *init();
/**向堆中添加数据*/
int add(heap*,int data);
/**查找*/
int find(heap *addr,int data,int *index);
/**获取*/
int get(heap* addr,int index,int *data);
/**销毁*/
void destory(heap *);
/**显示堆中的内容*/
void display(heap *);
/**获取堆的长度*/
int getlength(heap*);
#endif /**_HEAP__H__*/