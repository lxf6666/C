#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>

void push(sqStack *s,ElemType e)
{
    if( (s->top - s->base) >=  s->stacksize )
    {
        s->base = (ElemType *)realloc(s->base,(s->stacksize + STACKINCREAMENT)*sizeof(ElemType));
        if( !s->base )
            exit(0);
        s->top = s->base + s->stacksize;
        s->stacksize =s->stacksize+STACKINCREAMENT;
    }
    *(s->top)=e;
    s->top++;


}
