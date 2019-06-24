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
    struct BlanceTreeNode *Lchild,*Rchild;
}BlanceTreeNode;
BlanceTreeList* BlanceTreeInit();
void BlanceTreeDestory(BlanceTreeList *list);
void BlanceTreeDisplay(BlanceTreeList *list);
void BlanceTreeMidDisplay(BlanceTreeList *list);
int BlanceTreeInsert(BlanceTreeList *List,char value);
int BlanceTreeDelete(BlanceTreeList *List,char value);
BlanceTreeNode *BlanceTreeSearch(BlanceTreeList *list,char value);
#endif
