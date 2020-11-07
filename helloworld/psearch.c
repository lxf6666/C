#include<stdio.h>
char *str_chr(const char *str,int c)
{
    int ok=1;
    char *r=str;
    char b=(char)c+'0';
    while(*r&&ok)
    {
        if(*r==b)
        {
            ok=0;
        }
        else *r++;
    }
    if(ok==0)
    {
        return r;
    }
    else return NULL;

}
int char_num(const char *str,int c)
{
    char *r=str;
    char b=(char)c+'0';
    int n=0;
    while(*r)
    {
        if(*r==b)
        {
            n++;
            *r++;
        }
        else *r++;
    }
    return n;
}
void del_dig(char *str)
{
    puts("新字符：");
    char *r=str;
    while(*r)
    {
        if(*r>'0'&&*r<'9') ;
        else putchar(*r);
        *r++;
    }
}
int main()
{
    const char str[100];
    int c;
    puts("请输入一串字符，和你想查找的字符");
    scanf("%s%d",str,&c);
    printf("返回的指针%p\n",str_chr(str,c));
    printf("这个字符出现次数%d\n",char_num(str,c));
    puts("请输入一串字符");
    char s[100];
    scanf("%s",s);
    del_dig(s);
    return 0;
}
