/* Prints the word-lengt histogram vertically, with the loose definition that
 * a word is any sequence of characters that does not contain a blank, a tab
 * or a newline. So 'word,' becomes one word, obivously this is not a normal
 * definition of a word yet.
 */

#include <stdio.h>
#include "../../include/line.h"

void chist(size_t *hist);

int main()
{
    size_t hist[MAXLENGTH + 1];

    chist(hist);

    printf("Length of %ld word(s) exceed(s) %d\n", hist[0], MAXLENGTH);

    /* print vertical histogram */
    printf("Vertical Histogram\n");
    for (int i = 1; i <= MAXLENGTH; ++i) {
        printf("%ld\t%02d ", hist[i], i);
        for (int j = 0; j < hist[i]; ++j)
            putchar('|');
        putchar('\n');
    }

    return 0;
}
