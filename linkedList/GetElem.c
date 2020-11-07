#include <stdio.h>
#include <initLinkedList.h>
int GetElem( LinkList La, int n, EleType *e )
{
    int j;
    LinkList p;
    if(n==1)
    {
        p=La;
    }
    else p=La->Next;
    j=1;

    while( p && j<(n-1) )
    {
        p=p->Next;
        ++j;
    }
    if( !p||j>n )
    {
        return FALSE;
    }
    *e = p->data;
    return OK;
}
