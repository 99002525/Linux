#include<stdio.h>
#include "basic.h"
void mystrcpy(char s1[])
{
    char s2[100];
    int i;

    for (i = 0; s1[i] != '\0'; ++i) {
        s2[i] = s1[i];
    }
    s2[i] = '\0';
    printf("\n\nstring cpy:%s",s2);
}
