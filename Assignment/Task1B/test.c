#include<stdio.h>
#include "bitmask.h"
#include "mystring.h"
#include "myutils.h"
//#include "bitmask.c"
//#include "mystring.c"
//#include "myutlis.c"

char string1[45]="Rahul";
char string2[]="lokesh";
char string3[]="hello";
int main()
{
  printf("Length of the string is %d\n",len("he is good boy"));
  printf("string comapre is %d\n",cmp(string1,string2));
  printf("String Concatenation:%s\n",cat(string2,string3));
  printf("String Copy:%s\n",cpy(string,string1));
  printf("Factorial(5):%d\n",factorial(5));
  printf("Is Prime(5):%d\n",isprime(5));
  printf("Palindrome(12321):%d\n",ispallindrome(12321));
  printf("vsum(3,4,5):%d\n",sum(3,3,4,5));
  printf("Setbit(5,3):%d\n",setbit(5,3));
  printf("Clearbit(5,3): %d\n",clearbit(5,3));
  printf("Flipbit(5,3)%d\n",flipbit(5,3));
  printf("Query(5,3):%d\n",querybit(5,3));
  return 0;
}	
