#include <stdio.h>
#include <stdlib.h>
#include<defindoublelinklist.h>
void printfDLlist(DLNode *L)
{
    int i;
    DLNode *temp=L->next;
    for(i=1;temp->next!=L->next;temp=temp->next,i++)
        printf("第%d位置的数是%d\n",i,temp->data);
    printf("第%d位置的数是%d\n",i,temp->data);
}
