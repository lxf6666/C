#include<stdio.h>
#include<stdlib.h>
#include<initLinkedList.h>

void deleteNode(LinkList *head,EleType value)
{
    LinkList pre,current;
    current = *head;
    pre = NULL;

    while(current != NULL && current->data != value)
    {
        pre = current;
        current = current->Next;
    }
    if( current == NULL)
    {
        puts("找不到匹配的数据");
    }
    else
    {
        if(pre == NULL)
        {
           *head = current->Next;
        }
        else pre->Next = current->Next;
    }
    free(current);
}
