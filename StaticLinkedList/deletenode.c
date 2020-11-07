#include <stdio.h>
#include <stdlib.h>
#include<defiStaticLinkedList.h>
void deletenode(StaticLinkList L,int i)
{
    int k,l,j;
    k=MAXSIZE-1;
    for(l=1;l<i;l++)
    {
        k=L[k].cur;
    }
    j=L[k].cur;
    L[k].cur=L[j].cur;
    L[j].cur=L[0].cur;
    L[0].cur=j;


}
