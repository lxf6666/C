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
        puts("��λԭ��Ϊ1");
        h=h-s;
    }
    else h=h+s;
    return h;
}
int main()
{
    unsigned k;
    int z;
    puts("�������");
    scanf("%ld",&k);
    puts("ȡ���ڼ�λ");
    scanf("%d",&z);
    printf("%dȡ����%d֮��Ľ��Ϊ%d",k,z,inverse_n(k,z));
    return 0;
}
