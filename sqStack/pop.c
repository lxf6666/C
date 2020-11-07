#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>
void pop(sqStack *s,ElemType *e)
{
    if( s->base == s->top )
        printf("已经是空栈");
    *e = *(--s->top);
}
