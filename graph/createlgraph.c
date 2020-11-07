#include <stdio.h>
#include <stdlib.h>
#include<defingraph.h>
void createlgraph(LGraph *g)
{
    int i;
    Edge e;
    printf("输入几条边\n");
    scanf("%d",&((*g)->Ne));
    if((*g)->Ne!=0)
    {
        e=(Edge)malloc(sizeof(ENode));
        for(i=0;i<(*g)->Ne;i++)
        {
            scanf("%d %d %d",&e->v1,&e->v2,&e->Weight);
            insertlgraphEdge(&(*g),e);
        }
    }
    getchar();
    //读入顶点数据
    printf("输入%d个顶点信息\n",(*g)->Nv);
    for(i=0;i<(*g)->Nv;i++)
    {
        scanf("%c",&(((*g)->G[i]).Data));
        getchar();
    }

}
