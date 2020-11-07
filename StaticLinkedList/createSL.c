#include <stdio.h>
#include <stdlib.h>
#include<defiStaticLinkedList.h>
void create(StaticLinkList L,int n)
{
    int i,h;

    for(i=1;i<=n;i++)
    {
        puts("输入要加入的数据");
        scanf("%d",&h);
        L[i].data=h;
        L[i].cur=i+1;
    }
    L[MAXSIZE-1].cur=1;
    L[n].cur=0;
    L[0].cur=n+1;

}
