/* Reads one line a time from input, prints the length of arbitrary long lines
 * and as much as possible of the text.
 */
#include <stdio.h>
#include "../../include/line.h"

int main()
{
    char line[MAXLINE];
    char longest[MAXLINE];
    int max = 0;
    int len;

    while ((len = _getline(line, MAXLINE)) > 0) {
        printf("%3d %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("\nlongest line: %s\n", longest);

    return 0;
}
