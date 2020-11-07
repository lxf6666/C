#include <stdio.h>
#include <stdlib.h>
#include <initLinkedList.h>

LinkList connect(LinkList La,LinkList Lb)
{
    LinkList savehead=La->Next; //保存表A的头
    LinkList bone=Lb->Next; //保存表B第一个
    La->Next=bone;
    //free(Lb->Next);
    Lb->Next=savehead;
    return Lb;
}
