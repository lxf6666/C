#include <stdio.h>
#include <stdlib.h>
#include<defindoublelinklist.h>
void init(DLNode **L)
{
    *L=(DLNode *)malloc(sizeof(DLNode));
    if(!*L)
        printf("内存分配失败");
    (*L)->next=(*L)->pre=*L;

}
