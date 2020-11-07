#include <stdio.h>
#include <stdlib.h>
#include<definetree.h>
void inorder(BiTree t,int level)
{
    if(t)
    {
        inorder(t->lchild,level+1);
        visit(t->data,level);
        inorder(t->rchild,level+1);
    }
}
