#include<stdio.h>
unsigned inverse_n(unsigned x,int pos)
{
    unsigned h,s;
    s=1;
    h=x;
    if(pos>1)
        for(int i=1;i<pos;i++)
        s=2*s;
    else s=1;
    if((x>>=(pos-1))&1U)
    {
        puts("该位原本为1");
        h=h-s;
    }
    else h=h+s;
    return h;
}
int main()
{
    unsigned k;
    int z;
    puts("输入个数");
    scanf("%ld",&k);
    puts("取反第几位");
    scanf("%d",&z);
    printf("%d取反第%d之后的结果为%d",k,z,inverse_n(k,z));
    return 0;
}
