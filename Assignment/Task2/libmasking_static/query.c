#include "bits.h"
#include <stdio.h>
void query(int n, int k)
{
    if (n & (1 << (k - 1)))
        printf("SET\n");
    else
        printf("NOT SET\n");
}
