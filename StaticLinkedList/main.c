#include <stdio.h>
#include <stdlib.h>
#include<defiStaticLinkedList.h>

int main()
{
    int i,n,h,k;
    StaticLinkList aL;
    init(aL);
    puts("�봴���������ݵı�");
    scanf("%d",&n);
    create(aL,n);
    i=1;
    while(i)
    {
        if(i)
        printf("��%d����Ϊ%d\n",i,aL[i].data);
        else
        printf("��%d����Ϊ%d\n",n,aL[i].data);
        i=aL[i].cur;
    }
    puts("������Ҫ�����λ�ú�����");
    scanf("%d%d",&n,&h);
    insert(aL,n,h);

    i=1;
    k=1;
    while(i)
    {
        if(i)
        printf("��%d����Ϊ%d\n",k,aL[i].data);
        i=aL[i].cur;
        k++;
    }
    puts("������Ҫɾ�������ݵ�λ��");
    scanf("%d",&n);
    deletenode(aL,n);
    i=1;
    k=1;
    while(i)
    {
        if(i)
        printf("��%d����Ϊ%d\n",k,aL[i].data);
        i=aL[i].cur;
        k++;
    }
    return 0;
}
