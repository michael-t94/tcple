#include <stdio.h>

int wordlength()
{
    int length = 1;
    u_int8_t tmp = ~0;

    for (; (tmp = tmp >> 1) > 0; ++length)
        ;

    return length;
}

u_int8_t rightrot(u_int8_t x, int n)
{
    u_int8_t rbit;

    while (n-- > 0)
    {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;
        x = x | rbit;
    }

    return x;
}

int main()
{
    u_int8_t a = 0xcd;

    printf("%x\n", rightrot(a, 3));

    return 0;
}
