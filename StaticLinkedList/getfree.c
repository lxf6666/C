#include <stdio.h>
#include <stdlib.h>
#include<defiStaticLinkedList.h>
/*
��ȡ���з����±�
*/
int getfree(StaticLinkList L)
{
    int i = L[0].cur;
    if( L[0].cur )
    {
        L[0].cur=L[i].cur;
    }
    return i;
}
