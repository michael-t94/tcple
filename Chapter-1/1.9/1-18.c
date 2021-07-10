/* Removes trailing blanks and tabs from each line of input, and deletes
 * entirely blank lines.
 */
#include <stdio.h>
#include "../../include/line.h"

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = _getline(line, MAXLINE)) > 0) {
        int i = len - 2;
        /* move '\n' and '\0' one character to the left each time if the
         * character before '\n' is a blank or a tab
         */
        while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) {
            line[i] = '\n';
            line[i + 1] = '\0';
            --len;
            --i;
        }
        if (len > 1) /* ignore blank lines */
            printf("%s", line);
    }

    return 0;
}
