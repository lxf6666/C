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
    puts("���ַ���");
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
    puts("������һ���ַ�����������ҵ��ַ�");
    scanf("%s%d",str,&c);
    printf("���ص�ָ��%p\n",str_chr(str,c));
    printf("����ַ����ִ���%d\n",char_num(str,c));
    puts("������һ���ַ�");
    char s[100];
    scanf("%s",s);
    del_dig(s);
    return 0;
}
