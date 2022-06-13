#include <stdio.h>

/* count how many 1-bits there are in x . */
size_t bitcount(unsigned int x)
{
    size_t count = 0;

    for (; x > 0; x >>= 1) {
        if (x & 1)
            count++;
    }

    return count;
}

/* in a 2's complement system, x &= (x - 1) deletes the rightmost 1-bit in x */
size_t fast_bitcount(unsigned int x)
{
    size_t count = 0;

    for (; x > 0; x &= (x - 1)) {
        count++;
    }

    return count;
}

int main()
{
    unsigned int a = 255;
    size_t num = bitcount(a);

    printf("%lu 1-bits in 0x%x\n", num, a);

    printf("[fast bitcount] %lu 1-bits in 0x%x\n", fast_bitcount(a), a);

    return 0;
}
