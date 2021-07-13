/* reverse.c 
 *
 * Reverse the input one line a time
 */

#include <stdio.h>
#include "../../include/line.h"

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = _getline(line, MAXLINE)) > 0) {
            reverse(line);
            printf("%s", line);
    }

    return 0;
}
