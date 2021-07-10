/* Same as 1-16.c, except that this program only prints the line with length
 * greater than 80.
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
        if (len > LONGLINE)
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
