#include <stdio.h>
#include <stdlib.h>
#include <definetree.h>

int searchbisorttree(BiTree t,int key,BiTree *f,BiTree *p,BiTree sm)
{
    if(t==NULL)
    {
        *p=sm;
        return NULL;
    }
    else if( (t->data)>key )
    {
        *f=t;
        return searchbisorttree(t->lchild,key,f,p,t);
    }
    else if( (t->data)==key )
    {
        *p=t;
        return 1;
    }
    else
    {
        *f=t;
        return searchbisorttree(t->rchild,key,f,p,t);
    }
}
