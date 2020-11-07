#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>
void cpush(sqcStack *s,elemType e)
{
   // printf("e is %c\n",e);
    if( (s->top - s->base) >=  s->stacksize )
    {
        s->base = (elemType *)realloc(s->base,(s->stacksize + STACKINCREAMENT)*sizeof(elemType));
        if( !s->base )
            exit(0);
        s->top = s->base + s->stacksize;
        s->stacksize =s->stacksize+STACKINCREAMENT;
    }
    *(s->top)=e;
 //   printf("现在top指向%p,top身上的字符%c,base的地址%p\n",s->top,*(s->top),s->base);
    s->top++;
   // printf("现在top指向%p,top身上的字符%c,base的地址%p\n",s->top,*(s->top),s->base);


}
