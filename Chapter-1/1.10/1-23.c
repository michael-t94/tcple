/* rmcomment.c
 *
 * remove all C-style and C++-style comments in a C program
 */

#include <stdio.h>
#include "../../include/stack.h"

int main()
{
    Symbols s;
    s.top = s.elements;
    s.size = 0;

    int c;                      /* input character */
    int prev;                   /* previous input character */

    while ((c = getchar()) != EOF) {
        /* main logic to control when to push and pop */
        if (c == '/' || c == '*' || c == '"' || c == '\'' || c == '\n') {
            if (empty(&s)) {
                if (c != '*' && c != '\n')
                    push(&s, c);
            } else if (*s.top == '/') {
                if (c == '\n') {
                    pop(&s);
                    pop(&s);
                } else if (s.size < 2) {
                    push(&s, c);
                }
            } else if (*s.top == '*') {
                if (c == '/' && prev == '*') {
                    pop(&s);
                    pop(&s);
                }
            } else if (*s.top == c && prev != '\\') {
                pop(&s);
            }
        }
        /* save previous input character to recognize the closing pattern of a comment */
        prev = c;       
        /* control when to print the input character */
        if (empty(&s)) {
            if (c != '/')
                putchar(c);
        } else if (*s.top == '"' || *s.top == '\'') { /* inside a pair of double or single quotes */
            putchar(c);
        }
    }

    return 0;
}
