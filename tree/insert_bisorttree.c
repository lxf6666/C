#include <stdio.h>
#include <stdlib.h>
#include<definetree.h>
void insert_bisorttree(BiTree *t,int key)
{
    BiTree p,s,tmp;
    if(!searchbisorttree(*t,key,&tmp,&p,NULL))
    {
        s=(BiTree)malloc(sizeof(BiTNode));
        s->data=key;
        s->lchild = s->rchild = NULL;
        if( p == NULL )
        {
            *t = s;
        }
        else if( (p->data)>key )
        {
            p->lchild=s;
        }
        else
        {
            p->rchild=s;
        }
    }
    else
    {
        printf("该点已存在\n");
    }
}

