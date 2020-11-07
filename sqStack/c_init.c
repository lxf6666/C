#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>

void initc_Stack(sqcStack *s)
{
    s->base = (elemType *)malloc(Stack_init_size*sizeof(elemType));
    if(!s->base)
        exit(0);
    s->top = s->base;
    s->stacksize = Stack_init_size;
}

