#include "bits.h"
int flip(int n, int k)
{
    return (n ^ (1 << (k - 1)));
}