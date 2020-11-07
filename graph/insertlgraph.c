#include <stdio.h>
#include <stdlib.h>
#include<defingraph.h>
void insertlgraphEdge(LGraph *g,Edge e)
{
    PtrToAdjVNode NewNode;
    NewNode=(PtrToAdjVNode)malloc(sizeof(AdjVNode));
    NewNode->Adjv=e->v2;
    NewNode->wegiht=e->Weight;
    NewNode->Next=((*g)->G[e->v1]).FirstEdge;
    (*g)->G[e->v1].FirstEdge = NewNode;
    (*g)->G[e->v2].in=((*g)->G[e->v2]).in+1;
    if((*g)->Direction == 'n')
    {
        PtrToAdjVNode NewNode2;
        NewNode2=(PtrToAdjVNode)malloc(sizeof(AdjVNode));
        NewNode2->Adjv=e->v1;
        NewNode2->wegiht=e->Weight;
        NewNode2->Next=((*g)->G[e->v2]).FirstEdge;
        ((*g)->G[e->v2]).FirstEdge = NewNode2;
        ((*g)->G[e->v1]).in=((*g)->G[e->v1]).in+1;
    }
}
