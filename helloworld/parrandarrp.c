#include<stdio.h>
int main()
{
    int *h[5]={0,1,2,3,4};
    char a[5]={'0','1','2','3','4'};
    char (*p)[5]=&a;
    printf("%s\n",(*p));
    int b[2]={0,1};
    printf("%d\n",*(b+1));
    return 0;

}
