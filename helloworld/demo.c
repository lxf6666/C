#include<stdio.h>
int main()
{
    int a,b,c;
    b=0;
    puts("����һ����");
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        if(b<10)
        {
            printf("%d",b);
            b++;
        }
        else
        {
            b=0;
        }
    }
    return 0;
}
