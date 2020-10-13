#include "basic.h"
int mystrcmp(char mj1[], char mj2[])
{
    int i = 0, flag = 0;
    while(mj1[i] != '\0' && mj2[i] != '\0')
    {
        if(mj1[i] != mj2[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0 && mj1[i] == '\0' && mj2[i] == '\0')
        return 1;
    else
        return 0;
}

