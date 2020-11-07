#include<stdio.h>
#include<initList.h>
void deleteList(SqList *La,int n)
{
    int i;
    for(i=n;i<=La->length-1;i++)
    {
        La->data[i-1]=La->data[i];
    }
    --La->length;
}
