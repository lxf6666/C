#include <stdio.h>
#include <stdlib.h>
#include<Definqueue.h>
void q_destory(LinkQueue *q)
{
    while( q->qfront )
    {
        q->rear=q->qfront->next;
        free(q->qfront);
        q->qfront=q->rear;
    }
}
