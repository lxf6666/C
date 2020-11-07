#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>

void cpop(sqcStack *s,elemType *e)
{
    if( s->base == s->top )
        printf("已经是空栈");
    *e = *(--s->top);
}
