#include<stdio.h>
#include<stdlib.h>
#include<initLinkedList.h>
void insertList(LinkList *La)
{
    LinkList p,temp;
    p=(LinkList)malloc(sizeof(Node));
    if( p == NULL )
    {
        puts("sorry,�ڴ����ʧ��");
    }
    getinput(p);
    if( *La==NULL )
    {
        *La = p;
        p->Next = NULL;
    }
    else
    {
        temp = *La;
        *La = p;
        p->Next = temp;
    }
}
