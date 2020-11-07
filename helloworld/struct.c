#include<stdio.h>
#include<time.h>
int main()
{
    time_t now;
    struct tm *local;
    char wday_name[][7] = {"日","一","二","三","四","五","六"};

    time(&now);
    local = localtime(&now);
    printf("今天是");
    printf("%4d年 %2d月 %2d日 (%s)",local->tm_year+1900,local->tm_mon+1,local->tm_mday,wday_name[local->tm_wday]);
    return 0;
}
