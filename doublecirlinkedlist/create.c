#include <stdio.h>
#include <stdlib.h>
#include<defindoublelinklist.h>

void create(DLNode **L)
{
    DLNode *p,*q;
    p=*L;
    int n,h;
    printf("输入要创建的表的大小\n");
    scanf("%d",&n);
    printf("请输入数据\n");
    while(n>0)
    {
        scanf("%d",&h);
        q=(DLNode *)malloc(sizeof(DLNode));
        q->data=h;
        q->pre=p;
        q->next=p->next;
        p->next=q;
        p=q;
        --n;
    }
    p->next=(*L)->next;
    (*L)->next->pre=p;
}
