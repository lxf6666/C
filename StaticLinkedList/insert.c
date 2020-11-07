#include <stdio.h>
#include <stdlib.h>
#include<defiStaticLinkedList.h>
/*
在第i个元素前插入n
*/
int insert(StaticLinkList L,int i,ElemType n)
{
    int j,l,k;
    k=MAXSIZE-1;
    j=getfree(L);
    if(j)
    {
       L[j].data=n;
       for(l=1;l<i;l++)
       {
           k=L[k].cur;
       }
       L[j].cur = L[k].cur;
       //printf("L[j].cur为%d\n",L[j].cur);
       L[k].cur=j;


    }

}
