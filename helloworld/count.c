#include<stdio.h>
int main()
{
    int a,b;
    puts("����һ����");
    scanf("%d",&a);
    b=2;
    while(b<a)
    {
        if(b%2==0)
        printf("%d ",b);
        b*=2;

    }
    return 0;
}

