#include <stdio.h>
#include <stdlib.h>
#include<definetree.h>
void postorder(BiTree t,int level)
{
    if(t)
    {
        postorder(t->lchild,level+1);
        postorder(t->rchild,level+1);
        visit(t->data,level);
    }
}

