#ifndef _BT_H_
#define _BT_H_
#include "queue.h"
#define BT_OK 1
#define BT_ERR 0
typedef struct BinaryTree
{
    sBinaryTreeNode *root;
    squeue *queue;
    int length;
}sBinaryTree,*spBinaryTree;
/**初始化二叉树*/
sBinaryTree* StoreTreeInit();
/**销毁二叉树*/
void StoreTreeDestory(sBinaryTree *bt);
/**存储二叉树*/
int StoreTree(sBinaryTree *bt,int value);
/**前序遍历二叉树*/
void TreeFrontErgodic(sBinaryTree *bt);
/**中序遍历二叉树*/
void TreeMidErgodic(sBinaryTree *bt);
/**后续遍历二叉树*/
void TreeEedErgodic(sBinaryTree *bt);
/**二叉树的深度*/
int TreeDeep(sBinaryTree *bt);
/**显示二叉树对象*/
void DisplayStoreTree(sBinaryTree *bt);
#endif