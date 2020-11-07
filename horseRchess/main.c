#include <stdio.h>
#include <stdlib.h>
#define X 8
#define Y 8

int chess[X][Y];
int nextXY(int *x,int *y,int count)
{
    switch(count)
    {
    case 0:
        if( *x+2<=X-1 && *y-1>=0 && chess[*x+2][*y-1] == 0)
        {
            *x=*x+2;
            *y=*y-1;
            return 1;
        }
        break;
    case 1:
        if( *x+2<=X-1 && *y+1<=Y-1 && chess[*x+2][*y+1] == 0)
        {
            *x=*x+2;
            *y=*y+1;
            return 1;
        }
        break;
    case 2:
        if( *x+1<=X-1 && *y-2>=0 && chess[*x+1][*y-2] == 0)
        {
            *x=*x+1;
            *y=*y-2;
            return 1;
        }
        break;
    case 3:
        if( *x+1<=X-1 && *y+2<=Y-1 && chess[*x+1][*y+2] == 0)
        {
            *x=*x+1;
            *y=*y+2;
            return 1;
        }
        break;
    case 4:
        if( *x-2>=0 && *y+1<=Y-1 && chess[*x-2][*y+1] == 0)
        {
            *x=*x-2;
            *y=*y+1;
            return 1;
        }
        break;
    case 5:
        if( *x-2>=0 && *y-1>=0 && chess[*x-2][*y-1] == 0)
        {
            *x=*x-2;
            *y=*y-1;
            return 1;
        }
        break;
    case 6:
        if( *x-1>=0 && *y+2<=Y-1 && chess[*x-1][*y+2] == 0)
        {
            *x=*x-1;
            *y=*y+2;
            return 1;
        }
        break;
    case 7:
        if( *x-1>=0 && *y-2>=0 && chess[*x-1][*y-2] == 0)
        {
            *x=*x-1;
            *y=*y-2;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;

}
void printborad()
{
    int i,j;
    for(i=0;i<X;i++)
    {
        for(j=0;j<Y;j++)
        {
            printf("%2d\t",chess[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//深度优先遍历棋盘 x,y为坐标，tag为标记变量
int chessBFSboard(int x,int y,int tag)
{
    int x1=x,y1=y,flag=0,count=0;
    chess[x][y]=tag;
    if( X*Y == tag )
    {
        printborad();
        //打印棋盘
        return 1;
    }
    //找到马下一步可走的坐标x1,y1,若找到flag=1，否则为0
    flag=nextXY(&x1,&y1,count);
    while( 0 == flag && count<7 )
    {
        count++;
        flag=nextXY(&x1,&y1,count);
    }
    while( flag )
    {
        if(chessBFSboard(x1,y1,tag+1))
        {
            printf("ok");
            return 1;
        }
        //找到马下一步可走的坐标x1,y1,若找到flag=1，否则为0
        x1 = x;
        y1 = y;
        ++count;
        flag=nextXY(&x1,&y1,count);
        while( 0 == flag && count<7 )
        {
            ++count;
            flag=nextXY(&x1,&y1,count);
        }
    }
    if( 0 == flag )
    {
        chess[x][y] = 0;
    }
    return 0;
}

int main()
{
    int i,j;
    for(i=0;i<X;i++)
    {
       for(j=0;j<Y;j++)
            chess[i][j]=0;
    }
    if(!chessBFSboard(1,0,1))
    {
        printf("抱歉，失败\n");
    }
    return 0;
}
