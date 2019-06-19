#ifndef _BSP_H
#define _BSP_H
typedef struct BlanceTreeList
{
    int length;
    void *value;
}BlanceTreeList;

typedef struct BlanceTreeNode
{
    void * data;
    struct BlanceTreeNode *Lchild,Rchild;
}BlanceTreeNode;
BlanceTreeNode BlanceTreeInit();
void BlanceTreeDestory(BlanceTreeList list);
void BlanceTreeDisplay(BlanceTreeList list);
BlanceTreeNode BlanceTreeInsert(BlanceTreeList List,BlanceTreeNode node);
BlanceTreeNode BlanceTreeSearch(BlanceTreeList list,BlanceTreeNode node);
#endif
