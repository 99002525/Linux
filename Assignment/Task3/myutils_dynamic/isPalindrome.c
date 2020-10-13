#include "fun.h"
int isPalindrome(int number)
{
    int rem,rev=0;
    int n = number;
     while (n != 0)
    {
        rem = n % 10;
        rev = rev* 10 + rem;
        n /= 10;
    }
    if(number==rev)
        return 1;
    else
        return 0;
}
