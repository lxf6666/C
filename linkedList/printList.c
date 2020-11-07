#include<stdio.h>
#include<stdlib.h>
#include<initLinkedList.h>
void printfList(LinkList L)
{
    int count = 1;
    while( L!=NULL )
    {
        printf("第%d个数据,数据是：%d\n",count,L->data);
        L=L->Next;
        count++;
    }


}
