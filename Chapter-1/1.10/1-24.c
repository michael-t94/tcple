/* check.c
 *
 * check rudimentary syntax error of a C program
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/stack.h"

int main()
{
    Symbols s;
    s.top = s.elements;
    s.size = 0;

    int c;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '{':
                push(&s, c);
                break;
            case '[':
                push(&s, c);
                break;
            case '<':
                push(&s, c);
                break;
            case '"':
                push(&s, c);
                break;
            case '\'':
                push(&s, c);
                break;
            case '(':
                push(&s, c);
                break;
            case '}':
                pop(&s);
                break;
            case ']':
                if (*s.top == '[') {
                    pop(&s);
                    break;
                } else {
                    printf("Error: missing closing character for %c\n", *s.top);
                    exit(1);
                }
            case '>':
                pop(&s);
                break;
            case ')':
                if (*s.top == '(') {
                    pop(&s);
                    break;
                } else {
                    printf("Error: missing closing character for %c\n", *s.top);
                    exit(1);
                }
        }
    }

    if (empty(&s))
        printf("No rudimentary syntax errors founded\n");

    return 0;
}
