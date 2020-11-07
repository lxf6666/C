#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>

int main()
{
    /*int n,i,ss;
    double value;
    int e;
    sqStack s;
    init_Stack(&s);
    printf("要加入几个元素");
    scanf("%d",&n);
   for(i=1;i<=n;i++)
    {
        scanf("%lf",&value);
        push(&s,value);
    }
    printf("当前栈容量%d\n",currentsize(s));
    destory(&s);

    for(i=1;i<=n-1;i++)
    {
        s.top--;
        printf("栈的第%d个数是%d\n",i,*(s.top));
    }
    pop(&s,&e);
    printf("%d",e);
    ss=BinarytoDecimal(s);
    printf("转化结果:%d",ss);*/
    char str[100];
    sqcStack s;
    char c,h;
    char e[100];
    int i=0;
    initc_Stack(&s);
    printf("输入要计算的表达式,#结束\n");
    scanf(" %c",&c);
    while( c != '#')
    {

        while( c>='0' && c<='9')
        {
            printf("%c",c);
            e[i++]=c;
            e[i]='\0';
            scanf("%c",&c);
            if(c<'0' || c>'9')
            {
                e[i++]=' ';
                e[i]='\0';
                printf(" ");
            }
        }
        if( ')' == c )
        {
            cpop(&s,&h);
            while( '('!= h)
            {
                printf("%c ",h);
                e[i++]=h;
                e[i++]=' ';
                e[i]='\0';
                cpop(&s,&h);
            }
        }
        else if( '+' == c || '-' == c)
        {

            if(!cslen(s))
            {
                cpush(&s,c);
               // printf("栈内现在有%d\n",cslen(s));
            }
            else
            {
                do
                {
                    cpop(&s,&h);
                    if('(' == h )
                    {
                        cpush(&s,h);
                    }
                    else
                    {
                        printf("%c ",h);
                        e[i++]=h;
                        e[i++]=' ';
                        e[i]='\0';
                    }
                }while( cslen(s) && '('!=h );
            cpush(&s,c);
            }

        }
        else if( '(' == c ||  '*' == c || '/'== c )
        {
            cpush(&s,c);
        }
        else if( '#' == c )
        {
            break;
        }
        else
        {
            printf("用户输入错误\n");
        }
        scanf("%c",&c);
    }
  //  printf("栈内现在有%d\n",cslen(s));
    while(cslen(s))
    {
        cpop(&s,&h);
        printf("%c ",h);
        e[i++]=h;
        e[i++]=' ';
        e[i]='\0';
    }

        printf("转换后保存的串%s\n",e);


    //逆波兰
    int j=0;
    double temp,r;

    sqStack aS;
    init_Stack(&aS);
    //printf("表可有size:%d\n",aS.stacksize);

    char b;


    e[i++]='#';
    e[i]='\0';
    int m=0;
    b=e[m];
    while(b != '#')
    {
        while( isdigit(b) || b == '.')
        {
            str[j++]=b;
            str[j]='\0';
            if( j>=10 )
            {
                printf("输入单个数据过大计算结果溢出");
                return -1;
            }
            b=e[++m];
            if( b == ' ' )
            {
                temp = atof(str);
                push(&aS,temp);
                j=0;
            }
        }
        switch(b)
        {
            case '+':
                pop(&aS,&temp);
                pop(&aS,&r);
                push(&aS,r+temp);
                break;
            case '-':
                pop(&aS,&temp);
                pop(&aS,&r);
                push(&aS,r-temp);
                break;
            case '*':
                pop(&aS,&temp);
                pop(&aS,&r);
                push(&aS,temp*r);
                break;
            case '/':
                pop(&aS,&temp);
                pop(&aS,&r);
                if( temp!=0 )
                    push(&aS,r/temp);
                else
                {
                    printf("除数不能为0");
                    return -1;
                }

                break;
        }
        b=e[++m];
    }
    pop(&aS,&r);
    printf("计算的结果是%f\n",r);

    return 0;
}
