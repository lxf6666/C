#include<stdio.h>
#include<initList.h>
ElemType LocateElem(SqList La,int n)
{
    int i,temp;
    temp=0;
    if(La.length==0)
    {
        return ERROR;
    }
    for(i=0;i<La.length;i++)
    {
        if(La.data[i]==n)
            temp=i+1;
    }
    if(temp!=0)
        return temp;
    return FALSE;
}
