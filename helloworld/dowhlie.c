#include<stdio.h>
int main()
{
    printf("���������\n");
    int a,b,c,d;
    do{
        scanf("%d",&a);
        if(a<0)
            printf("������������\n");
    }while(a<0);
    b=a;
    c=0;
    d=0;
    do{
        if(a>0)
        {
            c=c*10+(a%10);
            d++;
        }
        a=a/10;
    }while(a>0);
    printf("%d����������%d\n%d��λ����%d",b,c,b,d);
    return 0;
}
