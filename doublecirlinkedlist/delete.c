#include <stdio.h>
#include <stdlib.h>
#include<defindoublelinklist.h>

void Deletenode(DLNode **L,int i)
{
    int j;
    DLNode *target,*temp;
    target=(*L)->next;
    if(i==1)
    {
       for(;target->next!=(*L)->next;target=target->next);
       temp=target->next;
       target->next=temp->next;
       temp->next->pre=target;
       (*L)->next=temp->next;
       free(temp);
    }
    else
    {
        for(j=1;j<i-1;j++)
        target=target->next;
        temp=target->next;
        target->next=temp->next;
        temp->next->pre=target;
    }
}
