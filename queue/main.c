#include <stdio.h>
#include <stdlib.h>
#include<Definqueue.h>

int main()
{
    LinkQueue q;
    que_init(&q);
    char c,s;
    printf("输入一串字符以#结束\n");
    scanf(" %c",&c);
    while('#'!=c)
    {
        q_insert(&q,c);
        scanf(" %c",&c);
    }
    printf("\n");
    printf("输入的字符串是\n");
    while( q.qfront->next )
    {
        q_dequeue(&q,&s);
        printf("%c",s);
    }


    return 0;
}
