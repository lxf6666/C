#include<stdio.h>
int main()
{
    int a,b;
    printf("please input two scores:a and b\n");
    scanf("%d",&a);
    scanf("%d",&b);
    if(a%b==0)
    {
        printf("b是a的约数");
    }
    else
    {
        printf("b不是a的约数");
    }

    return 0;
}
