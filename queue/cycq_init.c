#include <stdio.h>
#include <stdlib.h>
#include<Definqueue.h>

void cycq_init(cycleQueue *q)
{
    q->base=(elemType *)malloc(MAXSIZE * sizeof(elemType));
    if(!q->base)
        printf("内存分配失败");
    q->qfront = q->rear = 0;
}
