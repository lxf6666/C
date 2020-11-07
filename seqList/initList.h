#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define Maxsize 20
typedef int ElemType;
typedef struct
{
    ElemType data[Maxsize]; //最大长度
    int length;  //当前表长
} SqList;
