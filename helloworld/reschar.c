#include<stdio.h>
void put_rstring(char str[])
{
    int n=strlength(str)-1;
    while(n>=0)
    {
        putchar(str[n]);
        n--;
    }
}
void rev_string(char str[])
{
    int n=strlength(str)-1;
    for(int i=0;i<=n/2;i++)
    {
        char temp;
        temp=str[i];
        str[i]=str[n-i];
        str[n-i]=temp;
    }
    printf("\nÄæÐòºó\n\%s",str);
}
int strlength(char str[])
{
    int n=0;
    while(str[n])
        n++;
    return n;
}
int main(void)
{
    char str[100];
    scanf("%s",str);
    put_rstring(str);
    rev_string(str);
    return 0;
}
