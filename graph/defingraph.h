#define MaxVertexNum 10
#define INFINITY 111
typedef int WeightType;  //边
typedef char DataType;   //顶点
typedef int  Vertax;  //顶点下标表示顶点

//邻接矩阵生成图
typedef struct GNode
{
    int Nv;  //顶点数
    int Ne;  //边数
    char Direction; //是否有方向
    WeightType G[MaxVertexNum][MaxVertexNum];  //存放边
    DataType vexs[MaxVertexNum];  //存放顶点
}GNode,*MGraph;
typedef struct ENode
{
    Vertax v1,v2;
    WeightType Weight;
}ENode,*Edge;

//邻接表生成图
//边表结点
typedef struct AdjVNode
{
    Vertax Adjv; //邻接点下标
    WeightType wegiht;//边权重
    struct AdjVNode *Next;//链域
}AdjVNode,*PtrToAdjVNode;
//头结点
typedef struct Vnode
{
    int in;
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];
//图结点
typedef struct gNode
{
    char Direction; //是否有方向
    int Nv;  //顶点数
    int Ne;  //边数
    AdjList G;
}gNode,*LGraph;
