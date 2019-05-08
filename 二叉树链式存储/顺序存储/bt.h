#ifndef _BT_H_
#define _BT_H_
#define MAX 8
#define BT_OK 1
#define BT_ERR 0
typedef struct BinaryTree
{
    int data[MAX];
    int length;
}sBinaryTree,*spBinaryTree;
sBinaryTree* StoreTreeInit();
int StoreTree(sBinaryTree *bt,int value);
void DisplayStoreTree(sBinaryTree *bt);
void StoreTreeEnd(sBinaryTree bt);
#endif