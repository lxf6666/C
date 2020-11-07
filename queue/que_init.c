#include <stdio.h>
#include <stdlib.h>
#include<Definqueue.h>

void que_init(LinkQueue *q)
{
    q->qfront=q->rear=(QueuePrt)malloc(sizeof(QNode));
    if(!q->qfront)
        printf("内存分配失败");
    q->qfront->next=NULL;

}
