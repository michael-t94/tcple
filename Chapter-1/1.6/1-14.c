/* Prints the word-lengt histogram horizontally */

#include <stdio.h>
#include "hist.h"

void chist(size_t *hist);

int main()
{
    size_t hist[MAXLENGTH + 1];

    chist(hist);

    printf("Length of %ld word(s) exceed(s) %d\n", hist[0], MAXLENGTH);
    printf("Horizontal Histogram\n");

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

