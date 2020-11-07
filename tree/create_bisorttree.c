#include <stdio.h>
#include <stdlib.h>
#include<definetree.h>
void creat_bisorttree(BiTree *t,int num)
{
    int i,val;
    printf("请输入%d个数\n",num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&val);
        insert_bisorttree(t,val);
    }
}
