/* computes the histogram of lengths of words in input */

#include <stdio.h>
#include "hist.h"

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
