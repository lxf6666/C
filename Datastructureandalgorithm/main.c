#include <stdio.h>
#include <stdlib.h>
//斐波那契数列 递归实现
int count=0;
int time = 0;
int fib(int i)
{
    if (i<2)
        return i==0?0:1;
    return fib(i-1)+fib(i-2);
}
//逆向输出任意字符 递归实现
void res_printf()
{
    char a;
    scanf(" %c",&a);
    if(a != '#')
        res_printf();
    if(a != '#') printf("%c",a);
}
//递归二分查找
int find(int a[],int low,int high,int e)
{
    int mid;
    mid=(low+high)/2;
    if(e == a[mid]) return mid+1;
    else if( e>a[mid] ) return find(a,mid+1,high,e);
    else if( e<a[mid]) return find(a,low,mid-1,e);
}
//汉诺塔问题
//借y将n个盘子从x移动到z
void Hanotamove(int n,char x,char y,char z)
{

    if(1 == n)
    {
        printf("第%d步\n",time+1);
        ++time;
        printf("%c-->%c\n",x,z);
    }
    else
    {
        Hanotamove(n-1,x,z,y); //借z将n-1个盘子从x移动到y
        printf("第%d步\n",time+1);
        ++time;
        printf("%c-->%c\n",x,z);
        Hanotamove(n-1,y,x,z); //借x将n-1个盘子从y移动到y
    }
}
int no_danger( int row ,int j,int (*chess)[8] )
{
    int i,k,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
    //判断列方向是否有棋子
    for(i=0;i<8;i++)
    {
        if( *(*(chess+i)+j) != 0)
        {
            flag1=1;
            break;
        }
    }
    //判断左上
    for(i=row,k=j;i>=0 && k>=0;i--,k--)
    {
        if( *(*(chess+i)+k) != 0 )
        {
            flag2 = 1;
            break;
        }
    }
    //判断右下方
    for(i=row,k=j;i < 8 && k < 8;i++,k++)
    {
        if( *(*(chess+i)+k)!= 0 )
        {
            flag3 = 1;
            break;
        }
    }
    //判断右上方
    for(i=row,k=j;i >= 0 && k < 8;i--,k++)
    {
        if( *(*(chess+i)+k)!= 0 )
        {
            flag4 = 1;
            break;
        }
    }
    //判断左下方
    for(i=row,k=j;i <8 && k >= 0;i++,k--)
    {
        if( *(*(chess+i)+k)!= 0 )
        {
            flag5 = 1;
            break;
        }
    }
    if( flag1 || flag2 || flag3 || flag4 || flag5 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
//八皇后 (*chess)[8]表指向每一行的指针
void eight_queen( int row, int cow, int (*chess)[8] )
{
    int chess2[8][8],i,j;
    for( i=0;i<8;i++ )
    {
        for(j=0;j<8;j++)
        {
            chess2[i][j]=chess[i][j];
        }
    }
    if( 8==row )
    {
        printf("第%d种\n",count+1);
        for( i=0;i<8;i++ )
        {
            for( j=0;j<8;j++ )
            {
                printf("%d ",*(*(chess2+i)+j));
            }
            printf("\n");
        }
        printf("\n");
        count++;
    }
    else
    {
        for(j=0;j<cow;j++)
        {
            if( no_danger(row,j,chess) )
            {
                for( i=0;i<8;i++)
                {
                    *(*(chess2+row)+i) = 0;
                }
                *(*(chess2+row)+j) = 1;
                eight_queen( row+1, cow, chess2 );
            }
        }
    }
}
int main()
{
    //迭代实现斐波那契数列
    int r;
    int i,j;
    int a[100];
    a[0]=0;
    a[1]=1;
    printf("%d %d ",a[0],a[1]);
    for(i=2;i<40;i++)
    {
        a[i]=a[i-1]+a[i-2];
        printf("%d ",a[i]);
    }
    printf("\n%d\n",fib(5));
    printf("输入一串数，以#结束，程序会输出他的逆序");
    res_printf();
    printf("\n输入一个要查找的数");
    scanf("%d",&i);
    r=find(a,0,39,i);
    printf("这个数在数组的第%d位\n",r);

    //汉诺塔测试
    char x='x';
    char y='y';
    char z='z';
    int n;
    i=0;
    printf("请输入游戏盘子数:\n");
    scanf("%d",&n);
    Hanotamove(n,x,y,z);
    //八皇后
    int chess[8][8];
    for(i=0;i<8;i++)
    {
         for(j=0;j<8;j++)
         {
             chess[i][j]=0;
         }
    }

    eight_queen(0,8,chess);




    return 0;

}
