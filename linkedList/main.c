#include <stdio.h>
#include <stdlib.h>
#include <initLinkedList.h>

int main()
{
    int n,h;
    h=0;
    LinkList aL = NULL;
    LinkList bL = NULL;
    /*insertback(&aL);
    insertList(&aL);
    insertback(&aL);
    insertback(&aL);
    insertback(&aL);
    puts("输入要插入的数");
    scanf("%d",&n);
    seqinsert(&aL,n);
    puts("输入要插入的数");
    scanf("%d",&n);
    seqinsert(&aL,n);
    puts("输入要插入的数");
    scanf("%d",&n);
    seqinsert(&aL,n);
    printfList(aL);
   // realseList(&aL);
    puts("请输入要搜索的链表的数的位置");
    scanf("%d",&n);
    printf("要查找链表的%d位置\n",n);
    GetElem(aL,n,&h);
    printf("这个数在链表的%d位置的值是%d\n",n,h);
    puts("请输入要删除的数");
    scanf("%d",&n);
    deleteNode(&aL,n);
    printfList(aL);*/
    printf("输入初始化要加入几个数据\n");
    scanf("%d",&n);
    scyc_init(&aL,n);
    cycprintf(aL);
    /*
    printf("输入在表什么位置插入值\n");
    scanf("%d",&n);
    cycinsert(&aL,n);
    cycprintf(aL);
    printf("输入要删除什么位置的值\n");
    scanf("%d",&n);
    cycdelete(&aL,n);
    cycprintf(aL);
    printf("输入要查找什么值的位置\n");
    scanf("%d",&n);
    h=cycsearch(aL,n);
    printf("这个值在表第%d个\n",h);
    */
    LinkList aLrear;
    aLrear=rear(&aL);

    printf("输入初始化要加入几个数据\n");
    scanf("%d",&n);
    scyc_init(&bL,n);
    cycprintf(bL);
    LinkList bLrear;
    bLrear=rear(&bL);
    LinkList conLrear;
    conLrear=connect(aLrear,bLrear);
    cycprintf(conLrear->Next);
    //printf("aL尾部的值：%d\n",aLrear->data);



   // realseList(&aL);

    return 0;
}
