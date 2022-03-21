#include <stdio.h>

/*
 * set bits of x from p to the leftmost n bits of y
 */
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    // clear n bits of x starting at position p
    unsigned int tmp1 = x & ~(~(~0 << n) << (p + 1 - n));
    // extract n bits of y and shitf them to the position p
    unsigned int tmp2 = (y & ~(~0 << n)) << (p + 1 - n);
    // OR them to get the result
    unsigned int result = tmp1 | tmp2;

    return result;
}

int main()
{
    unsigned int a = 0x26u;
    unsigned int b = 0xdu;

    unsigned int c = setbits(a, 4, 3, b);

    printf("%u\n", c);
    printf("0x%x\n", c);

    return 0;
}
