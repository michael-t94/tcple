/* Print the histogram of the lengths of words in its input vertically or
 * horizontally, with the loose definition that a word is any sequence of
 * characters that does not contain a blank, a tab or a newline. So for example
 * 'word,' becomes one word, obivously this is not a normal * definition of a
 * word yet.
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

    printf("\nHorizontal Histogram\n");

    /* use maximum height as the height of the histogram */
    size_t max = hist[1];
    for (int i = 1; i <= MAXLENGTH; ++i) {
        if (max < hist[i])
            max = hist[i];
    }

    /* print the histogram horizontally */
    for (int i = 0; i < max; ++i) {
        for (int j = 1; j <= MAXLENGTH; ++j){
            if (i < max - hist[j])
                printf("   ");
            else
                printf("__ "); /* '__' represents histogram bar */
        }
        putchar('\n');
    }

    /* print each bin number below the histogram */
    for (int i = 1; i <= MAXLENGTH; ++i) {
        printf("%02d ", i);
    }
    printf("\n\n");

    /* at last print the value of each bin */
    for (int i = 1; i <= MAXLENGTH; ++i) {
        printf("%2ld ", hist[i]);
    }
    putchar('\n');
    return 0;
}

void chist(size_t *hist)
{
    for (int i = 0; i <= MAXLENGTH; ++i) hist[i] = 0;

    char c;
    int length = 0; /* length of a word */
    int state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {  /* outside a word now */
                if (length <= MAXLENGTH) {
                    ++hist[length];
                } else { /* using hist[0] to count how many times length exceeds MAXLENGTH */
                    ++hist[0];
                }
                length = 0;
                state = OUT;
            }
        } else if (state == OUT) { /* beginning of a word */
            state = IN;
            ++length;
        } else {    /* inside a word */
            ++length;
        }
    }
}
