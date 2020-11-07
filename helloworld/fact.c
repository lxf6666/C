#include<stdio.h>
long fact(int n)
{
    long s;
    s=1;
    for(int i=1;i<=n;i++)
        s*=i;
    return s;
}
long nfact(int n,long s)
{
    s*=n;
    n--;
    return (n<1?s:nfact(n,s));
}
int combinate(int x,int y)
{
    int s;
    s=1;
    return nfact(x,s)/(nfact(y,s)*nfact(x-y,s));
}
int main(void)
{
   /* int n;
    long s;
    s=1;
    puts("请输入一个数");
    scanf("%d",&n);
    printf("这个数的阶乘为：%d\n%d\n",fact(n),nfact(n,s));*/
    int x,y;
    puts("输入两个数");
    scanf("%d%d",&x,&y);
   /* while((x<y)||(x<0)||(y<0))
    {
        puts("请输入正确的两个数");
        scanf("%d",x);
        scanf("%d",y);
    }
    */
    int h=combinate(x,y);
    printf("这两个数的组合数为%d\n",h);
    return 0;
}
