#include <stdio.h>
#include <stdlib.h>
#include<defingraph.h>
void createMgraph(MGraph *g)
{
    int i;
    Edge E;
    printf("输入要创建图的边数\n");
    scanf("%d",&i);
    (*g)->Ne=i;
    if((*g)->Ne != 0)
    {
        E=(Edge)malloc(sizeof(ENode));
        for(i=0;i<(*g)->Ne;i++)
        {
            scanf("%d%d%d",&(E->v1),&(E->v2),&(E->Weight));
            insertEdge(&(*g),E);
        }
    }
    getchar();
    //读入顶点数据
    printf("输入%d个顶点信息\n",(*g)->Nv);
    for(i=0;i<(*g)->Nv;i++)
    {
        scanf("%c",&((*g)->vexs[i]));
        getchar();
    }

}
