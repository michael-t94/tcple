/* Prints the input one word per line, with the loose definition that a word
 * is any sequence of characters that does not contain a blank, a tab or a
 * newline. So 'word,' becomes one word, obivously this is not a normal
 * definition of a word yet.
 */

#include <stdio.h>
#include "../../../include/line.h"

int main()
{
    int state = OUT;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {  /* outside a word now */
                state = OUT;
                putchar('\n');
            }
        } else {
            state = IN;
            putchar(c);
        }
    }
    
    return 0;
}
