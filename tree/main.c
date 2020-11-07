#include <stdio.h>
#include <stdlib.h>
#include<definbithtree.h>
#include<definetree.h>
Bithtree pre;
//中序遍历线索化
void inthread(Bithtree t)
{
   if(t)
   {
        inthread(t->lchild); //递归左线索化
        if( !t->lchild )
        {
            t->ltag=Thread;
            t->lchild=pre;
        }
        if( !pre->rchild )
        {
            pre->rtag=Thread;
            pre->rchild=t;
        }

        pre=t;
        inthread(t->rchild);//递归右线索化

   }

}

void inorderthreading( Bithtree *p,Bithtree t)
{
    *p=(Bithtree)malloc(sizeof(BiThNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild= *p;
    if(!t)
    {
        (*p)->lchild=*p;
    }
    else
    {
        (*p)->lchild=t;
        pre=*p;
        inthread(t);
        pre->rtag=Thread;
        pre->rchild=*p;
        (*p)->rchild=pre;
    }


}
void visita(elemType data,PointerTag l,PointerTag r)
{
    printf("%c的ltag:%d,rtag:%d\n",data,l,r);
}

void Inorder(Bithtree head)
{
    Bithtree p;
    p=head->lchild;
    while(p!=head)
    {
        while( p->ltag ==Link )
        {
            p=p->lchild;

        }
        visita(p->data,p->ltag,p->rtag);
        while( p->rtag == Thread && p->rchild !=head )
        {
            p=p->rchild;
            visita(p->data,p->ltag,p->rtag);
        }
        p=p->rchild;
    }
}
int main()
{
    int level=1;
    int n;
    //二叉树设置
    BiTree t=NULL;
    printf("请输入要创建的树的数据的个数\n");
    scanf("%d",&n);
    creat_bisorttree(&t,n);
    printf("前序遍历结果\n");
    preorder(t,level);
    printf("\n");
    printf("输入要插入的数\n");
    scanf("%d",&n);
    insert_bisorttree(&t,n);
    printf("\n后序遍历结果\n");
    postorder(t,level);
    printf("输入要删除的结点");
    scanf("%d",&n);
    delete_bisorttree(&t,n);
    printf("中序遍历结果\n");
    inorder(t,level);



    //二叉线索树测试
/*    BiTree p,t,head = NULL;
    printf("输入要创建的树\n");
    createbithtree(&t);
    inorderthreading(&p,t);
    head=p;
    printf("中序遍历结果\n:");
    Inorder(p);
    */
    return 0;
}
