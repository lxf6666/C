#include<stdio.h>
#include<stdlib.h>
#include<initLinkedList.h>

void insertback(LinkList *L)
{
    LinkList p;
    static LinkList back;
    p=(LinkList)malloc(sizeof(Node));
    if( p==NULL )
    {
        puts("ÄÚ´æ·ÖÅäÊ§°Ü");
    }
    getinput(p);
    if( *L == NULL )
    {
        *L=p;
        p->Next=NULL;
    }
    else
    {
       back->Next=p;
       p->Next=NULL;
    }
    back = p;
}
