#include<stdio.h>
int main()
{
    int a,b;
    puts("����һ����");
    scanf("%d",&a);
    b=2;
    while(b<a)
    {
        printf("%d ",b);
        b+=2;
    }
    return 0;
}
