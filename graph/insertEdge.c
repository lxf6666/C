#include <stdio.h>
#include <stdlib.h>
#include<defingraph.h>
void insertEdge(MGraph *g,Edge e)
{
   // printf("这是%c\n",(*g)->Direction);
    if( (*g)->Direction == 'y' )
    {
        (*g)->G[e->v1][e->v2]=e->Weight;
       // printf("%d\n",(*g)->G[e->v1][e->v2]);
    }
    if((*g)->Direction == 'n' )
    {
        (*g)->G[e->v1][e->v2]=e->Weight;
        (*g)->G[e->v2][e->v1]=e->Weight;
    }
}
