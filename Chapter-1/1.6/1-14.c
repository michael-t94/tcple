/* Print the histogram of the frequencies of different characters in its input.
 * The program computes frequencies for characters from 32 to 126 which are
 * printable, and for character TAB, NL(newline), VF(vertical tab), CR(carriage
 * return).
 */

#include <stdio.h>

#define HEIGHT 100 /* maximum histogram height */

int main()
{
    size_t hist[99];
    int c;

    for (int i = 0; i < 99; ++i) hist[i] = 0;

    /* compute histogram */
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\t':
                ++hist[0];
                break;
            case '\n':
                ++hist[1];
                break;
            case '\v': /* vertical tab */
                ++hist[2];
                break;
            case '\r': /* carriage return */
                ++hist[3];
                break;
            default:
                ++hist[c - 28];
        }
    }

    /* find max value of histogram */
    int max = 0;
    for (int i = 0; i < 99; ++i) {
        if (max < hist[i])
            max = hist[i];
    }

    /* print histogram */
    printf("%5ld TAB ", hist[0]);
    for (int i = 0; i < (double)hist[0] / max * HEIGHT; ++i)
        putchar('|');
    printf("\n%5ld  NL ", hist[1]);
    for (int i = 0; i < (double)hist[1] / max * HEIGHT; ++i)
        putchar('|');
    printf("\n%5ld  VT ", hist[2]);
    for (int i = 0; i < (double)hist[2] / max * HEIGHT; ++i)
        putchar('|');
    printf("\n%5ld  CR ", hist[3]);
    for (int i = 0; i < (double)hist[3] / max * HEIGHT; ++i)
        putchar('|');
    putchar('\n');
    for (int i = 4; i < 99; ++i) {
        printf("%5ld '%c' ", hist[i], i + 28);
        for (int j = 0; j < (double)hist[i] / max * HEIGHT; ++j)
            putchar('|');
        putchar('\n');
    }

    return 0;
}
