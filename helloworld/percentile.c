#include<stdio.h>
int main()
{
    int a,b,r;
    printf("Please input two scores:a and b");
    scanf("%d",&a);
    scanf("%d",&b);
    r=(100*a)/b;
    printf("%dÊÇ%dµÄ%d%%:",a,b,r);
    return 0;
}
