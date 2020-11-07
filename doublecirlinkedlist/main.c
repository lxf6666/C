#include <stdio.h>
#include <stdlib.h>
#include<defindoublelinklist.h>

int main()
{
    int n,h;
    DLNode *L=NULL;
    init(&L);
    create(&L);
    printfDLlist(L);
    printf("输入要插入表的什么位置，要插入的数\n");
    scanf("%d%d",&n,&h);
    insert(&L,n,h);
    printfDLlist(L);
    printf("输入要删除表的什么位置的数\n");
    scanf("%d",&n);
    Deletenode(&L,n);
    printfDLlist(L);
    return 0;
}
