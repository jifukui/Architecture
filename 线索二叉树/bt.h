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
/**线索二叉树结构*/
typedef struct ClueTree
{
    int length;
    struct scluetreenode *top;
}scluetree,*spcluetree;
typedef struct ClueTreeNode
{
    int data;
    struct scluetreenode *lchild;
    struct scluetreenode *rchild;   
    int ltag;
    int rtag; 
}scluetreenode,*pscluetreenode;
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
/**线索二叉树中序存储*/
scluetree *ClueTreeInit();
scluetree * StoreClueTreeMid(sBinaryTree *bt);
scluetreenode *MidGetFrontNode(scluetreenode* node);
scluetreenode *MidGetAfterNode(scluetreenode *node);
void MidDisplayStoreTree(scluetree *root);
#endif