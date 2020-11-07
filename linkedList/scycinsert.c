#include <stdio.h>
#include <stdlib.h>
#include <initLinkedList.h>

void cycinsert(LinkList *L,int i)
{
    LinkList p,target,temp;
    EleType item;
    int j=1;

    printf("输出要插入的值");
    scanf("%d",&item);

    if(i == 1)
    {
        p=(LinkList)malloc(sizeof(Node));
        if(!p)
            printf("内存分配失败");
        p->data=item;

        for(target=*L;target->Next!=*L;target=target->Next);
        p->Next=*L;
        target->Next=p;
        *L=p;
    }
    else
    {
        target=*L;
        for(;j<i-1;++j)
            target=target->Next;
        p=(LinkList)malloc(sizeof(Node));
        p->data=item;

        temp=target->Next;
        target->Next=p;
        p->Next=temp;
    }

}
