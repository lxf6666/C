#include <stdio.h>
#include <stdlib.h>
#include <initLinkedList.h>

void cycdelete(LinkList *L,int i)
{
    LinkList target,pre;
    int j;
    if(i==1)
    {
        for(target=*L;target->Next!=*L;target=target->Next);
        pre=*L;
        *L=(*L)->Next;
        target->Next=*L;
        free(pre);
    }
    else
    {
    for(j=1;j<=i;++j)
    {
        pre=target;
        target=target->Next;
    }
    pre->Next=target->Next;
    free(target);
    }


}
