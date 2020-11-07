#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MaxData 666
typedef struct heap
{
    ElementType *elem;
    int size;
    int Capacity;
}heap,*Heap;
//初始化堆
void init(Heap *h,int Maxsize)
{
    *h=(Heap)malloc(sizeof(heap));
    (*h)->elem=(ElementType *)malloc( (Maxsize+1)*sizeof(ElementType) );
    (*h)->size=0;
    (*h)->Capacity=Maxsize;
    (*h)->elem[0]=MaxData;
}
//插入
void insert(Heap *h,ElementType e)
{
    int i;
    if( (*h)->size == (*h)->Capacity )
    {
        printf("堆已满");
    }
    i=++((*h)->size); //i标记最后一个位置
    for(;(*h)->elem[i/2]<e;i/=2)
    {
        (*h)->elem[i]=(*h)->elem[i/2];
    }
    (*h)->elem[i]=e;
}
//删除
ElementType delete_heap(Heap *h)
{
    int i,j;
    ElementType Maxelem,temp;
    if((*h)->size==0)
    {
        printf("堆已空");
    }
    Maxelem=(*h)->elem[1];

    temp = (*h)->elem[((*h)->size)--];
    for(i=1;(i*2) <= ((*h)->size);i=j) //i*2 <= (*h)->size 判别是否有左儿子
    {
        j=i*2;
        if(j!=(*h)->size && (*h)->elem[j]<(*h)->elem[j+1] )
        {
            j++;
        }
        if( temp >= (*h)->elem[j] ) break;
        else
        {
            (*h)->elem[i] = (*h)->elem[j];
        }
    }
    (*h)->elem[i]=temp;
    return Maxelem;
}
void create(Heap *h,int n)
{
    (*h)->size=n;
    int e,i,j,k,temp;
    printf("请输入%d个数据\n",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);
        (*h)->elem[i]=e;
    }

    for(k=n/2;k>0;k--)
    {
        temp = (*h)->elem[k];
        for(i=k;(i*2) <= ((*h)->size);i=j) //i*2 <= (*h)->size 判别是否有左儿子
        {
            j=i*2;
            if(j!=(*h)->size && (*h)->elem[j]<(*h)->elem[j+1] )
            {
                j++;
            }
            if( temp >= (*h)->elem[j] ) break;
            else
            {
                (*h)->elem[i] = (*h)->elem[j];
            }
        }
        (*h)->elem[i]=temp;
    }
}

int main()
{
    int n,i;
    Heap h=NULL;
    printf("要创建的堆的最大size\n");
    scanf("%d",&n);
    init(&h,n);
    printf("要创建几个数据\n");
    scanf("%d",&n);
    create(&h,n);
    for(i=1;i<=n;i++)
    {
        printf("%d ",h->elem[i]);
    }
    printf("\n输入想要插入的数\n");
    scanf("%d",&n);
    insert(&h,n);
    printf("插入后堆的变化\n");
    for(i=1;i<=h->size;i++)
    {
        printf("%d ",h->elem[i]);
    }

    printf("\n输入想要delete的数\n");
    n=delete_heap(&h);
    printf("删除的数是%d\n",n);
    printf("delete后堆的变化\n");
    for(i=1;i<=h->size;i++)
    {
        printf("%d ",h->elem[i]);
    }


    return 0;
}
