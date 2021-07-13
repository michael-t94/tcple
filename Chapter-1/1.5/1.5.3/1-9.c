/* sblank.c
 *
 * copy input to output and replace a sequence of blanks with one blank
 */

#include <stdio.h>

int main()
{
    int prev = '\0';  /* previous read-in character */
    int c;

    while ((c = getchar()) != EOF) {
        if(c == ' ' && c == prev) { /* chech for sequences of blanks */
            continue;   /* if yes, read next character */
        }
        putchar(c);
        prev = c;
    }

    return 0;
}
