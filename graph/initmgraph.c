#include <stdio.h>
#include <stdlib.h>
#include <defingraph.h>
void initmgraph(int VertexNum,char dir,MGraph *g)
{
    Vertax V,M;
    *g = (MGraph)malloc(sizeof(GNode));
    (*g)->Nv=VertexNum;
    (*g)->Ne=0;
    (*g)->Direction=dir;
   // printf("这是%c\n",(*g)->Direction);
    for(V=0;V<(*g)->Nv;V++)
    {
        for(M=0;M<(*g)->Nv;M++)
            if(M==V)
            {
                (*g)->G[V][M]=0;
            }
            else
                (*g)->G[V][M]=INFINITY;
    }

}
