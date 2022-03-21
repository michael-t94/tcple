#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}

int main()
{
    unsigned int a = 0xcd;

    printf("%x\n", invert(a, 4, 3));

    return 0;
}
