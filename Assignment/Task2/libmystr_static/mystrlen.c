#include "basic.h"
int mystrlen(char s[])
{
    int c=0;
    while(s[c]!='\0')
    {
        c++;
    }
    return c;
}

