#include<stdio.h>
#include<stdlib.h>
#include<initLinkedList.h>
void printfList(LinkList L)
{
    int count = 1;
    while( L!=NULL )
    {
        printf("��%d������,�����ǣ�%d\n",count,L->data);
        L=L->Next;
        count++;
    }


}
