
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "fun.h"
int main()
{
    int num;
    printf("Enter the Number");
    scanf("%d",&num);
    printf("\nPrime:%d",isPrime(num));
    printf("\nFactorial:%d",factorial(num));
    printf("\nPalindrome:%d",isPalindrome(num));
    printf("\nVsum:%d",vsum(3,3,4,5));
    return 0;
}
