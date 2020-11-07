#include<stdio.h>
int strtoi(const char *str)
{
    char a[10]="0123456789";
    int s[100];
    int r=0;
    int n=0;
    char *d=str;
    while(*d)
    {
        for(int i=0;i<10;i++)
        {
            if(*d==a[i])
            {
                s[n]=(int)(a[i]-'0');
                n++;
            }
        }
        *d++;
    }
    for(int i=0;i<n;i++)
    {
       int h=1;
       for(int j=1;j<=(n-i-1);j++)
       {
            h*=10;
       }
       r+=(s[i]*h);
    }

    return r;

}

int main()
{
    char s[100];
    int a[100];
    puts("输入一段字符串");
    scanf("%s",s);
        printf("转化结果为%d",strtoi(s));
    return 0;
}
