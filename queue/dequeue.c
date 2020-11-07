#include <stdio.h>
#include <stdlib.h>
#include<Definqueue.h>
void q_dequeue(LinkQueue *q,ElemType *e)
{
    if( q->qfront == q->rear )
        printf("队列已经空了，不能再出");

    QueuePrt temp=q->qfront->next;
    *e=temp->data;
    q->qfront->next=temp->next;
    if(q->rear == temp)
        q->rear=q->qfront;
    free(temp);
}
