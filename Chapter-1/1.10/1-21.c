/* entab.c
 *
 * Replace strings of blanks in input with minimal number of tabs and blanks to
 * achieve the same spacing.
 */

#include <stdio.h>
#include "../../include/line.h"

int main()
{
    int c;
    int pos = 1;
    int le;             /* left end of a string of blanks */
    int re;             /* right end of a string of blanks */
    int state = OUT;    /* initial state set to out of a string of blanks */

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (state == OUT) {
                state = IN;
                le = pos;
            }
            ++pos;
        } else {
            if (state == IN) {
                state = OUT;
                re = pos - 1;
                if (le != re) { /* a string of blanks */
                    int lcol = le / TABSTOP + 1; /* column where le is in */
                    int rcol = re / TABSTOP + 1; /* column where re is in */
                    if (lcol == rcol) { /* inside a column, just print out a string of blanks */
                        for (int i = le; i <= re; ++i)
                            putchar(' ');
                    } else {    /* accros the tabstop */
                        putchar('\t');  /* prefer tab character when either tab or blank is enough to reach the tabstop */
                        int ntabs = (re - lcol * TABSTOP) / TABSTOP; /* number of tabs to print */
                        int nb = (re - lcol * TABSTOP) % TABSTOP; /* number of blanks to print */
                        while (ntabs) {
                            putchar('\t');
                            --ntabs;
                        }
                        while (nb) {
                            putchar(' ');
                            --nb;
                        }
                    }
                } else putchar(' ');    /* a single blank */
            }
            putchar(c);
            if (c == '\n')
                pos = 1;
            else
                ++pos;
        }
    }

    return 0;
}
