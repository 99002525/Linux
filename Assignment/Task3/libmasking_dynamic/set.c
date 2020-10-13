#include "bits.h"
int set(int n, int k)
{
    return (n | (1 << (k - 1)));
}

