#include <stdio.h>
#include <stdlib.h>
#include<definsqstack.h>
#include<math.h>
int BinarytoDecimal(sqStack s)
{
    int e,n,i,ss;
    ss=0;
    n=currentsize(s);
    for(i=0;i<n;i++)
    {
        pop(s,&e);
        ss+=e*pow(2,i);
        s.top--;
    }
    return ss;
}
