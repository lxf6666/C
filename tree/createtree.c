#include <stdio.h>
#include <stdlib.h>
#include<definetree.h>

void createtree(BiTree *t)
{
    char c;

    scanf("%c",&c);
    if( ' ' == c )
    {
        *t=NULL;
    }
    else
    {
        *t=(BiTree)malloc(sizeof(BiTNode));
        (*t)->data = c;
        createtree(&(*t)->lchild);
        createtree(&(*t)->rchild);
    }
}
