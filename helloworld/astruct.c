#include<stdio.h>
typedef struct{
        int age;
        char sex[100];
        int heigh;
} man;
struct Animal{
    char name[100];
    int age;
} monkey={"ahua",6};;
int main()
{
    man xiaoming;
    struct Animal *p;
    p=&monkey;

    printf("xiaoming������:%d\n�Ա�:%s\n���:%d\n",xiaoming.age,xiaoming.sex,xiaoming.heigh);
    printf("�⶯�����:%s\n����:%-8d\n",p->name,p->age);

    return 0;

}
