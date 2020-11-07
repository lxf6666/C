#include <stdio.h>
#include <stdlib.h>
#include<defiStaticLinkedList.h>

int init(StaticLinkList L)
{
    int i;
    for(i=0;i<MAXSIZE-1;i++)
        L[i].cur=i+1;
        L[MAXSIZE-1].cur=0;
    return OK;
}
