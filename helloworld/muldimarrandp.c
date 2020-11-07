#include<stdio.h>
int main()
{
    char a[][3]={"asd","jha","dda"};
    printf("%c",**(a+1));
    printf("%c",*(*(a+1)+1));

}
