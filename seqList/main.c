#include <stdio.h>
#include <stdlib.h>
#include<initList.h>
int main()
{
    int i=3;
    int j;
    int h=0;
   // int *e;
    SqList La,Lb;
    printf("La�Ƿ�Ϊ��%d,Lb�Ƿ�Ϊ��%d\n",isEmpty(La),isEmpty(Lb));
    clear(&La);
    clear(&Lb);
    printf("La�Ƿ�Ϊ��%d,Lb�Ƿ�Ϊ��%d\n",isEmpty(La),isEmpty(Lb));

    for(j=0;j<5;j++)
        La.data[j]=2;
    ListLength(&La);
    for(j=0;j<5;j++)
        Lb.data[j]=3;
    ListLength(&Lb);

    printf("�ڱ�La%d��λ���ǣ�%d,��Lb��%dֵ��λ���ǣ�%d\n",i,LocateElem(La,i),i,LocateElem(Lb,i));
    ListInsert(&La,3,33);
    GetElem(La,3,&h);
    printf("now table La's third is %d, length is %d\n",h,La.length);
    h=99;
    printf("now h is %d\n",h);
    printf("now table La's third is %d, length is %d\n",h,La.length);
    deleteList(&La,3);
    GetElem(La,3,&h);
    printf("now table La's third is %d, length is %d\n",h,La.length);
    unionL(&La,Lb);
    for(j=0;j<La.length;j++)
        printf("La[%d]:%d\n",j+1,La.data[j]);



    return 0;
}
