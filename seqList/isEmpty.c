#include<stdio.h>
#include<initList.h>
ElemType isEmpty(SqList La)
{
    int i;
    for(i=0;i<Maxsize;i++)
    {
        if(La.data[i]!=0)
            return FALSE;
    }
    return TRUE;
}
