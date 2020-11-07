#define MAX_TREE_SIZE 100

typedef int ElemType;

//孩子双亲表示法
//孩子结点
/*
typedef struct CTNode
{
    int child;  //孩子结点的下标
    struct CTNode *next;  //指向下个孩子结点的指针
} *Childptr;

//表头
typedef struct
{
    ElemType data;  //存放再树中结点的数据
    int parent;  //存放双亲的下标
    Childptr firstChild;  //指向第一个孩子的指针
} CTBox;

//树结构
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];  //结点数组
    int r,n;
}
*/

//二叉树
typedef struct BiTNode
{
    ElemType data;  //数据域
    struct BiTNode *lchild,*rchild;  //指针域
}BiTNode, *BiTree;
