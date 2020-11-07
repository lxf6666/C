#include <stdio.h>
#include <stdlib.h>
#define Hashsize 12
#define Nulldata -999
typedef struct
{
    int *elem;//存放数据基地址
    int count;//当前元素个数

}HashTable;
void Init_HashTable(HashTable *ht)
{
    int i;
    ht->count=Hashsize;
    ht->elem=(int *)malloc(Hashsize*sizeof(int));
    if(ht==NULL)
    {
        printf("内存分配失败\n");
    }
    for(i=0;i<Hashsize;i++)
    {
        ht->elem[i]=Nulldata;
    }
     printf("初始化完成\n");
}

//除留余数法
int Hash(int key)
{
    return key % Hashsize;
}

void insertHash(HashTable *ht,int key)
{
    int addr;
    addr=Hash(key);
    while( ht->elem[addr]!=Nulldata )
    {
        addr=(addr+1)%Hashsize;
    }
    ht->elem[addr]=key;
}

void search_Hash(HashTable ht,int key,int *addr)
{
    *addr=Hash(key);

    while( ht.elem[*addr] != key )
    {
        *addr=(*addr+1)%Hashsize;
        if( ht.elem[*addr]==Nulldata || *addr ==Hash(key) )
        {
            printf("查找的数不存在");
            break;
        }
    }
}

int main()
{
    int n,i,j;
    HashTable ht;
    Init_HashTable(&ht);
    printf("输入要插入几个数在哈希表\n");
    scanf("%d",&n);
    printf("请输入%d个数\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        insertHash(&ht,j);
    }
    printf("请输入要查找的数据\n");
    scanf("%d",&j);
    int addr;

    search_Hash(ht,j,&addr);
    printf("你找的数在哈希表的%d位置\n",addr);
    return 0;
}
