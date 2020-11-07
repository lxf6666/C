#define OK 1
#define FALSE 0

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *pre;
    struct Node *next;
}DLNode;
