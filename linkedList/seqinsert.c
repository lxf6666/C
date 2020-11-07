#include<stdio.h>
#include<stdlib.h>
#include<initLinkedList.h>
void seqinsert( LinkList *head , EleType n )
{
    LinkList pre,current,New;
    current = *head;
    pre = NULL;

    while(current != NULL && current->data < n)
    {
        pre = current;
        current = current->Next;
    }
    New=(LinkList)malloc(sizeof(Node));
    if(New == NULL)
        puts("内存分配失败");
    New->Next=current;
    New->data=n;
    if( pre == NULL)
    {
        *head = New;
    }
    else
    {
        pre->Next = New;
    }


}
