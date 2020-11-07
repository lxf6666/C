#include<stdio.h>
int main()
{
    int a;
    puts("输入金字塔层数");
    scanf("%d",&a);
    printf("金字塔的层数为%d\n",a);
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
