#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int n)
{
    Node *p=NULL; //指向当前节点
    Node *head;
    head=(Node *)malloc(sizeof(Node));
    p=head;
    Node *s;
    int i=1;

    if(n!=0)
    {
        while(i<=n)
        {
            s=(Node *)malloc(sizeof(Node));
            s->data=i++;
            p->next=s;
            p=s;
        }
        s->next=head->next;
    }
    free(head);
    return s->next;
}

int main()
{
    int i;
    int n,m;
    printf("输入玩游戏的人数");
    scanf("%d",&n);
    Node *temp,*h;
    Node *L=create(n);
    /*for(i=1;h->next!=L;h=h->next,i++)
    printf("第%d个数%d\n",i,h->data);
    printf("第%d个数%d\n",i,h->data);
    */

    printf("开始人选择上限");
    scanf("%d",&m);


    while(L != L->next)
    {
        m = m%n;
        if(m==1)
        {
            printf("%d->",L->data);
            temp=L;
            for(;L->next!=temp;L=L->next,i++);
            L->next=temp->next;
            free(temp);
            L=L->next;
        }
        else
        {
        for(i=1;i<m-1;i++)
        {
            L=L->next;
        }
        printf("%d->",L->next->data);
        temp=L->next;
        L->next=temp->next;
        free(temp);
        L=L->next;
        }
        printf("出局人选择上限");
        scanf("%d",&m);
        --n;


    }
    printf("%d\n",L->data);

    return 0;
}
