#include<stdio.h>
#include<initList.h>
void clear(SqList *La)
{
    int i;
    for(i=0;i<Maxsize;i++)
        La->data[i]=0;
        La->length=0;
}
