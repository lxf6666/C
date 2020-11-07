#include <stdio.h>
#include <stdlib.h>
#include<definetree.h>
void preorder(BiTree t,int level)
{
    if(t)
    {
        visit(t->data,level);
        preorder(t->lchild,level+1);
        preorder(t->rchild,level+1);
    }
}
