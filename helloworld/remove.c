#include<stdio.h>
void del_digit(char str[])
{
    puts("�´�Ϊ");
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
    puts("����һ���ַ�");
    scanf("%s",str);
    del_digit(str);
    return 0;
}
