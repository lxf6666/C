#include <stdio.h>
#include <stdlib.h>
#include<defindoublelinklist.h>

void insert(DLNode **L,int i,ElemType val)
{
    int j;
    DLNode *p,*target,*temp;
    p=(DLNode *)malloc(sizeof(DLNode));
    p->data=val;
    target=(*L)->next;
    if( i==1 )
    {
        for(;target->next!=(*L)->next;target=target->next);
        (*L)->next=p;
        p->next=target->next;
        p->pre=target;
        target->next->pre=p;
        target->next=p;

    }
    else
    {
        for(j=1;j<i-1;j++)
        target=target->next;
        temp=target->next;
        target->next=p;
        temp->pre=p;
        p->next=temp;
        p->pre=target;

    }


}
