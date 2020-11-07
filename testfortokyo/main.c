#include <stdio.h>
#include <stdlib.h>
int count=0;
int comb1(int n ,int k)
{

    if((k==0)||(k==n))
    {
        count++;
        return 1;
    }
    else
    {
        count++;
        return comb1(n-1,k-1)+comb1(n-1,k);
    }

}
int comb3(int n,int k)
{
    int i,j;
    int a[100];
    if(n-k<k) k=n-k;
    if(k==0) return 1;
    if(k==1) return n;
    for(i=0;i<k;i++)
    {
        a[i]=i+2;
    }
    for(i=3;i<=n-k+1;i++)
    {
        a[0]=i;
        for(j=1;j<k;j++)
            a[j]+=a[j-1];
    }
    return a[k-1];
}
int main()
{
    int m=comb3(9,3);
    printf("%d",m);
    return 0;
}
