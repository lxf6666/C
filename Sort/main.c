#include <stdio.h>
#include <stdlib.h>
#define maxdata 666
#define Maxsize 10
//伪冒泡排序
void fakeBubblesort(int *a,int n)
{
    int i,j,temp,count1=0,count2=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            count1++;
            if(a[i]>a[j])
            {
                count2++;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\n总共进行了%d次判断,%d次交换\n",count1,count2);
}

//冒泡排序
void Bubblesort(int *a,int n)
{
    int i,j,temp,count1=0,count2=0;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            count1++;
            if(a[j-1]>a[j])
            {
                count2++;
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\n总共进行了%d次判断,%d次交换\n",count1,count2);
}
//改进的冒泡排序
void newBubblesort(int *a,int n)
{
    int i,j,temp,count1=0,count2=0,flag=1;
    for(i=0;i<n-1 && flag==1;i++)
    {
        flag=0;
        for(j=n-1;j>i;j--)
        {
            count1++;
            if(a[j-1]>a[j])
            {
                count2++;
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
                flag=1;
            }
        }
        if(flag ==0 ) break;
    }
    printf("\n总共进行了%d次判断,%d次交换\n",count1,count2);
}

//选择排序
void selectsort(int *a,int n)
{
    int i,j,temp,count1=0,count2=0,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            count1++;
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        if( min != i )
        {
            count2++;
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
    printf("\n总共进行了%d次判断,%d次交换\n",count1,count2);
}
//直接插入排序
void insertsort(int *a,int n)
{
    int i,j,temp,count1=0,count2=0;
    for(i=1;i<n;i++)
    {
        count1++;
        if(a[i]<a[i-1])
        {
            temp=a[i];
            for(j=i-1;a[j] > temp && j >= 0;j--)
            {
                count2++;
                a[j+1]=a[j];
            }
            a[j+1]=temp;
        }

    }
    printf("\n总共进行了%d次判断,%d次交换\n",count1,count2);
}
//希尔排序
void Shellsort(int *a,int n)
{
    int i,j,temp,count1=0,count2=0;
    int gap=n;
    do
    {
        gap = gap/2-1;
        for( i=gap;i<n;i++ )
        {

            count1++;
            if(a[i]<a[i-gap])
            {
                temp=a[i];
                for(j=i-gap;a[j]>temp && j>=0;j-=gap)
                {
                    count2++;
                    a[j+gap]=a[j];
                }
                a[j+gap]=temp;
            }
        }
    }while(gap>1);

    printf("\n总共进行了%d次判断,%d次交换\n",count1,count2);
}

//堆排序
//建立堆
void create_heap(int *h,int n)
{
    int i,j,k,temp;

    for(k=n/2;k>0;k--)
    {
        temp = h[k];
        for(i=k;(i*2) <= n;i=j) //i*2 <= (*h)->size 判别是否有左儿子
        {
            j=i*2;
            if(j!=n && h[j]<h[j+1] )
            {
                j++;
            }
            if( temp >= h[j] ) break;
            else
            {
                h[i] = h[j];
            }
        }
        h[i]=temp;
    }
}
//删除
int delete_heap(int *h,int n)
{
    int i,j;
    int Maxelem,temp;
    Maxelem=h[1];
    temp = h[n--];
    for(i=1;(i*2) <= n;i=j) //i*2 <= (*h)->size 判别是否有左儿子
    {
        j=i*2;
        if(j!=n && h[j]<h[j+1] )
        {
            j++;
        }
        if( temp >= h[j] ) break;
        else
        {
            h[i] = h[j];
        }
    }
    h[i]=temp;
    return Maxelem;
}
void heapsort(int *h,int n)
{
    int i,temp,high,count=0;
    high=n-1;
    create_heap(h,n);
    for(i=n-1;i>0;--i)
    {
        count++;
        temp = h[i];
        h[i] = delete_heap(h,high);
        --high;
    }
    printf("\n一共进行了%d次交换\n",count);
}

//归并排序递归实现
//合并
void Merge(int *list1,int list1_size,int *list2,int list2_size)
{
    int i,j,k,m;
    i=j=k=0;
    int temp[Maxsize];
    while(i<list1_size&&j<list2_size)
    {
        if(list1[i]<list2[j])
        {
            temp[k++]=list1[i++];
        }
        else
        {
            temp[k++]=list2[j++];
        }
    }
    while(i<list1_size)
    {
        temp[k++]=list1[i++];
    }
    while(j<list2_size)
    {
        temp[k++]=list2[j++];
    }
    for( m=0;m<list1_size+list2_size;m++)
    {
        list1[m]=temp[m];
    }
}
void mergesort(int *a,int n)
{
    if(n>1)
    {
    int *list1=a;
    int list1_size=n/2;
    int *list2=a+n/2;
    int list2_size=n-list1_size;

    mergesort(list1,list1_size);
    mergesort(list2,list2_size);
    Merge(list1,list1_size,list2,list2_size);
    }
}

//归并迭代实现
void Iteratemergesort( int *a,int n )
{
    int i,left_min,left_max,right_min,right_max,next;
    int *temp1=(int *)malloc(n*sizeof(int)); //临时数组

    for( i=1;i<n;i*=2)
    {
        for(left_min=0;left_min<n-i;left_min=right_max)
        {
            right_min=left_max=left_min+i;
            right_max=left_max+i;

            if(right_max>n)
            {
                right_max=n;
            }
            next=0;
            while(left_min<left_max && right_min<right_max)
            {
                if(a[left_min]<a[right_min])
                {
                    temp1[next++]=a[left_min++];
                }
                else
                {
                    temp1[next++]=a[right_min++];
                }
            }
            while( left_min < left_max )
            {
                a[--right_min]=a[--left_max];
            }
            while( next>0 )
            {
                a[--right_min]=temp1[--next];
            }
        }
    }
   free(temp1);
}


//快速排序
//交换
void swap(int *a,int i,int j)
{
    int tmp;
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}
//选主元
int selectPivot(int *a,int head,int rear)
{
    int mid;
    mid=(head+rear)/2;

    if(a[head]>a[mid])
    {
        swap(a,head,mid);
    }
    if(a[head]>a[rear])
    {
        swap(a,rear,head);
    }
    if(a[mid]>a[rear])
    {
        swap(a,rear,mid);
    }
        swap(a,mid,rear-1);
        return a[rear-1];
}
void Quicksort( int a[],int head,int rear )
{
    if( rear > head && rear>1)
    {
        int pivot,i,j;
        i=head;
        j=rear-1;
        pivot=selectPivot(a,head,rear);
    while(1)
    {
        while( i<j&&a[++i]<=pivot );
        while( i<j&&a[--j]>=pivot );
        if(j>i)
        {
            swap(a,i,j);
        }
        else
        {
            break;
        }

    }
    swap(a,rear-1,i);
    Quicksort(a,head,i-1);
    Quicksort(a,i+1,rear);
    }
}

void Quick_sort(int a[] ,int n)
{
    Quicksort(a,0,n-1);
}



int main()
{

    int i,n=10;

    //伪冒泡排序测试效率

    int a[10]={4,3,2,8,6,11,7,9,10,1};
    printf("原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    fakeBubblesort(&a,n);
    printf("伪冒泡排完序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }


    //未经升级的冒泡排序
    int b[10]={4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    Bubblesort(&b,n);
    printf("冒泡排完序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    //改进的冒泡排序效率
    int c[10]={4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    newBubblesort(&c,n);
    printf("改进的冒泡排完序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    //选择排序效率
    int d[10]={4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",d[i]);
    }
    selectsort(&d,n);
    printf("选择排序排完序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",d[i]);
    }

    //直接插入排序效率
    int e[10]={4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",e[i]);
    }
    insertsort(&e,n);
    printf("直接插入排序排完序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",e[i]);
    }
    //希尔排序效率
    int f[10]={4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",f[i]);
    }
    Shellsort(&f,n);
    printf("希尔排序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",f[i]);
    }

    //堆排序效率
    int m[11]={maxdata,4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",m[i]);
    }
    heapsort(&m,n+1);
    printf("堆排序后的数组为\n");
    for(i=1;i<n+1;i++)
    {
        printf("%d ",m[i]);
    }
    //归并排序效率
    int l[10]={4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",l[i]);
    }
    mergesort(&l,n);
    printf("\n归并排完序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",l[i]);
    }
    //(迭代)归并排序效率
    int o[10]={4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",o[i]);
    }
    Iteratemergesort(&o,n);
    printf("\n归并排完序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",o[i]);
    }
    //快速排序效率
    n=10;
    int k[10]={4,3,2,8,6,11,7,9,10,1};
    printf("\n原数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",k[i]);
    }
    Quick_sort(&k,n);
    printf("\n快速排完序后的数组为\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",k[i]);
    }

    return 0;
}
