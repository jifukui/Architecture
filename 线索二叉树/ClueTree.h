#ifndef _CLUE_TREE_H
#define _CLUE_TREE_H
#include "queue.h"
#define CLUETREE_ERR -1
#define CLUETREE_OK  0
typedef struct ClueTree
{
    int length;
    struct cluetreenode *top;
    struct squeue       *queue; 
}cluetreelist;
cluetreelist* ClueTreeInit();
int ClueTreeStror(cluetreelist *bl,int value);
int Mid(cluetreelist *bl);
int Front(cluetreelist *bl);
int End(cluetreelist *bl);
void FrontDisPlay(cluetreelist *bl);
cluetreenode *FrontGetNode(cluetreelist *bl,int value);
void FrontInsert(cluetreenode *Bp,int value);
void FrontDel(cluetreelist *bl,int value);
#endif