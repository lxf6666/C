#include<stdio.h>
void del_digit(char str[])
{
    puts("新串为");
    for(int i=0;str[i]!=NULL;i++)
    {
        if(((str[i]>='a')&&(str[i]<='z'))||((str[i]>='A')&&(str[i]<='Z')))
        {
            putchar(str[i]);
        }
    }
}
int main(void)
{
    char str[100];
    puts("输入一串字符");
    scanf("%s",str);
    del_digit(str);
    return 0;
}
