#include <stdio.h>
#include <stdlib.h>
#include <initLinkedList.h>
void cycprintf(LinkList L)
{
    LinkList target;
    int i=1;
    for(target = L;target->Next!=L;target=target->Next)
    {
        printf("表的第%d个数据是%d\n",i,(target)->data);
        i++;
    }
    printf("表的第%d个数据是%d\n",i,(target)->data);
}
