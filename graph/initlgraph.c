#include <stdio.h>
#include <stdlib.h>
#include<defingraph.h>
//初始化邻接表图
void initlgraph(LGraph *g,int n,char c)
{
    int i;
    *g=(LGraph)malloc(sizeof(gNode));
    (*g)->Nv=n;
    (*g)->Ne=0;
    (*g)->Direction=c;
    for(i=0;i<(*g)->Nv;i++)
    {
        (*g)->G[i].FirstEdge=NULL;
        (*g)->G[i].in=0;
    }
}


