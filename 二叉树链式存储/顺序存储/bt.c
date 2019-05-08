#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
const int BTMask=MAX;
sBinaryTree* StoreTreeInit()
{
    sBinaryTree * bt=NULL;
    bt=(sBinaryTree*)malloc(sizeof(sBinaryTree));
    bt->length=0;
    return bt;
}
int StoreTree(sBinaryTree *bt,int value)
{
    if(bt)
    {
        if(bt->length<BTMask)
        {
            bt->data[bt->length++]=value;
            return BT_OK;
        }
    }
    return BT_ERR;
}
void DisplayStoreTree(sBinaryTree *bt)
{
    if(bt)
    {
        int i,index=0;
        i=bt->length;
        while (index++,i--)
        {
            printf("The %d is %c \n",index,bt->data[index]);
        }
    }
}
void StoreTreeEnd(sBinaryTree *bt)
{
    bt->data[bt->length]='#';
}