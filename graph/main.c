#include <stdio.h>
#include <stdlib.h>
#include <defingraph.h>
#define maxsize 10

//求最短路径用到的辅助数组
typedef int Patharc[MaxVertexNum]; //存储最短路径下标的数组
typedef int shortPathTable[MaxVertexNum]; //用于存储到各点最短路径权值和

int Visited[MaxVertexNum]; //记录是否已经访问过
//kruskal用到的边集数组
typedef struct edgearr
{
    int begin;
    int end;
    int weight;
}Edgearr[MaxVertexNum];

//广度优先搜索用到的队列
typedef struct
{
    int data[maxsize];
    int front,rear;
}sqQueue;
void init_queue(sqQueue *q)
{
    int i;
    for(i=0;i<maxsize;i++)
        q->data[i]=0;
    q->front=q->rear=0;
}
void enqueue(sqQueue *q,int data)
{
    if((q->rear+1)%maxsize==q->front)
    {
        q->data[q->rear]=data;
        printf("队列已满\n");
    }
    else
    {
        q->data[q->rear]=data;
        q->rear=(q->rear+1)%maxsize;
    }

}
void dequeue(sqQueue *q,int *h)
{
    if(q->front==q->rear)
    {
        *h=q->data[q->front];
       // printf("队已经空");
    }
    *h=q->data[q->front];
    q->front=(q->front+1)%maxsize;
}


//邻接矩阵的深度优先搜索
//visit
void Visit(DataType d)
{
    printf("%c ",d);
}
void DFS( MGraph g,int i)
{
    int j;
    Visited[i]=1;
    Visit(g->vexs[i]);
    for(j=0;j<g->Nv;j++)
    {
        if( (g->G[i][j]!=0) && (g->G[i][j] != INFINITY)  && !Visited[j])
        {
            DFS(g,j);
        }
    }

}
//邻接矩阵广度BFS
void BFS(MGraph g)
{
    int i,j;
    sqQueue q;
    init_queue(&q);
    for(i=0;i<MaxVertexNum;i++)
    {
        Visited[i]=0;
    }
    for( i=0;i<g->Nv;i++)
    {
        if(!Visited[i])
        {
            Visited[i]=1;
            printf("%c ",g->vexs[i]);
            enqueue(&q,i);
            while(!(q.front==q.rear))
            {
                dequeue(&q,&i);
                for(j=0;j<g->Nv;j++)
                {
                    if( (g->G[i][j]!=0) && (g->G[i][j] != INFINITY) && !Visited[j])
                    {
                            Visited[j]=1;
                            printf("%c ",g->vexs[j]);
                            enqueue(&q,j);
                    }
                }
            }
        }
    }
}
//prim算法实现邻接矩阵生成最小生成树
void mintree_prim(MGraph g)
{
    int min,i,j,k;
    int adjvex[MaxVertexNum]; //保存相关下标 比如adjvex[2]=3为下标为2和下标为3的顶点相连
    int lowcost[MaxVertexNum]; //保存相关顶点权值

    lowcost[0]=0;
    adjvex[0]=0;

    for(i=1;i<g->Nv;i++)
    {
        lowcost[i]=g->G[0][i];//将0行所有权值加入lowcost
        adjvex[i]=0;

    }
    for( i=1;i<g->Nv;i++ )
    {
        min = INFINITY;
        j=1;
        k=0;
        //遍历所有结点
        while( j<g->Nv )
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;//将最小权值的下标存入k以待使用
            }
            j++;
        }
        //打印当前边中权最小的边
        printf("(%d,%d)",adjvex[k],k);
        lowcost[k]=0; //将发现的最小权值设为0表示完成任务，进行下个顶点遍历

        //邻接矩阵k行遍历寻找最小权值的边
        for( j=1;j<g->Nv;j++ )
        {
            if( lowcost[j]!=0 && g->G[k][j]<lowcost[j] )
            {
                lowcost[j]=g->G[k][j];
                adjvex[j]=k;
            }
        }
    }
}
//邻接矩阵图转化为边集数组
void vertoarr(MGraph g,Edgearr *a)
{
    int i,j,k;
    k=0;
    Edgearr temp;
    for(i=0;i<g->Nv;i++)
    {
         for(j=0;j<g->Nv;j++)
        {
            if(((g->G[i][j]) != INFINITY) && (j>i) )
            {
                a[k]->weight=g->G[i][j];
                a[k]->begin=i;
                a[k]->end=j;
                ++k;
            }

        }
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
             if((a[j]->weight) > (a[j+1]->weight))
             {
                temp->weight=a[j]->weight;
                temp->begin=a[j]->begin;
                temp->end=a[j]->end;
                a[j]->weight=a[j+1]->weight;
                a[j]->begin=a[j+1]->begin;
                a[j]->end=a[j+1]->end;
                a[j+1]->weight=temp->weight;
                a[j+1]->begin=temp->begin;
                a[j+1]->end=temp->end;
             }
        }

    }
}
//kruskal最小生成树
int Find(int *parent,int f)
{
    while( parent[f]>0 )
    {
        f = parent[f];
    }
    return f;
}
void mintree_kruskal(MGraph G,Edgearr *e)
{
    int i,n,m;
    int parent[MaxVertexNum];
    for(i=0;i<MaxVertexNum;i++)
    {
        parent[i]=0;
    }
    for(i=0;i<G->Ne;i++)
    {
        n = Find(parent,e[i]->begin);
        m = Find(parent,e[i]->end);

        if(n!=m)
        {
            parent[n]=m;
            printf("(%d,%d) %d  ",e[i]->begin,e[i]->end,e[i]->weight);
        }
    }

}
//Dijkstar生成最短路径
void ShortPath_Dijkstar(MGraph g,int v0,Patharc *P,shortPathTable *D)
{
    int v,w,k,min;
    int finals[MaxVertexNum]; //finals[w]=1表示已经求得顶点v0到vw最短路径
    //初始化
    for(v=0;v<g->Nv;v++)
    {
        finals[v]=0; //初始化未找到最短路径
        (*D)[v]=g->G[v0][v]; //将与v0相连得顶点得路径权值存入
        (*P)[v]=0; //初始化路径数组为0
    }
    (*D)[v0] = 0; //v0到v0为0
    finals[v0]=1; //v0到v0不需要求路径

    //开始循环,每次求v0到某个v得最短路径
    for(v=1;v<g->Nv;v++)
    {
        min=INFINITY;
        for(w=0;w<g->Nv;w++)
        {
            if(finals[w]!=1 && (*D)[w]<min )
            {
                min=(*D)[w];
                k=w;
            }
        }
        finals[k]=1;
        for(w=0;w<g->Nv;w++)
        {
            if(finals[w]!=1 && ((min+g->G[k][w])<(*D)[w]))
            {
                (*D)[w]=min+g->G[k][w];
                (*P)[w]=k;
            }
        }
    }
    //打印Dijkstar最小路径
    printf("Dijkstar求从%d出发得最短路径\n",v0);
    for(v=0;v<g->Nv;v++)
    {
       printf("%d->%d ",(*P)[v],v);
    }
}

