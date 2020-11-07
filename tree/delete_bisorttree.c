#include <stdio.h>
#include <stdlib.h>
#include<definetree.h>
void delete_bisorttree(BiTree *t,int key)
{
    BiTree p,q,s;
    s=NULL;
    if(!searchbisorttree(*t,key,&s,&p))
    {
        printf("要删除的节点不存在");
    }
    else
    {
        if( s->data > p->data )
        {
            if(p->lchild == NULL)
            {
                s->lchild=p->rchild;
                free(p);
            }
            else if(p->rchild == NULL)
            {
                s->lchild=p->lchild;
                free(p);
            }
            else
            {
                 q=p->lchild;
                while( q->rchild != NULL )
                {
                    s=q;
                    q=q->rchild;
                }
                if( q==p->lchild )
                {
                    p->lchild=q->lchild;
                    free(q);
                }
                else
                {
                    p->data=q->data;
                    s->rchild=q->lchild;
                    free(q);
                }
            }
        }
        else if( s->data < p->data )
        {
            if(p->lchild == NULL)
            {
                s->rchild=p->rchild;
                free(p);
            }
            else if(p->rchild == NULL)
            {
                s->rchild=p->lchild;
                free(p);
            }
            else
            {
                 q=p->lchild;
                while( q->rchild != NULL )
                {
                    s=q;
                    q=q->rchild;
                }
                if( q==p->lchild )
                {
                    p->data=q->data;
                    p->lchild=q->lchild;
                    free(q);
                }
                else
                {
                    p->data=q->data;
                    s->rchild=q->lchild;
                    free(q);
                }
            }
        }

    }
}
