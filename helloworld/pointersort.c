#include<stdio.h>
void sort3(int *n1, int *n2, int *n3)
{
    while(!((*n1<*n2)&&(*n2<*n3)))
    {
    if(*n1>*n2) swap(n1,n2);
    if(*n2>*n3) swap(n2,n3);
    if(*n1>*n3) swap(n1,n3);
    }
}
void swap(int *n1, int *n2)
{
    int temp;
    temp=*n1;
    *n1=*n2;
    *n2=temp;
}
int main(void)
{
    int a,b,c;
    puts("输入三个数");
    scanf("%d%d%d",&a,&b,&c);
    sort3(&a,&b,&c);
    printf("这三个数的升序排列为%d %d %d",a,b,c);
    return 0;
}
