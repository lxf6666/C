#include<stdio.h>
int str_char(const char str[], int c)
{
    int n=0;
    int s=0;
    int k,b;
    b=0;
    while(str[n]&&b==0)
    {
        k=(int)(str[n]-'0');
        if(k==c)
        {
            s=n;
            b++;
        }
        else s=s;
        n++;
    }
    if(s!=0||b) return s;
    else return -1;
}
int str_num(const char str[], int c)
{
    int n=0;
    int k,b;
    b=0;
    while(str[n])
    {
        k=(int)(str[n]-'0');
        if(k==c)
        {
            b++;
        }
        else b=b;
        n++;
    }
    return b;
}
int main(void)
{
    const char str[100];
    int c;
    puts("请输入一串字符，和你想查找的字符");
    scanf("%s%d",str,&c);
    printf("你要查找的字符在%s的第%d个\n",str,str_char(str,c));
    printf("你查得字符在%s中有%d个",str,str_num(str,c));
    return 0;
}
