#include<stdio.h>
int main()
{
    int x[2][3]={{1,2,3},{4,5,6}};
    int y[3][2]={{1,5},{5,3},{8,1}};
    int z[2][2]={{0,0},{0,0}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int n=0;n<3;n++)
                z[j][i]+=y[n][i]*x[j][n];
        }
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            printf("%d\n", z[i][j]);
    return 0;
}
