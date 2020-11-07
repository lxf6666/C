#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>
int currentsize(sqStack s)
{
    return (s.top-s.base);
}
