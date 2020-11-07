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

    printf("xiaoming：年龄:%d\n性别:%s\n身高:%d\n",xiaoming.age,xiaoming.sex,xiaoming.heigh);
    printf("这动物：名字:%s\n年龄:%-8d\n",p->name,p->age);

    return 0;

}
