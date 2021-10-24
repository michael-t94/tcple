/* read a line into buffer */

#include <stdio.h>

int main()
{
    int lim = 10;
    char line[lim];
    int c;
    int i = 0;
    enum loop {NO, YES} okloop = YES;

    while (okloop) {
        if (i >= lim - 1) {
            okloop = NO;
        } else if ((c = getchar()) == '\n') {
            okloop = NO;
        } else if (c == EOF) {
            okloop = NO;
        } else {
            line[i] = c;
            ++i;
        }
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    
    puts(line);
    puts("End of program");

    return 0;
}
