#include<stdio.h>
int main()
{
    int a;
    puts("�������������");
    scanf("%d",&a);
    printf("�������Ĳ���Ϊ%d\n",a);
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=(2*a-(2*i-1))/2;j++)
            putchar(' ');
        for(int j=1;j<=2*i-1;j++)
            putchar('*');
        for(int j=1;j<=(2*a-(2*i-1));j++)
            putchar(' ');
        putchar('\n');
    }

    return 0;
}
