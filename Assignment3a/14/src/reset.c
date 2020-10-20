
#include "bits.h"
int reset(int n, int k)
{
    return (n & (~(1 << (k - 1))));
}