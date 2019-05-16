#ifndef _TREE_NODE_H
#define _TREE_NODE_H
#define MAX 32
typedef struct ClueTreeNode
{
    int data;
    int ltag;
    int rtag;
    struct cluetreenode *lchild;
    struct cluetreenode *rchild; 
}cluetreenode,*pcluetreenode;
#endif