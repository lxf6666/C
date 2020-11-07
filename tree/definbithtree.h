//线索存储标志 Link（0）表示指向左右孩子的指针 Thread（1）表示指向双驱后继的线索
typedef char elemType;
typedef enum{Link,Thread} PointerTag;
typedef struct BiThNode
{
    elemType data;
    struct BiThNode *lchild,*rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThNode,*Bithtree;

