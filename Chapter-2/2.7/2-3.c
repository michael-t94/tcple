#include <stdio.h>

/* convert a hexidecimal string with optional '0x' or '0X' to equivalent integer */
int htoi(const char s[]);

int main()
{
    char s[100];

    printf("Input a hexidecimal number: ");
    scanf("%s", s);
    printf("%s(16) = %d(10)\n", s, htoi(s));

    return 0;
}

int htoi(const char s[])
{
    enum loopok {OK, NO} wloop = OK;
    int i = 0;
    int n = 0;      /* equivalent integer number: 0x00000000 ~ 0xffffffff */
    char c;

    /* pass '0x' or '0X' in the begining */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    while (wloop == OK) {
        c = s[i];
        if (c >= '0' && c <= '9') {
            n = 16 * n + c - '0';
        } else if (c >= 'A' && c <= 'F') {
            n = 16 * n + c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            n = 16 * n + c - 'a' + 10;
        } else {
            wloop = NO;
        }
        ++i;
    }

    return n;
}
