#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>
void clear(sqStack *s)
{
    s->top = s->base;
}
