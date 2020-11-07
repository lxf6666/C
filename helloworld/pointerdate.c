#include<stdio.h>
void yesterday(int *y, int *m, int *d)
{
   if(judgeyear(y)&&(*m==3)&&(*d==1))
   {
       --*m;
       *d=29;
   }
   else if((!judgeyear(y))&&(*m==3)&&(*d==1))
   {
       --*m;
       *d=28;
   }
   else if(*m==1&&*d==1)
   {
       --*y;
       *m=12;
       *d=31;
   }
   else if((judgemonth(m)==2)&&(*d==1))
   {
       --*m;
       *d=31;
   }
   else if((judgemonth(m)==1)&&(*m!=1)&&(*d==1))
   {
       --*m;
       *d=30;
   }
   else if(*d!=1)
   {
       *d--;
   }
}
void tomorrow(int *y, int *m, int *d)
{
    if(judgeyear(y)&&(*m==2)&&(*d==29))
   {
       ++*m;
       *d=1;
   }
   else if((!judgeyear(y))&&(*m==2)&&(*d==28))
   {
       ++*m;
       *d=28;
   }
   else if((judgemonth(m)==2)&&(*d==30))
   {
       ++*m;
       *d=1;
   }
   else if((judgemonth(m)==1)&&(*d==31))
   {
       ++*m;
       *d=1;
   }
   else if(*d!=1)
   {
       ++*d;
   }
}
int judgeyear(int *n)
{
    return (((*n%4)==0)?1:0);
}
int judgemonth(int *m)
{
    int h;
    if(((*m<=7)&&(*m%2==1))||((*m>7)&&(*m%2==0)))
        h=1;
    else if((*m<=7)&&(*m%2==0)&&(*m!=2)||((*m>7)&&(*m%2==1)))
        h=2;

}
int main(void)
{
    int y,n,d;
    puts("输入一个日期： 年 月 日");
    scanf("%d%d%d",&y,&n,&d);
    yesterday(&y,&n,&d);
    printf("这一天的昨天是%d年%d月%d日",y,n,d);
    return 0;
}

