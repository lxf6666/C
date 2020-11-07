#include<stdio.h>
int main()
{
    int a,b,sum;
    puts("输入两个数");
    scanf("%d",&a);
    scanf("%d",&b);
    sum=0;
    do{
        if(a<b)
        {
            sum+=a;
            a++;
        }
    }while(a<b);
    printf("a到b之间所有的整数之和为：%d\n",sum+b);
    return 0;
}
