#include<stdio.h>
int main()
{
    int a,b;
    printf("please input two scores:a and b\n");
    scanf("%d",&a);
    scanf("%d",&b);
    if(a%b==0)
    {
        printf("b��a��Լ��");
    }
    else
    {
        printf("b����a��Լ��");
    }

    return 0;
}
