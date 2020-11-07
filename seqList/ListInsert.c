#include<stdio.h>
#include<initList.h>
void ListInsert(SqList *La,int n,int e)
{
    int i;
    for(i=La->length+1;i>=n;i--)
    {
        La->data[i]=La->data[i-1];
    }
    La->data[n-1]=e;
    La->length++;
}
