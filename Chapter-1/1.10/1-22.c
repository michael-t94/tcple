/* fold.c
 *
 * fold long input lines into two or more shorter lines
 *
 * The program works likes following:
 * 1. read one line of input each time
 * 2. if the length of input line is less or equal to the specified text width, print
 *    the line and reset the value of lend and rend to their initial value; if the
 *    length of input line is greater than TEXTWIDTH, fold the input line based on
 *    the TEXTWIDTH. The program is clever enough to find out where to fold the line
 *    if the fold position is inside a word. Because the program reads one line a time,
 *    to fold the line is to replace the blank at fold position with a newline character.
 *    And the input should be first processed by the program detab.c to expand the tab
 *    character, Because tab is actually one character, but it takes multiple blanks on
 *    screen.
 * 3. if no more input lines, terminal and program.
 */

#include <stdio.h>
#include "../../include/line.h"

#define TEXTWIDTH 25            /* text width */

int main()
{
    char line[MAXLINE];         /* input line */
    int len;                    /* length of input line */
    int lend = 0;               /* left end of the folded line */
    int rend = TEXTWIDTH;       /* right end of the folded line */

    while ((len = _getline(line, MAXLINE)) > 0) {
        while (len > TEXTWIDTH) {  /* input line longer than text width */
            if (line[rend] != ' ' && line[rend] != '\n') { /* fold position inside a word */
                /* first find blank before the fold position */
                int tmp = rend;
                while (line[--tmp] != ' ' && tmp != lend)
                    ;
                if (tmp != lend)
                    rend = tmp;
                else { /* word longer than the text width, find blank after the word */
                    while (line[++rend] != ' ')
                        ;
                }
                line[rend] = '\n';  /* fold here */
            } else if (line[rend] == ' ') {
                line[rend] = '\n';
            }
            len = len - (rend - lend + 1);
            lend = rend + 1;
            rend = lend + TEXTWIDTH;
        }
        printf("%s", line);
        lend = 0;
        rend = TEXTWIDTH;
    }

    return 0;
}
