#include <stdio.h>
#include <stdlib.h>
#include<Definqueue.h>
void cyc_deq(cycleQueue *q,elemType *e)
{
    if( q->rear == q->qfront )
    {
        printf("队列已空");
    }
    *e = q->base[q->qfront];
    q->qfront = (q->qfront+1)%MAXSIZE;
}
