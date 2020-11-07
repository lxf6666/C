#include<stdio.h>
int main()
{
    printf("请输入个数\n");
    int a,b,c,d;
    do{
        scanf("%d",&a);
        if(a<0)
            printf("请输入正整数\n");
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
    printf("%d的逆序数是%d\n%d的位数是%d",b,c,b,d);
    return 0;
}
