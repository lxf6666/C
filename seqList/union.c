#include<stdio.h>
#include<initList.h>
void unionL(SqList *La, SqList Lb)
{
    int La_length,Lb_length,i;
    ElemType e;

    La_length = La->length;
    Lb_length = Lb.length;

    for(i=1;i<=Lb_length;i++)
    {
        GetElem(Lb,i,&e);
        if(!LocateElem(*La,e))
        {
            ListInsert(La,++La_length,e);
        }
    }
    La->length=La_length;



}
