#define OK 1
#define ERROR 0
#define Stack_init_size 20
#define STACKINCREAMENT 10
typedef double ElemType;
typedef char elemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;

typedef struct
{
    elemType *base;
    elemType *top;
    int stacksize;
}sqcStack;
