#include <stdio.h>
#include <stdlib.h>
#include <initLinkedList.h>
LinkList rear(LinkList *L)
{
    LinkList temp,Lrear;
    temp= *L;
    for(;temp->Next!=(*L);temp=temp->Next);
    Lrear=temp;
    return Lrear;

}
