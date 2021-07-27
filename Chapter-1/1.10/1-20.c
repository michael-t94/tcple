/* detab.c
 *
 * This program replaces tab characters in input with the right number of
 * blanks. In order to implement this program, the key is to understand
 * the meaning of tab stop and the function of <Tab> key.
 *
 * By default, tab stop is set to 8 character wide, so a tab stop is marked
 * at position 8 in every column(8 consecutive characters make a column).
 * \t means a <Tab> key, press the <Tab> key will bring the cursor to the
 * position past next tab stop. Example below.
 *
 *   col1    col2    col3    col4
 * 1      81      81      81      8
 *
 * Input:
 * 45\t    7778\t  9\t     10
 * I am Michael,\t she is Miki.
 *
 * Output:
 * 45      7778    9       10
 * I am Michael,   she is Miki.
 */

#include <stdio.h>
#include "../../include/line.h"

int main()
{
    char c;
    int nb;       /* number of blanks necessary */
    int pos = 1;  /* position of next character to be input/output in a line */

    while ((c = getchar()) != EOF) {
        if (c == '\t') { /* then pos - 1 is the number of non-tab characters have been read in so far */
            nb = TABSTOP - (pos - 1) % TABSTOP;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
