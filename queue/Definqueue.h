#define OK 1
#define ERROR 0
#define MAXSIZE 10
typedef char ElemType;
typedef int elemType;
//链队
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePrt;
typedef struct
{
    QueuePrt qfront,rear;//队头，队尾指针
}LinkQueue;
//循环队列 （数组实现）
typedef struct
{
    elemType *base;
    int qfront;
    int rear;
}cycleQueue;
