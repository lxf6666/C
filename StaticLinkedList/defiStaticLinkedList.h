#define OK 1
#define FALSE 0
#define MAXSIZE 10
typedef int ElemType;
typedef struct
{
    ElemType data;  //数据
    int cur;  //游标
} Component, StaticLinkList[MAXSIZE];
