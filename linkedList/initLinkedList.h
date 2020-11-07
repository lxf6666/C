#define OK 1
#define FALSE 0
typedef int EleType;
typedef struct Node
{
    EleType data; //数据域
    struct Node *Next; //指针域
} Node;
typedef struct Node* LinkList;
