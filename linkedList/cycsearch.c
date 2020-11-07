#include <stdio.h>
#include <stdlib.h>
#include <initLinkedList.h>
/*
返回位置
*/

int cycsearch(LinkList L,int Elem)
{
    LinkList target;
    int i=1;
    for(target=L;(target->Next !=L)&&(target->data!=Elem);++i)
        target=target->Next;
    if(target->Next==L)
        return FALSE;
    else return i;
}
