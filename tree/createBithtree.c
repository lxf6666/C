#include <stdio.h>
#include <stdlib.h>
#include<definbithtree.h>
#include<definetree.h>
void createbithtree( Bithtree *t )
{
    char c;
    scanf("%c",&c);
    if( ' ' == c )
    {
        *t = NULL;
    }
    else
    {
        *t=(Bithtree)malloc(sizeof(BiThNode));
        (*t)->data = c;
        (*t)->ltag=Link;
        (*t)->rtag=Link;
        createbithtree(&(*t)->lchild);
        createbithtree(&(*t)->rchild);
    }
}
