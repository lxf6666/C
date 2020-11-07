#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
//单链表
typedef struct sNode
{
    ElemType data;
    struct sNode *next;
}sNode;

typedef struct dNode
{
    ElemType data;
    struct dNode *next;
    struct dNode *pre;
}dNode;
//单链表的操作函数
void s_init(sNode **L)
{
    *L=(sNode *)malloc(sizeof(sNode));
    if(!*L)
        printf("内存分配失败");
    (*L)->next=NULL;
}
void s_create(sNode **L,int n)
{
    sNode *p,*temp;
    int i,e;
    temp=*L;
    printf("输入要加入的数");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);
        p=(sNode *)malloc(sizeof(sNode));
        p->data=e;
        if((*L)->next==NULL)
        {
            (*L)->next=p;
             p->next=NULL;
        }
        else
        {
            for(;temp->next!=NULL;temp=temp->next);
            temp->next=p;
            p->next=NULL;
        }

    }
}
void s_exchange(sNode **L,int i)
{
    int j;
    sNode *temp=(*L)->next;
    sNode *p;
    if( i == 1)
    {
        p=temp->next;
        (*L)->next=p;
        temp->next=p->next;
        p->next=temp;
    }
    else
    {
        for(j=1;j<i-1;j++)
            temp=temp->next;
        if(temp->next==NULL)
            printf("已经链表尾部了");
        else
        {
            p=temp->next;
            temp->next=p->next;
            temp=p->next;
            p->next=temp->next;
            temp->next=p;
        }
    }
}
void s_insert(sNode **L,ElemType e)
{
    sNode *p,*temp,*pre;
    temp=(*L)->next;
    p=(sNode *)malloc(sizeof(sNode));
    p->data=e;
    if(temp==NULL)
    {
        (*L)->next=p;
        p->next=NULL;
    }
    else
    {
        for(;(temp->data)<e;)
        {
            pre=temp;
            temp=temp->next;
        }
        pre->next=p;
        p->next=temp;
    }
}
void s_delete(sNode **L,ElemType e)
{
    sNode *temp,*pre;
    temp=(*L)->next;
    for(;temp->data!=e;)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    free(temp);
}
void s_insect(sNode **La,sNode *Lb)
{
    sNode *p,*q,*temp,*ap;
    p=(*La)->next;
    ap=(*La);
    q=Lb->next;
    if( q == NULL || p == NULL )
    {

        for(;p!=NULL;)
        {
            temp=p;
            p=p->next;
            free(temp);
        }
        (*La)->next=NULL;
    }
    else
    {
        while( p!=NULL && q!=NULL )
        {
            if( (p->data) == (q->data))
            {
                if( q->next == NULL )
                {
                    ap=p;
                    p=p->next;
                    for(;p!=NULL;)
                    {
                        temp=p;
                        p=p->next;
                        free(temp);
                    }
                    ap->next=NULL;
                    break;
                }
                    ap=p;
                    p=p->next;
                    q=q->next;

            }
            else if( (p->data) > (q->data) )
            {
                if( q->next == NULL )
                {
                    for(;p!=NULL;)
                    {
                        temp=p;
                        if(p->next == NULL)
                        {
                            ap->next=NULL;
                        }

                        p=p->next;
                        free(temp);

                    }
                }
                else
                {
                    q=q->next;
                }

            }
            else if( (p->data) < (q->data) )
            {
                if( (*La)->next == p )
                {
                    temp=p;
                    (*La)->next=p->next;
                }
                else
                {
                    if(p->next==NULL)
                    {
                        ap->next=NULL;
                    }
                    temp=p;
                    ap->next=p->next;
                }
                p=p->next;
                free(temp);

            }

        }

    }
}
void s_printf(sNode *L)
{
    int i;
    sNode *temp;
    temp=L->next;
    if(temp==NULL)
        printf("表已空");
    for(i=1;temp->next!=NULL;temp=temp->next,++i)
        printf("第%d个数据是%d\n",i,temp->data);
        printf("第%d个数据是%d\n",i,temp->data);
}
//双链的操作函数
void d_init(dNode **L)
{
    *L=(dNode *)malloc(sizeof(dNode));
    if(!*L)
        printf("内存分配失败");
    (*L)->next=NULL;
    (*L)->pre=NULL;
}
void d_create(dNode **L,int n)
{
    dNode *p,*temp;
    int i,e;
    temp=*L;
    printf("输入要加入的数");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);
        p=(sNode *)malloc(sizeof(sNode));
        p->data=e;
        if((*L)->next==NULL)
        {
            (*L)->next=p;
             p->next=NULL;
             p->pre=(*L);
        }
        else
        {
            for(;temp->next!=NULL;temp=temp->next);
            temp->next=p;
            p->next=NULL;
            p->pre=temp;
        }

    }
}
void d_printf(dNode *L)
{
    int i;
    dNode *temp;
    temp=L->next;
    for(i=1;temp->next!=NULL;temp=temp->next,++i)
        printf("第%d个数据是%d\n",i,temp->data);
    printf("第%d个数据是%d\n",i,temp->data);
}
void d_exchange(dNode **L,int i)
{
    int j;
    dNode *temp=(*L)->next;
    dNode *p;
    if( i == 1)
    {
        p=temp->next;
        temp->next=p->next;
        p->next->pre=temp;
        temp->pre=p;
        (*L)->next=p;
        p->pre=(*L);
        p->next=temp;
    }
    else
    {
        for(j=1;j<i-1;j++)
            temp=temp->next;
        if(temp->next==NULL)
            printf("已经链表尾部了");
        else
        {
            p=temp->next;
            temp->next=p->next;
            p->next->pre=temp;
            temp=p->next;
            p->next=temp->next;
            temp->next=p;
            p->pre=temp;
        }
    }
}

int main()
{
    int n;
    //单链测试
    sNode *L=NULL;
    s_init(&L);
    printf("你准备创建几个数据的表");
    scanf("%d",&n);
    s_create(&L,n);
    s_printf(L);
    /*
    printf("你准备交换哪个数据和它下个数据");
    scanf("%d",&n);
    s_exchange(&L,n);
    s_printf(L);
    //双链测试

    dNode *dL=NULL;
    d_init(&dL);
    printf("你准备创建几个数据的表");
    scanf("%d",&n);
    d_create(&dL,n);
    d_printf(dL);
    printf("你准备交换哪个数据和它下个数据");
    scanf("%d",&n);
    d_exchange(&dL,n);
    d_printf(dL);
    */
    //交
    sNode *sL=NULL;
    s_init(&sL);
    printf("你准备创建几个数据的表");
    scanf("%d",&n);
    s_create(&sL,n);
    s_printf(sL);
    printf("它们的交集是：");
    s_insect(&L,sL);
    s_printf(L);





    return 0;
}
