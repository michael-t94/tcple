/* count.c
 *
 * count blanks, newlines and tabs
 */

#include <stdio.h>

int main()
{
    size_t nb = 0;  /* number of blanks */
    size_t nn = 0;  /* number of newlines */
    size_t nt = 0;  /* number of tabs */

    int c;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ' :
                ++nb;
                break;
            case '\n':
                ++nn;
                break;
            case '\t':
                ++nt;
                break;
        }
    }

    printf("blanks: %ld\nnewlines: %ld\ntabs: %ld\n", nb, nn, nt);
    return 0;
}

