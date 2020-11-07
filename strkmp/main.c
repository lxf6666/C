#include <stdio.h>
#include <stdlib.h>

void get_next( char T[], int *next)
{
    int i,j;
    j=0;
    i=1;
    next[1]=0;
    while( i<T[0] )
    {
        if( j == 0 || T[i] == T[j] )
        {
            i++;
            j++;
            if( T[i] != T[j] )
            {
                next[i]=j;
            }
            else
            {
                next[i]=next[j];
            }
        }
        else
        {
            j = next[j];
        }
    }

}
//返回子串T在主串S第pos个字符之后的位置
int Index_kmp( char S[],char T[],int pos )
{
    int next[255];
    int i = pos;
    int j = 1;
    get_next( T,next );
    while( i<=S[0] && j<=T[0] )
    {
        if( 0==j || S[i] == T[j] )
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }

    }
    if( j>T[0] )
    {
        return i-T[0];
    }
    else
        return 0;
}
//bf匹配算法
int Index_bf( char S[], char T[])
{
    int i=1,j=1,k=i;
    while( i<=S[0] && j<=T[0] )
    {
        if( S[i]==T[j] )
        {
            ++i;
            ++j;
        }
        else
        {
            j=1;
            i=++k;
        }
    }
    if(j>T[0])
    {
        return k;
    }
    else return 0;
}
int main()
{
    int i=1;
    char s[255]=" aaaaaaaef";
    s[0]=10;
    char t[255];
    printf("主串为%s\n",s+1);
    printf("输入要检测的串\n");
    scanf("%s",t+1);
    while(t[i]!='\0')
    {
        i++;
    }
    t[0]=i-1;
    printf("要检测的串%s\n",t+1);
    i=Index_bf(s,t);
    printf("检测串在主串中的位置%d\n",i);
    i=Index_kmp(s,t,0);
    printf("检测串在主串中的位置%d\n",i);


    return 0;
}
