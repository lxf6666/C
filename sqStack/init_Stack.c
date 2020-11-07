#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>

void init_Stack(sqStack *s)
{
    s->base = (ElemType *)malloc(Stack_init_size*sizeof(ElemType));
    if(!s->base)
        exit(0);
    s->top = s->base;
    s->stacksize = Stack_init_size;
}
