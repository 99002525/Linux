#include<stdio.h>
#include "basic.h"
void mystrcat(char s1[], char s2[])
{
   int length = 0,j;
  while (s1[length] != '\0')
    {
    ++length;
    }

  for (j = 0; s2[j] != '\0'; ++j, ++length)
    {
    s1[length] = s2[j];
    }
  s1[length] = '\0';
  printf("\n\nCat str: %s",s1);
}
