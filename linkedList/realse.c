#include<stdio.h>
#include<stdlib.h>
#include<initLinkedList.h>
void realseList(LinkList *L)
{
    LinkList temp;
    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->Next;
        free(temp);

    }
    printf("内存已经释放");
}
