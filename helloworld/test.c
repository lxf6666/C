#include<stdio.h>
#define PI 3.14159
int main()
{
    int a,b,c,d,e,f,g;
    int x,h;
    double y;
    char str[]="ABC\0DEF";
    char s[]="asd";
    char *p="abcd";
    *p++;
    printf("p为%c\n",*p);
    printf("%s\n",str);
    h=10l;
    printf("%d\n",h<<=1);
    f=-2;
    g=1;
    printf("%d\n",f>g);
    y=x=1.5;
    printf("x:%d\ny:%f\n",x,y);
    puts("输入3个数");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    /*
    if(a>b)
        d=b;
    else
        d=a;
    if(d>c)
        d=c;
    else
        d=d;
    */
    putchar('awdjhksajdhkjash76876');
    printf("\na:%d\n",a);
    printf("b:%d\n",b);
    printf("c:%d\n",c);
    printf("min:%d\n",c>(a>b?b:a)?(a>b?b:a):c);

    /*
    scanf("%d",&d);
    if(d>0)
    {
        printf("d的绝对值是%d\n",d);
    }
    else
    {
        printf("d的绝对值是%d\n",-d);
    }*/

    printf("%d\n",a==b);
    printf("%d\n",c==b);
    printf("%d\n",a>b);
    printf("%d\n",b>a);
    printf("[%d]\n",123);
    printf("[%.4d]\n",23);
    printf("[%4d]\n",123);
    printf("[%04d]\n",123);
    printf("[%-4d]\n",123);
    return 0;
}
