#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
//暴力查找
int search(int *a,int value,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if( value == a[i] )
        {
           return i;
        }
    }
    return -1;
}
//哨兵 (最好数组a[0]不放数据)
int sentinelsearch(int *a,int key,int n)
{
    int i=n-1;
    a[0]=key;
    while(a[i]!=key)
    {
        i--;
    }
    return i;
}
//二分查找
int bisearch(int *a,int key,int n)
{
    int low,mid,high;
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while( low <= high )
    {
        if(a[mid]>key)
        {
            high=mid-1;
        }
        else if(a[mid]==key)
        {
            return mid;
        }
        else
        {
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    return -1;
}
//插值查找（按比例查找）
int propsearch(int *a,int key,int n)
{
    int low,mid,high;
    low=0;
    high=n-1;
    mid=low+((key-a[low])/(a[high]-a[low]))*(high-low);
    while( low <= high )
    {
        if(a[mid]>key)
        {
            high=mid-1;
        }
        else if(a[mid]==key)
        {
            return mid;
        }
        else
        {
            low=mid+1;
        }
        mid=low+((key-a[low])/(a[high]-a[low]))*(high-low);
    }
    return -1;
}
//斐波那契查找
void createfib(int *f)
{
    int i;
    f[0]=1;
    f[1]=1;
    for(i=2;i<maxsize;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
}
int fibsearch(int *a,int key,int n)
{
    int low=0;
    int k=0;
    int i,mid,high;

    int f[maxsize];
    createfib(&f);
    //找到与n相近的 位于斐波那契数列的位置
    while(n>f[k]-1)
    {
        ++k;
    }
    //制造一个临时数组存放
    int *temp;
    temp=(int *)malloc((f[k]-1)*sizeof(int));
    memcpy(temp,a,n*sizeof(int));
    for(i=n;i<f[k]-1;i++)
    {
            temp[i]=a[n-1];
    }

    high=f[k]-2;

    while(low<=high)
    {
        mid = low+f[k-1]-1;
        if(a[mid]>key)
        {
            high=mid-1;
            --k;
        }
        else if(a[mid]==key)
        {
            if(mid<n)
            {
                free(temp);
                return mid;
            }
            else
            {
                free(temp);
                return n-1;
            }
        }
        else
        {
            low=mid+1;
            k=k-2;
        }
    }
    free(temp);
    return -1;


}
int main()
{
    int i,n,s;
    int a[9];
    printf("输入初始化数组的值\n");
    for(i=0;i<9;i++)
    {
        scanf("%d",&n);
        a[i]=n;
    }
    printf("输入要查找的值\n");
    scanf("%d",&n);
    s=search(&a,n,9);
    if(s+1)
    {
        printf("所查找的值在数组的%d位\n",s+1);
    }
    else
    {
        printf("所查找的值在数组里不存在\n");
    }
    /* s=sentinelsearch(&a,n,5);
    if(s)
    {
        printf("所查找的值在数组的%d位\n",s+1);
    }
    else
        printf("所查找的值在数组里不存在\n");
    */
    //二分查找测试
    s=bisearch(&a,n,9);
    if(s+1)
    {
        printf("所查找的值在数组的%d位\n",s+1);
    }
    else
        printf("所查找的值在数组里不存在\n");
    //按比例查找测试
    s=propsearch(&a,n,9);
    if(s+1)
    {
        printf("所查找的值在数组的%d位\n",s+1);
    }
    else
        printf("所查找的值在数组里不存在\n");

    //斐波那契查找测试
    s=fibsearch(&a,n,9);
    if(s+1)
    {
        printf("所查找的值在数组的%d位\n",s+1);
    }
    else
        printf("所查找的值在数组里不存在\n");
    return 0;
}
