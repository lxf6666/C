#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>
int cslen(sqcStack s)
{
    //printf("现在top指向%p,base的地址%p\n",s.top,s.base);
    return (s.top-s.base);
}

