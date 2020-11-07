#include<stdio.h>
int main(void)
{
    int n=550;
    int *p=&n;
    int **pp=&p;

    printf("n:%p\n*p:%p\n**p:%p\n",&n,p,*pp);
    printf("n:%d\n*p:%d\n**p:%d\n",n,*p,**pp);
}
