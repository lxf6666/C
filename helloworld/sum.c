#include<stdio.h>
int main()
{
    int a,b,sum;
    puts("����������");
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
    printf("a��b֮�����е�����֮��Ϊ��%d\n",sum+b);
    return 0;
}
