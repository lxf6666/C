#include<stdio.h>
#include<initList.h>
void ListLength(SqList *La)
{
    int i,L;
    L=0;

    for(i=0;La->data[i]!=0;i++)
    {
        L++;
    }
        La->length = L;
}
