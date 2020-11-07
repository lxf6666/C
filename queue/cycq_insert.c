#include <stdio.h>
#include <stdlib.h>
#include<Definqueue.h>
void cycq_insert(cycleQueue *q,elemType e)
{
    if((q->rear+1)%MAXSIZE == q->qfront)
        printf("队列已满");
    q->base[q->rear] = e;
    q->rear = (q->rear+1)%MAXSIZE;

}
