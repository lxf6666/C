#include<stdio.h>
int main()
{
    int a,n;
    puts("������һ������a���һὫС�ڵ��������������ȫ���оٳ���");
    scanf("%d",&a);
    n=0;  /*�Ѿ��õ���������*/
    int p[a];
    unsigned long long counter=0; /*�˷��ͳ����������*/
    if(a<2)
    {
        puts("�������������С������������");
    }
    else if(a==3||a==4)
    {
        p[n++]=2;
        p[n++]=3;
        printf("С�ڵ���%d�������У�\n%d\n%d\n",a,p[0],p[1]);
    }
    else if(a==2)
    {
       p[n++]=2;
       printf("С�ڵ���%d�������У�\n%d\n",a,p[0]);
    }
    else if(a>=5)
    {
    p[n++]=2;
    p[n++]=3;
            for(int i=5;i<=a;i+=2)
            {
                int ctr=0;
                for(int j=1;counter++,p[j]*p[j]<=i;j++)
                {
                    counter++;
                    if(i%p[j]==0)
                    {
                        ctr=1;
                        break;
                    }
                }
                if(!ctr)
                {
                    p[n++]=i;
                }
            }
     printf("С�ڵ���%d�������У�\n",a);
    for(int h=0;h<n;h++)
    {
        printf("%d\n",p[h]);
    }
     printf("�ܹ���%d�����������Ϊ%ld",n,counter);
    }
    else puts("����������");

    return 0;
}
