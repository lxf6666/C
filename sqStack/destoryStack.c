#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>
void destory(sqStack *s)
{
    free( s->base );
    s->base=s->top=NULL;
    s->stacksize=0;
    if(!s->base)
        printf("栈销毁成功");
}
