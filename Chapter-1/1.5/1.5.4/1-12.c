/* print the input one word per line */

#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */
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
