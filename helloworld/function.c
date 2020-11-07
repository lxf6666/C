#include<stdio.h>
int minoftwonum(int x,int y)
{
    return x>y?y:x;
}
int minof3num(int x,int y,int z)
{
    return z>(x>y?y:x)?(x>y?y:x):z;
}
void hello(void)
{
    puts("hello");
}
int main(void)
{
    int a,b,c;
    a=5;
    b=3;
    c=7;
    printf("%d\n",minoftwonum(a,b));
    printf("%d\n",minof3num(a,b,c));
    hello();
    return 0;
}
