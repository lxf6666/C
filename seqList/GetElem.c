#include<stdio.h>
#include<initList.h>
ElemType GetElem(SqList La,int n,int *e)
{
    if( La.length==0 || n<1 || n>La.length)
        return FALSE;
    *e=La.data[n-1];
    return OK;
}