//floyd最小路径
void print_path(int n,int path[][maxsize])
{
    int i,j;
    printf("\nfloyed最短路径\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if( path[i][j] != -1 )
            {
                printf("%d->%d->%d  ",i,path[i][j],j);
            }
        }
    }
}
void ShortPath_floyd(MGraph g)
{
    int i,j,k;
    MGraph D = g;
    int path[maxsize][maxsize];
    for(i=0;i<g->Nv;i++)
    {
        for(j=0;j<g->Nv;j++)
        {
            path[i][j]=-1;
        }

    }
    for(k=0;k<g->Nv;k++)
    {
        for(i=0;i<g->Nv;i++)
        {
            for(j=0;j<g->Nv;j++)
            {
                if( D->G[i][k]+D->G[k][j]<D->G[i][j] )
                {
                    D->G[i][j]=D->G[i][k]+D->G[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    print_path(g->Nv,path);

}



//邻接表 DFS
void lDFS(LGraph g,int i)
{
    Visit(g->G[i].Data);
    Visited[i]=1;
    PtrToAdjVNode tmp;
    for(tmp=g->G[i].FirstEdge;tmp;tmp=tmp->Next)
    {
        if( !Visited[tmp->Adjv] )
        {
          //  printf("\n下个点%d,这个点下标为%d\n",g->G[tmp->Adjv].Data,tmp->Adjv);
            lDFS(g,tmp->Adjv);
        }
    }

}
//邻接表BFS
void lBFS(LGraph g)
{
    int i;
    PtrToAdjVNode tmp;
    sqQueue q;
    init_queue(&q);
    for(i=0;i<MaxVertexNum;i++)
    {
        Visited[i]=0;
    }
    for(i=0;i<g->Nv;i++)
    {
        if(!Visited[i])
        {
            Visited[i]=1;
            printf("%c ",g->G[i].Data);
            enqueue(&q,i);
            while(q.front!=q.rear)
            {
                dequeue(&q,&i);
                tmp=g->G[i].FirstEdge;
                while(tmp!=NULL)
                {
                    if(!Visited[tmp->Adjv])
                    {
                        printf("%c ",g->G[tmp->Adjv].Data);
                        Visited[tmp->Adjv]=1;
                        enqueue(&q,tmp->Adjv);
                    }
                    tmp=tmp->Next;
                }

            }
        }

    }
}
//拓扑排序
void TopuSort(LGraph g)
{
    int i;
    int avitsed[maxsize];
    for(i=0;i<maxsize;i++)
    {
        avitsed[i]=-1;
    }
    LGraph tmp=g;
    sqQueue q;
    init_queue(&q);
    PtrToAdjVNode p;
    int flag=0;
    while( flag<g->Nv )
    {
        for( i=0;i<tmp->Nv;i++)
        {
        if( tmp->G[i].in == 0 )
        {
            if( avitsed[(tmp->G[i].Data)]!=1 )
            {
                enqueue(&q,tmp->G[i].Data);
                flag++;
                avitsed[tmp->G[i].Data]=1;
            }
            if(flag==g->Nv)
            {
                break;
            }
            for(p=tmp->G[i].FirstEdge;p!=NULL;p=p->Next)
            {
                tmp->G[p->Adjv].in=tmp->G[p->Adjv].in-1;
            }
        }
        }
    }

    printf("拓扑排序结果\n");
    while( q.rear != q.front )
    {
        dequeue(&q,&i);
        printf("%c ",i);
    }
        dequeue(&q,&i);
        printf("%c ",i);
}

int main()
{
    int n,i,j;
    char c;
    /*
    //邻接矩阵实现图测试
    MGraph g;

    printf("输入需要几个顶点的图,和是否需要方向\n");
    scanf("%d %c",&n,&c);
    getchar();
    initmgraph(n,c,&g);
    createMgraph(&g);
    printf("所创建图的情况\n   ");
    for(i=0;i<g->Nv;i++)
    printf("%c ",g->vexs[i]);
    printf("\n");
    for(i=0;i<g->Nv;i++)
    {
        printf("%c: ",g->vexs[i]);
        for(j=0;j<g->Nv;j++)
        {

            printf("%d ",g->G[i][j]);
        }
        printf("\n");
    }

    //DFS测试（邻接矩阵）
    printf("输入从哪个点开始\n");
    scanf("%d",&n);
    printf("DFS遍历结果\n");
    DFS(g,n);
    printf("\n");


    //BFS测试（邻接矩阵）
    printf("BFS遍历结果\n");
    BFS(g);
    printf("\n");

    //prim最小生成树测试
    printf("prim最小生成树\n");
    mintree_prim(g);

    //边集数组测试
    Edgearr a[MaxVertexNum];
    vertoarr(g,&a);
    printf("\n转化为的按权值排序的边集数组为\n");
    for(i=0;i<g->Ne;i++)
    {
        printf("%d->%d  weight:%d\n",a[i]->begin,a[i]->end,a[i]->weight);
    }
    //kruskal生成最小树
    printf("kruskal生成最小树的结果\n");
    mintree_kruskal(g,&a);
    //Dijkstar生成最短路径测试
    Patharc p;
    shortPathTable h;
    ShortPath_Dijkstar(g,0,&p,&h);
    //floyd最短路径测试输出
    ShortPath_floyd(g);
    */

    //邻接表实现图测试
    for(i=0;i<MaxVertexNum;i++)
        Visited[i]=0;
    LGraph lg;
    printf("输入需要几个顶点的图,和是否需要方向\n");
    scanf("%d %c",&n,&c);
    getchar();
    initlgraph(&lg,n,c);
    createlgraph(&lg);

    //邻接表DFS测试
    printf("输入从哪个点开始\n");
    scanf("%d",&n);
    printf("DFS遍历结果\n");
    lDFS(lg,n);
    printf("\n");
    printf("BFS遍历结果\n");
    lBFS(lg);
    //拓扑排序测试
    TopuSort(lg);

    return 0;
}
