#include <stdio.h>
#include <stdlib.h>
#include<defiStaticLinkedList.h>

int main()
{
    int i,n,h,k;
    StaticLinkList aL;
    init(aL);
    puts("想创建几个数据的表");
    scanf("%d",&n);
    create(aL,n);
    i=1;
    while(i)
    {
        if(i)
        printf("第%d个数为%d\n",i,aL[i].data);
        else
        printf("第%d个数为%d\n",n,aL[i].data);
        i=aL[i].cur;
    }
    puts("请输入要插入的位置和数据");
    scanf("%d%d",&n,&h);
    insert(aL,n,h);

    i=1;
    k=1;
    while(i)
    {
        if(i)
        printf("第%d个数为%d\n",k,aL[i].data);
        i=aL[i].cur;
        k++;
    }
    puts("请输入要删除的数据的位置");
    scanf("%d",&n);
    deletenode(aL,n);
    i=1;
    k=1;
    while(i)
    {
        if(i)
        printf("第%d个数为%d\n",k,aL[i].data);
        i=aL[i].cur;
        k++;
    }
    return 0;
}
