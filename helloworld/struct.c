#include<stdio.h>
#include<time.h>
int main()
{
    time_t now;
    struct tm *local;
    char wday_name[][7] = {"��","һ","��","��","��","��","��"};

    time(&now);
    local = localtime(&now);
    printf("������");
    printf("%4d�� %2d�� %2d�� (%s)",local->tm_year+1900,local->tm_mon+1,local->tm_mday,wday_name[local->tm_wday]);
    return 0;
}
