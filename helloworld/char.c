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
    puts("������һ���ַ�����������ҵ��ַ�");
    scanf("%s%d",str,&c);
    printf("��Ҫ���ҵ��ַ���%s�ĵ�%d��\n",str,str_char(str,c));
    printf("�����ַ���%s����%d��",str,str_num(str,c));
    return 0;
}
