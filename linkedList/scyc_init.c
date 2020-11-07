#include <stdio.h>
#include <stdlib.h>
#include <initLinkedList.h>

void scyc_init(LinkList *L,int n)
{
    int item;
    LinkList temp;
    LinkList target;

    printf("输入结点信息\n");
    while(n>0)
    {
        --n;
        scanf("%d",&item);
        if(*L == NULL)
        {
            *L=(LinkList)malloc(sizeof(Node));
            if(*L==NULL)
                printf("内存分配失败");

            (*L)->data=item;
            (*L)->Next=*L;
        }
        else
        {
            for(target=(*L);target->Next!=(*L);target=target->Next);

            temp=(LinkList)malloc(sizeof(Node));
            if(!temp)
                printf("内存分配失败");
            temp->data=item;
            temp->Next=*L;
            target->Next=temp;
        }
    }
}
