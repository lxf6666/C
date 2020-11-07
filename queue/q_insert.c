#include <stdio.h>
#include <stdlib.h>
#include<Definqueue.h>
void q_insert(LinkQueue *q,ElemType e)
{
    QueuePrt p;
    p=(QueuePrt)malloc(sizeof(QNode));
    if( p == NULL )
        printf("内存分配失败");
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}
