#include<stdio.h>
int main()
{
    int a,n;
    puts("请输入一个整数a，我会将小于等于这个数的质数全都列举出来");
    scanf("%d",&a);
    n=0;  /*已经得到质数个数*/
    int p[a];
    unsigned long long counter=0; /*乘法和除法运算次数*/
    if(a<2)
    {
        puts("比你输入的数还小的质数不存在");
    }
    else if(a==3||a==4)
    {
        p[n++]=2;
        p[n++]=3;
        printf("小于等于%d的质数有：\n%d\n%d\n",a,p[0],p[1]);
    }
    else if(a==2)
    {
       p[n++]=2;
       printf("小于等于%d的质数有：\n%d\n",a,p[0]);
    }
    else if(a>=5)
    {
    p[n++]=2;
    p[n++]=3;
            for(int i=5;i<=a;i+=2)
            {
                int ctr=0;
                for(int j=1;counter++,p[j]*p[j]<=i;j++)
                {
                    counter++;
                    if(i%p[j]==0)
                    {
                        ctr=1;
                        break;
                    }
                }
                if(!ctr)
                {
                    p[n++]=i;
                }
            }
     printf("小于等于%d的质数有：\n",a);
    for(int h=0;h<n;h++)
    {
        printf("%d\n",p[h]);
    }
     printf("总共有%d个，计算次数为%ld",n,counter);
    }
    else puts("请输入正数");

    return 0;
}
