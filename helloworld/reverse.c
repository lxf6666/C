#include<stdio.h>
int main()
{
    int b;
    scanf("%d",&b);
    int a[b];
    int temp;
    for(int i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
        printf("%d\n",a[i]);
    }
    for(int i=0;i<(b/2);i++)
    {
        temp=a[i];
        a[i]=a[b-1-i];
        a[b-1-i]=temp;
    }
    for(int i=0;i<b;i++)
        printf("%d\n",a[i]);
    return 0;
}
