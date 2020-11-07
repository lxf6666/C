#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define init_size 10
#define increamentsize 10
typedef char ElemType;
typedef struct
{
    ElemType *top;
    ElemType *base;
    int stacksize;
}sqstack;
void s_init(sqstack *s)
{
    s->base=(ElemType *)malloc(s->stacksize*sizeof(ElemType));
    if( s->base == NULL )
        printf("内存分配失败");
    s->top=s->base;
    s->stacksize=init_size;
}
int getlen(sqstack s)
{
    return (s.top-s.base);
}
void s_push(sqstack *s,ElemType e)
{
    if( (s->top - s->base) >= s->stacksize )
    {
        s->base=(ElemType *)realloc(s->base,(s->stacksize+increamentsize)*sizeof(ElemType));
        if(!s->base)
            printf("内存分配失败");
        s->top=s->base + s->stacksize;
        s->stacksize=s->stacksize+increamentsize;
    }
    *(s->top)=e;
    s->top++;
}
void s_pop(sqstack *s,ElemType *e)
{
    if( s->top == s->base)
        printf("栈已空");
    *e=*(--s->top);
}


int main()
{
    int t=1;
    char e;
    char c[100];
    char *p;
    p=c;
    sqstack s;
    s_init(&s);
    printf("输入要检测的括号\n");
    scanf("%s",c);

    while( *p != '\0' )
    {
        if( *p == '(' || *p== '[' || *p== '{')
        {
            s_push(&s,*p);
        }
        else if( *p == ')')
        {
            s_pop(&s,&e);
            if( e != '(')
                {
                    t=0;
                    break;
                }
        }
        else if( *p==']' )
        {
            s_pop(&s,&e);
            if( e != '[')
                {
                    t=0;
                    break;
                }
        }
        else if( *p=='}')
        {
            s_pop(&s,&e);
            if( e != '{')
                {
                    t=0;
                    break;
                }
        }
        p++;
    }
    if(t)
    {
        printf("输入的括号格式正确");
    }
    else
    {
        printf("输入的括号格式不对");
    }



    return 0;
}
