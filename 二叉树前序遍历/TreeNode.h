#ifndef _TREE_NODE_H
#define _TREE_NODE_H
#define MAX 16
typedef struct BinaryTreeNode
{
    int data;
    struct sBinaryTreeNode *lchild;
    struct sBinaryTreeNode *rchild;
}sBinaryTreeNode,*spBinaryTreeNode;
#endif